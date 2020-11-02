#include <stdio.h>
#include <string.h> // strcmp�Լ� �̿�
#include "InfixCalculator.h" //��������� �������
#include "PostCalculator.h" //��������� �������

#pragma warning(disable:4996)

int main(void)
{

	/* ���� ����� */
	char exp1[20] = "3+7*2-4/3";
	char exp2[20] = "8*5+5-2/7-3";
	char exp3[20] = "7*8/3+7-4+4*5-3"; 

	char exp[20] = " "; // ����ڷκ��� �Է� ���� ���ڿ� ���� ����




	/* ���� ����� ��� ����Ͽ� �����ֱ� */
	printf("(1) %s = %d \n", exp1, EvalInfixExp(exp1));
	printf("(2) %s = %d \n", exp2, EvalInfixExp(exp2));
	printf("(3) %s = %d \n", exp3, EvalInfixExp(exp3));




	// ���� �ȳ� ����
	printf("\n\n\n * Ư������ @�� �Է��ϸ� ���� ���α׷��� ����˴ϴ�. \n");

	while (1) // ���������� ���� �۵��ϵ��� �ϱ�
	{

		if (strcmp(exp, "@") == 0) // Ư�� ���ڸ� �Է��ϸ� ������ �������´�.
			break;


		printf("\n\n ������ �Է��ϼ���. ���� ���� ����ص帮�ڽ��ϴ�. (ex) 5+2/7 : ");
		scanf("%s", &exp);

		printf(" %s = %d \n", exp, EvalInfixExp(exp)); //�Լ� ȣ���Ͽ� ���

	}

	
	return 0;
}
