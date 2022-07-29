#include <utility>

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
	public:
	/* (constructor) : constructs new pair (public member function) */
	/* std::pair<T1, T2>::pair */
		pair();
		pair(const T1& x, const T2& y);

		template <class U1, class U2>
		pair(const pair<U1, U2>& p);

		pair(const pair& p) = default;


	/* operator= : assigns the contents (public member function) */
	/* std::pair<T1, T2>::operator= */
	pair& operator=(const pair& other);
	// return *this

	/* make_pair : creates a pair object of type, defined by the argument types (function template) */
	template <class T1, class T2>
	std::pair<T1, T2> make_pair(T1 t, T2 u);

	/*
		operator== != < <= > >=
		lexicographically compares the values in the pair (function template)
	*/
	template <class T1, class T2>
	bool operator==(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs);

	template <class T1, class T2>
	bool operator!=(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs);

	template <class T1, class T2>
	bool operator<(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs);

	template <class T1, class T2>
	bool operator<=(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs);

	template <class T1, class T2>
	bool operator>(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs);

	template <class T1, class T2>
	bool operator>=(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs);
	};
}
