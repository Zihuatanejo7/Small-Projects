# include "List.h"

// 初始化函数
Status InitList(SqList* L)
{
    L->length = 0;
    return OK;
}

// 插入元素
Status ListInsert(SqList* pl, int i, ElemType e)
{
    int k = 0;

    if (pl->length == MAXSIZE)    // 表 满 了
    {
        return ERROR;
    }

    if (i<1 || i>pl->length + 1)  //  1=<i>=n(pl->length)
    {
        return ERROR;
    }

    if (i <= pl->length)
    {
        
        for (k = pl->length - 1; k >= i; k--)
        {
            pl->data[k + 1] = pl->data[k];
        }
    }

    pl->data[i - 1] = e;
    pl->length++;

    return OK;
}

static Status display(ElemType c)
{
    printf("%d ", c);
    return OK;
}

//L的每个数据元素输出
Status ListTraverse(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        display(L.data[i]);
    }
    printf("\n");
    return OK;
}

Status ListEmpty(SqList L)
{
    return L.length == 0 ? TRUE : FALSE;
}

Status ClearList(SqList* pl)
{
    pl->length = 0;
    return OK;
}

Status GetElem(SqList L, int i, ElemType* pe)
{
    if (L.length == 0 || i<1 || i>L.length)
    {
        return ERROR;
    }
    *pe = L.data[i - 1];
    return OK;
}

int LocateElem(SqList L, ElemType j)
{
    int i = 0;
    if (L.length == 0 )
    {
        return 0;
    }
        
    for (i = 0; i <= L.length; i++)
    {
        if (L.data[i] == j)
        {
            break;
        }
    }

    if (i >= L.length)
    {
        return 0;
    }

    return i + 1;  
}

int ListLength(SqList L)
{
    return L.length;
}

Status ListDelete(SqList* pl, int i, ElemType* pe)
{
    int k;
    if (pl->length == 0 || i<1 || i> pl->length)
    {
        return ERROR;
    }
    *pe = pl->data[i - 1];

    if (i < pl->length)
    {
        for (k = i; k <= pl->length - 1; k++)
        {
            pl->data[k-1] = pl->data[k];
        }
    }

    pl->length--;
    return OK;
}

void unionL(SqList* pl, SqList plb)
{
    ElemType e;
    int i = 0;
    int lena = pl->length;
    int lenb = plb.length;
    for (i = 1; i < lenb+1; i++)
    {
        GetElem(plb, i, &e);
        if (!LocateElem(*pl, e))
        {
            ListInsert(pl, ++lena, e);
        }      
    }
}