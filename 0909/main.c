#include "main.h"

int main()
{
	//bt_node *root=creat();//�ô�#�ŵ�ǰ�� ����������  ���Գɹ�
	char fs[MAX] = { "ABDECFG" };
	char is[MAX] = { "DBEAFCG" };
	char ls[MAX] = { "DEBFGCA" };
	
	bt_node *root = (bt_node *)malloc(sizeof(bt_node));
	root = creatfi(fs, is);      //��ǰ������򹹽�������  ���Գɹ�
	//root = creatil(is, ls);   //������ͺ��򹹽�������  ���Գɹ�

	/*///�ڶ������в���value    ���Գɹ�
	char ch = 'K';
	bt_node *node = (bt_node *)malloc(sizeof(bt_node)); 
	node=findvalue(root, ch);
	printf("%c\n", node->data);
	*/

	/*
	//���ݺ��ӽ��  ����˫�׽��    ���Գɹ�
	bt_node *parent = (bt_node *)malloc(sizeof(bt_node));
	bt_node *child = (bt_node *)malloc(sizeof(bt_node));
	child = root->leftchild->leftchild->leftchild->rightchild;
	parent = Find_Parent(root, child);
	printf("child->data=%c\n", child->data);
	printf("it's parent ->data=%c\n", parent->data);
	*/
	

	/*
	  
	int count = node_number(root);      //ͳ�����н��ĸ���
	int leafcount = leafnode_number(root);     //ͳ��Ҷ�ӽ��ĸ���  
	int two_branches = node_has_twochild_number(root);  //ͳ�ư���������֧�Ľ��ĸ���
	int one_branch = node_has_onechild_number(root);  //ͳ�ư���һ����֧�Ľ�����
	printf("the tree has %d of node\n", count);
	printf("the tree has %d of leafnode\n", leafcount);
	printf("the tree has %d of node which has two branches\n", two_branches);
	printf("the tree has %d of node which has one branch\n", one_branch);
	//���Գɹ�
	*/

	/*
	int dep = depth(root);
	printf("the depth of this tree is = %d\n", dep);
	//������������  ���Գɹ�
	*/

	
	//���ݶ���������   ���Գɹ�
/*	printf("\n�ݹ�汾�ĺ��������");
	lastorder(root);
	printf("\n�ݹ�汾�����������");
	inorder(root);
	printf("\n");
	
	//��α���  ���Գɹ�
	printf("��α�����");
	levelorder(root);
	*/
/*	
	printf("�ݹ�汾��ǰ�������");
	firstorder(root);

	printf("\nѭ���汾��ǰ�������");  //���Գɹ�
	while_firstorder(root);
	printf("\n");	

	printf("\nѭ���汾�����������");  
	while_inorder(root);
	printf("\n");
	printf("\nѭ���汾�ĺ��������");
	while_lastorder(root);
	printf("\n");
	
*/
	/* 
	//Ѱ�������ӽ��Ĺ�ͬ������ĸ��ڵ�         ���Գɹ�
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
	func2();   //��ӡһ�����ϵ������Ӽ�    ���Գɹ�
	*/

	/*
	//   ���Գɹ�    �ж�һ�����Ƿ�����ȫ������  ƽ�������  ��������
	
	printf("if the tree is a complete tree = %d\n", is_complete_tree(root));
	printf("if the tree is a full tree = %d\n", is_full_tree(root));
	printf("if the tree is a full tree = %d\n", isAVL(root));
*/

	print_k_level(root, 2);   //��ӡ��k��   ���ڵ�Ϊ��0 ��
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
