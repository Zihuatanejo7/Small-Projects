# include <stdio.h>

# define MAXSIZE 1000

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int status;
typedef int ElemType;

// ���Ա�ľ�̬����洢�ṹ
typedef struct
{
    ElemType data;
    int cur;  /* �α�(Cursor) ��Ϊ0ʱ��ʾ��ָ�� */
} Component, StaticLinkList[MAXSIZE];

status visit(ElemType c);

status ListTraverse(StaticLinkList L);

status InitList(StaticLinkList space);

int Malloc_SSL(StaticLinkList space);

int ListLength(StaticLinkList L);

status ListInsert(StaticLinkList L, int i, ElemType e);

status ListDelete(StaticLinkList L, int i);

void Free_SSL(StaticLinkList space, int k);