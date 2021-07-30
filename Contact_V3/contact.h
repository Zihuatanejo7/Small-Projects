//#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# include <assert.h>

# define MAX_LEN 30
//�ṹ������
struct student
{
    char name[MAX_LEN];  //����
    char wm[MAX_LEN];    //�Ա�
    char work[MAX_LEN]; //������λ
    char stel[MAX_LEN];  //�ֻ�
    char htel[MAX_LEN];  //סլ����
    char mail[MAX_LEN];  //E-Mail
    char home[MAX_LEN]; //��ͥסַ
};

struct system
{
    int cur;
    int cap;
    struct student* data;
};

//��ʼ����������
void InitSystem(struct system*ps);

void Add(struct system* ps);

void Display(const struct system* ps);

void Insert(struct system* ps);

void Delete(struct system* ps);

void Find(const struct system* ps);

void Modify(struct system* ps);

void Save(const struct system* ps);
