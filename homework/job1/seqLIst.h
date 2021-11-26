#ifndef SEQLIST_H
#define SEQLIST_H

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct {
    int *elem;
    int length;
    int listsize;
}SqList;

typedef struct {
    int *elem;
    int *move;
    int length;
    int listsize;
}DSqList;

#endif