#include "exam.cpp"
#include "catch/catch.hpp"

TEST_CASE("test_heapify_up")
{
	vector<int> elems{30, 26, 25, 12, 14, 18, 21, 6, 7, 9, 11, 13};
	Exam e(elems);
	e.elems.insert(e.elems.begin()+10, 32);
	e.heapifyUp(10);
	vector<int> heapifyUpExpected{32, 30, 25, 12, 26, 18, 21, 6, 7, 9, 14, 11, 13};
	REQUIRE(heapifyUpExpected == e.elems);
	e.elems.push_back(22);
	e.heapifyUp(13);
	vector<int> heapifyUpExpected2{32, 30, 25, 12, 26, 18, 22, 6, 7, 9, 14, 11, 13, 21};
	REQUIRE(heapifyUpExpected2 == e.elems);
	e.elems.push_back(2);
	e.heapifyUp(14);
	vector<int> heapifyUpExpected3{32, 30, 25, 12, 26, 18, 22, 6, 7, 9, 14, 11, 13, 21, 2};
	REQUIRE(heapifyUpExpected3 == e.elems);
}
TEST_CASE("test_heapify_down")
{
	vector<int> elems{13, 25, 7, 11, 18, 12, 14, 30, 6, 21, 9, 26};
	Exam e(elems);
	e.buildHeap();
	vector<int> heapifyDownExpected{30, 25, 26, 13, 21, 12, 14, 11, 6, 18, 9, 7};
	REQUIRE(heapifyDownExpected == e.elems);
	vector<int> elems2{1, 5, 2, 8, 4, 3, 6, 7};
	Exam e2(elems2);
	e2.buildHeap();
	vector<int> heapifyDownExpected2{8, 7, 6, 5, 4, 3, 2, 1};
	REQUIRE(heapifyDownExpected2 == e2.elems);
}
TEST_CASE("test_find_n_with_priority") {
	vector<int> elems{13, 25, 7, 11, 12, 18, 14, 30, 6, 21, 9, 26};
	Exam e(elems);
	vector<int> test = e.returnN(5);
	vector<int> expectedN{30, 26, 25, 21, 18};
	REQUIRE(expectedN == test);
	REQUIRE(e.elems == elems);
	vector<int> elems2{1, 12, 8, 10, 9, 4, 2, 7, 6, 3, 3, 11, 7};
	Exam e2(elems2);
	vector<int> test2 = e2.returnN(7);
	vector<int> expectedN2{12, 11, 10, 9, 8, 7, 7};
	REQUIRE(expectedN2 == test2);
}
TEST_CASE("test_find_with_compression")
{
	vector<int> elems{-1, 3, 5, 6, -1, 7, -3, 8, 9, -5};
	Exam e(elems);
	e.find(2);
	e.find(5);
	e.find(1);
	e.find(0);
	vector<int> findExpected{-1, 6, 9, 6, -1, 9, -3, 9, 9, -5};
	REQUIRE(findExpected == e.elems);
}
TEST_CASE("test_union_by_size")
{
	vector<int> elems{-1, 3, 5, 6, -1, 7, -3, 8, 9, -5};
	Exam e(elems);
	e.unionBySize(1, 2);
	vector<int> unionExpected{-1, 6, 9, 6, -1, 9, 9, 9, 9, -8};
	REQUIRE(unionExpected == e.elems);
	e.unionBySize(8, 9);
	REQUIRE(unionExpected == e.elems);
	e.unionBySize(3, 4);
	vector<int> unionExpected2{-1, 6, 9, 9, 9, 9, 9, 9, 9, -9};
	REQUIRE(unionExpected2 == e.elems);
}
TEST_CASE("test_linear_probing")
{
	vector<int> elems{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	Exam e(elems);
	e.insertLP(1);
	e.insertLP(6);
	e.insertLP(16);
	e.insertLP(27);
	e.insertLP(12);
	e.insertLP(26);
	vector<int> expectedNoResize{-1, 1, 12, -1, -1, -1, 6, 16, 27, 26};
	REQUIRE(expectedNoResize == e.elems);
	e.insertLP(22);
	e.insertLP(45);
	e.insertLP(51);
	e.insertLP(69);
	e.insertLP(70);
	e.insertLP(13);
	vector<int> expectedResize{45, 1, 69, 26, 27, 51, 6, 70, -1, -1, -1, -1, 12, 13, -1, -1, 16, -1, -1, -1, -1, -1, 22};
	REQUIRE(expectedResize == e.elems);
	e.removeLP(45);
	e.removeLP(46);
	e.removeLP(70);
	e.insertLP(24);
	e.removeLP(1);
	e.removeLP(24);
	vector<int> expectedRemove{-2, -2, 69, 26, 27, 51, 6, -2, -1, -1, -1, -1, 12, 13, -1, -1, 16, -1, -1, -1, -1, -1, 22 };
	REQUIRE(expectedRemove == e.elems);
	REQUIRE(9 == e.elemCount);
}
TEST_CASE("test_double_hashing")
{
	vector<int> elems{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	Exam e(elems);
	e.insertDH(1);
	e.insertDH(6);
	e.insertDH(16);
	e.insertDH(27);
	e.insertDH(12);
	e.insertDH(26);
	vector<int> expectedNoResize{-1, 1, -1, 12, 26, 16, 6, 27, -1, -1, -1};
	REQUIRE(expectedNoResize == e.elems);
	e.insertDH(22);
	e.insertDH(45);
	e.insertDH(51);
	e.insertDH(69);
	e.insertDH(70);
	vector<int> expectedResize{69, 1, -1, 26, 27, 51, 6, 45, 70, -1, -1, -1, 12, -1, -1, -1, 16, -1, -1, -1, -1, -1, 22};
	REQUIRE(expectedResize == e.elems);
	e.removeDH(45);
	e.removeDH(46);
	e.removeDH(70);
	e.removeDH(1);
	e.removeDH(69);
	vector<int> expectedRemove{-2, -2, -1, 26, 27, 51, 6, -2, -2, -1, -1, -1, 12, -1, -1, -1, 16, -1, -1, -1, -1, -1, 22};
	REQUIRE(expectedRemove == e.elems);
	REQUIRE(7 == e.elemCount);
}
