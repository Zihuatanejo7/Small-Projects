# include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

# define MAXSIZE 20

typedef int Status;
typedef int ElemType;

// ���Ա�
typedef struct
{
    ElemType data[MAXSIZE];        // ���飬�洢����Ԫ�� 
    int length;                    // ���Ա�ǰ����
}SqList;

// ��ʼ������
Status InitList(SqList* pl);
// ����Ԫ��
Status ListInsert(SqList* pl, int i, ElemType e);
// ��֤�Ƿ�Ϊ�ձ�
Status ListEmpty(SqList L);
// ��ձ�
Status ClearList(SqList* pl);
// ��ȡ�ض�Ԫ��
Status GetElem(SqList L, int i, ElemType* pe);
// �ض�Ԫ���ڱ��и���λ��
int LocateElem(SqList L, ElemType j);

int ListLength(SqList L);
//ɾ��ָ��Ԫ��
Status ListDelete(SqList* pl, int i, ElemType* pe);
//�ϲ�������
void unionL(SqList* pl, SqList plb);