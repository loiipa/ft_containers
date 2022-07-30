// #include <algorithm>

namespace ft
{
	/* std::equal : determines if two sets of elements are the same (function templtae) */
	template <class InputIt1, class InputIt2>
	bool equal (InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 == *first2))
			{
				return false;
			}
		}
		return true;
	}

	template <class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!p(*first1, *first2))
			{
				return false;
			}
		}
		return true;
	}

	/* 
		std::lexicographical_copmare : returns true if one range is lexicographically less than another
		(function template)
	*/
	// void붙이는 이유는 오버로드 된 연산자의 호출을 방지하기 위함
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
			{
				return true;
			}
			if (*first2 < *first1)
			{
				return false;
			}
		}
		return (first1 == last1) && (first2 != last2);
	}

	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (comp(*first1, *first2))
			{
				return true;
			}
			if (comp(*first2, *first1))
			{
				return false;
			}
		}
		return (first1 == last1) && (first2 != last2);
	}
}
