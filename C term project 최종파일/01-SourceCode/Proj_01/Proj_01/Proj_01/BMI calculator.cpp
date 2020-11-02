#include <stdio.h>

//보고서 쓸때!  오류 왜났었는가? BMI값을 사용자에게 보여주기 위해 프린트할때 형식지정자를 %lf를 해야할거를 %d로 하였다. 아주 미세한 데에서 ..그래서 원하는 bmi결과값이 나오지 않았었다!
// 대략 한 시간 좀 넘게 무난하게 풀어냈다. 
// 그런데 함수호출 참조에 의한 호출로 해야하는지??? 의문이다!! 

double BMI_calculator(double weight, double height);
void BMI_evaluation(double BMI);

int main()
{

	double weight_in_kilograms, height_in_meters; //무게, 키
	double BMI; //BMI값



	printf("Write your Weight(kg): ");
	scanf_s("%lf", &weight_in_kilograms );

	printf("Write your Height(cm): "); //사용자에게 익숙한 단위로 받도록 한다.
	scanf_s("%lf", &height_in_meters ); 
	height_in_meters = height_in_meters / 100; //사용자로부터 cm단위로 입력 받았으니, m단위로 바꿔주어야 한다.



	printf("\n\n\n======================================================\n");
	BMI = BMI_calculator(weight_in_kilograms, height_in_meters); //BMI계산
	printf("Your BMI value is '%lf'.\n", BMI);

	BMI_evaluation(BMI);//BMI가 어느 범위에 포함되는지 평가
	printf("\n======================================================\n\n\n");



	printf("< Reference for BMI Values > \n");
	printf("Underweight:  less than 18.5 \n");
	printf("Normal:       between 18.5 and 24.9 \n");
	printf("Overweight:   between 25 and 29.9 \n");
	printf("Obese:        30 or greater \n");



	return 0;

}

double BMI_calculator(double weight, double height) //신장은 여기서 미터 기준. 미터로 받아야함.
{
	double BMI; //메인함수에서의 BMI변수와 이름은 똑같지만, 둘은 사실 다른 메모리 영역에 위치하고 있어 엄연히 다른 변수이다.

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
