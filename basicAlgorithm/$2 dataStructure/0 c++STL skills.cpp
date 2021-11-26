// * vector     变长数组， 倍增的思想
// *    size()
// *    empty()
// *    clear()
// *    front()/back()
// *    push_back()/pop_back()
// *    begin()/end()
// *    可以比较运算
// * pair<int, int>
// *    first   second
// *    支持比较运算，以first作为第一关键字，以second为第二关键字（字典序）
// ! 系统分配空间时，与所需空间大小无关，与申请次数有关，所以使用vector时应该尽量减少申请次数

// * string     字符串，
// *    substr(), c_str()
// *    size()
// *    empty()
// *    clear()

// * queue      队列(没有clear())
// *    push(), front(), back(), pop()
// *    size()
// *    empty()

// * priority_queue     优先队列（默认是大根堆）
// *    变成小根堆：
// *        1.heap.push()
// *        2.priority_queue<int, vector<int>, greater<int>>
// *    push(), top(), pop()

// * stack      栈(没有clear())，push(), top(), pop()

// * deque      双端队列(基本啥都有，有clear(), 但是慢)

// * set, map, multiset, multimap   基于平衡二叉树（红黑树），动态维护有序序列
// *    begin()/end()   ++,--   返回前驱和后继，时间复杂度O(logn)
// * set/multiset
// *    insert()    插入一个数
// *    find()
// *    count()
// *    erase()
// *        1. 输入一个x，删除所有x O(k+logn)
// *        2. 输入一个迭代器，删除这个迭代器
// *    lower_bound()/upper_bound()
// *        lower_bound(x)  返回大于等于x的最小的数的迭代器
// *        upper_bound(x)  返回大于x的最小的数的迭代器

// * map/multimap
// *    insert()    插入的数是一个pair
// *    erase()     pair或者迭代器
// *    find()
// *    []          时间复杂度O(logn)
// *    lower_bound()/upper_bound()

// * unordered_set, unordered_map, unordered_multiset, unordered_multimap   哈希表
// *    增删改查都是O(1)
// *    没有lower_bound()/upper_bound()以及迭代器的++,--
// *    其他与上面的类似

// * bitset     压位
// *    bitset<n> s;
// *    ~,&,|,^
// *    >>,<<
// *    ==,!=
// *    []
// *    count()返回1的个数
// *    any()   判断是否至少有一个1
// *    none()  判断是否都是0
// *    set()   把所有位置成1
// *    reset() 把所有位变为0
// *    flip()  等价于~
// *    flip(k) 把第k位取反

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#include <vector>

using namespace std;

int main()
{
    vector<int> a(10, 3);
    vector<int> b[10];
    // * 几种遍历方式
    for (auto x : a)
        cout << x << ' ';
    for (vector<int>::iterator i = a.begin(); i != a.end(); i++) // ! 前面那一大串可以改成auto
        cout << *i << ' ';
    return 0;
}