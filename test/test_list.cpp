#include <gtest.h>
#include "List.h"

TEST(ListTest, list_append) {
    List<int> l;
    ASSERT_NO_THROW(l.push_back(1));
}

TEST(ListTest, list_extract) {
    List<int> l;
    l.push_back(1);
    ASSERT_NO_THROW(l.extract());
}

TEST(ListTest, list_extract_correct) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    ASSERT_EQ(l.extract(), 1);
}

TEST(ListTest, list_push_front_extract_correct) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    ASSERT_EQ(l.extract(), 3);
}

TEST(ListTest, list_correct_size) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    ASSERT_EQ(l.size(), 3);
}

TEST(ListTest, empty_list) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    l.extract();
    l.extract();
    l.extract();
    ASSERT_TRUE(l.empty());
}

TEST(ListTest, non_empty_list) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    ASSERT_FALSE(l.empty());
}

TEST(ListTest, list_extract_order) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    ASSERT_EQ(l.extract(), 3);
    ASSERT_EQ(l.extract(), 1);
    ASSERT_EQ(l.extract(), 2);
}

TEST(ListTest, list_copy_extract_order) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    List<int> l2 = l;
    ASSERT_EQ(l2.extract(), 3);
    ASSERT_EQ(l2.extract(), 1);
    ASSERT_EQ(l2.extract(), 2);
}

TEST(ListTest, list_copy_size) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_front(3);
    List<int> l2 = l;
    ASSERT_EQ(l2.size(), 3);
}

TEST(ListSortTest, merge_sorted_lists) {
    List<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(4);
    List<int> l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);
    List<int> l = merge_sorted_lists(l1, l2);
    ASSERT_EQ(l.extract(), 1);
    ASSERT_EQ(l.extract(), 1);
    ASSERT_EQ(l.extract(), 2);
    ASSERT_EQ(l.extract(), 2);
    ASSERT_EQ(l.extract(), 3);
    ASSERT_EQ(l.extract(), 4);
}

TEST(ListSortTest, merge_sort) {
    List<int> l;
    l.push_back(7);
    l.push_back(1);
    l.push_back(3);
    l.push_back(2);
    l.push_back(6);
    l.push_back(4);
    l.push_back(5);
    merge_sort(l);
    ASSERT_EQ(l.extract(), 1);
    ASSERT_EQ(l.extract(), 2);
    ASSERT_EQ(l.extract(), 3);
    ASSERT_EQ(l.extract(), 4);
    ASSERT_EQ(l.extract(), 5);
    ASSERT_EQ(l.extract(), 6);
    ASSERT_EQ(l.extract(), 7);
}


TEST(ListSortTest, merge_sorted_lists_desc) {
    List<int> l1;
    l1.push_back(4);
    l1.push_back(2);
    l1.push_back(1);
    List<int> l2;
    l2.push_back(3);
    l2.push_back(2);
    l2.push_back(1);
    List<int> l = merge_sorted_lists(l1, l2, false);
    ASSERT_EQ(l.extract(), 4);
    ASSERT_EQ(l.extract(), 3);
    ASSERT_EQ(l.extract(), 2);
    ASSERT_EQ(l.extract(), 2);
    ASSERT_EQ(l.extract(), 1);
    ASSERT_EQ(l.extract(), 1);
}

TEST(ListSortTest, merge_sort_desc) {
    List<int> l;
    l.push_back(7);
    l.push_back(1);
    l.push_back(3);
    l.push_back(2);
    l.push_back(6);
    l.push_back(4);
    l.push_back(5);
    merge_sort(l, false);
    ASSERT_EQ(l.extract(), 7);
    ASSERT_EQ(l.extract(), 6);
    ASSERT_EQ(l.extract(), 5);
    ASSERT_EQ(l.extract(), 4);
    ASSERT_EQ(l.extract(), 3);
    ASSERT_EQ(l.extract(), 2);
    ASSERT_EQ(l.extract(), 1);
}

