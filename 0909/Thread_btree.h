#ifndef ThreadBinaryTree
#define ThreadBinaryTree

typedef char elem_type;
#define END  '#'
typedef enum{link=0,thread=1}pointtag;
/*
 ������������ �����ݽṹ��һ����Ԫ��  
 ����ָ�������� ��������ָ��
 �Լ���־����ָ�뵽����ָ�� ���Һ��ӻ��� �������е�ǰ����� ��־λ
 �Լ�������
*/
typedef struct thread_btree
{
	struct thread_btree *leftchild;
	struct thread_btree *rightchild;
	pointtag ltag, rtag;
	elem_type data;
}thread_btree;

thread_btree *creat_thrtree_byf();//���ݴ����ŵ����򴴽�������

thread_btree * creat_thrtree_fi(char *fs, char *is);//�������������������������
void inorder_thrtree(thread_btree *ptr);  //��������˶�����  �����Ƿ񴴽��ɹ�

void make_thread_tree_by_inorder(thread_btree *ptr);//����Ŷ����� ������  ������������Ľ��

void make_thread_tree_by_firstorder(thread_btree *ptr);//����Ŷ����� ������  ������������Ľ��
void make_thread_tree_by_lastorder(thread_btree *ptr);//����Ŷ����� ������  ���պ�������Ľ��

thread_btree *First(thread_btree *p);
thread_btree * Next(thread_btree *p);
void thr_inorder(thread_btree *ptr);//�������������������

void thr_firstorder(thread_btree *ptr);//���������������������
void thr_lastorder(thread_btree *ptr);//���������������������

thread_btree *Last(thread_btree *p);
thread_btree* Prev(thread_btree *p);
void thr_inorder_res(thread_btree *ptr);//�����ӡ�������

#endif