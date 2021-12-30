/*任务 1
基于以下 C 程序框架, 我们希望你实现 task1() 这个函数, 
它把 rows 中所 有满足 b >= 10 && b < 50 
并且 a == 1000 || a == 2000 || a == 3000 的行
的内容都打印到终端.
*/

#include<iostream>

typedef struct Row
{
    int a;
    int b; 
} Row;
/*!
 * Task 1.
 *
 * Find out all the rows that sastify below conditions:
 *
 *     ((b >= 10 && b < 50) &&
 *      (a == 1000 || a == 2000 || a == 3000))
 *
 * Print them to the terminal, one row per line, for example:
 *
 * 1000,20
 * 1000,23
 * 2000,16
 *
 * @param nrows
 * @param rows
 */
void
task1(const Row *rows, int nrows)
{
    /*
     * TODO: implement this function.
     */
    for (int i = 0; i < nrows; ++ i) {
        if (rows[i].b >= 10 && rows[i].b < 50 
            && (rows[i].a == 1000 || rows[i].a == 2000 || rows[i].a == 3000)) {
                std::cout << rows[i].a << "," << rows[i].b << std::endl;
        }
    }
}
// 你可以基于题目要求换用其它语言, 我们推荐你在 C, C++ 中进行选择. 当然 你也可以采用其它语言.

int main()
{
    Row sorted_rows[] = {
        { 1000, 20 },
        { 1000, 23 },
        { 2000, 16 },
        { 20, 33 },};
    task1(sorted_rows, 4);
}