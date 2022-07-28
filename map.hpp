#include <map>

namespace ft
{
	/* std::map */
	// collection of key-value pairs, sorted by keys, keys ar unique (class template)
	template <class Key, class T, class Compare = std::less<Key>,
		class Allocator = std::allocator<std::pair<const Key, T> >
	> class map
	{
		class value_compare : std::binary_function<value_type, value_type, bool>
		{
		protected:
		// Initializes the internal instance of the comparator to c
			value_compare(Compare c);
			Compare Comp;
		public:
			// Compares lhs.first and rhs.first by calling the stored comparator
			bool operator()(const value_type& lhs, const value_type& rhs) const;
		};

	public:
	/* (constructor) : constructs the map (public member function) */
	/* std::map <Key, T, Compare, Allocator>::map */

	// Constructs an empty container
	map();
	explicit map(const Compare& comp, const Allocator& alloc = Allocator());

	// Constructs the container with the contents of the range [first, last).
	template <class InputIt>
	map(InputIt first, InputIt last, const Compare& comp = Compare(),
		const Allocator& alloc = Allocator());

	// Copy constructor
	map(const map& other);

	/* (destructor) : destructs the map (public member function) */
	/* std::map <Key, T, Compare, Allocator>::~map */
	~map();

	/* operator= : assigns values to the container (public member function) */
	/* std::map <Key, T, Compare, Allocator>::operator= */
	map& operator=(const map& other);

	/* get_allocator : returns the associated allocator (public member function) */
	/* std::map <Key, T, Compare, Allocator>::get_allocator */
	allocator_type get_allocator() const;

	/* at : access specified element with bounds checking (public member function) */
	/* std::map <Key, T, Compare, Allocator>::at */
	T& at(const Key& key);
	const T& at(const Key& key) const;

	/* operator[] : access or insert specified element (public member function) */
	/* std::map <Key, T, Compare, Allocator>::operator[] */
	T* operator[](const Key& key);

	/* begin : returns an iterator to the beginning (public member function) */
	/* std::map <Key, T, Compare, Allocator>::begin */
	iterator begin();
	const_iterator begin() const;

	/* end : returns an iterator to the end (public member function) */
	/* std::map <Key, T, Compare, Allocator>::end */
	iterator end();
	const_iterator end() const;

	/* rbegin : returns a reverse iterator to the beginning (public member function) */
	/* std::map <Key, T, Compare, Allocator>::rbegin */
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;

	/* rend : returns a reverse iterator to the end (public member function) */
	/* std::map <Key, T, Compare, Allocator>::rend */
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	/* empty : checks whether the container is empty (public member function) */
	/* std::map <Key, T, Compare, Allocator>::empty */
	bool empty() const;

	/* size : returns the number of elements (public member function) */
	/* std::map <Key, T, Compare, Allocator>::size */
	size_type size() const;

	/* max_size : returns the maximum possible number of elements (public member function) */
	/* std::map <Key, T, Compare, Allocator>::max_size */
	size_type max_size() const;

	/* clear : clears the contents (public member function) */
	/* std::map <Key, T, Compare, Allocator>::clear */
	void clear();

	/* insert : inserts elements (public member function) */
	/* std::map <Key, T, Compare, Allocator>::insert */
	std::pair<iterator, bool> insert(const value_type& value);

	iterator insert(iterator hint, const value_type& value);

	template <class InputIt>
	void insert(InputIt first, inputIt last);

	/* erase : erases elements (public member function) */
	/* std::map <Key, T, Compare, Allocator>::erase */
	void erase(iterator pos);
	void erase(iterator first, iterator last);
	size_type erase(consst Key& key);

	/* swap : swaps the contents (public member function) */
	/* std::map <Key, T, Compare, Allocator>::swap */
	void swap(map& other);

	/* count : returns the number of elements matching specific key (public member function) */
	/* std::map <Key, T, Compare, Allocator>::count */
	// key값과 매칭되는 개수 (0 or 1)
	size_type count(const Key& key) const;

	/* find : finds elements with specific key (public member function) */
	/* std::map <Key, T, Compare, Allocator>::find */
	iterator find(const Key& key);
	const_iterator find(const Key& key) const;

	/* equal_range : returns range of elements matching a specific key (public member function) */
	/* std::map <Key, T, Compare, Allocator>::equal_range */
	// iterator를 범위로, 존재하는 key보다 작거나 크면 각각 begin, end를 가리키는 것을 보인다.
	std::pair<iterator, iterator> equal_range(const Key& key);
	std::pair<const_iterator, const_iterator> equal_range(const Key& key) const;

	/* lower_bound : returns an iterator to the first element not less than the given key (public member function) */
	/* std::map <Key, T, Compare, Allocator>::lower_bound */
	iterator lower_bound(const Key& key);
	const_iterator lower_bound(const Key& key) const;

	/* upper_bound : returns an iterator to the first element grater than the given key (public member function) */
	/* std::map <Key, T, Compare, Allocator>::upper_bound */
	iterator upper_bound(const Key& key);
	const_iterator upper_bound(const &Key key) const;s

	};
}
