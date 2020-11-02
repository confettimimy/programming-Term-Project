#include <stdio.h>


// 함수 원형
double BMI_calculate(double weight, double height); 
void BMI_evaluate(double BMI);

int main()
{

	double weight_in_kilograms, height_in_meters; // 무게, 키
	double BMI; //BMI값



	printf("Write your Weight(kg): ");
	scanf_s("%lf", &weight_in_kilograms ); // 사용자로부터 kg단위로 무게를 입력 받도록 한다.

	printf("Write your Height(cm): "); 
	scanf_s("%lf", &height_in_meters ); // 사용자로부터 cm단위로 키를 입력 받도록 한다.
	height_in_meters = height_in_meters / 100; // 사용자에게 익숙한 단위인 cm로 입력 받았으니, m단위로 바꿔주어야 한다.



	printf("\n\n\n======================================================\n");
	BMI = BMI_calculate(weight_in_kilograms, height_in_meters); // BMI값을 계산해주는 함수 호출. 반환된 결과값을 변수 BMI에 대입.
	printf("Your BMI value is '%lf'.\n", BMI); // BMI 수치 출력

	BMI_evaluate(BMI); // BMI 수치가 어느 범위에 포함되는지 평가하여 출력
	printf("\n======================================================\n\n\n");



	// 사용자 인덱스 참고용
	printf("< Reference for BMI Values > \n");
	printf("Underweight:  less than 18.5 \n");
	printf("Normal:       between 18.5 and 24.9 \n");
	printf("Overweight:   between 25 and 29.9 \n");
	printf("Obese:        30 or greater \n");



	return 0;
}

double BMI_calculate(double weight, double height) // BMI 수치 값을 계산하여 그 결과값을 반환하는 함수 정의
{
	double BMI; 

	BMI = weight / ( height*height ); // BMI 값을 계산하는 수식

	return BMI;

}

void BMI_evaluate(double BMI) // 해당 BMI 수치가 어느 index에 속하는지 출력하여 알려주는 함수 정의
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
