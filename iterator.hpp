// #include <iterator>
#include <cstddef>	//std::ptrdiff_t

namespace ft
{
/*
	 std::iterator
	 base class to ease the definition of required types for simple iterators
	 (class template)
*/
	template<
		class Category,
		class T,
		class Distance = std::ptrdiff_t,
		class Pointer = T*,
		class Reference = T&
	> struct iterator;

/*
	std::input_iterator_tag
	std::output_iterator_tag
	std::forward_iterator_tag
	std::bidirectional_iterator_tag
	std::random_access_iterator_tag
	empty class types used to indicate iterator categories
*/
	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

/*
	std::iterator_traits
	provides uniform interface to the properties of an iterator
*/
	template <class Iter>
	struct iterator_traits
	{
		typedef Iter::difference_type		difference_type;
		typedef Iter::value_type			value_type;
		typedef Iter::pointer				pointer;
		typedef Iter::reference				reference;
		typedef Iter::iterator_category		iterator_category;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef ft::random_access_iterator_tag		iterator_category;
	};

	/* std::reverse_iterator : iterator adaptor for reverse-order traversal (class template) */
	// current는 기본 iterator
	template <class Iter>
	class reverse_iterator
		: public ft::iterator<
			ft::iterator_traits<Iter>::iterator_category,
			ft::iterator_traits<Iter>::value_type,
			ft::iterator_traits<Iter>::difference_type,
			ft::iterator_traits<iTer>::pointer,
			ft::iterator_traits<Iter>::reference,
		>
	{
	public:
		typedef Iter											iterator_type;
		typedef ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef ft::iterator_traits<Iter>::value_type			value_type;
		typedef ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef ft::iterator_traits<Iter>::pointer				pointer;
		typedef ft::iterator_traits<Iter>::reference			reference;

		/* (constructor) : constructs a new iterator adaptor */
		/* std::reverse_iterator<Iter>:reverse_iterator */
		reverse_iterator() : current() { }

		explicit reverse_iterator(iterator_type x) : current(x) { }

		template <class U>
		reverse_iterator(const reverse_iterator<U>& other) : current(other.base()) { }

		/* operator= : assigns another iterator adaptor */
		/* std::reverse_iterator<Iter>::operator= */
		template <class U>
		reverse_iterator& operator=(const reverse_iterator<U>& other)
		{
			this->current = other->base();
			return *this;
		}

		/* base : accesses the underlying iterator */
		/* (즉, iterator로 돌아온다고 생각하면 될듯) */
		/* std::reverse_iterator<Iter>::base */
		iterator_type base() const
		{
			return current;
		}

		/* operator*, operator-> : access the pointed-to element */
		/* std::reverse_iterator<Iter>::operator* */
		/* std::reverse_iterator<Iter>::operator-> */
		// -1하는건 reverse라서
		reference operator*() const
		{
			Iter tmp = current;
			return *--tmp;
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		/* operator[] : accesses an element by index */
		/* std::reverse_iterator<Iter>::operator[] */
		reference operator[] (difference_type n) const
		{
			return *(*this + n);
		}


		/* advances or decrements the iterator */
		/* std::reverse_iterator<Iter>::operator++, +, +=, --, -, -= */

		/* pre_increments or pre_decrements by one respectively */

		/* operator++ */
		//
		reverse_iterator& operator++()
		{
			--current;
			return *this;
		}

		/* operator-- */
		reverse_iterator& operator--()
		{
			++current;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp(*this);
			--current;
			return tmp;
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp(*this);
			++current;
			return *this;
		}

		/* operator+ */
		// 자기자신의 값이 바뀌지 않음 -> *this가 아니라 생성자로 리턴
		reverse_iterator& operator+(difference_type n) const
		{
			return reverse_iterator(this->current - n);
		}

		/* operator- */
		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(this->current + n);
		}

		/* operator+= */
		reverse_iterator operator+=(diffenece_type n)
		{
			current -= n;
			return *this;
		}

		/* operator-= */
		reverse_iterator operator-=(difference_type n)
		{
			current += n;
			return *this;
		}

	protected:
		/* current(protected) : the underlying iterator of which base() returns a copy */
		Iter current;

	public:
		/* compares the underlying iterators */
		/* operator== */
		template <class Iterator1, class Iterator2>
		bool operator==(const ft::reverse_iterator<Iterator1>& lhs, const ft:reverse_iterator<Iterator2>& rhs)
		{
			return lhs->base() == rhs->base();
		}

		/* operator!= */
		template <class Iterator1, class Iterator2>
		bool operator!=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator2<Iterator2>& rhs)
		{
			return lhs->base() == rhs->base();
		}

		/* operator< */
		template <class Iterator1, class Iterator2>
		bool operator<(const ft::reverse_iterator<Iterator1>& lhs, const ft:reverse_iterator<Iterator2>& rhs)
		{
			return lhs->base() < rhs->base();
		}

		/* operator<= */
		template <class Iterator1, class Iterator2>
		bool operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft:reverse_iterator<Iterator2>& rhs)
		{
			return lhs->base() <= rhs->base();
		}

		/* operator> */
		template <class Iterator1, class Iterator2>
		bool operator>(const ft::reverse_iterator<Iterator1>& lhs, const ft:reverse_iterator<Iterator2>& rhs)
		{
			return lhs->base() > rhs->base();
		}

		/* operator>= */
		template <class Iterator1, class Iterator2>
		bool operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft:reverse_iterator<Iterator2>& rhs)
		{
			return lhs->base() >= rhs->base();
		}

		/* operator+ : advances the iterator */
		/* operator+(std::reverse_iterator) */
		/* 2 + itr 같이 iterator가 뒤에 오는 경우 */
		template <class Iter>
		reverse_iterator<Iter> operator+(
			typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
		{
			return reverse_iterator<Iter>(it.base() - n);
		}

		/* operator- : conputes the distance beetween two iterator adaptors */
		/* operator-(std::reverse_iterator) */
		template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs )
		{
			return rhs.base() - lhs.base();
		}
	};
}
