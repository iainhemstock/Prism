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
#include <array>
#include <functional>
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
#include <prism/Allocator>
#include <prism/LogAllocator>
#include <prism/functor>
#include <prism/Map>
#include <prism/h/BinarySearchTree.h>
#include <prism/Version>
#include <prism/PrismVersion>
#include <prism/type>
//#include <prism/h/Obj.h>

using namespace prism;
using namespace std;



int main(int argc, char * argv[]) {
	// to run certain test cases use string with this format: "*Class1*:*Class2*:*ClassN*"
	// to run a single test within a test case use: "*Class.test*" e.g. "*Stack.pop*"
	::testing::GTEST_FLAG(filter) = "type*";
	::testing::InitGoogleTest(&argc, argv);

	typedef prism::conditional_type<true, int[2],int[6]>::type arr1;
	typedef prism::conditional_type<false, int[2],int[6]>::type arr2;
	cout << sizeof(arr1) << endl;
	cout << sizeof(arr2) << endl;

	return RUN_ALL_TESTS();
//	return 0;
}









































