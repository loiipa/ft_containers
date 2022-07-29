//#include <iterator>
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

/*
	std::reverse_iterator
	iterator adaptor for reverse-order traversal
	(class template)
*/
	template <class Iter>
	class reverse_iterator
		: public ft::iterator<
			ft::iterator_traits<Iter>::iterator_traits<Iter>::iterator_category,
			ft::iterator_traits<Iter>::value_type,
			ft::iterator_traits<Iter>::difference_type,
			ft::iterator_traits<iTer>::pointer,
			ft::iterator_traits<Iter>::reference,
		>
	{
		typedef Iter											iterator_type;
		typedef ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef ft::iterator_traits<Iter>::value_type			value_type;
		typedef ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef ft::iterator_traits<Iter>::pointer				pointer;
		typedef ft::iterator_traits<Iter>::reference			reference;

	public:
		/* (constructor) : constructs a new iterator adaptor */
		/* std::reverse_iterator<Iter>:reverse_iterator */
		reverse_iterator();
		explicit reverse_iterator(iterator_type x);
		template <class U>
		reverse_iterator(const reverse_iterator<U>& othrer);

		/* operator= : assigns another iterator adaptor */
		/* std::reverse_iterator<Iter>::operator= */
		template <class U>
		reverse_iterator& operator=(const reverse_iterator<U>& other);

		/* base : accesses the underlying iterator */
		/* (즉, iterator로 돌아온다고 생각하면 될듯) */
		/* std::reverse_iterator<Iter>::base */
		iterator_type base() const;

		/*
			operator*, operator-> :
			access the pointed-to element
		*/
		/* std::reverse_iterator<Iter>::operator* */
		/* std::reverse_iterator<Iter>::operator-> */
		reference operator*() const;
		pointer operator->() const;

		/* operator[] : accesses an element by index */
		/* std::reverse_iterator<Iter>::operator[] */
		/* unspecified */ operator[] (difference_type n) const;


		/* advances or decrements the iterator */
		/* std::reverse_iterator<Iter>::operator++, +, +=, --, -, -= */

		/* pre_increments or pre_decrements by one respectively */

		/* operator++ */
		reverse_iterator& operator++();

		/* operator-- */
		reverse_iterator& operator--();

		/* operator+ */
		reverse_iterator& operator+(difference_type n) const;

		/* operator- */
		reverse_iterator operator-(difference_type n) const;

		/* operator+= */
		reverse_iterator operator+=(diffenece_type n);

		/* operator-= */
		reverse_iterator operator-=(difference_type n);

	protected:
		/* current(protected) : the underlying iterator of which base() returns a copy */
		iterator current;

	public:
		/* compares the underlying iterators */
		/* operator== */
		template <class Iterator1, class Iterator2>
		bool operator==(const ft::reverse_iterator<Iterator1>& lhs,
			const ft:reverse_iterator<Iterator2>& rhs);

		/* operator!= */
		template <class Iterator1, class Iterator2>
		bool operator!=(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator2<Iterator2>& rhs);

		/* operator< */
		template <class Iterator1, class Iterator2>
		bool operator<(const ft::reverse_iterator<Iterator1>& lhs,
			const ft:reverse_iterator<Iterator2>& rhs);

		/* operator<= */
		template <class Iterator1, class Iterator2>
		bool operator<=(const ft::reverse_iterator<Iterator1>& lhs,
			const ft:reverse_iterator<Iterator2>& rhs);

		/* operator> */
		template <class Iterator1, class Iterator2>
		bool operator>(const ft::reverse_iterator<Iterator1>& lhs,
			const ft:reverse_iterator<Iterator2>& rhs);

		/* operator>= */
		template <class Iterator1, class Iterator2>
		bool operator>=(const ft::reverse_iterator<Iterator1>& lhs,
			const ft:reverse_iterator<Iterator2>& rhs);

		/* operator+ : advances the iterator */
		/* operator+(std::reverse_iterator) */
		/* 2 + itr 같이 iterator가 뒤에 오는 경우 */
		template <class Iter>
		reverse_iterator<Iter> operator+(
			typename reverse_iterator<Iter>::difference_type n,
			const reverse_iterator<Iter>& it );

		/* operator- : conputes the distance beetween two iterator adaptors */
		/* operator-(std::reverse_iterator) */
		template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type
			operator-(const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs );
	}
}
