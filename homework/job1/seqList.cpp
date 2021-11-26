#include <stdio.h>
#include <stdlib.h>
#include "seqLIst.h"

int CreateList_Sq(SqList &L, int n)
{
    int LIST_SIZE= n;
    L.elem = (int *)malloc(LIST_SIZE * sizeof(int));
    if (!L.elem)
        return 0;
    L.length = n;
    L.listsize = LIST_SIZE;
    for(int i = 1; i <=n; i++)L.elem[i-1] = i;
    return 1;
}
int CreateList_DSq(DSqList &L)
{
    int LIST_SIZE= LIST_INIT_SIZE;
    L.elem = (int *)malloc(LIST_SIZE * sizeof(int));
    L.move = (int *)malloc(LIST_SIZE * sizeof(int));

    if (!L.elem || !L.move)
        return 0;
    L.length = 0;
    L.listsize = LIST_SIZE;
    return 1;
}

int ListInsertLast_Sq(DSqList *L, int e, int t)
{
    if (!L)
        return 0;
    if (L->length + 1 >= L->listsize)
    {
        int *newbase1 = (int *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
        int *newbase2 = (int *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));

        L->elem = newbase1;
        L->move = newbase2;
        L->listsize += LISTINCREMENT;
    }
    L->elem[L->length] = e;
    L->move[L->length] = t;
    L->length++;
    return 1;
}

int ListDelete_Sq(SqList &L, int i, int &e)
{
    if ((i < 1) || (i > L.length))
        return 0;
    int *p = &(L.elem[i - 1]);
    e = *p;
    int *q = L.elem + L.length - 1;
    for (++p; p <= q; ++p)
        *(p - 1) = *p;
    --L.length;
    return 1;
}

int ListTraverse_Output_Sq(DSqList L)
{
    for(int i = 1; i < L.length; i++)
    {
        printf("<%d,%d>", L.elem[i-1], L.move[i-1]);
    }
}

int Josephus_Lk(SqList &L, DSqList &D, int m)
{
    int *p = L.elem;
}