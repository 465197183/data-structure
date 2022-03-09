#include"Stack.h"

void TestStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	DrawStack(&st);
	StackPop(&st);
	StackPop(&st);
	DrawStack(&st);
	StackDestroy(&st);

}

int main()
{
	TestStack();
	return 0;
}