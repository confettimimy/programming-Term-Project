#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

#pragma warning(disable:4996)


int GetOpPrec(char op) /* �������� ���� �켱���� ������ ��ȯ�Ѵ� */
{
	switch (op)
	{
	
	     case '*':
		 case '/':
			 return 5; // �켱������ ���� ����� ������
		 case '+':
		 case '-':
			 return 3; // �켱������ ���� ����� ������

	}

	return -1;   // ��ϵ��� ���� ������
}


/* GetOpPrec �Լ��� ȣ������ �������� �� �������� �켱������ ���Ͽ�, �� ����� ��ȯ�ϴ� �Լ� */
int WhoPrecOp(char op1, char op2) 
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec) // op1�� �켱������ �� ���ٸ�
		return 1;
	else if (op1Prec < op2Prec) // op2�� �켱������ �� ���ٸ�
		return -1;
	else // op1�� op2�� �켱������ ���ٸ�
		return 0;
}


/* ���� ǥ��������� ��ȯ�� ����ϴ� �Լ� ((hightlight)) */
void ConvToRPNExp(char exp[])
{


	Stack stack;
	int expLen = strlen(exp); // �迭 ����� ���� ��ȯ���ִ� �Լ�
	char * convExp = (char*)malloc(expLen + 1);

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char)*expLen + 1); // conExp�� �ʱ�ȭ�ϰ��� �ϴ� ù �ּҸ� �ǹ�
	StackInit(&stack); // �ʱ�ȭ �Ѵ�




	for (i = 0; i < expLen; i++)
	{
		tok = exp[i]; // exp�� ���޵� ������ �� ���ھ� tok�� ����


		if (isdigit(tok)) // tok�� ����� ���ڰ� �����̸�,
		{
			convExp[idx++] = tok; // �迭 conExp�� �׳� ����
		}
		else // tok�� ����� ���ڰ� ���ڰ� �ƴ϶��,
		{
			switch (tok)
			{
			
			case '+': case '-': 
			case '*': case '/':
				while (!SIsEmpty(&stack) &&
					WhoPrecOp(SPeek(&stack), tok) >= 0)
					convExp[idx++] = SPop(&stack);

				SPush(&stack, tok);
				break;
			}
		}


	}

	while (!SIsEmpty(&stack)) // ���ÿ� �����Ͱ� �����ִٸ�, ���ÿ� ���� �ִ� ��� �����ڸ�
		convExp[idx++] = SPop(&stack); // �迭 conExp�� �̵��Ѵ�

	strcpy(exp, convExp); // ��ȯ�� ������ exp�� �����ϰ�
	free(convExp); // conExp�� �Ҹ��Ų��



}