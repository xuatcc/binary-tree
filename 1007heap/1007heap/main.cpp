#include <stdio.h>
#include "Heap.h"

int main()
{

	heap hp;
	init_heap(&hp);
	int ar[] = { 21, 2, 45, 63, 7, 86, 43, 78, 90 };
	int n = sizeof(ar) / sizeof(ar[0]);
	printf("ar[]={");
	for (int i = 0; i < n; i++)
	{
		printf("%d ,", ar[i]);
	}
	printf("}\n");
	int choose;
	printf("想要按照哪种方式排序？\n0 最小堆 \n1 最大堆\n请输入序号：");
	scanf("%d", &choose);
	insert_heap(&hp, ar, n,choose);
	for (int i = 0; i < n; i++)
	{
		 elemtype res = pop_heap(&hp,choose);
		 printf("%d  ", res);
    }
	printf("\n");
			
}