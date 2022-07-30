// #include <utility>

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		T1 first;
		T2 second;

	public:

	public:
		/* (constructor) : constructs new pair (public member function) */
		/* std::pair<T1, T2>::pair */
		pair() : first(), second () { }

		pair(const T1& x, const T2& y) : first(x), second(y) { }

		template <class U1, class U2>
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) { }

		pair(const pair& p) = default;


		/* operator= : assigns the contents (public member function) */
		/* std::pair<T1, T2>::operator= */
		pair& operator=(const pair& other)
		{
			this->first = other.first;
			this->second = other.second;
			return *this;
		}
		// return *this

		/* make_pair : creates a pair object of type, defined by the argument types (function template) */
		template <class T1, class T2>
		ft::pair<T1, T2> make_pair(T1 t, T2 u)
		{
			return pair<T1, T2>(t, u);
		}

		/*
			operator== != < <= > >=
			lexicographically compares the values in the pair (function template)
		*/
		template <class T1, class T2>
		bool operator==(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
		{
			return (lhs.first == rhs.first) && (lhs.second == rhs.second);
		}

		template <class T1, class T2>
		bool operator!=(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
		{
			return !(lhs == rhs);
		}

		template <class T1, class T2>
		bool operator<(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
		{
			return (lhs.first < rhs.first) || (!(rhs.first < lhs.first) && (lhs.second < rhs.second))
		}

		template <class T1, class T2>
		bool operator<=(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
		{
			return !(rhs < lhs);
		}

		template <class T1, class T2>
		bool operator>(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
		{
			return rhs < lhs;
		}

		template <class T1, class T2>
		bool operator>=(const std::pair<T1, T2>& lhs, const std::pair<T1, T2>& rhs)
		{
			return !(lhs < rhs);
		}
	};
}
