#define _CRT_SECURE_NO_WARNINGS 1

# include "contact.h"

// ��ӡ�˵�
void menu()
{
	cout<<"****************ͨѶ¼����ϵͳ****************\n" << endl;
	cout << "*****     1. ����û�        2.��ʾ�û�*****" << endl;
	cout << "*****     3. ɾ���û�        4.�����û�*****" << endl;
	cout << "*****     5. �޸��û�        6.����û�*****" << endl;
	cout << "                   0.�˳�ϵͳ\n" << endl;
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
		cout << "��������ز���(0 - 6):";
		cin >> input;
		switch (input)
		{
		case 0:cout << "ϵͳ�����˳�" << endl; break;
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