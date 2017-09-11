#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#define MAX 15
typedef char elem_type;
typedef struct bt_node
{
	struct bt_node *parent;
	struct bt_node *leftchild;
	struct bt_node *rightchild;
	elem_type data;
}bt_node;

bt_node * creat();      //�����ն������ǰ�����   ����������
bt_node * creatfi(char *fs, char *is);     //���������ǰ�����  ����������
bt_node * creatil(char *is, char *ls);       //��������ͺ�������  ����������
/*
bt_node * init();   //   �������Ա�������� ��ʼ��������  �ѷ����ķ���
void insert(bt_node *root, char ch, char *pos);      //   ͬ��
*/
int  inorder(bt_node *ptr);   //���ݶ�����  ��ӡ����������
int firstorder(bt_node *ptr);     //ǰ�����
int lastorder(bt_node *ptr);      //�������
int levelorder(bt_node *ptr);    // ��α���

/*
�ǵݹ���������
�ҵ��㷨˼�룺
����ѭ��Ƕ��   ���ѭ�� ����������������Ϊ��  ����������ջ  ѭ���Ľ��������� ջ��Ϊ��
�ڲ�ѭ�� ��������ӡ����������    ѭ������������ ���������һ����֧
*/
int while_inorder(bt_node *ptr);

bt_node *findvalue(bt_node *root, elem_type value);     //  �ڶ������� ����ֵ
bt_node *findparent(bt_node *root, bt_node *child);       //  ����ĳ�����ӽڵ��˫�׽��
bt_node *Find_Parent(bt_node *root, bt_node*child);        //���ݹ�ĺ��� ��װ

int  node_number(bt_node *ptr);    //�������н��ĸ���
int  leafnode_number(bt_node *ptr);      //����Ҷ�ӽ��ĸ���
int node_has_twochild_number(bt_node *ptr);  //�������������֧�Ľ�����
int node_has_onechild_number(bt_node *ptr);  //�������һ����֧�Ľ�����
int depth(bt_node *root);    //��������������

bt_node *find_near_common_parent(bt_node *root, bt_node *node1, bt_node *node2);
//Ѱ�������ӽ��Ĺ�ͬ������ĸ��ڵ�

/*
��α����õ�  ����
*/
typedef struct{
	bt_node * data[MAX];
	int front;//ͷָ��
	int rear; 
}sq_queue;

void init_squeue(sq_queue *q);
int lenth_squeue(sq_queue *q);
bool in_squeue(sq_queue *q, bt_node *val);
bt_node * out_squeue(sq_queue *q);



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
bt_node* pop(stack *s) ;//��ջ

/*
��ӡһ�����ϵ������Ӽ�
*/
void func2();


