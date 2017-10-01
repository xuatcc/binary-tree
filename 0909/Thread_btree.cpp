
#include "main.h"

thread_btree *creat_thrtree(char * &str)//���ݴ����ŵ������������������
{
	thread_btree *root = NULL;
	if (*str != END)
	{
		root = (thread_btree *)malloc(sizeof(thread_btree));
		root->data = *str;
		root->ltag = link;  //typedef enum{link=0,thread=1}pointtag;
		root->rtag = link;
		root->leftchild = creat_thrtree(++str);
		root->rightchild = creat_thrtree(++str);
	}
	return root;
}
thread_btree *creat_thrtree_byf()
{
	char *str = "ABC##DE##F##G#H##";
	return creat_thrtree(str);
}

thread_btree * creat_thrtree_fi(char *fs, char *is)
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
	thread_btree *root = (thread_btree *)malloc(sizeof(thread_btree));
	char *temp = is;
	while (*temp != *fs)     //���������ҵ����ڵ�
	{
		temp++;
	}
	root->data = *temp++;
	root->ltag = link;
	root->rtag = link;
	char *tail = is;
	do
	{
		tail++;
	} while (*tail);
	tail--;      //ָ�����һ��
	char leftchildtree[MAX] = { 0 };
	char rightchildtree[MAX] = { 0 };
	strncpy(leftchildtree, is, temp - is - 1);
	fs++;
	root->leftchild = creat_thrtree_fi(fs, leftchildtree);

	strncpy(rightchildtree, temp, tail - temp + 1);
	fs += (temp - is - 1);
	root->rightchild = creat_thrtree_fi(fs, rightchildtree);


	return root;
}
void inorder_thrtree(thread_btree *ptr) //��������˶�����  �����Ƿ񴴽��ɹ�
{
	if (ptr != NULL)
	{
		inorder_thrtree(ptr->leftchild);
		printf("%c  ", ptr->data);
		inorder_thrtree(ptr->rightchild);

	}
}

void make_by_inorder(thread_btree *ptr, thread_btree *&p)
{
	if (ptr != NULL)
	{
		make_by_inorder(ptr->leftchild, p);
		if (ptr->leftchild == NULL)
		{
			ptr->leftchild = p;
			ptr->ltag = thread;
		}
		if (p != NULL && p->rightchild == NULL)
		{
			p->rightchild = ptr;
			p->rtag = thread;
		}
		p = ptr;
		make_by_inorder(ptr->rightchild, p);
	}
}
void make_thread_tree_by_inorder(thread_btree *ptr)//����Ŷ����� ������  ������������Ĺ���
{
	thread_btree *p = NULL;
	make_by_inorder(ptr, p);
	p->rightchild = NULL;
	p->rtag = thread;
}

void make_by_firstorder(thread_btree *ptr, thread_btree *&p)
{
	if (ptr != NULL)
	{
		if (ptr->leftchild == NULL)
		{
			ptr->ltag = thread;
			ptr->leftchild = p;
		}
		if (p!=NULL && p->rightchild == NULL)
		{
			p->rtag = thread;
			p->rightchild = ptr;
		}
		p = ptr;
		if (ptr->ltag == link)
		{
			make_by_firstorder(ptr->leftchild, p);
		}
		if (ptr->rtag == link)
		{
			make_by_firstorder(ptr->rightchild, p);
		}
		
	}
}
void make_thread_tree_by_firstorder(thread_btree *ptr)//����Ŷ����� ������  ������������Ľ��
{
	thread_btree *p = NULL;
	make_by_firstorder(ptr, p);
	p->rightchild = NULL;
	p->rtag = thread;
}

void make_by_lastorder(thread_btree *ptr, thread_btree *&p)
{
	if (ptr != NULL)
	{
		if (ptr->ltag == link)
		{
			make_by_lastorder(ptr->leftchild, p);
		}
		if (ptr->rtag == link)
		{
			make_by_lastorder(ptr->rightchild, p);
		}
		if (ptr->leftchild == NULL)
		{
			ptr->ltag = thread;
			ptr->leftchild = p;
		}
		if (p != NULL && p->rightchild == NULL)
		{
			p->rtag = thread;
			p->rightchild = ptr;
		}
		p = ptr;
	}
}
void make_thread_tree_by_lastorder(thread_btree *ptr)//����Ŷ����� ������  ���պ�������Ĺ���
{
	thread_btree *p = NULL;
	make_by_lastorder(ptr, p);
	p->rightchild = NULL;
	p->rtag = thread;
}

thread_btree *First(thread_btree *p)
{
	while (p != NULL && p->ltag != thread)
	{
		p = p->leftchild;
	}
	return p;
}
thread_btree * Next(thread_btree *p)
{
	if (p == NULL) 
		return NULL;
	if (p->rtag == thread)
	{
		return p->rightchild;
	}
	else
	{
		return First(p->rightchild);
	}
}
void thr_inorder(thread_btree *ptr)//�������������������
{
	printf("������������������������ӡ��");
	for (thread_btree *p = First(ptr); p != NULL; p = Next(p))
	{
		printf("%c  ", p->data);
	}
	printf("\n");
}

thread_btree *Last(thread_btree *p)
{
	while (p != NULL&&p->rtag != thread)
	{
		p = p->rightchild;
	}
	return p;
}
thread_btree* Prev(thread_btree *p)
{
	if (p == NULL)
	{
		return NULL;
	}
	if (p->ltag == thread)
	{
		return p->leftchild;
	}
	else
	{
		return Last(p->leftchild);//�ҵ����ӵ����ұ�
	}
}
void thr_inorder_res(thread_btree *ptr)
{
	printf("������������������������ӡ��");
	for (thread_btree *p = Last(ptr); p != NULL; p = Prev(p))
	{
		printf(" %c  ", p->data);
	}
	printf("\n");
}

void thr_firstorder(thread_btree *ptr)//�ǵݹ����������������������
{
	printf("ǰ����������������Ĵ�ӡ��");
	for (; ptr != NULL;)
	{
		printf("%c  ", ptr->data);
		if (ptr->ltag == link)
		{
			ptr = ptr->leftchild;
			continue;
		}
		else
		{
			ptr = ptr->rightchild;
		}
	}
	printf("\n");
}

/*
�������  ����д
*/
thread_btree * find_parent(thread_btree*root,thread_btree *child)
{
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		thread_btree *resault = (thread_btree*)malloc(sizeof(thread_btree));
		resault = NULL;
		if (root->leftchild == child || root->rightchild == child)
		{
			return root;
		}
		resault = find_parent(root->leftchild, child);
		if (resault == NULL)
		{
			resault = find_parent(root->rightchild, child);
		}
		return resault;


	}
	
}
void thr_lastorder(thread_btree *ptr)//���������������������
{
	printf("������������������Ĵ�ӡ��");
	for (thread_btree *p = First(ptr); p!= ptr;)
	{
		printf("%c  ", p->data);
		if (p->rtag == thread)
		{
			p = p->rightchild;
		}
		else
		{
			p = find_parent(ptr, p);
		}
		
	}
	for (thread_btree *p = Last(ptr); p != ptr;)
	{
		//����д��
	}
	printf("\n");
}

/*

void make_minheap(heapelem *ar, int n)
{
	if (ar == NULL || n < 2)
	{
		return 0;
	}
	int end = n - 1;
	int pos = (end - 1) / 2;
	while (pos >= 0)
	{
		FilterDown(ar, pos, end);        //���ѹ���   ��������
		--pos;
	}
	heap_sort(ar,n);//�������   
}
void FilterDown(heapelem *ar, int pos, int end)
{
	int temp = ar[pos];
	int i = pos;
	for (int j = i*2+1; j <= end; j = j * 2 + 1)
	{
		if (j<end && ar[j]>ar[j + 1])
		{
			j++;
		}
		if (temp <= ar[j])
		{
			break;
		}
		ar[i] = ar[j];
		i = j;
	}
	ar[i] = temp;
}
*/