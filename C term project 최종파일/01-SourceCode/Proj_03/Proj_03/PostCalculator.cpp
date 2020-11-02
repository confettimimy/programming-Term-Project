#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

#pragma warning(disable:4996)




int EvalRPNExp(char exp[])  /* ���� ǥ����� ������ ����Ͽ� �� ����� ��ȯ�ϴ� �Լ� */
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);


	for (i = 0; i < expLen; i++) // ������ �����ϴ� ���� ������ ������� �ݺ�!!!
	{
		tok = exp[i]; // tok�� �� ���ھ� ����

		if (isdigit(tok)) // ������ ������ �����̸�,
		{
			SPush(&stack, tok - '0');     // ���ڷ� ��ȯ�Ͽ� ���ÿ� PUSH !
		}
		else // ������ �ƴ� �����ڶ��,
		{
			// ���� ���� ���� �� ��° �ǿ�����!
			op2 = SPop(&stack); // ���ÿ��� �� ��° ������ ������
			op1 = SPop(&stack); // ���ÿ��� ù ��° ������ ������

			switch (tok) // �����ϰ� �� ����� �ٽ� ���ÿ� PUSH !
			{
		    	case '+':
				   SPush(&stack, op1 + op2);
				   break;
		    	case '-':
			    	SPush(&stack, op1 - op2);
			    	break;
			    case '*':
				    SPush(&stack, op1*op2);
				    break;
			    case '/':
				   SPush(&stack, op1 / op2);
				   break;
			}
		}
	}
	return SPop(&stack); // ������ ���� ����� ���ÿ��� ������ ��ȯ

}
