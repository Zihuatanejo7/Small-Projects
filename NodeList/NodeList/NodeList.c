# include "NodeList.h"

// ��ʼ��˳�����Ա� 
status InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));   //����ͷ�ڵ�
	if ((*L) == NULL)
	{
		return ERROR;     //�ռ俪��ʧ��
	}

	(*L)->next = NULL;    // ��β

	return OK;
}

// �������������L������Ԫ�ظ���
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next;   // pָ���һ����� 

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

// �����������e����L�е�i������Ԫ�ص�ֵ 
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

//  �������������L�е�1����e�����ϵ������Ԫ�ص�λ��
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

// ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
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

// �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨)
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

// �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨)
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