#include "bt.h"

#ifndef STACK_H
#define STACK_H

/*
�÷ǵݹ� �������������  �õ�ջ
*/
//��ջ������
typedef struct stacknode
{
	bt_node*  data;   //ջ�е�Ԫ���� �������Ľ������
	struct stacknode *next;
}node;
typedef struct linkstack
{
	node *top;
	int count;
}stack;
/*
��ջû��ͷ���  ջ��ָ��ͷ��   ջ�׵�Ԫ��.next=NULL
*/
void init_stack(stack *s);  //��ʼ��
bool is_empty(stack *s);  //�п�
bool push(stack *s, bt_node*  e);//��ջ
bt_node* pop(stack *s);//��ջ


#endif