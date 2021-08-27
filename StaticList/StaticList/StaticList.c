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

// ��һά����space�и���������һ����������space[0].curΪͷָ�룬"0"��ʾ��ָ�� 
status InitList(StaticLinkList space)
{
    int i = 0;
    for (i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;        //   ��i��Ԫ�ص��α� = ��i+1��Ԫ�ص��±�
    }
    space[MAXSIZE - 1].cur = 0;     // Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص��α�Ϊ 0 

    return OK;
}

// �����ÿռ�����ǿգ��򷵻ط���Ľ���±�
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
    space[k].cur = space[0].cur;    /* �ѵ�һ��Ԫ�ص�curֵ����Ҫɾ���ķ���cur */
    space[0].cur = k;               /* ��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur */
}


