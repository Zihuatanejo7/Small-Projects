#pragma once

// ͨѶ¼����ϵͳ  �����汾 

# include <iostream>
# include <string>
# include <string.h>

using namespace std;

# define MAXSIZE 1000

// male 0 ����
// female 1 Ů��

struct user
{
	string name; 
	string sex; 
	int age; 
	string tel;
	string address; 
};


struct system
{
	user user_arr[MAXSIZE];
	int len;          //  ��ǰϵͳ���û�����
};

void InitSystem(struct system *p);

int Add_User(struct system* p);

void Show_User(const struct system* p);

int Del_User(struct system* p);

int Find_User(const struct system* p);

int Modify_User(struct system* p);

int Clear_Users(struct system* p);