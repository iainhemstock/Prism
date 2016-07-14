/*
 * Algorithms.h
 * v0.1
 *
 *  Created on: Jul 13, 2016
 *      Author: iainhemstock
 */

#ifndef PRISM_ALGORITHMS_H_
#define PRISM_ALGORITHMS_H_

// todo remove this
#include <iostream>

namespace prism {

template <class T>
void swap(T& a, T& b);

/**
 * Searches the range \em [first,last) for the first occurrence of two consecutive elements
 * that match, and returns an iterator to the first of these two elements, or \em last if no such pair is found.
 */
template <class ForwardIterator>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last) {
	while (first != last) {
		if (*first == *(first+1))
			return first;
		first++;
	}
	return last;
}

/**
 * Returns true if \em pred returns true for all the elements in the range \em [first,last)
 * or if the range is empty, and false otherwise.
 */
template <class InputIterator, class Predicate>
bool all_of(InputIterator first, InputIterator last, Predicate pred) {
	while (first != last) {
		if (!pred(*first)) return false;
		first++;
	}
	return true;
}

/**
 * Returns true if \em pred returns true for any of the elements in the range \em [first, last].
 */
template <class InputIterator, class Predicate>
bool any_of(InputIterator first, InputIterator last, Predicate pred) {
	while (first != last) {
		if (pred(*first)) return true;
		first++;
	}
	return false;
}

/**
 * Copies the elements in the range \em [first,last) into the range beginning at \em otherFirst.
 */
template <class InputIterator, class OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator otherFirst) {
	while (first != last) {
		*otherFirst = *first;
		first++;
		otherFirst++;
	}
	return otherFirst;
}

/**
 * Copies the elements in the range \em [first,last) for
 * which \em pred returns true to the range beginning at \em otherFirst.
 */
template <class InputIterator, class OutputIterator, class Predicate>
OutputIterator copy_if(InputIterator first, InputIterator last, OutputIterator otherFirst, Predicate pred) {
	while (first != last) {
		if (pred(*first)) {
			*otherFirst = *first;
			otherFirst++;
		}
		first++;

	}
	return otherFirst;
}

/**
 * Copies the first \em n elements from the range beginning at \em first into the range beginning at \em otherFirst.
 */
template <class InputIterator, class Size, class OutputIterator>
OutputIterator copy_n(InputIterator first, Size n, OutputIterator otherFirst) {
	while (n>0) {
	    *otherFirst = *first;
	    ++otherFirst;
	    ++first;
	    --n;
	  }
	return otherFirst;
}

/**
 * Returns the number of elements in the range \em [first,last) that compare equal to \em value.
 */
template <class InputIterator, class T>
int count(InputIterator first, InputIterator last, const T& value) {
	int c = 0;
	while (first++ != last) {
		if (*first == value) c++;
	}
	return c;
}

/**
 * Returns the number of elements in the range \em [first,last) for which \em pred is true.
 */
template <class InputIterator, class Predicate>
int count_if(InputIterator first, InputIterator last, Predicate pred) {
	int c = 0;
	while (first != last)  {
		if (pred(*first)) c++;
		first++;
	}
	return c;
}

/**
 * Deletes the elements in the range \em [first, last] by using the c++ delete operator.
 * The element that the iterator points to therefore must be a pointer.
 */
template <class ForwardIterator>
void delete_range(ForwardIterator first, ForwardIterator last) {
	while (first != last) {
		delete *first;
		first++;
	}
}

/**
 * Compares the elements in the range \em [first1,last1) with those in the
 * range beginning at \em first2, and returns true if all of the
 * elements in both ranges match. \n
 * The elements are compared using operator==.
 */
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first, InputIterator1 last, InputIterator2 otherFirst) {
	while (first != last) {
		if (!(*first == *otherFirst)) return false;
		first++;
		otherFirst++;
	}
	return true;
}

/**
 * Assigns \em value to all the elements in the range \em [first,last).
 */
template <class ForwardIterator, class T>
void fill(ForwardIterator first, ForwardIterator last, const T& value) {
	while (first != last) {
		*first = value;
		first++;
	}
}

/**
 * Assigns \em value to the first \em n elements of the sequence pointed by \em first.
 */
template <class ForwardIterator, class T>
void fill_n(ForwardIterator first, int size, const T& value) {
	while (size > 0) {
		*first = value;
		size--;
		first++;
	}
}

/**
 * Returns an iterator to the first element in the range \em [first,last)
 * that compares equal to \em value. If no such element is found, the function returns \em last.
 */
template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& value) {
	while (first != last) {
		if (*first == value) return first;
		first++;
	}
	return last;
}

/**
 * Returns an iterator to the first element in the range \em [first,last) for which \em pred returns true.
 * If no such element is found, the function returns \em last.
 */
template <class InputIterator, class Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate pred) {
	while (first != last) {
		if(pred(*first)) return first;
		first++;
	}
	return last;
}

/**
 * Applies function \em func to each of the elements in the range \em [first,last).
 */
template <class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function func) {
	while (first != last) {
		func(*first);
		first++;
	}
	return func;
}

/**
 * Returns the largest of \em a and \em b.
 * If they are equivalent then \em a is returned.
 */
template <class T>
const T& max(const T& a, const T& b) {
	if (b > a) return b;
	return a;
}

/**
 * Returns the smallest of \em a and \em b.
 * If they are equivalent then \em a is returned.
 */
template <class T>
const T& min(const T& a, const T& b) {
	if (b > a) return a;
	return b;
}

/**
 * Returns true if \em pred returns false for all the elements in the range \em [first,last)
 * or if the range is empty, and false otherwise.
 */
template <class InputIterator, class Predicate>
bool none_of(InputIterator first, InputIterator last, Predicate pred) {
	while (first != last) {
		if (pred(*first)) return false;
		first++;
	}
	return true;
}

/**
 * Transforms the range \em [first,last) into a range with all the elements that
 * compare equal to \em value removed, and returns an iterator to the new end of that range.
 */
template <class ForwardIterator, class T>
ForwardIterator remove (ForwardIterator first, ForwardIterator last, const T& value) {
  ForwardIterator result = first;
  while (first!=last) {
    if (!(*first == value)) {
      *result = *first;
      ++result;
    }
    ++first;
  }
  return result;
}

/**
 * Copies the elements in the range \em [first,last) to the range beginning at \em otherFirst,
 * except those elements that compare equal to \em value.
 */
template <class InputIterator, class OutputIterator, class T>
OutputIterator remove_copy (InputIterator first, InputIterator last, OutputIterator otherFirst, const T& value)
{
  while (first!=last) {
    if (!(*first == value)) {
      *otherFirst = *first;
      ++otherFirst;
    }
    ++first;
  }
  return otherFirst;
}

/**
 * Copies the elements in the range \em [first,last) to the range beginning at \em otherFirst,
 * except those elements for which \em pred returns true.
 */
template <class InputIterator, class OutputIterator, class UnaryPredicate>
OutputIterator remove_copy_if (InputIterator first, InputIterator last, OutputIterator otherFirst, UnaryPredicate pred)
{
  while (first!=last) {
    if (!pred(*first)) {
      *otherFirst = *first;
      ++otherFirst;
    }
    ++first;
  }
  return otherFirst;
}

/**
 * Transforms the range \em [first,last) into a range with all the elements for which
 * \em pred returns true removed, and returns an iterator to the new end of that range.
 */
template <class ForwardIterator, class Predicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, Predicate pred) {
	ForwardIterator result = first;
	while (first != last) {
		if (!pred(*first)) {
			*result = *first;
			++result;
		}
		++first;
	}
	return result;
}

/**
 * Assigns \em newValue to all the elements in the range \em [first,last) that compare equal to \em oldValue.
 */
template <class ForwardIterator, class T>
void replace(ForwardIterator first, ForwardIterator last, const T& oldValue, const T& newValue) {
	while (first != last) {
		if (*first == oldValue)
			*first = newValue;
		first++;
	}
}

/**
 * Copies the elements in the range \em [first,last) to the range beginning
 * at \em otherFirst, replacing the appearances of \em oldValue by \em newValue.
 */
template <class InputIterator, class OutputIterator, class T>
OutputIterator replace_copy(InputIterator first, InputIterator last, OutputIterator otherFirst,
		const T& oldValue, const T& newValue)
{
	while (first != last) {
		if (*first == oldValue)
			*otherFirst = newValue;
		else
			*otherFirst = *first;
		first++;
		otherFirst++;
	}
	return otherFirst;
}

/**
 * Copies the elements in the range \em [first,last) to the range beginning at \em otherFirst,
 * replacing those for which \em pred returns true by newValue.
 */
template <class InputIterator, class OutputIterator, class Predicate, class T>
OutputIterator replace_copy_if(InputIterator first, InputIterator last, OutputIterator otherFirst,
		Predicate pred, const T& newValue)
{
	while (first != last) {
		if (pred(*first)) *otherFirst = newValue;
		else *otherFirst = *first;
		first++;
		otherFirst++;
	}
	return otherFirst;
}

/**
 * Assigns \em newValue to all the elements in the range \em [first,last) for which \em pred returns true.
 */
template <class ForwardIterator, class Predicate, class T>
void replace_if(ForwardIterator first, ForwardIterator last, Predicate pred, const T& newValue) {
	while (first != last) {
		if (pred(*first))
			*first = newValue;
		first++;
	}
}

/**
 * Sorts the elements in the range \em [first, last] in ascending order using bubble sort.
 */
template <class RandomAccessIterator>
void sort(RandomAccessIterator first, RandomAccessIterator last) {

	int i,j;
	int n = last - first;


	bool swapped = false;

	for(i = 0; i < n-1; i++) {
		swapped = false;
		RandomAccessIterator thisElement = first;

		for(j = 0; j < n-1-i; j++) {
			RandomAccessIterator nextElement = thisElement + 1;

			if(*thisElement > *nextElement) {
				prism::swap(*thisElement, *nextElement);
				swapped = true;
			}
			thisElement++;
		}

		if(!swapped) {
			break;
		}

	}

}

/**
 * Exchanges the values of \em a and \em b.
 */
template <class T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

/**
 * Exchanges the values of each of the elements in the range \em [first1,last1)
 * with those of their respective elements in the range beginning at \em otherFirst.
 */
template <class ForwardIterator1, class ForwardIterator2>
ForwardIterator2 swap_ranges(ForwardIterator1 first, ForwardIterator1 last, ForwardIterator2 otherFirst) {
	while (first != last) {
		prism::swap(*first, *otherFirst);
		first++;
		otherFirst++;
	}
	return otherFirst;
}

}

#endif /* PRISM_ALGORITHMS_H_ */
