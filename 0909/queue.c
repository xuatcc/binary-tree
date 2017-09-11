
#include "bt.h"
#define MAXSIZE 20
void init_squeue(sq_queue *q)
{
	q->front = 0;
	q->rear = 0;
}
int lenth_squeue(sq_queue *q)
{
	int len = ((q->rear) + MAXSIZE - (q->front)) % MAXSIZE;
	return len;
}
bool in_squeue(sq_queue *q, bt_node *val)
{
	//����ʱ ���ж϶���
	if ((q->rear + 1) % MAXSIZE == q->front)
	{
		printf("������\n");
		return false;
	}
	q->data[q->rear] = val;
	q->rear = (q->rear + 1) % MAXSIZE;
	//����ֻ����β��       ѭ���������� βָ��<ͷָ��    ������������   
	return true;
}
bt_node * out_squeue(sq_queue *q)
{
	//ɾ��ǰ ���ж϶ӿ�
	if (q->rear == q->front)
	{
		printf("�ӿգ�\n");
		return false;
	}
	bt_node *temp = (bt_node*)malloc(sizeof(bt_node));
	temp = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return  temp;//ɾ����ͷɾ
}
bool destory_squeue(sq_queue *q) //˳���������ʵ�� �������� ֻ�����
{
	int len = lenth_squeue(q);
	elem_type val;
	for (int i = 0; i < len; i++)
	{
		out_squeue(q, &val);
	}
	return true;
}


