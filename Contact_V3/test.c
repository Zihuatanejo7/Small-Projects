#define _CRT_SECURE_NO_WARNINGS 1

# include "contact.h"

//主菜单函数
void menu()
{
    printf("\n=======================================================\n");
    printf("              欢迎来到学生信息管理系统\n\n");
    printf("            1.输入数据         2.显示数据\n");
    printf("            3.插入数据         4.删除数据\n");
    printf("            5.查找数据         6.修改数据\n");
    printf("            7.保存数据         8.返回主菜单\n");
    printf("\n                    0.退出         \n");
    printf("\n=======================================================\n");
}

int main(void)
{
    int input = 0;
    struct system s[] = { 0 };

    InitSystem(&s);

    menu();
    do
    {
        printf("请输入选择:");
        scanf("%d", &input);
        switch (input)
        {
        case 1: Add(&s);     break;
        case 2: Display(&s); break;
        case 3: Insert(&s);  break;
        case 4: Delete(&s);  break;
        case 5: Find(&s);    break;
        case 6: Modify(&s);  break;
        case 7: Save(&s);    break;
        case 8: menu();      break;
        case 0:
            printf("===============欢迎你再次使用通讯录系统===============\n");
            exit(1);//退出系统
            break;
        default:
                printf("输入有误!!!"); 
                break;
        }
    } while (input);
    return 0;
}