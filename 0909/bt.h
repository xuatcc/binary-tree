#ifndef BT_H
#define BT_H



#define MAX 15
typedef char elem_type;
typedef struct bt_node
{
	struct bt_node *parent;
	struct bt_node *leftchild;
	struct bt_node *rightchild;
	elem_type data;
}bt_node;

bt_node * creat();      //根据终端输入的前序遍历   创建二叉树
bt_node * creatfi(char *fs, char *is);     //根据中序和前序遍历  创建二叉树
bt_node * creatil(char *is, char *ls);       //根据中序和后续遍历  创建二叉树
// 前序和后序创建不出 二叉树，无非判断二叉树根节点的左右子树部分

/*
bt_node * init();   //   用做测试遍历结果的 初始化二叉树  已废弃的方法
void insert(bt_node *root, char ch, char *pos);      //   同上
*/
int  inorder(bt_node *ptr);   //根据二叉树  打印中序遍历结果
int firstorder(bt_node *ptr);     //前序遍历
int lastorder(bt_node *ptr);      //后序遍历
int levelorder(bt_node *ptr);    // 层次遍历

/*
非递归的先序遍历
我的算法思想：
两个循环嵌套   外层循环 ：当结点的右子树不为空  将右子树入栈  循环的结束条件是 栈不为空
内层循环 ：遍历打印结点的左子树    循环结束条件是 结点至少有一个分支
*/
int while_firstorder(bt_node *ptr);
int while_inorder(bt_node *ptr);
int while_lastorder(bt_node *ptr);

bt_node *findvalue(bt_node *root, elem_type value);     //  在二叉树中 查找值
bt_node *findparent(bt_node *root, bt_node *child);       //  查找某个孩子节点的双亲结点
bt_node *Find_Parent(bt_node *root, bt_node*child);        //将递归的函数 封装

int  node_number(bt_node *ptr);    //计算所有结点的个数
int  leafnode_number(bt_node *ptr);      //计算叶子结点的个数
int node_has_twochild_number(bt_node *ptr);  //计算包含两个分支的结点个数
int node_has_onechild_number(bt_node *ptr);  //计算包含一个分支的结点个数
int depth(bt_node *root);    //计算二叉树的深度

bt_node *find_near_common_parent(bt_node *root, bt_node *node1, bt_node *node2);
//寻找两个子结点的共同的最近的父节点





/*
打印一个集合的所有子集
*/
void func2();


#endif