#include <stdio.h>


// �Լ� ����
double BMI_calculate(double weight, double height); 
void BMI_evaluate(double BMI);

int main()
{

	double weight_in_kilograms, height_in_meters; // ����, Ű
	double BMI; //BMI��



	printf("Write your Weight(kg): ");
	scanf_s("%lf", &weight_in_kilograms ); // ����ڷκ��� kg������ ���Ը� �Է� �޵��� �Ѵ�.

	printf("Write your Height(cm): "); 
	scanf_s("%lf", &height_in_meters ); // ����ڷκ��� cm������ Ű�� �Է� �޵��� �Ѵ�.
	height_in_meters = height_in_meters / 100; // ����ڿ��� �ͼ��� ������ cm�� �Է� �޾�����, m������ �ٲ��־�� �Ѵ�.



	printf("\n\n\n======================================================\n");
	BMI = BMI_calculate(weight_in_kilograms, height_in_meters); // BMI���� ������ִ� �Լ� ȣ��. ��ȯ�� ������� ���� BMI�� ����.
	printf("Your BMI value is '%lf'.\n", BMI); // BMI ��ġ ���

	BMI_evaluate(BMI); // BMI ��ġ�� ��� ������ ���ԵǴ��� ���Ͽ� ���
	printf("\n======================================================\n\n\n");



	// ����� �ε��� �����
	printf("< Reference for BMI Values > \n");
	printf("Underweight:  less than 18.5 \n");
	printf("Normal:       between 18.5 and 24.9 \n");
	printf("Overweight:   between 25 and 29.9 \n");
	printf("Obese:        30 or greater \n");



	return 0;
}

double BMI_calculate(double weight, double height) // BMI ��ġ ���� ����Ͽ� �� ������� ��ȯ�ϴ� �Լ� ����
{
	double BMI; 

	BMI = weight / ( height*height ); // BMI ���� ����ϴ� ����

	return BMI;

}

void BMI_evaluate(double BMI) // �ش� BMI ��ġ�� ��� index�� ���ϴ��� ����Ͽ� �˷��ִ� �Լ� ����
{

	if (BMI < 18.5)
	{
		printf("You are in Underweight.");
	}
	else if ( (BMI>=18.5) && (BMI<=24.9) )
	{
		printf("You are in Normal.");
	}
	else if ( (BMI>=25) && (BMI<=29.9) ) 
	{
		printf("You are in Overweight.");
	}
	else if (BMI >= 30)
	{
		printf("You are in Obese.");
	}
	

}
