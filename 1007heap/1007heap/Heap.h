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

void init_heap(heap *hp);//初始化堆结构
void destory_heap(heap *hp);  //销毁堆结构
void clear_heap(heap *hp); //清空堆
bool empty_heap(heap *hp);  //判空
bool full_heap(heap *hp);  //判满
int size_heap(heap *hp);  //返回堆前大小
elemtype pop_heap(heap *hp, int choose);  //返回堆顶元素
void insert_heap(heap *hp, elemtype *ar, int n, int choose);//初始化时赋值
void push_heap(heap *hp,elemtype data);  //压入一个元素
void swap(elemtype *a, elemtype *b);
void make_heap(heap *hp, int choose);  //制作堆
void make_sort(heap *hp);  //堆排序
void Filer_up(elemtype *ar, int start);  //调整堆
void FilterDown_min(elemtype *ar, int pos, int end);  //
void FilterDown_max(elemtype *ar, int pos, int end);


#endif