#include "bt.h"

bt_node * init()
{
	bt_node *root = (bt_node*)malloc(sizeof(bt_node));
	root->parent = NULL;
	root->data = 'A';
	root->leftchild = NULL;
	root->rightchild = NULL;
	return root;
}
bt_node * creat() //测试成功
{
	bt_node *root = NULL;
	elem_type item;
	scanf("%c", &item); //ABC##DE##F##G#H##
	if (item != '#')
	{
		root = (bt_node *)malloc(sizeof(bt_node));
		root->data = item;
		root->leftchild = creat();
		root->rightchild = creat();
	}
	return root;
}
bt_node * creatfi(char *fs, char *is)
{
	/*
	根据前序和中序创建二叉树
	1、通过先序遍历找到根结点A，再通过A在中序遍历的位置找出左子树，右子树
	2、在A的左子树中，找左子树的根结点（在先序中找），转步骤1
	3、在A的右子树中，找右子树的根结点（在先序中找），转步骤1
	*/
	if (!strlen(is))
	{
		return NULL;
	}
	bt_node *root = (bt_node *)malloc(sizeof(bt_node));
	char *temp = is;
	while (*temp!=*fs)     //在中序中找到根节点
	{
		temp++;
	}
	root->data = *temp++;
	char *tail = is;
	do
	{
		tail++;
	} while (*tail);
	tail--;      //指向最后一个
	char leftchildtree[MAX] = { 0 };
	char rightchildtree[MAX]={0};
	strncpy(leftchildtree, is, temp - is-1);
	fs++;
	root->leftchild = creatfi(fs, leftchildtree);
	
	strncpy(rightchildtree, temp, tail - temp + 1);
	fs += (temp - is - 1);
	root->rightchild = creatfi(fs, rightchildtree);
	
	
	return root;
}
bt_node * creatil(char *is, char *ls)
{
	if (!strlen(is))
	{
		return NULL;
	}
	char leftchildtree_is[MAX] = { 0 };
	char rightchildtree_is[MAX] = { 0 };
	char leftchildtree_ls[MAX] = { 0 };
	char rightchildtree_ls[MAX] = { 0 };
	char *is_head = is, *is_tail = is;
	char *ls_head = ls, *ls_tail = ls;
	while (*is_tail)
	{
		is_tail++;
	}
	is_tail--;
	while (*ls_tail)
	{
		ls_tail++;
	}  
	ls_tail--;//指向后序的最后一个结点  是根节点
	bt_node * root = (bt_node *)malloc(sizeof(bt_node));
	root->data = *ls_tail;
	while (*is != *ls_tail)
	{
		is++;
	}
	strncpy(leftchildtree_is, is_head, is - is_head);
	strncpy(leftchildtree_ls, ls_head, is - is_head);
	strncpy(rightchildtree_is, ++is, is_tail - is + 1);
	char *right = ls_head + (is - is_head - 1);
	strncpy(rightchildtree_ls, right, is_tail - is +1);
	root->leftchild = creatil(leftchildtree_is, leftchildtree_ls);
	root->rightchild = creatil(rightchildtree_is, rightchildtree_ls);
	return root;
}

void insert(bt_node *root, char ch, char *pos)
{
	bt_node *child = (bt_node*)malloc(sizeof(bt_node));
	if (!strcmp(pos, "left"))
	{
		root->leftchild = child;
	}
	else
	{
		root->rightchild = child;
	}
	child->data = ch;
	child->leftchild = NULL;
	child->rightchild = NULL;
	child->parent = root;
}

int  inorder(bt_node *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	else if (ptr->leftchild == NULL&&ptr->rightchild == NULL)
	{
		printf("%c ", ptr->data);
		return 0;
	}
	else
	{
		inorder(ptr->leftchild);
		printf("%c ", ptr->data);
		inorder(ptr->rightchild);
	}
}
int firstorder(bt_node *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	else if (ptr->leftchild == NULL&&ptr->rightchild == NULL)
	{
		printf("%c ", ptr->data);
		return 0;
	}
	else
	{
		printf("%c ", ptr->data);
		firstorder(ptr->leftchild);
		firstorder(ptr->rightchild);
	
	}

}
int lastorder(bt_node *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	else if (ptr->leftchild == NULL&&ptr->rightchild == NULL)
	{
		printf("%c ", ptr->data);
		return 0;
	}
	else
	{

		lastorder(ptr->leftchild);
		lastorder(ptr->rightchild);
		printf("%c ", ptr->data);
	}

}
int levelorder(bt_node *ptr)
{
	sq_queue q; //定义一个 顺序队列 
	init_squeue(&q);
	in_squeue(&q, ptr);
	while (lenth_squeue(&q) != 0)
	{
		bt_node *temp=(bt_node*)malloc(sizeof(bt_node));
		temp=out_squeue(&q);
		printf("%c ", temp->data);
		if (temp->leftchild != NULL)
		{
			in_squeue(&q, temp->leftchild);
		}
		if (temp->rightchild != NULL)
		{
			in_squeue(&q, temp->rightchild);
		}
	}
}

/*
非递归的先序遍历
我的算法思想：
	两个循环嵌套   外层循环 ：当结点的右子树不为空  将右子树入栈  循环的结束条件是 栈不为空
					内层循环 ：遍历打印结点的左子树    循环结束条件是 结点至少有一个分支
*/
int while_inorder(bt_node *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	stack s;
	init_stack(&s);
	do  //至少循环一次   已判定了二叉树不为空
	{
		if (!is_empty(&s))  //如果 不为空
		{
			ptr = pop(&s);       //让根节点=右子树
		}
		printf("%c ", ptr->data);
		while (ptr->leftchild != NULL || ptr->rightchild != NULL)  //至少有一分支
		{
			if (ptr->leftchild != NULL&&ptr->rightchild != NULL)  //有两个分支
			{
				push(&s, ptr->rightchild);  //右孩子入栈
			}
			if (ptr->leftchild != NULL)  //有左孩子
			{
				ptr = ptr->leftchild;   
			}
			else       //有右孩子
			{
				ptr = ptr->rightchild;
			}
			printf("%c ", ptr->data);
		}
	} while (!is_empty(&s));
}

bt_node *findvalue(bt_node *root,elem_type value)
{
	bt_node *resault = (bt_node*)malloc(sizeof(bt_node));
	resault = NULL;

	if (root == NULL || root->data == value)
	{
		return root;
	}
	else
	{
		resault = findvalue(root->leftchild, value);		
		if (resault == NULL)  //右孩子不为空 并且没找到
		{
			resault = findvalue(root->rightchild, value);
		}
		else
			return resault;
	}
	//	return NULL;
}
bt_node *findparent(bt_node *root, bt_node *child)
{
	if (root == NULL )
	{
		return NULL;
	}
	else
	{
		bt_node *resault = (bt_node*)malloc(sizeof(bt_node));
		resault = NULL;
		if (root->leftchild ==child||root->rightchild==child)
		{
			return root;
		}
		resault=findparent(root->leftchild, child);
		if (resault == NULL)
		{
			resault = findparent(root->rightchild, child);
		}
		return resault;
		

	}
	
}
bt_node *Find_Parent(bt_node *root, bt_node*child)
{
	if (root==NULL||root == child || child == NULL)
	{
		return NULL;
	}
	else
	{
		return findparent(root, child);
	}
}

int  node_number(bt_node *ptr)
{
	if (ptr == NULL )
	{
		return 0;
	}
	else
	{
		return node_number(ptr->leftchild) + node_number(ptr->rightchild) + 1 ;
	
	}

}
int  leafnode_number(bt_node *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	else if (ptr->leftchild == NULL && ptr->rightchild == NULL)//求叶子节点的附加条件
	{
		return 1;
	}
	else
	{
		return leafnode_number(ptr->leftchild) + leafnode_number(ptr->rightchild);

	}

}
int node_has_twochild_number(bt_node *ptr)
{
	if ((ptr == NULL) || (ptr->leftchild == NULL && ptr->rightchild == NULL) )
	{
		//  空结点 或者叶子结点 
		return 0;
	}
	else if (ptr->leftchild != NULL && ptr->rightchild != NULL)
	{
		// 有两个分支  
		return 1 + node_has_twochild_number(ptr->leftchild) + node_has_twochild_number(ptr->rightchild);;
	}
	return 0;
	//还有 只有一个分支的情况  
}
int node_has_onechild_number(bt_node *ptr)
{
	if ((ptr == NULL) || (ptr->leftchild == NULL && ptr->rightchild == NULL))
	{
		//  空结点 或者叶子结点 
		return 0;
	}
	else if (ptr->leftchild!=NULL && ptr->rightchild==NULL)
	{
		//只有 左孩子
		return 1 + node_has_onechild_number(ptr->leftchild);
	}
	else if (ptr->rightchild != NULL&&ptr->leftchild == NULL)
	{
		//只有 右孩子
		return 1 + node_has_onechild_number(ptr->rightchild);
	}
	else if (ptr->leftchild != NULL && ptr->rightchild != NULL)
	{
		// 有两个分支  
		return node_has_onechild_number(ptr->leftchild) + node_has_onechild_number(ptr->rightchild);
	}
}

int depth(bt_node *root)
{
	int i=0, j=0;
	if (root->leftchild == NULL&&root->rightchild == NULL)
	{
		return 1;
	}
	if (root->leftchild!=NULL)
	{
		i += depth(root->leftchild);
	}
	if (root->rightchild != NULL)
	{
		j += depth(root->rightchild);
	}
	return i > j ? i + 1 : j + 1;
}

/*
找两个孩子结点 最近的 共同的  父结点

我的思路是： 用两个队列保存孩子结点的父结点 以及父节点的父结点 一直循环直到根节点
			然后比较两个队列里的元素  第一个相等的元素  即为最近的 共同结点
*/
bt_node *find_near_common_parent(bt_node *root, bt_node *node1, bt_node *node2)
{
	sq_queue q1;
	sq_queue q2;
	init_squeue(&q1);
	init_squeue(&q2);
	bt_node *node = (bt_node*)malloc(sizeof(bt_node));
	for (node = Find_Parent(root, node1); node->data != root->data; node = Find_Parent(root, node))
	{
		if (node != NULL)
		{
			in_squeue(&q1, node);
		}
	}
	in_squeue(&q1, node);  //根节点 入队列
	for (node = Find_Parent(root, node2); node->data != root->data; node = Find_Parent(root, node))
	{
		if (node != NULL)
		{
			in_squeue(&q2, node);
		}
	}
	in_squeue(&q2, node);
	bt_node *temp1 = (bt_node*)malloc(sizeof(bt_node));
	bt_node *temp2 = (bt_node*)malloc(sizeof(bt_node));
	int lenth1 = lenth_squeue(&q1);
	int lenth2 = lenth_squeue(&q2);
	for (int i = 0; i < lenth1; i++)
	{
		temp1 = out_squeue(&q1);
		for (int j = 0; j < lenth2; j++)
		{
			temp2 = out_squeue(&q2);
			if(temp1->data == temp2->data)
			{
				return temp1;
			}
			in_squeue(&q2, temp2);
		}
	}
	return NULL;
}

/*
打印一个集合的所有子集
*/
void func2()
{
	int a[4] = { 1, 2, 3, 4 };
	int length = sizeof(a) / (sizeof(a[0]));
	int i, j, k;
	int t = 1 << length;//一共有2^n个子集。
	for (i = 0; i < t; i++)
		//用n位的二进制数来表示对应的位是否存在。
	{
		j = i;
		k = 0;
		printf("{");
		while (j)
		{
			if (j & 1)//取得j的二进制形式的最低位。
			{
				printf("%d ", a[k]);
			}
			j >>= 1;//j右移一位
			++k;
		}
		printf("}\n");
	}


}
