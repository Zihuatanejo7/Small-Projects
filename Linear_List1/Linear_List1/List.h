# include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

# define MAXSIZE 20

typedef int Status;
typedef int ElemType;

// 线性表
typedef struct
{
    ElemType data[MAXSIZE];        // 数组，存储数据元素 
    int length;                    // 线性表当前长度
}SqList;

// 初始化表函数
Status InitList(SqList* pl);
// 插入元素
Status ListInsert(SqList* pl, int i, ElemType e);
// 验证是否为空表
Status ListEmpty(SqList L);
// 清空表
Status ClearList(SqList* pl);
// 获取特定元素
Status GetElem(SqList L, int i, ElemType* pe);
// 特定元素在表中给的位置
int LocateElem(SqList L, ElemType j);

int ListLength(SqList L);
//删除指定元素
Status ListDelete(SqList* pl, int i, ElemType* pe);
//合并两个表
void unionL(SqList* pl, SqList plb);