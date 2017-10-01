#ifndef ThreadBinaryTree
#define ThreadBinaryTree

typedef char elem_type;
#define END  '#'
typedef enum{link=0,thread=1}pointtag;
/*
 线索化二叉树 的数据结构是一个五元组  
 包含指向左子树 右子树的指针
 以及标志左右指针到底是指向 左右孩子还是 遍历序列的前驱后继 标志位
 以及数据域
*/
typedef struct thread_btree
{
	struct thread_btree *leftchild;
	struct thread_btree *rightchild;
	pointtag ltag, rtag;
	elem_type data;
}thread_btree;

thread_btree *creat_thrtree_byf();//根据带井号的先序创建二叉树

thread_btree * creat_thrtree_fi(char *fs, char *is);//根据先序中序遍历创建二叉树
void inorder_thrtree(thread_btree *ptr);  //中序遍历此二叉树  检验是否创建成功

void make_thread_tree_by_inorder(thread_btree *ptr);//将这颗二叉树 线索化  按照中序遍历的结果

void make_thread_tree_by_firstorder(thread_btree *ptr);//将这颗二叉树 线索化  按照先序遍历的结果
void make_thread_tree_by_lastorder(thread_btree *ptr);//将这颗二叉树 线索化  按照后序遍历的结果

thread_btree *First(thread_btree *p);
thread_btree * Next(thread_btree *p);
void thr_inorder(thread_btree *ptr);//中序遍历此线索二叉树

void thr_firstorder(thread_btree *ptr);//先序遍历此线索化二叉树
void thr_lastorder(thread_btree *ptr);//后序遍历此线索化二叉树

thread_btree *Last(thread_btree *p);
thread_btree* Prev(thread_btree *p);
void thr_inorder_res(thread_btree *ptr);//逆序打印中序遍历

#endif