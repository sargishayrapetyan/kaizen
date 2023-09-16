#pragma once

#include "kaizen.h" // test using generated header: jump with the parachute you folded

// TODO: Remove these std includes below when "kaizen.h" includes them
#include <unordered_map>
#include <forward_list>
#include <set>
#include <map>

void test_utils_sum()
{
    BEGIN_SUBTEST;

    zen::vector<int> v = { 1, 2, 3, 4, 5 };

    ZEN_EXPECT(zen::sum(v) == 15);
    ZEN_EXPECT(zen::sum(zen::vector<int>{}) == 0);

    // Test with std::list of floats
    std::list<float> float_list = { 1.5f, 2.5f, 3.5f };
    ZEN_EXPECT(zen::sum(float_list) == 7.5);

    // Test with std::array of doubles
    std::array<double, 3> double_array = { 1.1, 2.2, 3.3 };
    ZEN_EXPECT(zen::sum(double_array) == 6.6);

    // Test with std::forward_list
    std::forward_list<int> fwd_list = { 10, 20, 30 };
    ZEN_EXPECT(zen::sum(fwd_list) == 60);

    // Test with std::deque
    std::deque<int> int_deque = { 11, 22, 33 };
    ZEN_EXPECT(zen::sum(int_deque) == 66);

    // Test with std::set (no duplicates, ordered)
    std::set<int> int_set = { 5, 10, 15 };
    ZEN_EXPECT(zen::sum(int_set) == 30);

    // Test with std::map (should sum values, not keys)
    std::map<int, int> int_map = { {1, 2}, {3, 4}, {5, 6} };
    //zen::sum(int_map);  // should fail compilation with message: ZEN STATIC ASSERTION FAILED. "ELEMENT TYPE EXPECTED TO BE Addable, BUT IS NOT"

    // Test with std::unordered_map (should sum values, not keys)
    std::unordered_map<int, int> int_umap = { {1, 2}, {3, 4}, {5, 6} };
    //zen::sum(int_umap); // should fail compilation with message: ZEN STATIC ASSERTION FAILED. "ELEMENT TYPE EXPECTED TO BE Addable, BUT IS NOT"
}

void test_to_string()
{
    std::vector<std::vector<std::vector<int>>> vvv     = { {{1, 2}, {3, 4}}, {{5, 6}, {7, 8}} };
    std::vector<std::vector<int>>              vv      = { {1, 2}, {3, 4} };
    std::vector<std::vector<int>>              vve     = { {}, {}, {} };
    std::vector<std::list<int>>                vx      = { {1, 2}, {3, 4} };
    std::list<std::vector<int>>                xv      = { {1, 2}, {3, 4} };
    std::vector<int>                           vone    = { 1 };
    std::vector<int>                           v       = { 1, 2, 3 };
    std::vector<std::array<int, 2>>            va      = { {1, 2}, {3, 4} };
    std::vector<int>                           vmix    = { 1, 2, 3 };
    std::vector<int>                           vempty;

    ZEN_EXPECT(zen::to_string()                  == "");
    ZEN_EXPECT(zen::to_string(1, 2, 3)           == "1 2 3");
    ZEN_EXPECT(zen::to_string(42.24)             == "42.24");
    ZEN_EXPECT(zen::to_string("hello")           == "hello");
    ZEN_EXPECT(zen::to_string(v)                 == "[1, 2, 3]");
    ZEN_EXPECT(zen::to_string(vempty)            == "[]");
    ZEN_EXPECT(zen::to_string(1, 42.24, "hello") == "1 42.24 hello");
    ZEN_EXPECT(zen::to_string(vone)              == "[1]");
    ZEN_EXPECT(zen::to_string(vv)                == "[[1, 2], [3, 4]]");
    ZEN_EXPECT(zen::to_string(vve)               == "[[], [], []]");
    ZEN_EXPECT(zen::to_string(vx)                == "[[1, 2], [3, 4]]");
    ZEN_EXPECT(zen::to_string(xv)                == "[[1, 2], [3, 4]]");
    ZEN_EXPECT(zen::to_string(va)                == "[[1, 2], [3, 4]]");
    ZEN_EXPECT(zen::to_string(vvv)               == "[[[1, 2], [3, 4]], [[5, 6], [7, 8]]]");
    ZEN_EXPECT(zen::to_string(vmix, "mixed", 42) == "[1, 2, 3] mixed 42");
}

void main_test_utils()
{
    BEGIN_TEST;
    zen::vector<int> v = {1, 2, 3, 4, 5};

    std::string s = zen::to_string(v);
    ZEN_EXPECT(s == "[1, 2, 3, 4, 5]");

    ZEN_EXPECT(zen::random_int() <= 10);

    test_utils_sum();
    test_to_string();
}