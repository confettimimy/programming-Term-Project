#include <stdio.h>
#include <string.h> // strcmp함수 이용
#include "InfixCalculator.h" //사용자정의 헤더파일
#include "PostCalculator.h" //사용자정의 헤더파일

#pragma warning(disable:4996)

int main(void)
{

	/* 예시 연산식 */
	char exp1[20] = "3+7*2-4/3";
	char exp2[20] = "8*5+5-2/7-3";
	char exp3[20] = "7*8/3+7-4+4*5-3"; 

	char exp[20] = " "; // 사용자로부터 입력 받을 문자열 수식 변수




	/* 예시 연산식 결과 출력하여 보여주기 */
	printf("(1) %s = %d \n", exp1, EvalInfixExp(exp1));
	printf("(2) %s = %d \n", exp2, EvalInfixExp(exp2));
	printf("(3) %s = %d \n", exp3, EvalInfixExp(exp3));




	// 종료 안내 문구
	printf("\n\n\n * 특수문자 @를 입력하면 계산기 프로그램이 종료됩니다. \n");

	while (1) // 연속적으로 계산기 작동하도록 하기
	{

		if (strcmp(exp, "@") == 0) // 특수 문자를 입력하면 루프를 빠져나온다.
			break;


		printf("\n\n 수식을 입력하세요. 위와 같이 계산해드리겠습니다. (ex) 5+2/7 : ");
		scanf("%s", &exp);

		printf(" %s = %d \n", exp, EvalInfixExp(exp)); //함수 호출하여 계산

	}

	
	return 0;
}
