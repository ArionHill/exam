#include <algorithm>
#include <iostream>
#include <vector>

typedef struct Row
{
    int a;
    int b; 
} Row;

bool cmp_func(const Row &lv, const Row &rv) 
{
    if (lv.a < rv.a) {
        return true;
    } else {
        return lv.a == rv.a && lv.b < rv.b;
    }
    return false;
}

// int merge(const std::vector<Row>::iterator &start1, const std::vector<Row>::iterator &end1,
//         const std::vector<Row>::iterator &start2, const std::vector<Row>::iterator &end2, std::vector<Row> &res)
// {
//     auto tmp1 = start1;
//     auto tmp2 = start2;
//     while (tmp1 < end1 && tmp2 < end2) {
//         if (tmp1->b < tmp2->b) {
//             res.push_back(*tmp1);
//              ++ tmp1;
//         } else {
//             res.push_back(*tmp2);
//              ++ tmp2;
//         }
//     }

//     while (tmp1 < end1) {
//         res.push_back(*tmp1);
//         ++ tmp1;
//     }
//     res.insert(res.end(), tmp1, end1);
//     res.insert(res.end(), tmp2, end2);
//     return 0;
// }

void task1(const Row *rows, int nrows)
{
    std::vector<Row> vec(rows, rows+nrows);
    auto start2000 = lower_bound(vec.begin(), vec.end(), Row{2000, 10}, cmp_func);
    // auto end2000 = upper_bound(vec.begin(), vec.end(), Row{2000, 49}, cmp_func);

    auto start1000 = lower_bound(vec.begin(), start2000, Row{1000, 10}, cmp_func);
    // auto end1000 = upper_bound(start1000, start2000, Row{1000, 49}, cmp_func);

    auto start3000 = lower_bound(end2000, vec.end(), Row{3000, 10}, cmp_func);
    // auto end3000 = upper_bound(start3000, vec.end(), Row{3000, 49}, cmp_func);

    for (int i = 10; i < 50; ++ i) {
        while (start1000->a == 1000 && start1000->b == i) {
            std::cout << start1000->a << "," << start1000->b << std::endl;
            ++ start1000;
        }
        while (start2000->a == 2000 && start2000->b == i) {
            std::cout << start2000->a << "," << start2000->b << std::endl;
            ++ start2000;
        }
        while (start3000->a == 3000 && start3000->b == i) {
            std::cout << start3000->a << "," << start3000->b << std::endl;
            ++ start3000;
        }
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