# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

# define MAXSIZE 20   // ��ʼ�洢�ռ��С

typedef int status;
typedef int ElemType;

// ���Ա�ĵ�����洢�ṹ
typedef struct Node
{
    ElemType data;       // ������
    struct Node* next;   // ָ����
}Node;

typedef struct Node* LinkList; // ����LinkList 

// ��ʼ��˳�����Ա� 
status InitList(LinkList* L);
// ��ʾԪ��
status ListTraverse(LinkList L);
// ��
int ListLength(LinkList L);
// �жϱ��Ƿ�Ϊ��
status ListEmpty(LinkList L);
// �������
status ClearList(LinkList* L);

status GetElem(LinkList L, int i, ElemType* pe);

status ListInsert(LinkList* L, int i, ElemType e);

status ListDelete(LinkList* L, int j, ElemType* pe);

void CreateListHead(LinkList* L, int n);

void CreateListTail(LinkList* L, int n);

int LocateElem(LinkList L, ElemType e);
