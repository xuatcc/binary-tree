#include "bt.h"

void init_stack(stack *s) //初始化   
{
	//s->top = (node *)malloc(sizeof(node));
	s->top = NULL;
	s->count = 0;
	//初始化一个空的链栈
}
bool is_empty(stack *s)//判空
{
	if (s->count == 0)
		return true;
	return false;
}
bool push(stack *s, bt_node*  e)//入栈  链栈不用判断栈满
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
	//printf("入栈成功！\n");
	return true;
}
bt_node*  pop(stack *s)//出栈
{
	if (s->count == 0)
	{
		printf("栈已空！\n");
		return false;
	}
	node *delnode = s->top;
	bt_node *e = (bt_node*)malloc(sizeof(bt_node));
	e = delnode->data;
	s->top = delnode->next;
	free(delnode);
	s->count--;
	//printf("出栈成功！\n");
	return e;
}