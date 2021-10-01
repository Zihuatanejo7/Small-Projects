#define _CRT_SECURE_NO_WARNINGS 1

# include<iostream>
using namespace std;
# include "Person.h"
# include <vector>
# include <deque>
# include <algorithm>
# include <time.h>

void createPerson(vector<Person>& v)
{
	
	string seed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += seed[i];
		Person p(name, 0);

		v.push_back(p);
	}

	
}

void setScore(vector<Person> &v)
{
	srand((unsigned int)time(NULL));

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			d.push_back(rand() % 100 + 1);
		}

		// ����
		sort(d.begin(), d.end());

		d.pop_front();
		d.pop_back();

		int sum = 0;
		for (deque<int>::iterator i = d.begin(); i != d.end(); i++)
		{
			sum += *i;
		}

		// ƽ���ָ�ѡ��
		it->m_score = sum / d.size();
	}

}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������ " << it->m_Name << " ƽ���֣� " << it->m_score << endl;
	}
}


void test()
{
	// ����5��ѡ��
	vector<Person>v;
	createPerson(v);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "����Ϊ:" << it->m_Name << "����Ϊ:" << it->m_score << endl;
	}

	// ��5��ѡ�ִ��
	setScore(v);
	showScore(v);
}

int main()
{
	test();
	system("pause");
	return 0;
}