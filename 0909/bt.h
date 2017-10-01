#ifndef BT_H
#define BT_H



#define MAX 20
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
// ǰ��ͺ��򴴽����� ���������޷��ж϶��������ڵ��������������

/*
bt_node * init();   //   �������Ա�������� ��ʼ��������  �ѷ����ķ���
void insert(bt_node *root, char ch, char *pos);      //   ͬ��
*/
void  inorder(bt_node *ptr);   //���ݶ�����  ��ӡ����������
void  firstorder(bt_node *ptr);     //ǰ�����
void lastorder(bt_node *ptr);      //�������
int levelorder(bt_node *ptr);    // ��α���

void print_k_level(bt_node *ptr, int k);   //��ӡ��k��
/*
�ǵݹ���������
�ҵ��㷨˼�룺
����ѭ��Ƕ��   ���ѭ�� ����������������Ϊ��  ����������ջ  ѭ���Ľ��������� ջ��Ϊ��
�ڲ�ѭ�� ��������ӡ����������    ѭ������������ ���������һ����֧
*/
int while_firstorder(bt_node *ptr);
int while_inorder(bt_node *ptr);
int while_lastorder(bt_node *ptr);

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

bool is_complete_tree(bt_node *root);   //�Ƿ�����ȫ������
bool is_full_tree(bt_node *root);   //�Ƿ�����������
bool is_balance_tree(bt_node * root);         //�Ƿ���ƽ�������
bool is_bstree(bt_node *root);  //�Ƿ��Ƕ���������
/*
��ӡһ�����ϵ������Ӽ�
*/
void func2();


#endif