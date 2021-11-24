#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAXSIZE 10 //最大长度
typedef char ElemType;
typedef struct
{
    ElemType *elem;           //指向顺序存储的线性表的基地址
    unsigned int uListLength; //线性表的当前长度
    unsigned int uListSize;   //线性表的最大长度
} SqList;
//线性表采用顺序存储实现，基本操作函数声明如下：
bool InitList(SqList &L, unsigned int uListSize); //线性表初始化
bool DestroyList(SqList &L);                      //销毁线性表
//下面是三个在表尾插入一个数据元素的函数声明
bool ListTailInsertPassByValue(SqList L, ElemType e);
bool ListTailInsertPassByRef(SqList &L, ElemType e);
bool ListTailInsertPassByPoint(SqList *L, ElemType e);
int main()
{
    SqList sqList;
    int i = 0;
    char cTemp = 0;
    ElemType eTemp = '1';
    InitList(sqList, MAXSIZE);
    cout<< sqList.uListLength <<sqList.elem[0]<<sqList.elem[1]<<sqList.elem[2]<<endl;

    eTemp = '1';
    ListTailInsertPassByValue(sqList, eTemp);
    cout<< sqList.uListLength <<sqList.elem[0]<<sqList.elem[1]<<sqList.elem[2]<<endl;

    eTemp = '2';
    ListTailInsertPassByRef(sqList, eTemp);
    cout<< sqList.uListLength <<sqList.elem[0]<<sqList.elem[1]<<sqList.elem[2]<<endl;

    eTemp = '3';
    ListTailInsertPassByPoint(&sqList, eTemp);
    cout<< sqList.uListLength <<sqList.elem[0]<<sqList.elem[1]<<sqList.elem[2]<<endl;

}
//线性表初始化，InitList，代码略，参考教材或PPT代码
//销毁线性表，DestroyList，代码略，参考教材或PPT代码
//三个在顺序表尾巴插入数据元素函数的实现代码
bool InitList(SqList &L, unsigned int uListSize)
{
    L.elem = (ElemType *)malloc(uListSize * sizeof(ElemType));
    if (!L.elem)
        return false;
    L.uListLength = 0;
    L.uListSize = uListSize;
    return true;
}

bool ListTailInsertPassByValue(SqList L, ElemType e)
{
    if ((L.elem) && (L.uListLength < L.uListSize))
    {
        L.elem[L.uListLength] = e;
        L.uListLength++;
        return true;
    }
    else
        return false;
}
bool ListTailInsertPassByRef(SqList &L, ElemType e)
{
    if ((L.elem) && (L.uListLength < L.uListSize))
    {
        L.elem[L.uListLength] = e;
        L.uListLength++;
        return true;
    }
    else
        return false;
}
bool ListTailInsertPassByPoint(SqList *L, ElemType e)
{
    if (!L)
        return false;
    if ((L->elem) && (L->uListLength < L->uListSize))
    {
        L->elem[L->uListLength] = e;
        L->uListLength++;
        return true;
    }
    else
        return false;
}