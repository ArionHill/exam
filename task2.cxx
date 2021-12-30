#include <algorithm>
#include <iostream>
#include <vector>

typedef struct Row
{
    int a;
    int b; 
} Row;

bool cmp_func(const Row &lv, const Row &rv) {
    if (lv.a < rv.a) {
        return true;
    } else {
        return lv.a == rv.a && lv.b < rv.b;
    }
    return false;
}

void task1(const Row *rows, int nrows)
{
    std::vector<Row> vec(rows, rows+nrows);

    auto start2000 = lower_bound(vec.begin(), vec.end(), Row{2000, 10}, cmp_func);
    auto end2000 = upper_bound(vec.begin(), vec.end(), Row{2000, 49}, cmp_func);
    auto start1000 = lower_bound(vec.begin(), start2000, Row{1000, 10}, cmp_func);
    auto end1000 = upper_bound(start1000, start2000, Row{1000, 49}, cmp_func);
    auto start3000 = lower_bound(end2000, vec.end(), Row{3000, 10}, cmp_func);
    auto end3000 = upper_bound(start3000, vec.end(), Row{3000, 49}, cmp_func);
    
    auto tmp = start1000;
    while (tmp < end1000) {
        std::cout << tmp->a << "," << tmp->b << std::endl;
        tmp ++;
    }
    tmp = start2000;
    while (tmp < end2000) {
        std::cout << tmp->a << "," << tmp->b << std::endl;
        tmp ++;
    }
    tmp = start3000;
    while (tmp < end3000) {
        std::cout << tmp->a << "," << tmp->b << std::endl;
        tmp ++;
    }
}

int main()
{
    Row sorted_rows[] = {
        { 1000, 9 },
        { 1000, 10 },
        { 1000, 20 },
        { 1000, 23 },
        { 1000, 49 },

        { 1000, 50 },
        { 1000, 51 },
        { 2000, 10 },
        { 2000, 16 },
        { 2000, 17 },

        { 2000, 33 },
        { 2000, 40 },
        { 3000, 33 },
    };
    task1(sorted_rows, 13);
}