# include "NodeList.h"

// 初始化顺序线性表 
status InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));   //产生头节点
	if ((*L) == NULL)
	{
		return ERROR;     //空间开辟失败
	}

	(*L)->next = NULL;    // 表尾

	return OK;
}

// 操作结果：返回L中数据元素个数
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next;   // p指向第一个结点 

	while (p != NULL)
	{
		i++;
		p = p->next; 
	}
	return i;
}

static status visit(ElemType c)
{
	printf("%d\n",c);
	return OK;
}

status ListTraverse(LinkList L)
{
	while (L->next != NULL)
	{
		visit(L->data);
		L=L->next;
	}
	printf("\n");
	return OK;
}

status ListEmpty(LinkList L)
{
	return L->next == NULL ? TRUE:FALSE;
}



status ClearList(LinkList *L)
{
	LinkList p,q;
	p = (*L)->next;
	while (p!=NULL)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

// 操作结果：用e返回L中第i个数据元素的值 
status GetElem(LinkList L, int j, ElemType* pe)
{
	LinkList p = L->next;

	int i = 1;
	for (i = 1;p&&i<j;i++)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return ERROR;
	}
	*pe = p->data;
	return OK;

}

//  操作结果：返回L中第1个与e满足关系的数据元素的位序
int LocateElem(LinkList L, ElemType e)
{
	LinkList p = L->next;
	int i = 1;
	while (p != NULL)
	{
		if (p->data == e)
		{
			return i;
		}
		p = p->next;
		i++;
	}
	return 0;
}

status ListInsert(LinkList* L, int j, ElemType e)
{
	LinkList p = *L;
	LinkList s = (LinkList)malloc(sizeof(Node));
	if (s == NULL)
	{
		return ERROR;
	}
	else
	{
		s->data = e;
	}

	int i = 1;
	for (i = 1; p && i < j; i++)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return ERROR;
	}

	s->next = p->next;
	p->next = s;

	return OK;
}

// 删除L的第i个数据元素，并用e返回其值，L的长度减1
status ListDelete(LinkList* L, int j, ElemType* pe)
{
	LinkList p = *L;
	LinkList s;
	int i = 1;
	for (i = 1; p && i < j; i++)
	{
		p = p->next;
	}
	if (p == NULL)
	{
		return ERROR;
	}
	s = p->next;
	*pe = s->data;
	p->next = s->next;
	free(s);
	return OK;
}

// 随机产生n个元素的值，建立带表头结点的单链线性表L（头插法)
void CreateListHead(LinkList* L, int n)
{
	LinkList p;

	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	srand((unsigned)time(0));
	int i = 1;
	for (i = 1; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;

		p->next = (*L)->next;
		(*L)->next = p;
	}
}

// 随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法)
void CreateListTail(LinkList* L, int n)
{
	*L = (LinkList)malloc(sizeof(Node));
	LinkList r = *L;

	srand((unsigned)time(0));
	int i = 1;
	for (i = 1; i < n; i++)
	{
		LinkList p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p = p->next;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}