#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;
typedef struct DLNode
{
    int data;
    int moveTimes;
    struct DLNode *next;
} DLNode, *DLinkList;

LinkList CreatList(LinkList &L, int n);
int CreatList(DLinkList &L);
DLinkList ListInsert(DLinkList p, int x, int y);
int ListTraverse_Test(LinkList L);
int ListTraverse_Output(DLinkList L);
int length_LinkList(LinkList L);
int empty_LinkList(LinkList L);
void Josephus(LinkList &L, DLinkList &D, int m);

#endif