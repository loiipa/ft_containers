#include <iostream>
#include <memory>
// #include <vector>
#include <stdexcept>
#include "vector_iterator.hpp"

// 멤벼 변수가 무엇인지 확인해봐야 함.
// bool 자료형에 대해 따로 구현할 필요가 없음
// allocator는 std::allocator 가능
// 예외처리 추가해야함

namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef vector_iterator<pointer>				iterator;
		typedef vector_iterator<const_pointer>			const_iterator;
		typedef std::reverse_iterator<iterator>			reverse_iterator;
		typedef std::reverse_iterator<const_iterator> 	const_reverse_iterator;

		/* LegacyRandomAccessIterator and LegacyContiguousIterator to */
		// typedef value_type 								iterator;
		// typedef const value_type						const_iterator;

	private:
		pointer			_begin;
		pointer			_end;
		pointer			_end_cap;
		allocator_type	_alloc;

	public:
		// Member functions

		/* (constructor) : constructs the vector */
		/* std::vector<T, Allocator>::vector */
		// 원래는 cppreference 참고, 생성자는 https://cplusplus.com/reference/vector/vector/vector/ 참고하였음

		// vector();
		// explicit vector(const Allocator& alloc)
		// explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
		/*
		template <class InputIt>
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
		*/
		// vector(const vector& other);

		explicit vector(const allocator_type& alloc = allocator_type())
		: _begin(NULL), _end(NULL), _end_cap(NULL), _alloc(alloc) { }

		explicit vector(size_type count, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
		: _begin(NULL), _end(NULL), _end_cap(NULL), _alloc(alloc)
		{
			// count <= 0일때는..?
			if (count > max_size())
				throw std::length_error("vector");
			_begin = _alloc.allocate(count);
			_end = _begin;
			_end_cap = _begin + count;
			// ul, _end는 명령문이 실행된 후 변화됨.
			for (size_type ul = 0; ul < count; ++ul, (void) ++_end)
			{
				_alloc.construct(_end, 0);
			}
		}
		template <class InputIt>
		vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type());
		vector(const vector& other);

		/* (decstructor) : destructs the vector */
		/* std::vector<T, Allocator>::~vector */
		~vector()
		{
			clear();
			_alloc.deallocate(_begin, _end_cap - _begin);
		}

		/* operator= assigns : values to the container */
		/* std:;vector<T, Allocator>::operator= */
		vector& operator=(const vector& other);

		/* assign : assigns values to the container */
		/* std::vector<T, Allocator>::assign */
		void assign(size_type count, const T& value);
		template<class InputIt>
		void assign(InputIt first, InputIt last);

		/* get_allocator : returns the associated allocator */
		/* std::vector<T, Allocator>::get_allocator */
		allocator_type get_allocator() const;


		// Element access

		/* at : access specified element with bounds checking */
		/* std::vector<T, Allocator>::at */
		reference at(size_type pos);
		const_reference at(size_type pos) const;

		/* exceptions */
		/* std::out_of_range if !(pos < size()) */

		/* operator[] a: ccess specified element */
		/* std::vector<T, Allocator>::operator[] */
		reference operator[](size_type pos);
		const_reference operator[](size_type pos) const;

		/* front : access the first element */
		/* std::vector<T, Allocator>::front */
		reference front();
		const_reference front() const;

		/* back : access the last element */
		/* std::vector<T, Allocator>::back */
		reference back();
		const_reference back() const;

		/* data : direct access to the underlying array */
		/* std::vector<T, Allocator>::data */
		T* data();
		const T* data() const;


		// Iterator

		/* begin : returns an iterator to the beginning */
		/*std::vector<T, Allocator>::begin */
		iterator begin();
		const_iterator begin() const;

		/* end : returns an iterator to the end */
		/*std::vector<T, Allocator>::end */
		iterator end();
		const_iterator end() const;

		/* rbegin : returns a reverse iterator to the beginning */
		/*std::vector<T, Allocator>::rbegin */
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		/* rend : returns a reverse iterator to the end */
		/*std::vector<T, Allocator>::rend */
		reverse_iterator rend();
		const_reverse_iterator rend() const;


		// Capacity

		/* empty : checks whether the container is empty */
		/* std::vector<T, Allocator>::empty */
		bool empty() const;

		/* size : returns the number of elements */
		/* std::vector<T, Allocator>::size */
		size_type size() const
		{
			return _end - _begin;
		}

		/* max_size : returns the maximum possible number of elements */
		/* std::vector<T, Allocator>::max_size */
		size_type max_size() const
		{
			return _alloc.max_size();
		}

		/* reserve : reserve storage */
		/* std::vector<T, Allocator>::reserve */
		void reserve(size_type new_cap)
		{
			return _end_cap - _begin;
		}

		/* exceptions */
		// std::length_error if (new_cap > max_size())
		// any exception thrown by Allocator::allocate() (typically std::bad_alloc)

		/* capacity : returns the number of elements
		that can be held in currently acllocated storage */
		/* std::vector<T, Allocator>::capacity */
		size_type capacity() const;


		// Modifiers

		/* clear : clears the contents */
		/* std::vector<T, Allocator>::clear */
		void clear()
		{
			while (_begin != _end)
			{
				--_end;
				_alloc.destroy(_end);
			}
		}

		/* insert : inserts elements */
		/* std::vector<T, Allocator>::insert */
		iterator insert(iterator pos, const T& value);
		void insert(iterator pos, size_type count, const T& value);
		template<class InputIt>
		void insert(iterator pos, InputIt first, InputIt last);

		// pos - iterator before which the content will be inserted. pos may be the end() iterator

		/* erase : erases elements */
		/* std::vector<T, Allocator>::erase */
		iterator erase(iterator pos);
		iterator erase(iterator first, iterator last);

		/* push_back : adds an elements to the end */
		/* std::vector<T, Allocator>::push_back */
		void push_back(const T& value);

		/* pop_back : removes the last element */
		/* std::vector<T, Allocator>::push_back */
		void pop_back();

		/* resize : changes the number of elements stored */
		/* std::vector<T, Allocator>::resize */
		void resize(size_type count, T value = T());

		/* swap : swaps the contents */
		/* std::vector<T, Allocator>::swap */
		void swap(vector & othrer);

	};
	// Non-member functions

	/* lexicographically compares the values in the vector */
	/* operator== */
	template <class T, class Alloc>
	bool operator==(const std::vector<T, Alloc> & lhs, const std::vector<T, Alloc> & rhs);

	/* operator!= */
	template <class T, class Alloc>
	bool operator!=(const std::vector<T, Alloc> & lhs, const std::vector<T, Alloc> & rhs);

	/* operator< */
	template <class T, class Alloc>
	bool operator<(const std::vector<T, Alloc> & lhs, const std::vector<T, Alloc> & rhs);

	/* operator<= */
	template <class T, class Alloc>
	bool operator<=(const std::vector<T, Alloc> & lhs, const std::vector<T, Alloc> & rhs);

	/* operator> */
	template <class T, class Alloc>
	bool operator>(const std::vector<T, Alloc> & lhs, const std::vector<T, Alloc> & rhs);

	/* operator>= */
	template <class T, class Alloc>
	bool operator>=(const std::vector<T, Alloc> & lhs, const std::vector<T, Alloc> & rhs);


	/* std::swap (std::vector) : specializes the std::swap algoorithm */
	/* std::swap(std::vector) */
	template <class T, class Alloc>
	void swap(std::vector<T, Alloc> & lhs, std::vector<T, Alloc>&  rhs);
}
