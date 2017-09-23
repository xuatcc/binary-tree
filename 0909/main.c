#include "main.h"

int main()
{
	//bt_node *root=creat();//用带#号的前序 构建二叉树  测试成功
	char fs[MAX] = { "ABDECFG" };
	char is[MAX] = { "DBEAFCG" };
	char ls[MAX] = { "DEBFGCA" };
	
	bt_node *root = (bt_node *)malloc(sizeof(bt_node));
	root = creatfi(fs, is);      //用前序和中序构建二叉树  测试成功
	//root = creatil(is, ls);   //用中序和后序构建二叉树  测试成功

	/*///在二叉树中查找value    测试成功
	char ch = 'K';
	bt_node *node = (bt_node *)malloc(sizeof(bt_node)); 
	node=findvalue(root, ch);
	printf("%c\n", node->data);
	*/

	/*
	//根据孩子结点  查找双亲结点    测试成功
	bt_node *parent = (bt_node *)malloc(sizeof(bt_node));
	bt_node *child = (bt_node *)malloc(sizeof(bt_node));
	child = root->leftchild->leftchild->leftchild->rightchild;
	parent = Find_Parent(root, child);
	printf("child->data=%c\n", child->data);
	printf("it's parent ->data=%c\n", parent->data);
	*/
	

	/*
	  
	int count = node_number(root);      //统计所有结点的个数
	int leafcount = leafnode_number(root);     //统计叶子结点的个数  
	int two_branches = node_has_twochild_number(root);  //统计包含两个分支的结点的个数
	int one_branch = node_has_onechild_number(root);  //统计包含一个分支的结点个数
	printf("the tree has %d of node\n", count);
	printf("the tree has %d of leafnode\n", leafcount);
	printf("the tree has %d of node which has two branches\n", two_branches);
	printf("the tree has %d of node which has one branch\n", one_branch);
	//测试成功
	*/

	/*
	int dep = depth(root);
	printf("the depth of this tree is = %d\n", dep);
	//求二叉树的深度  测试成功
	*/

	
	//根据二叉树遍历   测试成功
/*	printf("\n递归版本的后序遍历：");
	lastorder(root);
	printf("\n递归版本的中序遍历：");
	inorder(root);
	printf("\n");
	
	//层次遍历  测试成功
	printf("层次遍历：");
	levelorder(root);
	*/
/*	
	printf("递归版本的前序遍历：");
	firstorder(root);

	printf("\n循环版本的前序遍历：");  //测试成功
	while_firstorder(root);
	printf("\n");	

	printf("\n循环版本的中序遍历：");  
	while_inorder(root);
	printf("\n");
	printf("\n循环版本的后序遍历：");
	while_lastorder(root);
	printf("\n");
	
*/
	/* 
	//寻找两个子结点的共同的最近的父节点         测试成功
	bt_node *node1 = (bt_node *)malloc(sizeof(bt_node));
	node1 = root->leftchild->leftchild->leftchild;
	bt_node *node2 = (bt_node *)malloc(sizeof(bt_node));
	node2 = root->leftchild->leftchild;
	bt_node *node3 = (bt_node *)malloc(sizeof(bt_node));
	node3 = find_near_common_parent(root, node1, node2);
	printf("the childnode no.1 is %c\n", node1->data);
	printf("the childnode no.2 is %c\n", node2->data);
	if (node3 != NULL)
	{
		printf("their commom parent  node is %c\n", node3->data);
	}
	else
	{
		printf("they has not common parent node\n");
	}
	*/

	/*
	func2();   //打印一个集合的所有子集    测试成功
	*/

	/*
	//   测试成功    判断一棵树是否是完全二叉树  平衡二叉树  满二叉树
	
	printf("if the tree is a complete tree = %d\n", is_complete_tree(root));
	printf("if the tree is a full tree = %d\n", is_full_tree(root));
	printf("if the tree is a full tree = %d\n", isAVL(root));
*/

	print_k_level(root, 2);   //打印第k层   根节点为第0 层
}

/*
static int count = 0;
void swap(int *arr, int a, int b)
{
int temp = arr[a];
arr[a] = arr[b];
arr[b] = temp;
}
void perm(int *arr, int k, int m)
{
if (k == m)
{
count++;
for (int i = 0; i <= m; i++)
{
printf("%d  ", arr[i]);
}
printf("\n");
}
else
{
for (int j=k; j < m;)
{
perm(arr, ++j, m);
swap(arr, j, m);
}

}
}
int main()
{
int arr[] = { 1, 2, 3 };
int n = sizeof(arr) / sizeof(arr[0]);
perm(arr, 0, n - 1);
}
*/
