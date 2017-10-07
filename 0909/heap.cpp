#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include "Heap.h"

void init_heap(heap *hp)
{
	assert(hp != NULL);
	hp->cursize = 0;
	hp->maxsize = HEAPSIZE;
	hp->data = (elemtype *)malloc(sizeof(elemtype)*hp->maxsize);
	if (hp->data == NULL)
	{
		exit(1);
	}
}
void destory_heap(heap *hp)
{//销毁堆结构
	assert(hp != NULL);
	free(hp->data);
	hp->data = NULL;
	hp->cursize = 0;
	hp->maxsize = 0;
}
void clear_heap(heap *hp)  //清空堆
{
	assert(hp != NULL);
	hp->cursize = 0;

}
bool empty_heap(heap *hp)
{
	//判空
	assert(hp != NULL);
	return hp->cursize == 0;

}
bool full_heap(heap *hp)
{
	//判满
	assert(hp != NULL);
	return hp->cursize == hp->maxsize;
}
int size_heap(heap *hp)
{//返回堆前大小
	assert(hp != NULL);
	return hp->cursize;
}
elemtype pop_heap(heap *hp,int choose)
{
	//返回堆顶元素
	assert(hp != NULL);
	if (empty_heap(hp))
	{
		printf("the heap is  empty!\n");
		exit(0);
	}
	elemtype tmp = hp->data[0];
	swap(&hp->data[0], &hp->data[hp->cursize - 1]);//交换堆顶元素到 最后
	hp->cursize -= 1;
	switch (choose)
	{
	case 0:FilterDown_min(hp->data, 0, hp->cursize - 1); break;
	case 1:FilterDown_max(hp->data, 0, hp->cursize - 1); break;
	}
	
	return tmp;
}
void swap(elemtype *a, elemtype *b)
{
	elemtype temp = *a;
	*a = *b;
	*b = temp;
}
void push_heap(heap *hp, elemtype data)
{
	//压入一个元素
	assert(hp != NULL);
	if (full_heap(hp))
	{
		printf("the heap is  full!\n");
		exit(0);
	}
	hp->data[hp->cursize] = data;
	hp->cursize += 1;
	Filer_up(hp->data, hp->cursize - 1); //将插入元素后的堆进行调整
}
void insert_heap(heap *hp, elemtype *ar, int n,int choose)//初始化时赋值
{
	assert(hp != NULL &&  ar != NULL && n>0);
	for (int i = 0; i<n; ++i)
	{
		hp->data[i] = ar[i];
	}
	hp->cursize = n;
	make_heap(hp,choose);
	

}

void make_heap(heap *hp,int choose)
{
	//制作堆   由下往上
	assert(hp != NULL);
	int end = hp->cursize - 1;
	int pos = (end - 1) / 2;
	switch (choose)
	{
	case 0:while (pos >= 0)
			{
			   FilterDown_min(hp->data, pos, end);
			   --pos;
			}
		   break;
	case 1:while (pos >= 0)
			{
			   FilterDown_max(hp->data, pos, end);
			   --pos;
			}
		   break;
	default:
		break;
	}
	

}
void make_sort(heap *hp)
{ //堆排序

} 

void Filer_up(elemtype *ar, int start)
{
	int j = start, i = (j - 1) / 2;
	elemtype tmp = ar[j];
	while (j > 0)
	{
		if (ar[i] <= tmp)
			break;
		ar[j] = ar[i];
		j = i;
		i = (j - 1) / 2;
	}
	ar[j] = tmp;

}


void FilterDown_max(elemtype *ar, int pos, int end)
{
	int temp = ar[pos];
	int i = pos;
	for (int j = i * 2 + 1; j <= end; j = j * 2 + 1)
	{
		if (j<end && ar[j]<ar[j + 1])
		{
			j++;
		}
		if (temp >= ar[j])
		{
			break;
		}
		ar[i] = ar[j];
		i = j;
	}
	ar[i] = temp;
}
void FilterDown_min(elemtype *ar, int pos, int end)
{
	int temp = ar[pos];
	int i = pos;
	for (int j = i * 2 + 1; j <= end; j = j * 2 + 1)
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
FilterDown(ar, pos, end);        //建堆过程   由下往上
--pos;
}
heap_sort(ar,n);//排序过程
}

void heap_sort(heapelem *ar,int n)
{
int pos=n-1;
while(pos>0)
{
swap(pos,0);
FilterDown(ar, pos, end);
pos--;
}
}

void swap(heapelem &a,heapelem &b)
{
heapelem temp=a;
a=b;
b=temp;
}
*/