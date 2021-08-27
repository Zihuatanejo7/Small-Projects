# include "StaticList.h"

status visit(ElemType c)
{
    printf("%c ", c);
    return OK;
}

status ListTraverse(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE - 1].cur;
    while (i)
    {
        visit(L[i].data);
        i = L[i].cur;
        j++;
    }
    return j;
    printf("\n");
    return OK;
}

// 将一维数组space中各分量链成一个备用链表，space[0].cur为头指针，"0"表示空指针 
status InitList(StaticLinkList space)
{
    int i = 0;
    for (i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;        //   第i个元素的游标 = 第i+1个元素的下表
    }
    space[MAXSIZE - 1].cur = 0;     // 目前静态链表为空，最后一个元素的游标为 0 

    return OK;
}

// 若备用空间链表非空，则返回分配的结点下标
int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;

    if (i)
    {

        space[0].cur = space[i].cur;
    }

    return i;
}

int ListLength(StaticLinkList L)
{
    int i = L[MAXSIZE - 1].cur;

    int j = 0;

    while (i)
    {
        j++;
        i = L[i].cur;
    }

    return j;
}
status ListInsert(StaticLinkList L, int i, ElemType e)
{
    int l;
    int k = MAXSIZE- 1;
    if (i<1 || i>ListLength(L) + 1)
    {
        return ERROR;
    }

    int j = Malloc_SLL(L);

    if (j)
    {
        L[j].data = e;
        for (l = 0; l <= i - 1; i++)
        {
            k = L[k].cur;
        }

        L[j].cur = L[k].cur;
        L[i].cur = j;
    }
    return OK;
}
status ListInsert(StaticLinkList L, int i, ElemType e)
{
    int l;
    int k = MAXSIZE - 1;
    if (i<1 || i>ListLength(L) + 1)
    {
        return ERROR;
    }

    int j = Malloc_SLL(L);

    if (j)
    {
        L[j].data = e;

        for (l = 1; l < i - 1; i++)
        {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;

        return OK;
    }

    return ERROR;
}

status ListDelete(StaticLinkList L, int i)
{
    int k = MAXSIZE - 1;
    int j = 0;
    for (j = 0; j <= i - 1; j++)
    {
        k = L[k].cur;
    }

    j = L[k].cur;
    L[k].cur = L[j].cur;

    Free_SLL(L, j);

    return OK;
}

void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;    /* 把第一个元素的cur值赋给要删除的分量cur */
    space[0].cur = k;               /* 把要删除的分量下标赋值给第一个元素的cur */
}


