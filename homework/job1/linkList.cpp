#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"

LinkList CreatList(LinkList &L, int n) //初始化链表的函数
{
    LinkList newNode, rear;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    rear = L;
    if (n < 1)
    {
        return rear;
    }
    rear->data = 1;
    for (int i = 2; i <= n; i++)
    {
        newNode = (LinkList)malloc(sizeof(LNode));
        newNode->data = i;
        newNode->next = rear->next;
        rear->next = newNode;
        rear = rear->next;
    }
    rear->next = L;
    return rear;
}

int CreatList(DLinkList &L) //初始化链表的函数
{
    DLinkList newNode, rear;
    L = (DLinkList)malloc(sizeof(DLNode));
    L->next = NULL;
    if (L)
        return 1;
    else
        return 0;
}

DLinkList ListInsert(DLinkList p, int x, int y) //尾插法向目标线性表插入被删除元素
{
    DLinkList pNew;
    pNew = (DLinkList)malloc(sizeof(DLNode));
    pNew->data = x;
    pNew->moveTimes = y;
    pNew->next = p->next;
    p->next = pNew;
    return pNew;
}

int ListTraverse_Test(LinkList L) //遍历链表并输出的函数（用于调试）
{
    if (!L)
        return 0;
    LinkList p = L;
    int len = length_LinkList(L);
    for (int i = 1; i <= len; i++)
    {
        if (!p->data)
            return 0;
        printf("%d\n", p->data);
        p = p->next;
    }
    return 1;
}

int ListTraverse_Output(DLinkList L) //遍历链表并输出的函数（用于输出）
{
    if (!L)
        return 0;
    DLinkList p = L;
    p = p->next;
    while (p)
    {
        printf("<%d,%d>\n", p->data, p->moveTimes);
        p = p->next;
    }
    return 1;
}

int length_LinkList(LinkList L) //取表长函数
{
    LinkList p = L;
    int count = 0;
    while (p->next && p != p->next)
    {
        count++;
        p = p->next;
    }
    return count;
}

int empty_LinkList(LinkList L) //判断是否为空
{
    LinkList p = L;
    if (!p || p == p->next)
        return 1;
    else
        return 0;
}

void Josephus_Lk(LinkList &p1, DLinkList &D, int m) //约瑟夫函数
{
    if (m <= 0)
    {
        printf("输入值M有误，请检查输入");
        return;
    }
    LinkList tmp;
    DLinkList p2 = D;
    int cnt = 0;
    while (p1->next != p1) //循环结束条件为只剩下最后一个节点
    {
        int len = length_LinkList(p1);
        int step = m % len;
        for (int i = 1; i < step; i++)
        {
            p1 = p1->next;
            cnt++;
        } //指针每移动一次，计数器加一

        tmp = p1->next;                      //记录要删除的节点
        p2 = ListInsert(p2, tmp->data, cnt); //存入目标线性表中

        p1->next = p1->next->next; //删除该节点
        free(tmp);
    }
}