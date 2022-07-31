#include <iostream>
#include <memory>
#include <iterator>	//std::distance
#include <vector>
#include <stdexcept>
#include "utility.hpp"
#include "algorithm.hpp"
#include "type_traits.hpp"
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
			if (count > this->max_size())
				throw std::length_error("vector");
			this->_begin = this->_alloc.allocate(count);
			this->_end = this->_begin;
			this->_end_cap = this->_begin + count;
			// ul, _end는 명령문이 실행된 후 변화됨.
			for (size_type ul = 0; ul < count; ++ul, (void) ++(this->_end))
			{
				this->_alloc.construct(this->_end, value);
			}
		}

		// 위의 생성자를 의도하지만, 여기로 들어가는 것을 방지하기위해 enable_if로 막아준다.
		template <class InputIt>
		vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<InputIt>::value>::type* = NULL)
		: _begin(NULL), _end(NULL), _end_cap(NULL), _alloc(alloc)
		{
			difference_type dif = std::distance(first, last);
			this->_begin = this->_alloc.allocate(dif);
			this->_end = this->_begin;
			this->_end_cap = this->_begin + dif;

			for (InputIt it = first; it != last; ++it)
			{
				this->_alloc.construct(this->_end, *it);
				++(this->_end);
			}
		}

		vector(const vector& other)
		: _begin(NULL), _end(NULL), _end_cap(NULL), _alloc(other._alloc)
		{
			size_type count = other.size();
			if (count > this->max_size())
				throw std::length_error("vector");
			this->_begin = this->_alloc.allocate(count);
			this->_end = this->_begin;
			this->_end_cap = this->_begin + count;

			for (const_iterator it = other.begin(); it != other.end(); ++it)
			{
				this->_alloc.construct(this->_end, *it);
				++(this->_end);
			}
		}

		/* (decstructor) : destructs the vector */
		/* std::vector<T, Allocator>::~vector */
		~vector()
		{
			clear();
			_alloc.deallocate(_begin, _end_cap - _begin);
		}

		/* operator= assigns : values to the container */
		/* std:;vector<T, Allocator>::operator= */
		vector& operator=(const vector& other)
		{
			this->_alloc = other._alloc;

			size_type count = other.size();
			if (count > this->max_size())
				throw std::length_error("vector");
			this->_begin = this->_alloc.allocate(count);
			this->_end = this->_begin;
			this->_end_cap = this->_begin + count;

			for (const_iterator it = other.begin(); it != other.end(); ++it)
			{
				this->_alloc.construct(this->_end, *it);
				++(this->_end);
			}
			return *this;
		}

		/* assign : assigns values to the container */
		/* std::vector<T, Allocator>::assign */
		void assign(size_type count, const T& value)
		{
			if (count > this->max_size())
				throw std::length_error("vector");

			this->clear();
			if (this->capacity() < count)
			{
				this->_alloc.deallocate(this->_begin, this->_end_cap - this->_begin);
				this->_begin = _alloc.allocate(count);
				this->_end = this->_begin;
				this->_end_cap = this->_begin + count;
			}
			else
			{
				this->_end = this->_begin;
			}

			for (size_type ul = 0; ul < count; ++ul, (void) ++(this->_end))
			{
				this->_alloc.construct(this->_end, value);
			}
		}
		template<class InputIt>
		void assign(InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value>::type* = NULL)
		{

		}

		/* get_allocator : returns the associated allocator */
		/* std::vector<T, Allocator>::get_allocator */
		allocator_type get_allocator() const
		{
			return this->_alloc;
		}


		// Element access

		/* at : access specified element with bounds checking */
		/* std::vector<T, Allocator>::at */
		reference at(size_type pos)
		{
			if (pos < 0 || pos >= this->size())
				throw std::out_of_range("vector");
			return *(this->begin() + pos);
		}
		const_reference at(size_type pos) const
		{
			if (pos < 0 || pos >= this->size())
				throw std::out_of_range("vector");
			return *(this->begin() + pos);
		}

		/* exceptions */
		/* std::out_of_range if !(pos < size()) */

		/* operator[] a: ccess specified element */
		/* std::vector<T, Allocator>::operator[] */
		reference operator[](size_type pos)
		{
			return *(this->begin() + pos);
		}
		const_reference operator[](size_type pos) const
		{
			return *(this->begin() + pos);
		}

		/* front : access the first element */
		/* std::vector<T, Allocator>::front */
		reference front()
		{
			return *(this->begin());
		}

		const_reference front() const
		{
			return *(this->begin());
		}

		/* back : access the last element */
		/* std::vector<T, Allocator>::back */
		reference back()
		{
			return *(this->end() - 1);
		}

		const_reference back() const
		{
			return *(this->end() - 1);
		}

		/* data : direct access to the underlying array */
		/* std::vector<T, Allocator>::data */
		// T* data();
		// const T* data() const;


		// Iterator

		/* begin : returns an iterator to the beginning */
		/*std::vector<T, Allocator>::begin */
		iterator begin()
		{
			return iterator(this->_begin);
		}

		const_iterator begin() const
		{
			return const_iterator(this->_begin);
		}

		/* end : returns an iterator to the end */
		/*std::vector<T, Allocator>::end */
		iterator end()
		{
			return iterator(this->_end);
		}

		const_iterator end() const
		{
			return const_iterator(this->_end);
		}

		/* rbegin : returns a reverse iterator to the beginning */
		/*std::vector<T, Allocator>::rbegin */
		reverse_iterator rbegin()
		{
			return reverse_iterator(this->end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(this->end());
		}

		/* rend : returns a reverse iterator to the end */
		/*std::vector<T, Allocator>::rend */
		reverse_iterator rend()
		{
			return reverse_iterator(this->begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(this->begin());
		}


		// Capacity

		/* empty : checks whether the container is empty */
		/* std::vector<T, Allocator>::empty */
		bool empty() const
		{
			return this->_begin == this->_end;
		}

		/* size : returns the number of elements */
		/* std::vector<T, Allocator>::size */
		size_type size() const
		{
			return this->_end - this->_begin;
		}

		/* max_size : returns the maximum possible number of elements */
		/* std::vector<T, Allocator>::max_size */
		size_type max_size() const
		{
			return this->_alloc.max_size();
		}

		/* reserve : reserve storage */
		/* std::vector<T, Allocator>::reserve */
		void reserve(size_type new_cap)
		{
			if (new_cap > this->max_size())
				throw std::length_error("vector");
			if (new_cap <= this->capacity())
			{
				return;
			}
			allocator_type allocNew;
			pointer beginNew = allocNew.allocate(new_cap);
			pointer endNew = beginNew;

			pointer beginTmp = this->_begin;
			
			for (size_type ul = 0; ul < this->size(); ++ul, (void) ++endNew, (void) ++beginTmp)
			{
				*endNew = *beginTmp;
			}
			this->_alloc.deallocate(_begin, _end_cap - _begin);
			this->_begin = beginNew;
			this->_end = endNew;
			this->_end_cap = beginNew + new_cap;
			this->_alloc = allocNew;
		}

		/* exceptions */
		// std::length_error if (new_cap > max_size())
		// any exception thrown by Allocator::allocate() (typically std::bad_alloc)

		/* capacity : returns the number of elements
		that can be held in currently acllocated storage */
		/* std::vector<T, Allocator>::capacity */
		size_type capacity() const
		{
			return this->_end_cap - this->_begin;
		}


		// Modifiers

		/* clear : clears the contents */
		/* std::vector<T, Allocator>::clear */
		void clear()
		{
			while (this->_begin != this->_end)
			{
				--(this->_end);
				this->_alloc.destroy(this->_end);
			}
		}

		/* insert : inserts elements */
		/* std::vector<T, Allocator>::insert */
		iterator insert(iterator pos, const T& value)
		{
			size_type addSize = 1;
			if (this->size() + addSize > this->max_size())
				throw std::length_error("vector");
			if (this->size() == this->capacity())
			{
				// size 키우기
				// 이동 -> 00000 / a / 000 뭐 이런식
				
			}
			else
			{
				// 해당 pos ~ end()까지 한칸씩 이동 -> _end += 1;
				// pos자리에 삽입
				this->_alloc.construct(this->_end, this->back());
				++(this->_end);
				//for (size_type ul = 0; ul < this->)
				
			}
			// 끝자리 삽입?
		}
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
		void push_back(const T& value)
		{
			size_type addSize = 1;

			if (this->size() + addSize > this->max_size())
				throw std::length_error("vector");
			if (this->size() == this->capacity())
			{
				if (this->capacity() * 2 > this->max_size())
				{
					this->reserve(this->max_size());
				}
				else
				{
					if (this->capacity() < addSize)
						this->reserve(addSize);
					else
						this->reserve(this->capacity() * 2);
				}
			}
			this->_alloc.construct(this->_end, value);
			++(this->_end);
		}

		/* pop_back : removes the last element */
		/* std::vector<T, Allocator>::push_back */
		void pop_back()
		{
			--(this->_end);
			this->_alloc.destory(this->_end);
		}

		/* resize : changes the number of elements stored */
		/* std::vector<T, Allocator>::resize */
		void resize(size_type count, T value = T())
		{
			// 초과 -> 초과된 공간만큼 value 채움
			// if (capacity() < count);
			// 미만 -> 깎임
			if (count > this->max_size())
				throw std::length_error("vector");
			if (count < this->size())
			{
				for (size_type ul = 0; ul < this->size() - count; ++ul);
				{
					--(this->end());
					this->_alloc.destroy(this->_end);
				}
				return;
			}
			else if (count > this->capacity())
			{
				if (count < this->capacity() * 2)
				{
					if (this->capacity() * 2 > this->max_size())
						this->reserve(this->max_size());
					else
						this->reserve(this->capacity() * 2);
				}
				else
				{
					this->reserve(count);
				}
			}
			for (size_type ul = 0; ul < count - this->size(); ++ul, ++(this->_end))
			{
				this->_alloc.construct(this->_end, value);
			}
		}

		/* swap : swaps the contents */
		/* std::vector<T, Allocator>::swap */
		void swap(vector& other)
		{
			ft::swap(this->_begin, other._begin);
			ft::swap(this->_end, other._end);
			ft::swap(this->_end_cap, other._end_cap);
			ft::swap(this->_alloc, other._alloc);
		}

	};
	// Non-member functions

	/* lexicographically compares the values in the vector */
	/* operator== */
	template <class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	/* operator!= */
	template <class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		return !(lhs == rhs);
	}

	/* operator< */
	template <class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	/* operator<= */
	template <class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		return !(rhs < lhs);
	}

	/* operator> */
	template <class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		return rhs < lhs;
	}

	/* operator>= */
	template <class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc> & lhs, const ft::vector<T, Alloc> & rhs)
	{
		return !(lhs < rhs);
	}


	/* std::swap (std::vector) : specializes the std::swap algoorithm */
	/* std::swap(std::vector) */
	template <class T, class Alloc>
	void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}
