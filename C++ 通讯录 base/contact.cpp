#define _CRT_SECURE_NO_WARNINGS 1

# include "contact.h"

void InitSystem(struct system* p)
{
	p->len = 0;
}

// ����û�
int Add_User(struct system* p)
{
	// ϵͳ��
	if (p->len == MAXSIZE)
	{
		cout << "��ǰϵͳ����";

		return 0;
	}

	string name;
	cout << "�û�����:";
	cin >> name;
	p->user_arr[p->len].name = name;

	string sex;
	cout << "�û��Ա�:";
	cin >> sex;
	p->user_arr[p->len].sex = sex;

	int age;
	cout << "�û�����:";
	cin >> age;
	p->user_arr[p->len].age = age;

	string tel;
	cout << "�û���ϵ��ʽ:";
	cin >>tel ;
	p->user_arr[p->len].tel = tel;

	string address;
	cout << "�û�סַ:";
	cin >> address;
	p->user_arr[p->len].address = address;

	cout << "��ӳɹ�\n\n";

	p->len++;

	return 1;
}

void Show_User(const struct system* p)
{
	cout << "****************��ǰ�û���Ϣ****************\n" << endl;
	for (int i = 0; i < p->len; i++)
	{
		cout << "�û�:" << i
			<< "\t�û�����:" << p->user_arr[i].name
			<< "\t�û��Ա�:" << p->user_arr[i].sex
			<< "\t�û�����:" << p->user_arr[i].age
			<< "\t�û���ϵ��ʽ:" << p->user_arr[i].tel
			<< "\t�û�סַ:" << p->user_arr[i].address << endl;
	}
	
	cout << "\n****************��ʾ���****************\n";
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
		cout << "ϵͳ�ѿ�";
		return 0;
	}

	string name;
	cout << "������Ҫɾ�����û�����:";
	cin >> name;

	int k = find(*p, name);

	if (-1 == k)
	{
		cout << "��ϵͳ�޴��û�\n";
	}
	else
	{
		for (int i = k; i < p->len; i++)
		{
			p->user_arr[i] = p->user_arr[i + 1];
		}
	}
	p->len--;

	cout << "�û���ɾ��";
}


int Find_User(const struct system* p)
{
	string name;
	cout << "�����ҵ��û�����Ϊ:";
	cin >> name;
	int k = find(*p, name);
	if (k == -1)
	{
		cout << "ϵͳ���޴��û�";
		return -1;
	}
	else
	{
			cout<< "\t�û�����:" << p->user_arr[k].name
			<< "\t�û��Ա�:" << p->user_arr[k].sex
			<< "\t�û�����:" << p->user_arr[k].age
			<< "\t�û���ϵ��ʽ:" << p->user_arr[k].tel
			<< "\t�û�סַ:" << p->user_arr[k].address << endl;
	}
	
}


int Modify_User(struct system* p)
{
	string name;
	cout << "���޸ĵ��û�����Ϊ:";
	cin >> name;
	int k = find(*p, name);

	if (k == -1)
	{
		cout << "ϵͳ���޴��û�\n";
		return -1;
	}
	else
	{
		string name;
		cout << "�û�����:";
		cin >> name;
		p->user_arr[k].name = name;

		string sex;
		cout << "�û��Ա�:";
		cin >> sex;
		p->user_arr[k].sex = sex;

		int age;
		cout << "�û�����:";
		cin >> age;
		p->user_arr[k].age = age;

		string tel;
		cout << "�û���ϵ��ʽ:";
		cin >> tel;
		p->user_arr[k].tel = tel;

		string address;
		cout << "�û�סַ:";
		cin >> address;
		p->user_arr[k].address = address;
	}
}

int Clear_Users(struct system* p)
{
	p->len = 0;
	cout << "ϵͳ�����";
	return 1;
}