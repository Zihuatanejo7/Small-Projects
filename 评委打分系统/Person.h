#pragma once

# include <iostream>
using namespace std;
# include <string>

class Person
{
public:
	Person(string name, int score)
	{
		m_Name = name;
		m_score = score;
	}

	string m_Name;
	int m_score;
};
