# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define OK 1
# define ERROR 0
# define TRUE 1
# define FALSE 0

# define MAXSIZE 20   // 初始存储空间大小

typedef int status;
typedef int ElemType;

// 线性表的单链表存储结构
typedef struct Node
{
    ElemType data;       // 数据域
    struct Node* next;   // 指针域
}Node;

typedef struct Node* LinkList; // 定义LinkList 

// 初始化顺序线性表 
status InitList(LinkList* L);
// 显示元素
status ListTraverse(LinkList L);
// 表长
int ListLength(LinkList L);
// 判断表是否为空
status ListEmpty(LinkList L);
// 清空链表
status ClearList(LinkList* L);

status GetElem(LinkList L, int i, ElemType* pe);

status ListInsert(LinkList* L, int i, ElemType e);

status ListDelete(LinkList* L, int j, ElemType* pe);

void CreateListHead(LinkList* L, int n);

void CreateListTail(LinkList* L, int n);

int LocateElem(LinkList L, ElemType e);
