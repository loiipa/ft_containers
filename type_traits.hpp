// #include <type_traits>

namespace ft
{
	/* std::enable_if */
	template <bool B, class T = void>
	struct enable_if { };

	template <class T>
	struct enable_if<true, T> { typedef T type; };

	// integral쪽은 고민 필요
	/*
		integral_constant : compile-time constant of specified type with specified value
		class template, since C++11
	*/
	template <class T, T v>
	struct integral_constant
	{
		// static constexpr T value = v;
		// using value_type = T;
		// using type = integral_constant;
		// constexpr operator value_type() const noexcept { return value; }

		static const T value = v;
		typedef T					value_type;
		typedef integral_constant	type;
		operator value_type() const { return value; }
	};

	/* specialization */
	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	// is_integral_base를 이용하여 해당하는 integral을 true_type으로 해줌.
	template <class T>
	struct is_integral_base : public false_type {};

	template <>
	struct is_integral_base<int> : public true_type {};

	/*
		is_integral : checks if a type is an integral type
		class template, since C++11
	*/
	template <class T>
	// struct is_integral : integral_constant<bool, is_integral<T>()> { };
	struct is_integral : is_integral_base<T> { };


}
