#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h" // ConvToRPNExp 함수의 호출을 위해
#include "PostCalculator.h" // EvalRPNExp 함수의 호출을 위해

#pragma warning(disable:4996)

int EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;

	char * expcpy = (char*)malloc(len + 1); // 문자열 저장 공간 동적으로 할당
	strcpy(expcpy, exp); // exp를 expcpy에 복사


	ConvToRPNExp(expcpy); // 후위 표기법의 수식으로 변환
	ret = EvalRPNExp(expcpy); // 후위표기법 수식 계산

	free(expcpy); // 문자열 저장공간 해제

	return ret; // 계산결과 반환하기
}

