#include <type_traits>

namespace ft
{
	/* std::enable_if */
	template <bool B, class T = void>
	struct enable_if { };

	template <class T>
	struct enable_if<true, T> { typedef T type; };
}

