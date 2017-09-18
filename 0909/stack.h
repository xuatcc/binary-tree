#include "bt.h"

#ifndef STACK_H
#define STACK_H

/*
用非递归 先序遍历二叉树  用到栈
*/
//链栈的申明
typedef struct stacknode
{
	bt_node*  data;   //栈中的元素是 二叉树的结点类型
	struct stacknode *next;
}node;
typedef struct linkstack
{
	node *top;
	int count;
}stack;
/*
链栈没有头结点  栈顶指向头部   栈底的元素.next=NULL
*/
void init_stack(stack *s);  //初始化
bool is_empty(stack *s);  //判空
bool push(stack *s, bt_node*  e);//入栈
bt_node* pop(stack *s);//出栈


#endif