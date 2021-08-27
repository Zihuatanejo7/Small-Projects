# include <stdio.h>

# define MAXSIZE 1000

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int status;
typedef int ElemType;

// 线性表的静态链表存储结构
typedef struct
{
    ElemType data;
    int cur;  /* 游标(Cursor) ，为0时表示无指向 */
} Component, StaticLinkList[MAXSIZE];

status visit(ElemType c);

status ListTraverse(StaticLinkList L);

status InitList(StaticLinkList space);

int Malloc_SSL(StaticLinkList space);

int ListLength(StaticLinkList L);

status ListInsert(StaticLinkList L, int i, ElemType e);

status ListDelete(StaticLinkList L, int i);

void Free_SSL(StaticLinkList space, int k);