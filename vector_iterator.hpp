#include "iterator.hpp"

namespace ft
{
	template <class Iter>
	class vector_iterator : public ft::iterator<
		typename ft::iterator_traits<Iter>::iterator_category,
		typename ft::iterator_traits<Iter>::value_type,
		typename ft::iterator_traits<Iter>::difference_type,
		typename ft::iterator_traits<Iter>::pointer,
		typename ft::iterator_traits<Iter>::reference
		>
	{
	public:
		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;

	protected:
		Iter current;

	public:
		vector_iterator() : current(NULL) { }
		explicit vector_iterator(iterator_type x) : current(x) { }
		template <class U>
		vector_iterator(const vector_iterator<U>& other) : current(other.base()) { }

		template <class U>
		vector_iterator& operator=(const vector_iterator<U>& other)
		{
			this->current = other->base();
			return *this;
		}

		iterator_type base() const
		{
			return current;
		}

		reference operator*() const
		{
			Iter tmp = current;
			return *tmp;
		}

		pointer operator->() const
		{
			return &(operator*());
		}

		reference operator[] (difference_type n) const
		{
			return *(*this + n);
		}

		vector_iterator& operator++()
		{
			++current;
			return *this;
		}

		vector_iterator& operator--()
		{
			--current;
			return *this;
		}

		vector_iterator operator++(int)
		{
			vector_iterator tmp(*this);
			++current;
			return tmp;
		}

		vector_iterator operator--(int)
		{
			vector_iterator tmp(*this);
			--current;
			return tmp;
		}

		vector_iterator operator+(difference_type n) const
		{
			return vector_iterator(this->current + n);
		}

		vector_iterator operator-(difference_type n) const
		{
			return vector_iterator(this->current - n);
		}

		vector_iterator &operator+=(difference_type n)
		{
			current += n;
			return *this;
		}

		vector_iterator &operator-=(difference_type n)
		{
			current -= n;
			return *this;
		}
	};
	template <class Iterator1, class Iterator2>
	bool operator==(
		const ft::vector_iterator<Iterator1>& lhs, const ft::vector_iterator<Iterator2>&rhs)
	{
		return lhs->base() == rhs->base();
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(
		const ft::vector_iterator<Iterator1>& lhs, const ft::vector_iterator<Iterator2>&rhs)
	{
		return lhs->base() != rhs->base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<(
		const ft::vector_iterator<Iterator1>& lhs, const ft::vector_iterator<Iterator2>&rhs)
	{
		return lhs->base() < rhs->base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(
		const ft::vector_iterator<Iterator1>& lhs, const ft::vector_iterator<Iterator2>&rhs)
	{
		return lhs->base() <= rhs->base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>(
		const ft::vector_iterator<Iterator1>& lhs, const ft::vector_iterator<Iterator2>&rhs)
	{
		return lhs->base() > rhs->base();
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(
		const ft::vector_iterator<Iterator1>& lhs, const ft::vector_iterator<Iterator2>&rhs)
	{
		return lhs->base() >= rhs->base();
	}

	template <class Iter>
	vector_iterator<Iter> operator+ (
		typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
	{
		return vector_iterator<Iter>(it->base() + n);
	}

	template <class Iter>
	typename vector_iterator<Iter>::difference_type operator-(
		const vector_iterator<Iter>& lhs, vector_iterator<Iter>& rhs)
	{
		return lhs->base() - rhs->base();
	}
}
