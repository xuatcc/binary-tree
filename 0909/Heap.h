#ifndef HEAP_H
#define HEAP_H
#define MY_ASSERT(statement)  if(!statement) \
	exit(1)
#define HEAPSIZE 100
typedef int elemtype;
typedef struct heap
{
	elemtype *data;
	int maxsize;
	int cursize;
}heap;

void init_heap(heap *hp);//��ʼ���ѽṹ
void destory_heap(heap *hp);  //���ٶѽṹ
void clear_heap(heap *hp); //��ն�
bool empty_heap(heap *hp);  //�п�
bool full_heap(heap *hp);  //����
int size_heap(heap *hp);  //���ض�ǰ��С
elemtype pop_heap(heap *hp, int choose);  //���ضѶ�Ԫ��
void insert_heap(heap *hp, elemtype *ar, int n, int choose);//��ʼ��ʱ��ֵ
void push_heap(heap *hp,elemtype data);  //ѹ��һ��Ԫ��
void swap(elemtype *a, elemtype *b);
void make_heap(heap *hp, int choose);  //������
void make_sort(heap *hp);  //������
void Filer_up(elemtype *ar, int start);  //������
void FilterDown_min(elemtype *ar, int pos, int end);  //
void FilterDown_max(elemtype *ar, int pos, int end);


#endif