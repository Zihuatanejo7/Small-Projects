#define _CRT_SECURE_NO_WARNINGS 1

# include "contact.h"

// ��ʼ������
void InitSystem(struct system* ps)
{
	assert(NULL != ps);

	ps->data = (struct student*)malloc(sizeof(struct student));

	if (NULL != ps)
	{
		ps->cur = 0;
		ps->cap = 3;
	}
	else
	{
		return;
	}
}
 
// ���ݺ���
void Expand_Capacity(struct system* ps)
{
	assert(NULL != ps);
	if (ps->cur == ps->cap)
	{
		ps->cap += 2;
		struct student* ptr = (struct student*)realloc(ps->data, ps->cap * sizeof(struct student));
		if (NULL != ptr)
		{
			ps->data = ptr;
		}
	}
}

// �û����뺯��
void Add(struct system* ps)
{
	assert(NULL != ps);
	if (ps->cur != ps->cap)
	{
		// ����û�
		printf("========��������========\n");
		printf("\n���֣�");
		scanf("%s", ps->data[ps->cur].name);
		printf("\n�Ա�");
		scanf("%s", ps->data[ps->cur].wm);
		printf("\n������λ��");
		scanf("%s", ps->data[ps->cur].work);
		printf("\n�ֻ���");
		scanf("%s", ps->data[ps->cur].stel);
		printf("\nסլ���룺");
		scanf("%s", ps->data[ps->cur].htel);
		printf("\nE-Mail��");
		scanf("%s", ps->data[ps->cur].mail);
		printf("\n��ͥ��ַ��");
		scanf("%s", ps->data[ps->cur].home);

		(ps->cur)++;

		printf("\n��ǰ�û���ӳɹ�\n");
		printf("===================================\n");
	}
	else
	{
		Expand_Capacity(ps);
	}
}
 
// ������ʾ����
void Display(const struct system* ps)
{
	assert(NULL != ps);

	printf("========��ʾ����========\n");
	if (ps->cur)
	{
		int i = 0;
		for (i = 0; i < ps->cur; i++)
		{
			printf("���֣�%s\n", ps->data[i].name);
			printf("�Ա�%s\t", ps->data[i].wm);
			printf("������λ��%s\t", ps->data[i].work);
			printf("�ֻ���%s\t", ps->data[i].stel);
			printf("סլ���룺%s\t", ps->data[i].htel);
			printf("E-Mail��%s\t", ps->data[i].mail);
			printf("��ͥסַ��%s\n", ps->data[i].home);
		}
		printf("========��ʾ���========\n");
	}
	else
	{
		printf("��ǰͨѶ¼����%d���û�", ps->cur);
	}
}

// �����ض��û����ֺ���
static int Find_name(const struct system* ps, const char* pname)
{
	assert(NULL != ps);
	assert(NULL != pname);
	int i = 0;
	for (i = 0; i < ps->cur; i++)
	{
		if (strcmp(ps->data[i].name, pname) == 0)
			return i;
	}
	return -1;
}

//�����û��û���Ϣ����
void Insert(struct system* ps)
{
	assert(NULL != ps);
	if (ps->cur == ps->cap)
	{
		Expand_Capacity(ps);
	}

	int location = 0;

	printf("Ҫ�����λ�ã�0, ����ϵͳͷλ��  1,����ϵͳβλ��\n");
	scanf("%d", &location);
	switch (location)
	{
	case 0:
	{
		int i = 0;
		for (i = ps->cur-1; i >= 0; i--)
		{
			ps->data[i+1] = ps->data[i];
		}
		printf("========��������========\n");
		printf("\n���֣�");
		scanf("%s", ps->data[0].name);
		printf("\n�Ա�");
		scanf("%s", ps->data[0].wm);
		printf("\n������λ��");
		scanf("%s", ps->data[0].work);
		printf("\n�ֻ���");
		scanf("%s", ps->data[0].stel);
		printf("\nסլ���룺");
		scanf("%s", ps->data[0].htel);
		printf("\nE-Mail��");
		scanf("%s", ps->data[0].mail);
		printf("\n��ͥ��ַ��");
		scanf("%s", ps->data[0].home);
		(ps->cur)++;
		break;
	}
		
	case 1:
	{
		(ps->cur)++;
		printf("========��������========\n");
		printf("\n���֣�");
		scanf("%s", ps->data[ps->cur].name);
		printf("\n�Ա�");
		scanf("%s", ps->data[ps->cur].wm);
		printf("\n������λ��");
		scanf("%s", ps->data[ps->cur].work);
		printf("\n�ֻ���");
		scanf("%s", ps->data[ps->cur].stel);
		printf("\nסլ���룺");
		scanf("%s", ps->data[ps->cur].htel);
		printf("\nE-Mail��");
		scanf("%s", ps->data[ps->cur].mail);
		printf("\n��ͥ��ַ��");
		scanf("%s", ps->data[ps->cur].home);
		break;
	}
	default:break;
	}
}

// ɾ��ָ���û���Ϣ����
void Delete(struct system* ps)
{
	assert(NULL != ps);
	char name[MAX_LEN];
	printf("������Ҫɾ�����û���:");
	scanf("%s", name);

	int ret = Find_name(ps, name);
	int i = 0;
	if (-1 == ret)
	{
		printf("\n��ǰͨѶ¼���޴��û�\n");
	}
	else
	{
		for (i = ret; i < ps->cur; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
		printf("�û�%s �ѱ�ɾ��",ps->data[ret].name);
		(ps->cur)--;
	}
}

// ��ʾָ���û���Ϣ����
void Find(const struct system* ps)
{
	assert(NULL != ps);
	char name[MAX_LEN];
	printf("������Ҫ�鿴���û���:");
	scanf("%s", name);
	int ret = Find_name(ps, name);
	if (-1 == ret)
	{
		printf("��ǰ����ϵͳ�޴��û�");
	}
	else
	{
		printf("========�޸�����========\n");
		printf("���֣�%s\n", ps->data[ret].name);
		printf("�Ա�%s\t", ps->data[ret].wm);
		printf("������λ��%s\t", ps->data[ret].work);
		printf("�ֻ���%s\t", ps->data[ret].stel);
		printf("סլ���룺%s\t", ps->data[ret].htel);
		printf("E-Mail��%s\t", ps->data[ret].mail);
		printf("��ͥסַ��%s\n", ps->data[ret].home);
		printf("========�޸����========\n");
	}
}

//  �޸�ָ���û���Ϣ����
void Modify(struct system* ps)
{
	assert(NULL != ps);
	char name[MAX_LEN];
	printf("������Ҫ�޸���Ϣ���û���:");
	scanf("%s", name);
	int ret = Find_name(ps, name);
	if (-1 == ret)
	{
		printf("��ǰ����ϵͳ�޴��û�");
	}
	else
	{
		printf("========�޸�����========\n");
		printf("\n���֣�");
		scanf("%s", ps->data[ret].name);
		printf("\n�Ա�");
		scanf("%s", ps->data[ret].wm);
		printf("\n������λ��");
		scanf("%s", ps->data[ret].work);
		printf("\n�ֻ���");
		scanf("%s", ps->data[ret].stel);
		printf("\nסլ���룺");
		scanf("%s", ps->data[ret].htel);
		printf("\nE-Mail��");
		scanf("%s", ps->data[ret].mail);
		printf("\n��ͥ��ַ��");
		scanf("%s", ps->data[ret].home);
		printf("========�޸����========\n");
	}
}

// �޸�ָ���û���Ϣ����
void Save(const struct system* ps)
{
	assert(NULL != ps);

	FILE* pf = fopen("data.txt", "w");
	int i = 0;
	for (i = 0; i < ps->cur; i++)
	{
		fprintf(pf, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t",
			ps->data[i].name,
			ps->data[i].wm,
			ps->data[i].work,
			ps->data[i].stel,
			ps->data[i].htel,
			ps->data[i].mail,
			ps->data[i].home);
		printf("\n");
	}
	printf("\n����ɹ�\n");
	fclose(pf);
	pf = NULL;
}
