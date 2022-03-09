#include"Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;  //top:0/-1¶¼¿ÉÒÔ
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (ST*)realloc(ps->a, newcapacity * sizeof(ST));
		if (tmp == NULL)
		{
			perror("StackPush::");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

//void DrawStack(ST ps)
//{
//	int count = ps.top;
//	while (count--)
//	{
//		if (count == 0)
//			printf("     |__%d__|\n", ps.a[count]);
//		else
//			printf("     |  %d  |\n", ps.a[count]);
//	}
//}

void DrawStack(const ST* ps)
{
	assert(ps);
	int count = ps->capacity;
	while (count--)
	{
		if (count >= ps->top)
			printf("     |       |\n");
		else if (count == 0)
			printf("     |___%d___|\n\n\n", ps->a[count]);
		else
			printf("     |   %d   |\n", ps->a[count]);
	}
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));

	ps->top--;
}

int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}


STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	//if (ps->top == 0)
	//	return true;
	//else
	//	return false;
	return ps->top == 0;
}

void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}