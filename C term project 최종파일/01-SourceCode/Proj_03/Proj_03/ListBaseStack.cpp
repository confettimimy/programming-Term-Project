#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

#pragma warning(disable:4996)

void StackInit(Stack * pstack)
{
	pstack->head = NULL; // ������ ���� head�� NULL�� �ʱ�ȭ�Ѵ�
}

int SIsEmpty(Stack * pstack)
{
	if (pstack->head == NULL) // ������ ��� head���� NULL�� ����ȴ�
		return TRUE;
	else
		return FALSE;
}

/* ����Ʈ�� �Ӹ��� �� ��带 �߰��ϴ� �Լ� */
void SPush(Stack * pstack, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node)); // �� ��� ����

	newNode->data = data; // �� ��忡 ������ ����
	newNode->next = pstack->head; // �� ��尡 �ֱٿ� �߰��� ��带 ����Ŵ

	pstack->head = newNode; // ������ ���� head�� �� ��带 ����Ŵ
}

/* ������ ���� head�� ����Ű�� ��带 �Ҹ��Ű��, �Ҹ�� ����� �����͸� ��ȯ�ϴ� �Լ� */
Data SPop(Stack * pstack)
{
	Data rdata;
	Node * rnode;

	if (SIsEmpty(pstack)) // ������ ����ִٸ�,
	{
		printf(" Stack Memory Error!\n");
		exit(-1);
	}

	rdata = pstack->head->data; // ������ ����� �����͸� �ӽ÷� ����
	rnode = pstack->head; // ������ ����� �ּ� ���� �ӽ÷� ����

	pstack->head = pstack->head->next; // ������ ����� ���� ��带 head�� ����Ŵ
	free(rnode); // ��� ����

	return rdata; // ������ ����� ������ ��ȯ
}

Data SPeek(Stack * pstack)
{
	if (SIsEmpty(pstack))
	{
		printf(" Stack Memory Error!\n");
		exit(-1);
	}

	return pstack->head->data; // head�� ����Ű�� ��忡 ����� ������ ��ȯ!!!
}