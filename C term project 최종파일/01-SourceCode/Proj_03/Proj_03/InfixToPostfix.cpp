#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

#pragma warning(disable:4996)


int GetOpPrec(char op) /* 연산자의 연산 우선순위 정보를 반환한다 */
{
	switch (op)
	{
	
	     case '*':
		 case '/':
			 return 5; // 우선순위가 높은 경우의 연산자
		 case '+':
		 case '-':
			 return 3; // 우선순위가 낮은 경우의 연산자

	}

	return -1;   // 등록되지 않은 연산자
}


/* GetOpPrec 함수의 호출결과를 바탕으로 두 연산자의 우선순위를 비교하여, 그 결과를 반환하는 함수 */
int WhoPrecOp(char op1, char op2) 
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec) // op1의 우선순위가 더 높다면
		return 1;
	else if (op1Prec < op2Prec) // op2의 우선순위가 더 높다면
		return -1;
	else // op1과 op2의 우선순위가 같다면
		return 0;
}


/* 후위 표기법으로의 변환을 담당하는 함수 ((hightlight)) */
void ConvToRPNExp(char exp[])
{


	Stack stack;
	int expLen = strlen(exp); // 배열 요소의 갯를 반환해주는 함수
	char * convExp = (char*)malloc(expLen + 1);

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char)*expLen + 1); // conExp는 초기화하고자 하는 첫 주소를 의미
	StackInit(&stack); // 초기화 한다




	for (i = 0; i < expLen; i++)
	{
		tok = exp[i]; // exp로 전달된 수식을 한 문자씩 tok에 저장


		if (isdigit(tok)) // tok에 저장된 문자가 숫자이면,
		{
			convExp[idx++] = tok; // 배열 conExp에 그냥 저장
		}
		else // tok에 저장된 문자가 숫자가 아니라면,
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

	while (!SIsEmpty(&stack)) // 스택에 데이터가 남아있다면, 스택에 남아 있는 모든 연산자를
		convExp[idx++] = SPop(&stack); // 배열 conExp로 이동한다

	strcpy(exp, convExp); // 변환된 수식을 exp에 복사하고
	free(convExp); // conExp는 소멸시킨다



}