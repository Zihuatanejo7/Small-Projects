#define _CRT_SECURE_NO_WARNINGS 1

# include "contact.h"

//���˵�����
void menu()
{
    printf("\n=======================================================\n");
    printf("              ��ӭ����ѧ����Ϣ����ϵͳ\n\n");
    printf("            1.��������         2.��ʾ����\n");
    printf("            3.��������         4.ɾ������\n");
    printf("            5.��������         6.�޸�����\n");
    printf("            7.��������         8.�������˵�\n");
    printf("\n                    0.�˳�         \n");
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
        printf("������ѡ��:");
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
            printf("===============��ӭ���ٴ�ʹ��ͨѶ¼ϵͳ===============\n");
            exit(1);//�˳�ϵͳ
            break;
        default:
                printf("��������!!!"); 
                break;
        }
    } while (input);
    return 0;
}