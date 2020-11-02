#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

#pragma warning(disable:4996)




int EvalRPNExp(char exp[])  /* 후위 표기법의 수식을 계산하여 그 결과를 반환하는 함수 */
{
	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;

	StackInit(&stack);


	for (i = 0; i < expLen; i++) // 수식을 구성하는 문자 각각을 대상으로 반복!!!
	{
		tok = exp[i]; // tok에 한 문자씩 저장

		if (isdigit(tok)) // 문자의 내용이 정수이면,
		{
			SPush(&stack, tok - '0');     // 숫자로 변환하여 스택에 PUSH !
		}
		else // 정수가 아닌 연산자라면,
		{
			// 먼저 꺼낸 값이 두 번째 피연산자!
			op2 = SPop(&stack); // 스택에서 두 번째 연산자 꺼낸다
			op1 = SPop(&stack); // 스택에서 첫 번째 연산자 꺼낸다

			switch (tok) // 연산하고 그 결과를 다시 스택에 PUSH !
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
	return SPop(&stack); // 마지막 연산 결과를 스택에서 꺼내어 반환

}
