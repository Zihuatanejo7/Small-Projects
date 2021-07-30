//#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# include <assert.h>

# define MAX_LEN 30
//结构体声明
struct student
{
    char name[MAX_LEN];  //名字
    char wm[MAX_LEN];    //性别
    char work[MAX_LEN]; //工作单位
    char stel[MAX_LEN];  //手机
    char htel[MAX_LEN];  //住宅号码
    char mail[MAX_LEN];  //E-Mail
    char home[MAX_LEN]; //家庭住址
};

struct system
{
    int cur;
    int cap;
    struct student* data;
};

//初始化函数声明
void InitSystem(struct system*ps);

void Add(struct system* ps);

void Display(const struct system* ps);

void Insert(struct system* ps);

void Delete(struct system* ps);

void Find(const struct system* ps);

void Modify(struct system* ps);

void Save(const struct system* ps);
