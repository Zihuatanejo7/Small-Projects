#define _CRT_SECURE_NO_WARNINGS 1

# include "contact.h"

void InitSystem(struct system* p)
{
	p->len = 0;
}

// 添加用户
int Add_User(struct system* p)
{
	// 系统满
	if (p->len == MAXSIZE)
	{
		cout << "当前系统已满";

		return 0;
	}

	string name;
	cout << "用户名字:";
	cin >> name;
	p->user_arr[p->len].name = name;

	string sex;
	cout << "用户性别:";
	cin >> sex;
	p->user_arr[p->len].sex = sex;

	int age;
	cout << "用户年龄:";
	cin >> age;
	p->user_arr[p->len].age = age;

	string tel;
	cout << "用户联系方式:";
	cin >>tel ;
	p->user_arr[p->len].tel = tel;

	string address;
	cout << "用户住址:";
	cin >> address;
	p->user_arr[p->len].address = address;

	cout << "添加成功\n\n";

	p->len++;

	return 1;
}

void Show_User(const struct system* p)
{
	cout << "****************当前用户信息****************\n" << endl;
	for (int i = 0; i < p->len; i++)
	{
		cout << "用户:" << i
			<< "\t用户名字:" << p->user_arr[i].name
			<< "\t用户性别:" << p->user_arr[i].sex
			<< "\t用户年龄:" << p->user_arr[i].age
			<< "\t用户联系方式:" << p->user_arr[i].tel
			<< "\t用户住址:" << p->user_arr[i].address << endl;
	}
	
	cout << "\n****************显示完毕****************\n";
}

static int find(struct system s, string name)
{
	for (int i = 0; i <= s.len; i++)
	{
		if (s.user_arr[i].name == name)
		{
			return i;
		}
	}

	return -1;
}


int Del_User(struct system* p)
{
	if (p->len == 0)
	{
		cout << "系统已空";
		return 0;
	}

	string name;
	cout << "请输入要删除的用户名字:";
	cin >> name;

	int k = find(*p, name);

	if (-1 == k)
	{
		cout << "本系统无此用户\n";
	}
	else
	{
		for (int i = k; i < p->len; i++)
		{
			p->user_arr[i] = p->user_arr[i + 1];
		}
	}
	p->len--;

	cout << "用户已删除";
}


int Find_User(const struct system* p)
{
	string name;
	cout << "待查找的用户名字为:";
	cin >> name;
	int k = find(*p, name);
	if (k == -1)
	{
		cout << "系统中无此用户";
		return -1;
	}
	else
	{
			cout<< "\t用户名字:" << p->user_arr[k].name
			<< "\t用户性别:" << p->user_arr[k].sex
			<< "\t用户年龄:" << p->user_arr[k].age
			<< "\t用户联系方式:" << p->user_arr[k].tel
			<< "\t用户住址:" << p->user_arr[k].address << endl;
	}
	
}


int Modify_User(struct system* p)
{
	string name;
	cout << "待修改的用户名字为:";
	cin >> name;
	int k = find(*p, name);

	if (k == -1)
	{
		cout << "系统中无此用户\n";
		return -1;
	}
	else
	{
		string name;
		cout << "用户名字:";
		cin >> name;
		p->user_arr[k].name = name;

		string sex;
		cout << "用户性别:";
		cin >> sex;
		p->user_arr[k].sex = sex;

		int age;
		cout << "用户年龄:";
		cin >> age;
		p->user_arr[k].age = age;

		string tel;
		cout << "用户联系方式:";
		cin >> tel;
		p->user_arr[k].tel = tel;

		string address;
		cout << "用户住址:";
		cin >> address;
		p->user_arr[k].address = address;
	}
}

int Clear_Users(struct system* p)
{
	p->len = 0;
	cout << "系统已清空";
	return 1;
}