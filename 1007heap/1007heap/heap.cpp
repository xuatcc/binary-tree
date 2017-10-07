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
{//���ٶѽṹ
	assert(hp != NULL);
	free(hp->data);
	hp->data = NULL;
	hp->cursize = 0;
	hp->maxsize = 0;
}
void clear_heap(heap *hp)  //��ն�
{
	assert(hp != NULL);
	hp->cursize = 0;

}
bool empty_heap(heap *hp)
{
	//�п�
	assert(hp != NULL);
	return hp->cursize == 0;

}
bool full_heap(heap *hp)
{
	//����
	assert(hp != NULL);
	return hp->cursize == hp->maxsize;
}
int size_heap(heap *hp)
{//���ض�ǰ��С
	assert(hp != NULL);
	return hp->cursize;
}
elemtype pop_heap(heap *hp,int choose)
{
	//���ضѶ�Ԫ��
	assert(hp != NULL);
	if (empty_heap(hp))
	{
		printf("the heap is  empty!\n");
		exit(0);
	}
	elemtype tmp = hp->data[0];
	swap(&hp->data[0], &hp->data[hp->cursize - 1]);//�����Ѷ�Ԫ�ص� ���
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
	//ѹ��һ��Ԫ��
	assert(hp != NULL);
	if (full_heap(hp))
	{
		printf("the heap is  full!\n");
		exit(0);
	}
	hp->data[hp->cursize] = data;
	hp->cursize += 1;
	Filer_up(hp->data, hp->cursize - 1); //������Ԫ�غ�Ķѽ��е���
}
void insert_heap(heap *hp, elemtype *ar, int n,int choose)//��ʼ��ʱ��ֵ
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
	//������   ��������
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
{ //������

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
FilterDown(ar, pos, end);        //���ѹ���   ��������
--pos;
}
heap_sort(ar,n);//�������
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