# include "StaticList.h"

int main()
{
    StaticLinkList L;
    status i;
    i = InitList(L);
    printf("��ʼ��L��L.length=%d\n", ListLength(L));

    i = ListInsert(L, 1, 'F');
    i = ListInsert(L, 1, 'E');
    i = ListInsert(L, 1, 'D');
    i = ListInsert(L, 1, 'B');
    i = ListInsert(L, 1, 'A');

    printf("\n��L�ı�ͷ���β���FEDBA��\nL.data=");
    ListTraverse(L);

    i = ListInsert(L, 3, 'C');
    printf("\n��L�ġ�B���롰D��֮����롰C����\nL.data=");
    ListTraverse(L);

    i = ListDelete(L, 1);
    printf("\n��L��ɾ����A����\nL.data=");
    ListTraverse(L);

    printf("\n");

    return 0;
}

