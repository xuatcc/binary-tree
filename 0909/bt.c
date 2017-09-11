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
bt_node * creat() //���Գɹ�
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
	����ǰ������򴴽�������
	1��ͨ����������ҵ������A����ͨ��A�����������λ���ҳ���������������
	2����A���������У����������ĸ���㣨���������ң���ת����1
	3����A���������У����������ĸ���㣨���������ң���ת����1
	*/
	if (!strlen(is))
	{
		return NULL;
	}
	bt_node *root = (bt_node *)malloc(sizeof(bt_node));
	char *temp = is;
	while (*temp!=*fs)     //���������ҵ����ڵ�
	{
		temp++;
	}
	root->data = *temp++;
	char *tail = is;
	do
	{
		tail++;
	} while (*tail);
	tail--;      //ָ�����һ��
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
	ls_tail--;//ָ���������һ�����  �Ǹ��ڵ�
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
	sq_queue q; //����һ�� ˳����� 
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
�ǵݹ���������
�ҵ��㷨˼�룺
	����ѭ��Ƕ��   ���ѭ�� ����������������Ϊ��  ����������ջ  ѭ���Ľ��������� ջ��Ϊ��
					�ڲ�ѭ�� ��������ӡ����������    ѭ������������ ���������һ����֧
*/
int while_inorder(bt_node *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	stack s;
	init_stack(&s);
	do  //����ѭ��һ��   ���ж��˶�������Ϊ��
	{
		if (!is_empty(&s))  //��� ��Ϊ��
		{
			ptr = pop(&s);       //�ø��ڵ�=������
		}
		printf("%c ", ptr->data);
		while (ptr->leftchild != NULL || ptr->rightchild != NULL)  //������һ��֧
		{
			if (ptr->leftchild != NULL&&ptr->rightchild != NULL)  //��������֧
			{
				push(&s, ptr->rightchild);  //�Һ�����ջ
			}
			if (ptr->leftchild != NULL)  //������
			{
				ptr = ptr->leftchild;   
			}
			else       //���Һ���
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
		if (resault == NULL)  //�Һ��Ӳ�Ϊ�� ����û�ҵ�
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
	else if (ptr->leftchild == NULL && ptr->rightchild == NULL)//��Ҷ�ӽڵ�ĸ�������
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
		//  �ս�� ����Ҷ�ӽ�� 
		return 0;
	}
	else if (ptr->leftchild != NULL && ptr->rightchild != NULL)
	{
		// ��������֧  
		return 1 + node_has_twochild_number(ptr->leftchild) + node_has_twochild_number(ptr->rightchild);;
	}
	return 0;
	//���� ֻ��һ����֧�����  
}
int node_has_onechild_number(bt_node *ptr)
{
	if ((ptr == NULL) || (ptr->leftchild == NULL && ptr->rightchild == NULL))
	{
		//  �ս�� ����Ҷ�ӽ�� 
		return 0;
	}
	else if (ptr->leftchild!=NULL && ptr->rightchild==NULL)
	{
		//ֻ�� ����
		return 1 + node_has_onechild_number(ptr->leftchild);
	}
	else if (ptr->rightchild != NULL&&ptr->leftchild == NULL)
	{
		//ֻ�� �Һ���
		return 1 + node_has_onechild_number(ptr->rightchild);
	}
	else if (ptr->leftchild != NULL && ptr->rightchild != NULL)
	{
		// ��������֧  
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
���������ӽ�� ����� ��ͬ��  �����

�ҵ�˼·�ǣ� ���������б��溢�ӽ��ĸ���� �Լ����ڵ�ĸ���� һֱѭ��ֱ�����ڵ�
			Ȼ��Ƚ������������Ԫ��  ��һ����ȵ�Ԫ��  ��Ϊ����� ��ͬ���
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
	in_squeue(&q1, node);  //���ڵ� �����
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
��ӡһ�����ϵ������Ӽ�
*/
void func2()
{
	int a[4] = { 1, 2, 3, 4 };
	int length = sizeof(a) / (sizeof(a[0]));
	int i, j, k;
	int t = 1 << length;//һ����2^n���Ӽ���
	for (i = 0; i < t; i++)
		//��nλ�Ķ�����������ʾ��Ӧ��λ�Ƿ���ڡ�
	{
		j = i;
		k = 0;
		printf("{");
		while (j)
		{
			if (j & 1)//ȡ��j�Ķ�������ʽ�����λ��
			{
				printf("%d ", a[k]);
			}
			j >>= 1;//j����һλ
			++k;
		}
		printf("}\n");
	}


}
