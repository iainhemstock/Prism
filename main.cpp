/*
 * main.cpp
 *
 *  Created on: Dec 28, 2014
 *      Author: iainhemstock
 */


#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <forward_list>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <chrono>
#include <ctime>
#include <initializer_list>
#include <utility>
#include <type_traits>
#include <new>
#include <memory>
#include <map>
#include <prism/Array>
#include <prism/Stack>
#include <prism/List>
#include <prism/Queue>
#include <prism/Vector>
#include <prism/iterator>
#include <prism/Point>
#include <prism/Pointf>
#include <prism/OutOfBoundsException>
#include <prism/SharedPointer>
#include <prism/Fraction>
#include <prism/Mathf>
#include <prism/Size>
#include <prism/Rect>
#include <prism/Circle>
#include <prism/String>
#include <prism/Char>
#include <prism/algorithm>
#include <prism/Bitvector>
#include <prism/Time>
#include <prism/Pair>
#include <prism/Deque>
#include <prism/utility>
#include <prism/memory>
#include <prism/Allocator>
#include <prism/LogAllocator>
#include <prism/functor>
#include <prism/Map>
#include <prism/h/BinarySearchTree.h>
#include <prism/Version>
#include <prism/PrismVersion>
//#include <prism/h/Obj.h>

using namespace prism;
using namespace std;

template <class InputIterator>
void printRange(InputIterator first, InputIterator last) {
	while (first != last)
		cout << *first++ << endl;
}

int main(int argc, char * argv[]) {
	// to run certain test cases use string with this format: "*Class1*:*Class2*:*ClassN*"
	// to run a single test within a test case use: "*Class.test*" e.g. "*Stack.pop*"
//	::testing::GTEST_FLAG(filter) = "*List*";
//	::testing::InitGoogleTest(&argc, argv);

	Vector<int> v = {5,4,3,2,1};
	prism::sort_heap(v.begin(), v.end());

	printRange(v.begin(), v.end());

//	return RUN_ALL_TESTS();
//	return 0;
}













