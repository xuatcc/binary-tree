#include "bt.h"

void init_stack(stack *s) //��ʼ��   
{
	//s->top = (node *)malloc(sizeof(node));
	s->top = NULL;
	s->count = 0;
	//��ʼ��һ���յ���ջ
}
bool is_empty(stack *s)//�п�
{
	if (s->count == 0)
		return true;
	return false;
}
bool push(stack *s, bt_node*  e)//��ջ  ��ջ�����ж�ջ��
{
	if (s->count == 0)
	{
		s->top = (node *)malloc(sizeof(node));
		if (s->top == NULL)
		{
			return false;
		}
		s->top->data = e;
		s->top->next = NULL;
	}
	else
	{
		node *newnode = (node *)malloc(sizeof(node));
		newnode->data = e;
		newnode->next = s->top;
		s->top = newnode;
	}
	s->count++;
	//printf("��ջ�ɹ���\n");
	return true;
}
bt_node*  pop(stack *s)//��ջ
{
	if (s->count == 0)
	{
		printf("ջ�ѿգ�\n");
		return false;
	}
	node *delnode = s->top;
	bt_node *e = (bt_node*)malloc(sizeof(bt_node));
	e = delnode->data;
	s->top = delnode->next;
	free(delnode);
	s->count--;
	//printf("��ջ�ɹ���\n");
	return e;
}