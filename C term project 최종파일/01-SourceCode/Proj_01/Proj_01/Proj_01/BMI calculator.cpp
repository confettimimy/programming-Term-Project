#include <stdio.h>

//���� ����!  ���� �ֳ����°�? BMI���� ����ڿ��� �����ֱ� ���� ����Ʈ�Ҷ� ���������ڸ� %lf�� �ؾ��ҰŸ� %d�� �Ͽ���. ���� �̼��� ������ ..�׷��� ���ϴ� bmi������� ������ �ʾҾ���!
// �뷫 �� �ð� �� �Ѱ� �����ϰ� Ǯ��´�. 
// �׷��� �Լ�ȣ�� ������ ���� ȣ��� �ؾ��ϴ���??? �ǹ��̴�!! 

double BMI_calculator(double weight, double height);
void BMI_evaluation(double BMI);

int main()
{

	double weight_in_kilograms, height_in_meters; //����, Ű
	double BMI; //BMI��



	printf("Write your Weight(kg): ");
	scanf_s("%lf", &weight_in_kilograms );

	printf("Write your Height(cm): "); //����ڿ��� �ͼ��� ������ �޵��� �Ѵ�.
	scanf_s("%lf", &height_in_meters ); 
	height_in_meters = height_in_meters / 100; //����ڷκ��� cm������ �Է� �޾�����, m������ �ٲ��־�� �Ѵ�.



	printf("\n\n\n======================================================\n");
	BMI = BMI_calculator(weight_in_kilograms, height_in_meters); //BMI���
	printf("Your BMI value is '%lf'.\n", BMI);

	BMI_evaluation(BMI);//BMI�� ��� ������ ���ԵǴ��� ��
	printf("\n======================================================\n\n\n");



	printf("< Reference for BMI Values > \n");
	printf("Underweight:  less than 18.5 \n");
	printf("Normal:       between 18.5 and 24.9 \n");
	printf("Overweight:   between 25 and 29.9 \n");
	printf("Obese:        30 or greater \n");



	return 0;

}

double BMI_calculator(double weight, double height) //������ ���⼭ ���� ����. ���ͷ� �޾ƾ���.
{
	double BMI; //�����Լ������� BMI������ �̸��� �Ȱ�����, ���� ��� �ٸ� �޸� ������ ��ġ�ϰ� �־� ������ �ٸ� �����̴�.

	BMI = weight / ( height*height );

	return BMI;

}

void BMI_evaluation(double BMI)
{

	if (BMI < 18.5)
	{
		printf("You are in Underweight.");
	}
	else if (18.5 <= BMI <= 24.9)
	{
		printf("You are in Normal.");
	}
	else if (25 <= BMI <= 29.9) 
	{
		printf("You are in Overweight.");
	}
	else if (BMI >= 30)
	{
		printf("You are in Obese.");
	}
	

}
