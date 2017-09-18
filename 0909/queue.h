#ifndef QUEUE_H
#define QUEUE_H


#include "bt.h"
/*
��α����õ�  ����
*/
typedef struct{
	bt_node * data[MAX];
	int front;//ͷָ��
	int rear;
}sq_queue;

void init_squeue(sq_queue *q);
int lenth_squeue(sq_queue *q);
bool in_squeue(sq_queue *q, bt_node *val);
bt_node * out_squeue(sq_queue *q);

#endif