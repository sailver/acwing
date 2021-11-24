#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"
#include "linkList.cpp"

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    // ----- 方法一：顺序表 ------

    // ----- 方法二：循环链表 ------

    LinkList L, p;
    DLinkList D;

    if (p = CreatList(L, n))
    {
        CreatList(D);
        // ListTraverse_Test(L); //调试语句
        Josephus(p, D, m);
        ListTraverse_Output(D);
    };
    return 0;
}
