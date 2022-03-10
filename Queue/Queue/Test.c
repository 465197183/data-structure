#include"Queue.h"

void TestQueue1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePop(&q);
	QueuePop(&q);	
	QueuePop(&q);	
	QueuePop(&q);
	QueuePop(&q);
	printf("%d",QueueBack(&q));
	QueueDestroy(&q);
}

void QueueTest2()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePop(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueueEmpty(&q);
	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d ", front);
		QueuePop(&q);
	}

}

int main()
{
	QueueTest2();
	return 0;
}