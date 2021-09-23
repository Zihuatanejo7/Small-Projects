#pragma once

// 通讯录管理系统  基础版本 

# include <iostream>
# include <string>
# include <string.h>

using namespace std;

# define MAXSIZE 1000

// male 0 男性
// female 1 女性

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
	int len;          //  当前系统中用户人数
};

void InitSystem(struct system *p);

int Add_User(struct system* p);

void Show_User(const struct system* p);

int Del_User(struct system* p);

int Find_User(const struct system* p);

int Modify_User(struct system* p);

int Clear_Users(struct system* p);