#include "gtest/gtest.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "exchange_sort.h"
#include "bubble_sort.h"
#include "optimized_bubble_sort.h"
#include "binary_insertion_sort.h"
#include "shaker_sort.h"
#include "shell_sort.h"
#include "quick_sort.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>
#include "util.hpp"
#include "util\util.hpp"
#include "external_1pass_merge_sort.hpp"
#include "external_2pass_merge_sort.hpp"
#include "external_natural_merge_sort.hpp"
#include"OneList.hpp"
#include "DoubleList.hpp"
/*
TEST(insertion_sortTest, SingleElement) {
    int arr[] = { 42 };
    insertion_sort(arr, 1);
    ASSERT_EQ(1, sizeof(arr) / sizeof(arr[0])) << "Array size changed!";
    EXPECT_EQ(42, arr[0]);
}

TEST(insertion_sortTest, AlreadySorted) {
    int arr[] = { 1, 2, 3, 4, 5 };
    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(insertion_sortTest, ReverseOrder) {
    int arr[] = { 5, 4, 3, 2, 1 };
    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(insertion_sortTest, RandomOrder) {
    int arr[] = { 3, 7, 9, 1, 8, 6, 2 };
    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(insertion_sortTest, ArrayWithNegativeNumbers) {
    int arr[] = { 3, -1, 2, -5, 0 };
    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(insertion_sortTest, DoubleArray) {
    int arr[] = { 3.1, -1.2, 2.0, -5.5, 0.0 };
    insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);

    }
}
TEST(selection_sortTest, SingleElement) {
    int arr[] = { 42 };
    selection_sort(arr, 1);
    ASSERT_EQ(1, sizeof(arr) / sizeof(arr[0])) << "Array size changed!";
    EXPECT_EQ(42, arr[0]);
}

TEST(selection_sortTest, AlreadySorted) {
    int arr[] = { 1, 2, 3, 4, 5 };
    selection_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(selection_sortTest, ReverseOrder) {
    int arr[] = { 5, 4, 3, 2, 1 };
    selection_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(selection_sortTest, RandomOrder) {
    int arr[] = { 3, 7, 9, 1, 8, 6, 2 };
    selection_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(selection_sortTest, ArrayWithNegativeNumbers) {
    int arr[] = { 3, -1, 2, -5, 0 };
    selection_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(selection_sortTest, DoubleArray) {
    int arr[] = { 3.1, -1.2, 2.0, -5.5, 0.0 };
    selection_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);

    }
}
TEST(exchange_sortTest, SingleElement) {
    int arr[] = { 42 };
    exchange_sort(arr, 1);
    ASSERT_EQ(1, sizeof(arr) / sizeof(arr[0])) << "Array size changed!";
    EXPECT_EQ(42, arr[0]);
}

TEST(exchange_sortTest, AlreadySorted) {
    int arr[] = { 1, 2, 3, 4, 5 };
    exchange_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(exchange_sortTest, ReverseOrder) {
    int arr[] = { 5, 4, 3, 2, 1 };
    exchange_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(exchange_sortTest, RandomOrder) {
    int arr[] = { 3, 7, 9, 1, 8, 6, 2 };
    exchange_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(exchange_sortTest, ArrayWithNegativeNumbers) {
    int arr[] = { 3, -1, 2, -5, 0 };
    exchange_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(exchange_sortTest, DoubleArray) {
    int arr[] = { 3.1, -1.2, 2.0, -5.5, 0.0 };
    exchange_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);

    }
}
TEST(bubble_sortTest, SingleElement) {
    int arr[] = { 42 };
    bubble_sort(arr, 1);
    ASSERT_EQ(1, sizeof(arr) / sizeof(arr[0])) << "Array size changed!";
    EXPECT_EQ(42, arr[0]);
}

TEST(bubble_sortTest, AlreadySorted) {
    int arr[] = { 1, 2, 3, 4, 5 };
    bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(bubble_sortTest, ReverseOrder) {
    int arr[] = { 5, 4, 3, 2, 1 };
    bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(bubble_sortTest, RandomOrder) {
    int arr[] = { 3, 7, 9, 1, 8, 6, 2 };
    bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(bubble_sortTest, ArrayWithNegativeNumbers) {
    int arr[] = { 3, -1, 2, -5, 0 };
    bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(bubble_sortTest, DoubleArray) {
    int arr[] = { 3.1, -1.2, 2.0, -5.5, 0.0 };
    bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);

    }
}
TEST(optimized_bubble_sortTest, SingleElement) {
    int arr[] = { 42 };
    optimized_bubble_sort(arr, 1);
    ASSERT_EQ(1, sizeof(arr) / sizeof(arr[0])) << "Array size changed!";
    EXPECT_EQ(42, arr[0]);
}

TEST(optimized_bubble_sortTest, AlreadySorted) {
    int arr[] = { 1, 2, 3, 4, 5 };
    optimized_bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(optimized_bubble_sortTest, ReverseOrder) {
    int arr[] = { 5, 4, 3, 2, 1 };
    optimized_bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(optimized_bubble_sortTest, RandomOrder) {
    int arr[] = { 3, 7, 9, 1, 8, 6, 2 };
    optimized_bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(optimized_bubble_sortTest, ArrayWithNegativeNumbers) {
    int arr[] = { 3, -1, 2, -5, 0 };
    optimized_bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(optimized_bubble_sortTest, DoubleArray) {
    int arr[] = { 3.1, -1.2, 2.0, -5.5, 0.0 };
    optimized_bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);

    }
}
TEST(binary_insertion_sortTest, SingleElement) {
    int arr[] = { 42 };
    binary_insertion_sort(arr, 1);
    ASSERT_EQ(1, sizeof(arr) / sizeof(arr[0])) << "Array size changed!";
    EXPECT_EQ(42, arr[0]);
}

TEST(binary_insertion_sortTest, AlreadySorted) {
    int arr[] = { 1, 2, 3, 4, 5 };
    binary_insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(binary_insertion_sortTest, ReverseOrder) {
    int arr[] = { 5, 4, 3, 2, 1 };
    binary_insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(binary_insertion_sortTest, RandomOrder) {
    int arr[] = { 3, 7, 9, 1, 8, 6, 2 };
    binary_insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(binary_insertion_sortTest, ArrayWithNegativeNumbers) {
    int arr[] = { 3, -1, 2, -5, 0 };
    binary_insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(binary_insertion_sortTest, DoubleArray) {
    int arr[] = { 3.1, -1.2, 2.0, -5.5, 0.0 };
    binary_insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);

    }
}
TEST(shaker_sortTest, SingleElement) {
    int arr[] = { 42 };
    shaker_sort(arr, 1);
    ASSERT_EQ(1, sizeof(arr) / sizeof(arr[0])) << "Array size changed!";
    EXPECT_EQ(42, arr[0]);
}

TEST(shaker_sortTest, AlreadySorted) {
    int arr[] = { 1, 2, 3, 4, 5 };
    shaker_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(shaker_sortTest, ReverseOrder) {
    int arr[] = { 5, 4, 3, 2, 1 };
    shaker_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(shaker_sortTest, RandomOrder) {
    int arr[] = { 3, 7, 9, 1, 8, 6, 2 };
    shaker_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(shaker_sortTest, ArrayWithNegativeNumbers) {
    int arr[] = { 3, -1, 2, -5, 0 };
    shaker_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(shaker_sortTest, DoubleArray) {
    int arr[] = { 3.1, -1.2, 2.0, -5.5, 0.0 };
    shaker_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);

    }
}
TEST(shell_sortTest, SingleElement) {
    int arr[] = { 42 };
    shell_sort(arr, 1);
    ASSERT_EQ(1, sizeof(arr) / sizeof(arr[0])) << "Array size changed!";
    EXPECT_EQ(42, arr[0]);
}

TEST(shell_sortTest, AlreadySorted) {
    int arr[] = { 1, 2, 3, 4, 5 };
    shell_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(shell_sortTest, ReverseOrder) {
    int arr[] = { 5, 4, 3, 2, 1 };
    shell_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(shell_sortTest, RandomOrder) {
    int arr[] = { 3, 7, 9, 1, 8, 6, 2 };
    shell_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(shell_sortTest, ArrayWithNegativeNumbers) {
    int arr[] = { 3, -1, 2, -5, 0 };
    shell_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(shell_sortTest, DoubleArray) {
    int arr[] = { 3.1, -1.2, 2.0, -5.5, 0.0 };
    shell_sort(arr, sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);

    }
}
TEST(quick_sorttTest, SingleElement) {
    int arr[] = { 42 };
    quick_sort(arr, 0, 0);
    ASSERT_EQ(1, sizeof(arr) / sizeof(arr[0])) << "Array size changed!";
    EXPECT_EQ(42, arr[0]);
}
TEST(quick_sortTest, AlreadySorted) {
    int arr[] = { 1, 2, 3, 4, 5 };
    quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(quick_sortTest, ReverseOrder) {
    int arr[] = { 5, 4, 3, 2, 1 };
    quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        EXPECT_EQ(i + 1, arr[i]);
    }
}

TEST(quick_sortTest, RandomOrder) {
    int arr[] = { 3, 7, 9, 1, 8, 6, 2 };
    quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0])-1);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(quick_sortTest, ArrayWithNegativeNumbers) {
    int arr[] = { 3, -1, 2, -5, 0 };
    quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);
    }
}
TEST(quick_sortTest, DoubleArray) {
    int arr[] = { 3.1, -1.2, 2.0, -5.5, 0.0 };
    quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        ASSERT_LE(arr[i], arr[i + 1]);

    }
}*//*
TEST(TestExternal1PassMergeSort, TestComparators) {
    comparator_t c = default_comparator<int>;
    int a, b;
    a = 10, b = 10;
    ASSERT_EQ(c(&a, &b), 0) << "10 == 10 ?";
    a = 5, b = 10;
    ASSERT_EQ(c(&a, &b), -1) << "5 < 10 ?";
    a = 10, b = 5;
    ASSERT_EQ(c(&a, &b), 1) << "10 > 5 ?";
}

TEST(TestExternal1PassMergeSort, TestOne_Sorted) {
    std::size_t const len = 1;
    int data[len]{ 10 };
    files ff = lots_fopen("merge1pass_1", true);
    ASSERT_NE(ff.fin ,nullptr);

    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_1pass_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, ff.tmp3, ff.tmp4, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    ASSERT_EQ(data[0], 10);
}

TEST(TestExternal1PassMergeSort, Test10_Sorted) {
    std::size_t const len = 10;
    int data[len]{ 5, 1, 3, 4, 0, 9, 8, 7, 6, 2 };
    char str[len * 2];
    files ff = lots_fopen("merge1pass_10", true);
    ASSERT_NE(ff.fin, nullptr);
    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_1pass_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, ff.tmp3, ff.tmp4, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    array10i_str(str, len * 2, data);
    ASSERT_STREQ(str, "0 1 2 3 4 5 6 7 8 9");
}

TEST(TestExternal1PassMergeSort, Test100Random_Sorted) {
    std::size_t const len = 100;
    int data[len];
    arrayi_fill(data, len, 50);
    files ff = lots_fopen("merge1pass_100", true);
    ASSERT_NE(ff.fin, nullptr);
    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_1pass_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, ff.tmp3, ff.tmp4, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    ASSERT_TRUE(array_is_sorted(data, len));
}

TEST(TestExternal1PassMergeSort, Test1000Random_Sorted) {
    std::size_t const len = 1000;
    int data[len];
    arrayi_fill(data, len, 50);
    files ff = lots_fopen("merge1pass_1000", true);
    ASSERT_NE(ff.fin, nullptr);
    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_1pass_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, ff.tmp3, ff.tmp4, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    ASSERT_TRUE(array_is_sorted(data, len));


}
TEST(TestExternal2PassMergeSort, TestComparators) {
    comparator_t c = default_comparator<int>;
    int a, b;
    a = 10, b = 10;
    ASSERT_EQ(c(&a, &b), 0) << "10 == 10 ?";
    a = 5, b = 10;
    ASSERT_EQ(c(&a, &b), -1) << "5 < 10 ?";
    a = 10, b = 5;
    ASSERT_EQ(c(&a, &b), 1) << "10 > 5 ?";
}

TEST(TestExternal2PassMergeSort, TestOne_Sorted) {
    std::size_t const len = 1;
    int data[len]{ 10 };
    files ff = lots_fopen("merge2pass_1", false);
    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_2pass_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    ASSERT_EQ(data[0], 10);
}

TEST(TestExternal2PassMergeSort, Test10_Sorted) {
    std::size_t const len = 10;
    int data[len]{ 5, 1, 3, 4, 0, 9, 8, 7, 6, 2 };
    char str[len * 2];
    files ff = lots_fopen("merge2pass_10", false);
    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_2pass_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    array10i_str(str, len * 2, data);
    ASSERT_STREQ(str, "0 1 2 3 4 5 6 7 8 9");
}

TEST(TestExternal2PassMergeSort, Test100Random_Sorted) {
    std::size_t const len = 100;
    int data[len];
    arrayi_fill(data, len, 50);
    files ff = lots_fopen("merge2pass_100", false);
    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_2pass_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    ASSERT_TRUE(array_is_sorted(data, len));
}

TEST(TestExternal2PassMergeSort, Test1000Random_Sorted) {
    std::size_t const len = 1000;
    int data[len];
    arrayi_fill(data, len, 50);
    files ff = lots_fopen("merge2pass_1000", false);
    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_2pass_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    ASSERT_TRUE(array_is_sorted(data, len));
}
*//*
TEST(TestExternalNaturalMergeSort, Test1000Random_Sorted) {
    std::size_t const len = 1000;
    int data[len];
    arrayi_fill(data, len, 50);
    files ff = lots_fopen("merge_natural_1000", false);
    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_natural_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    ASSERT_TRUE(array_is_sorted(data, len));
}
TEST(TestExternalNaturalMergeSort, Test100Random_Sorted) {
    std::size_t const len = 100;
    int data[len];
    arrayi_fill(data, len, 50);
    files ff = lots_fopen("merge_natural_100", false);
    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_natural_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    ASSERT_TRUE(array_is_sorted(data, len));
}
TEST(TestExternalNaturalMergeSort, TestComparators) {
    comparator_t c = default_comparator<int>;
    int a, b;
    a = 10, b = 10;
    ASSERT_EQ(c(&a, &b), 0) << "10 == 10 ?";
    a = 5, b = 10;
    ASSERT_EQ(c(&a, &b), -1) << "5 < 10 ?";
    a = 10, b = 5;
    ASSERT_EQ(c(&a, &b), 1) << "10 > 5 ?";
}

TEST(TestExternalNaturalMergeSort, TestOne_Sorted) {
    std::size_t const len = 1;
    int data[len]{ 10 };
    files ff = lots_fopen("merge_natural_1", false);
    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_natural_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    ASSERT_EQ(data[0], 10);
}

TEST(TestExternalNaturalMergeSort, Test10_Sorted) {
    std::size_t const len = 10;
    int data[len]{ 5, 1, 3, 4, 0, 9, 8, 7, 6, 2 };
    char str[len * 2];
    files ff = lots_fopen("merge_natural_10", false);
    arrayi_print(ff.fin, data, len);
    array_to_file(ff.f, data, len);
    merge_natural_sort_default<int>(ff.f, ff.tmp1, ff.tmp2, len);
    array_from_file(ff.f, data, len);
    arrayi_print(ff.fout, data, len);
    lots_fclose(ff);
    array10i_str(str, len * 2, data);
    ASSERT_STREQ(str, "0 1 2 3 4 5 6 7 8 9");
}
*/

TEST(TestOne, DefaultConstructor) {
    OneList<int> obj;
    ASSERT_TRUE(obj.empty());
    ASSERT_EQ(obj.begin(), nullptr);
    ASSERT_EQ(obj.end(), nullptr);
    // что за счётчик?
}

TEST(TestOne, CopyConstructor) {
    OneList<int> initial;
    initial.push_back(1);
    initial.push_back(2);
    initial.push_back(3);
    OneList<int> copy = initial;
    ASSERT_NE(&copy, &initial);
    ASSERT_FALSE(copy.empty());
    for (auto it1 = initial.begin(), it2 = copy.begin();; ++it1, ++it2) {
        bool e1 = it1.empty(), e2 = it2.empty();
        if (e1 && e2) break;
        ASSERT_TRUE(!(e1 ^ e2)) <<
            "One of iterators exhausted before other.\nMaybe not all values were copied";
        ASSERT_EQ(*it1, *it2) << "All elements of copy should be the same (copied) as of initial";
    }
    (void)initial.pop_front();
    ASSERT_EQ(copy.front(), 1) << "Changing initial should not reflect on copy";
}

TEST(TestOne, Destructor) {
    OneList<int>* initial = new OneList<int>();
    initial->push_back(1);
    initial->push_back(2);
    initial->push_back(3);
    delete initial;
    // idk imagine valgrind there
    SUCCEED() << "How to check that?";
}

TEST(TestOne, push_front) {
    OneList<int> obj;
    obj.push_front(1);
    ASSERT_TRUE(obj.begin() != nullptr);
    ASSERT_EQ(*obj.begin(), 1);
    obj.push_front(2);
    auto it = obj.begin();
    ASSERT_TRUE(it != nullptr);
    ASSERT_EQ(*it, 2);
    ++it;
    ASSERT_EQ(*it, 1);
}

TEST(TestOne, push_back) {
    OneList<int> obj;
    obj.push_back(1);
    auto it1 = obj.begin();
    ASSERT_TRUE(it1 != nullptr);
    ASSERT_EQ(*it1, 1);
    ++it1;
    ASSERT_EQ(it1, obj.end());
    obj.push_back(2);
    auto it = obj.begin();
    ASSERT_TRUE(it != nullptr);
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_NE(it, nullptr);
    ASSERT_EQ(*it, 2);
    ++it;
    ASSERT_EQ(it, obj.end());
}

TEST(TestOne, insert) {
    OneList<int> obj;
    obj.insert(0, 10); // 10
    ASSERT_EQ(obj.front(), 10);
    obj.insert(0, 13); // 13 10
    ASSERT_EQ(obj.front(), 13);
    ASSERT_EQ(obj[1], 10);
    obj.insert(1, 20); // 13 20 10
    ASSERT_EQ(obj.size(), 3);
    ASSERT_EQ(obj[0], 13);
    ASSERT_EQ(obj[1], 20);
    ASSERT_EQ(obj[2], 10);
    obj.insert(3, 40); // 13 20 10 40
    ASSERT_EQ(obj.size(), 4);
    ASSERT_EQ(obj[0], 13);
    ASSERT_EQ(obj[1], 20);
    ASSERT_EQ(obj[2], 10);
    ASSERT_EQ(obj[3], 40);
}

TEST(TestOne, pop_front) {
    OneList<int> obj;
    ASSERT_NO_THROW(obj.pop_front());
    obj.push_back(1);
    obj.pop_front();
    ASSERT_TRUE(obj.empty());
    obj.push_back(1);
    obj.push_back(2);
    obj.pop_front();
    ASSERT_FALSE(obj.empty());
    ASSERT_EQ(obj[0], 2);
    ASSERT_NE(obj.begin(), nullptr);
    ASSERT_EQ(*obj.begin(), 2);
}

TEST(TestOne, pop_back) {
    OneList<int> obj;
    ASSERT_NO_THROW(obj.pop_back());
    obj.push_back(1);
    obj.pop_back();
    ASSERT_TRUE(obj.empty());
    obj.push_back(1);
    ASSERT_EQ(obj.back(), 1);
    obj.push_back(2);
    ASSERT_EQ(obj.back(), 2);
    ASSERT_EQ(obj[0], 1);
    ASSERT_EQ(obj[1], 2);
    obj.pop_back();
    ASSERT_FALSE(obj.empty());
    ASSERT_EQ(obj.back(), 1);
}

TEST(TestOne, front) {
    OneList<int> obj;
    ASSERT_ANY_THROW(obj.front());
    obj.push_back(123);
    ASSERT_EQ(obj.front(), 123);
}

TEST(TestOne, back) {
    OneList<int> obj;
    ASSERT_ANY_THROW(obj.back());
    obj.push_back(123);
    ASSERT_EQ(obj.back(), 123);
}

TEST(TestOne, size) {
    OneList<int> obj;
    ASSERT_EQ(obj.size(), 0);
    obj.push_back(1);
    ASSERT_EQ(obj.size(), 1);
    obj.push_back(2);
    ASSERT_EQ(obj.size(), 2);
}

TEST(TestOne, indexing) {
    OneList<int> obj;
    ASSERT_ANY_THROW(obj[0]);
    ASSERT_ANY_THROW(obj[15]);
    obj.push_back(1);
    obj.push_back(2);
    obj.push_back(3);
    ASSERT_EQ(obj[0], 1);
    ASSERT_EQ(obj[1], 2);
    ASSERT_EQ(obj[2], 3);
    ASSERT_ANY_THROW(obj[15]);
}

TEST(TestOne, iterators) {
    OneList<int> obj{ 0, 1, 2 };
    int i = 0;
    for (auto it = obj.begin(); it != obj.end(); ++it, i++)
        ASSERT_EQ(*it, i);
}

TEST(TestOne, Add500) {
    OneList<int> obj;
    ASSERT_EQ(obj.size(), 0);
    for (int i = 0; i < 500; i++)
        obj.push_back(i);
    ASSERT_EQ(obj.size(), 500);
    ASSERT_EQ(obj[400], 400);
}

TEST(TestDouble, DefaultConstructor) {
    DoubleList<int> obj;
    ASSERT_TRUE(obj.empty());
    ASSERT_EQ(obj.begin(), nullptr);
    ASSERT_EQ(obj.end(), nullptr);
    // что за счётчик?
}

TEST(TestDouble, CopyConstructor) {
    DoubleList<int> initial;
    initial.push_back(1);
    initial.push_back(2);
    initial.push_back(3);
    DoubleList<int> copy = initial;
    ASSERT_NE(&copy, &initial);
    ASSERT_FALSE(copy.empty());
    for (auto it1 = initial.begin(), it2 = copy.begin();; ++it1, ++it2) {
        bool e1 = it1.empty(), e2 = it2.empty();
        if (e1 && e2) break;
        ASSERT_TRUE(!(e1 ^ e2)) <<
            "One of iterators exhausted before other.\nMaybe not all values were copied";
        ASSERT_EQ(*it1, *it2) << "All elements of copy should be the same (copied) as of initial";
    }
    (void)initial.pop_front();
    ASSERT_EQ(copy.front(), 1) << "Changing initial should not reflect on copy";
}

TEST(TestDouble, Destructor) {
    DoubleList<int>* initial = new DoubleList<int>();
    initial->push_back(1);
    initial->push_back(2);
    initial->push_back(3);
    delete initial;
    // idk imagine valgrind there
    SUCCEED() << "How to check that?";
}

TEST(TestDouble, push_front) {
    DoubleList<int> obj;
    obj.push_front(1);
    ASSERT_TRUE(obj.begin() != nullptr);
    ASSERT_EQ(*obj.begin(), 1);
    obj.push_front(2);
    auto it = obj.begin();
    ASSERT_TRUE(it != nullptr);
    ASSERT_EQ(*it, 2);
    ++it;
    ASSERT_EQ(*it, 1);
}

TEST(TestDouble, push_back) {
    DoubleList<int> obj;
    obj.push_back(1);
    auto it1 = obj.begin();
    ASSERT_TRUE(it1 != nullptr);
    ASSERT_EQ(*it1, 1);
    ++it1;
    ASSERT_EQ(it1, obj.end());
    obj.push_back(2);
    auto it = obj.begin();
    ASSERT_TRUE(it != nullptr);
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_NE(it, nullptr);
    ASSERT_EQ(*it, 2);
    ++it;
    ASSERT_EQ(it, obj.end());
}

TEST(TestDouble, insert) {
    DoubleList<int> obj;
    obj.insert(0, 10); // 10
    ASSERT_EQ(obj.front(), 10);
    obj.insert(0, 13); // 13 10
    ASSERT_EQ(obj.front(), 13);
    ASSERT_EQ(obj[1], 10);
    obj.insert(1, 20); // 13 20 10
    ASSERT_EQ(obj.size(), 3);
    ASSERT_EQ(obj[0], 13);
    ASSERT_EQ(obj[1], 20);
    ASSERT_EQ(obj[2], 10);
    obj.insert(3, 40); // 13 20 10 40
    ASSERT_EQ(obj.size(), 4);
    ASSERT_EQ(obj[0], 13);
    ASSERT_EQ(obj[1], 20);
    ASSERT_EQ(obj[2], 10);
    ASSERT_EQ(obj[3], 40);
}

TEST(TestDouble, pop_front) {
    DoubleList<int> obj;
    ASSERT_NO_THROW(obj.pop_front());
    obj.push_back(1);
    obj.pop_front();
    ASSERT_TRUE(obj.empty());
    obj.push_back(1);
    obj.push_back(2);
    obj.pop_front();
    ASSERT_FALSE(obj.empty());
    ASSERT_EQ(obj[0], 2);
    ASSERT_NE(obj.begin(), nullptr);
    ASSERT_EQ(*obj.begin(), 2);
}

TEST(TestDouble, pop_back) {
    DoubleList<int> obj;
    ASSERT_NO_THROW(obj.pop_back());
    obj.push_back(1);
    obj.pop_back();
    ASSERT_TRUE(obj.empty());
    obj.push_back(1);
    ASSERT_EQ(obj.back(), 1);
    obj.push_back(2);
    ASSERT_EQ(obj.back(), 2);
    ASSERT_EQ(obj[0], 1);
    ASSERT_EQ(obj[1], 2);
    obj.pop_back();
    ASSERT_FALSE(obj.empty());
    ASSERT_EQ(obj.back(), 1);
}

TEST(TestDouble, front) {
    DoubleList<int> obj;
    ASSERT_ANY_THROW(obj.front());
    obj.push_back(123);
    ASSERT_EQ(obj.front(), 123);
}

TEST(TestDouble, back) {
    DoubleList<int> obj;
    ASSERT_ANY_THROW(obj.back());
    obj.push_back(123);
    ASSERT_EQ(obj.back(), 123);
}

TEST(TestDouble, size) {
    DoubleList<int> obj;
    ASSERT_EQ(obj.size(), 0);
    obj.push_back(1);
    ASSERT_EQ(obj.size(), 1);
    obj.push_back(2);
    ASSERT_EQ(obj.size(), 2);
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}