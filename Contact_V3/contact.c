#define _CRT_SECURE_NO_WARNINGS 1

# include "contact.h"

// 初始化函数
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
 
// 扩容函数
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

// 用户输入函数
void Add(struct system* ps)
{
	assert(NULL != ps);
	if (ps->cur != ps->cap)
	{
		// 添加用户
		printf("========输入数据========\n");
		printf("\n名字：");
		scanf("%s", ps->data[ps->cur].name);
		printf("\n性别：");
		scanf("%s", ps->data[ps->cur].wm);
		printf("\n工作单位：");
		scanf("%s", ps->data[ps->cur].work);
		printf("\n手机：");
		scanf("%s", ps->data[ps->cur].stel);
		printf("\n住宅号码：");
		scanf("%s", ps->data[ps->cur].htel);
		printf("\nE-Mail：");
		scanf("%s", ps->data[ps->cur].mail);
		printf("\n家庭地址：");
		scanf("%s", ps->data[ps->cur].home);

		(ps->cur)++;

		printf("\n当前用户添加成功\n");
		printf("===================================\n");
	}
	else
	{
		Expand_Capacity(ps);
	}
}
 
// 数据显示函数
void Display(const struct system* ps)
{
	assert(NULL != ps);

	printf("========显示数据========\n");
	if (ps->cur)
	{
		int i = 0;
		for (i = 0; i < ps->cur; i++)
		{
			printf("名字：%s\n", ps->data[i].name);
			printf("性别：%s\t", ps->data[i].wm);
			printf("工作单位：%s\t", ps->data[i].work);
			printf("手机：%s\t", ps->data[i].stel);
			printf("住宅号码：%s\t", ps->data[i].htel);
			printf("E-Mail：%s\t", ps->data[i].mail);
			printf("家庭住址：%s\n", ps->data[i].home);
		}
		printf("========显示完毕========\n");
	}
	else
	{
		printf("当前通讯录中有%d个用户", ps->cur);
	}
}

// 查找特定用户名字函数
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

//插入用户用户信息函数
void Insert(struct system* ps)
{
	assert(NULL != ps);
	if (ps->cur == ps->cap)
	{
		Expand_Capacity(ps);
	}

	int location = 0;

	printf("要插入的位置：0, 管理系统头位置  1,管理系统尾位置\n");
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
		printf("========输入数据========\n");
		printf("\n名字：");
		scanf("%s", ps->data[0].name);
		printf("\n性别：");
		scanf("%s", ps->data[0].wm);
		printf("\n工作单位：");
		scanf("%s", ps->data[0].work);
		printf("\n手机：");
		scanf("%s", ps->data[0].stel);
		printf("\n住宅号码：");
		scanf("%s", ps->data[0].htel);
		printf("\nE-Mail：");
		scanf("%s", ps->data[0].mail);
		printf("\n家庭地址：");
		scanf("%s", ps->data[0].home);
		(ps->cur)++;
		break;
	}
		
	case 1:
	{
		(ps->cur)++;
		printf("========输入数据========\n");
		printf("\n名字：");
		scanf("%s", ps->data[ps->cur].name);
		printf("\n性别：");
		scanf("%s", ps->data[ps->cur].wm);
		printf("\n工作单位：");
		scanf("%s", ps->data[ps->cur].work);
		printf("\n手机：");
		scanf("%s", ps->data[ps->cur].stel);
		printf("\n住宅号码：");
		scanf("%s", ps->data[ps->cur].htel);
		printf("\nE-Mail：");
		scanf("%s", ps->data[ps->cur].mail);
		printf("\n家庭地址：");
		scanf("%s", ps->data[ps->cur].home);
		break;
	}
	default:break;
	}
}

// 删除指定用户信息函数
void Delete(struct system* ps)
{
	assert(NULL != ps);
	char name[MAX_LEN];
	printf("请输入要删除的用户名:");
	scanf("%s", name);

	int ret = Find_name(ps, name);
	int i = 0;
	if (-1 == ret)
	{
		printf("\n当前通讯录中无此用户\n");
	}
	else
	{
		for (i = ret; i < ps->cur; i++)
		{
			ps->data[i] = ps->data[i + 1];
		}
		printf("用户%s 已被删除",ps->data[ret].name);
		(ps->cur)--;
	}
}

// 显示指定用户信息函数
void Find(const struct system* ps)
{
	assert(NULL != ps);
	char name[MAX_LEN];
	printf("请输入要查看的用户名:");
	scanf("%s", name);
	int ret = Find_name(ps, name);
	if (-1 == ret)
	{
		printf("当前管理系统无此用户");
	}
	else
	{
		printf("========修改数据========\n");
		printf("名字：%s\n", ps->data[ret].name);
		printf("性别：%s\t", ps->data[ret].wm);
		printf("工作单位：%s\t", ps->data[ret].work);
		printf("手机：%s\t", ps->data[ret].stel);
		printf("住宅号码：%s\t", ps->data[ret].htel);
		printf("E-Mail：%s\t", ps->data[ret].mail);
		printf("家庭住址：%s\n", ps->data[ret].home);
		printf("========修改完毕========\n");
	}
}

//  修改指定用户信息函数
void Modify(struct system* ps)
{
	assert(NULL != ps);
	char name[MAX_LEN];
	printf("请输入要修改信息的用户名:");
	scanf("%s", name);
	int ret = Find_name(ps, name);
	if (-1 == ret)
	{
		printf("当前管理系统无此用户");
	}
	else
	{
		printf("========修改数据========\n");
		printf("\n名字：");
		scanf("%s", ps->data[ret].name);
		printf("\n性别：");
		scanf("%s", ps->data[ret].wm);
		printf("\n工作单位：");
		scanf("%s", ps->data[ret].work);
		printf("\n手机：");
		scanf("%s", ps->data[ret].stel);
		printf("\n住宅号码：");
		scanf("%s", ps->data[ret].htel);
		printf("\nE-Mail：");
		scanf("%s", ps->data[ret].mail);
		printf("\n家庭地址：");
		scanf("%s", ps->data[ret].home);
		printf("========修改完毕========\n");
	}
}

// 修改指定用户信息函数
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
	printf("\n保存成功\n");
	fclose(pf);
	pf = NULL;
}
