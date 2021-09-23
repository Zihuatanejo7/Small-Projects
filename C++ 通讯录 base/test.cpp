#define _CRT_SECURE_NO_WARNINGS 1

# include "contact.h"

// 打印菜单
void menu()
{
	cout<<"****************通讯录管理系统****************\n" << endl;
	cout << "*****     1. 添加用户        2.显示用户*****" << endl;
	cout << "*****     3. 删除用户        4.查找用户*****" << endl;
	cout << "*****     5. 修改用户        6.清空用户*****" << endl;
	cout << "                   0.退出系统\n" << endl;
	cout << "******************************************" << endl;

}
int main()
{
	
	struct system s;
	InitSystem(&s);

	int input;
	do
	{
		menu();
		cout << "请输入相关操作(0 - 6):";
		cin >> input;
		switch (input)
		{
		case 0:cout << "系统正在退出" << endl; break;
		case 1: Add_User(&s); break;
		case 2: Show_User(&s); break;
		case 3: Del_User(&s); break;
		case 4: Find_User(&s); break;
		case 5: Modify_User(&s); break;
		case 6: Clear_Users(&s); break;
		default: break;
		}
	} while (input);

	system("pause");

	return 0;
}