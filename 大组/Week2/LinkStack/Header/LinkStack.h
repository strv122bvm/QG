#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//��ջ
//��ʼ��ջ
Status initLStack(LinkStack* s) {
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	return (s->top == NULL) ? SUCCESS : ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (isEmptyLStack(s) == SUCCESS)
		return ERROR; // Stack is empty
	*e = s->top->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack* s) {
	while (s->top != NULL) {
		LinkStackPtr tmp = s->top;
		s->top = s->top->next;
		free(tmp);
	}
	s->count = 0;
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack* s) {
	clearLStack(s);
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) {
	*length = s->count;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data) {
	LinkStackPtr newNode = (LinkStackPtr)malloc(sizeof(StackNode));
	if (newNode == NULL)
		return ERROR; // Memory allocation failed
	newNode->data = data;
	newNode->next = s->top;
	s->top = newNode;
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* data) {
	if (isEmptyLStack(s) == SUCCESS)
		return ERROR; // Stack is empty
	LinkStackPtr tmp = s->top;
	*data = tmp->data;
	s->top = tmp->next;
	free(tmp);
	s->count--;
	return SUCCESS;
}


#endif 
