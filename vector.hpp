#include <memory>
// #include <vector>

// 멤벼 변수가 무엇인지 확인해봐야 함.
// bool 자료형에 대해 따로 구현할 필요가 없음
// allocator는 std::allocator 가능

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
		typedef Allocator::pointer						pointer;
		typedef Allocator::const_pointer				const_pointer;

		typedef value_type 								iterator;				/* LegacyRandomAccessIterator and LegacyContiguousIterator to */
		typedef const value_type						const_iterator;			/* LegacyRandomAccessIterator and LegacyContiguousIterator to */
		typedef std::reverse_iterator<iterator>			reverse_iterator;
		typedef std::reverse_iterator<const_iterator> 	const_reverse_iterator;



		// Member functions

		/* (constructor) : constructs the vector */
		/* std::vector<T, Allocator>::vector */
		vector();
		explicit vector(const Allocator& alloc);
		explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator());
		template <class InputIt>
		vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
		vector(const vector& other);

		/* (decstructor) : destructs the vector */
		/* std::vector<T, Allocator>::~vector */
		~vector();

		/* operator= assigns : values to the container */
		/* std:;vector<T, Allocator>::operator= */
		vector& operator=(const vector& other);

		/* assign : assigns values to the container */
		/* std::vector<T, Allocator>::assign */
		void assign(size_type count, const T& value);
		template<class InputIt>
		void assign(InputIt first, Inputit last);

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
		const_reverse iterator rend() const;


		// Capacity

		/* empty : checks whether the container is empty */
		/* std::vector<T, Allocator>::empty */
		bool empty() const;

		/* size : returns the number of elements */
		/* std::vector<T, Allocator>::size */
		size_type size() const;

		/* max_size : returns the maximum possible number of elements */
		/* std::vector<T, Allocator>::max_size */
		size_type max_size() const;

		/* reserve : reserve storage */
		/* std::vector<T, Allocator>::reserve */
		void reserve(size_type new_cap);

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
		void clear();

		/* insert : inserts elements */
		/* std::vector<T, Allocator>::insert */
		iterator insert(iterator pos, const T& value);
		void insert(iterator pos, size_type count, const T& value);
		template<class InputIt>
		void insert(iterator pos, inputIt first, InputIt last);

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
		void swap(std::vector<T, Alloc> & lhs, std::vector<t, Alloc>& & rhs);

	};
}
