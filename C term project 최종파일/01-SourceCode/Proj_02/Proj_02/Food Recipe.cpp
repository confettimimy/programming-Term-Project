#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 


#define num_of_food 10 // 음식 개수를 10개로 지정

#pragma warning (disable:4996)

void showing_Menu(char list[][30]); // 함수의 원형

struct dish { 

	char a[20]; //문자
	int b; //숫자
	char c[20];//문자
	int d; //숫자
	char e[20];//문자
	int f; //숫자
	char g[20];//문자
	int h; //숫자
	char i[20];//문자

}; // 구조체 선언

int main()
{

	struct dish d[num_of_food]; // 구조체 배열 선언

	char input_FoodName[100]; // 사용자로부터 입력받을  음식이름
	int input_NumPeople; // 사용자로부터 입력받을  음식 먹는 사람 수

	char list_of_foods[num_of_food][30] = { "라면", "알리오올리오", "삶은계란", "간장계란밥", "샐러드",
		                                    "아이스카라멜마끼야또", "베이글샌드위치", "뜨거운돌체라떼",
	                                        "스팸마요덮밥", "카레" }; // 10개의 음식 목록. 이중 문자열 배열




	/*  각 음식의 정보 데이터 입력	*/

	//라면
	strcpy(d[0].a, "- 라면: ");
	d[0].b = 1;
	strcpy(d[0].c, "봉지,\n- 물: ");
	d[0].d = 500;
	strcpy(d[0].e, "ml,\n- 파: ");
	d[0].f = 20;
	strcpy(d[0].g, "grams,\n- 계란: ");
	d[0].h = 1;
	strcpy(d[0].i, "개.\n");

	//알리오올리오
	strcpy(d[1].a, "- 스파게티 면: ");
	d[1].b = 1;
	strcpy(d[1].c, "인분,\n- 물: ");
	d[1].d = 700;
	strcpy(d[1].e, "ml,\n- 올리브유: ");
	d[1].f = 5;
	strcpy(d[1].g, "TS,\n- 통마늘: ");
	d[1].h = 7;
	strcpy(d[1].i, "개.\n");

	//삶은계란
	strcpy(d[2].a, "- 계란: ");
	d[2].b = 5;
	strcpy(d[2].c, "개,\n- 물: ");
	d[2].d = 700;
	strcpy(d[2].e, "ml,\n- 소금: ");
	d[2].f = 1;
	strcpy(d[2].g, "TS,\n- 식초: ");
	d[2].h = 1;
	strcpy(d[2].i, "TS.\n");

	//간장계란밥
	strcpy(d[3].a, "- 계란: ");
	d[3].b = 2;
	strcpy(d[3].c, "개,\n- 간장: ");
	d[3].d = 1;
	strcpy(d[3].e, "TS,\n- 참기름: ");
	d[3].f = 1;
	strcpy(d[3].g, "TS,\n- 밥: ");
	d[3].h = 1;
	strcpy(d[3].i, "공기.\n");

	//샐러드
	strcpy(d[4].a, "- 양배추: ");
	d[4].b = 4;
	strcpy(d[4].c, "장,\n- 딸기: ");
	d[4].d = 13;
	strcpy(d[4].e, "개,\n- 크림치즈: ");
	d[4].f = 100;
	strcpy(d[4].g, "g,\n- 오리엔탈소스: ");
	d[4].h = 20;
	strcpy(d[4].i, "ml.\n");

	//아이스카라멜마끼야또
	strcpy(d[5].a, "- 우유: ");
	d[5].b = 500;
	strcpy(d[5].c, "ml,\n- 에스프레소: ");
	d[5].d = 2;
	strcpy(d[5].e, "샷,\n- 카라멜시럽: ");
	d[5].f = 1;
	strcpy(d[5].g, "펌프,\n- 얼음: ");
	d[5].h = 7;
	strcpy(d[5].i, "개.\n");

	//베이글샌드위치
	strcpy(d[6].a, "- 베이글: ");
	d[6].b = 1;
	strcpy(d[6].c, "개,\n- 크림치즈: ");
	d[6].d = 30;
	strcpy(d[6].e, "g,\n- 슬라이스햄: ");
	d[6].f = 1;
	strcpy(d[6].g, "장,\n- 양상추: ");
	d[6].h = 1;
	strcpy(d[6].i, "장.\n");

	//뜨거운돌체라떼
	strcpy(d[7].a, "- 스팀우유: ");
	d[7].b = 500;
	strcpy(d[7].c, "ml,\n- 에스프레소: ");
	d[7].d = 2;
	strcpy(d[7].e, "샷,\n- 연유: ");
	d[7].f = 20;
	strcpy(d[7].g, "g,\n- 시럽: ");
	d[7].h = 1;
	strcpy(d[7].i, "펌프.\n");

	//스팸마요덮밥
	strcpy(d[8].a, "- 밥: ");
	d[8].b = 1;
	strcpy(d[8].c, "공기,\n- 스팸: ");
	d[8].d = 100;
	strcpy(d[8].e, "g,\n- 마요네즈: ");
	d[8].f = 50;
	strcpy(d[8].g, "g,\n- 간장: ");
	d[8].h = 1;
	strcpy(d[8].i, "TS.\n");

	//카레
	strcpy(d[9].a, "- 카레가루: ");
	d[9].b = 50;
	strcpy(d[9].c, "g,\n- 감자: ");
	d[9].d = 1;
	strcpy(d[9].e, "개,\n- 당근: ");
	d[9].f = 1;
	strcpy(d[9].g, "개,\n- 돼지고기: ");
	d[9].h = 100;
	strcpy(d[9].i, "g.\n");









	showing_Menu(list_of_foods); // 메뉴판 보여주는 함수 호출









	printf("\n\n\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" Insert Food Name (by Hangeul):  ");
	scanf_s("%s", &input_FoodName, 30 ); // 음식의 이름을 입력받기
	printf(" How many people:  ");
	scanf_s("%d", &input_NumPeople); //음식을 몇 명이서 먹을지 입력받기




	
	
	
	if ( strcmp(input_FoodName, "라면") == 0 ) // 사용자가 '라면'을 입력했다면
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[0].a, input_NumPeople*d[0].b, d[0].c, input_NumPeople*d[0].d, d[0].e,
			input_NumPeople*d[0].f, d[0].g, input_NumPeople*d[0].h, d[0].i); 

	}
	else if( strcmp(input_FoodName, "알리오올리오") == 0 ) // 사용자가 '알리오올리오'를 입력했다면
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[1].a, input_NumPeople*d[1].b, d[1].c, input_NumPeople*d[1].d, d[1].e,
			input_NumPeople*d[1].f, d[1].g, input_NumPeople*d[1].h, d[1].i); 

	}
	else if (strcmp(input_FoodName, "삶은계란") == 0) // 사용자가 '삶은계란'을 입력했다면
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[2].a, input_NumPeople*d[2].b, d[2].c, input_NumPeople*d[2].d, d[2].e,
			input_NumPeople*d[2].f, d[2].g, input_NumPeople*d[2].h, d[2].i); 

	}
	else if (strcmp(input_FoodName, "간장계란밥") == 0) // 사용자가 '간장계란밥'을 입력했다면
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[3].a, input_NumPeople*d[3].b, d[3].c, input_NumPeople*d[3].d, d[3].e,
			input_NumPeople*d[3].f, d[3].g, input_NumPeople*d[3].h, d[3].i); 

	}
	else if (strcmp(input_FoodName, "샐러드") == 0) // 사용자가 '샐러드'를 입력했다면
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[4].a, input_NumPeople*d[4].b, d[4].c, input_NumPeople*d[4].d, d[4].e,
			input_NumPeople*d[4].f, d[4].g, input_NumPeople*d[4].h, d[4].i); 

	}
	else if (strcmp(input_FoodName, "아이스카라멜마끼야또") == 0) // 사용자가 '아이스카라멜마끼야또'를 입력했다면
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[5].a, input_NumPeople*d[5].b, d[5].c, input_NumPeople*d[5].d, d[5].e,
			input_NumPeople*d[5].f, d[5].g, input_NumPeople*d[5].h, d[5].i); 

	}
	else if (strcmp(input_FoodName, "베이글샌드위치") == 0) // 사용자가 '베이글샌드위치'를 입력했다면
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[6].a, input_NumPeople*d[6].b, d[6].c, input_NumPeople*d[6].d, d[6].e,
			input_NumPeople*d[6].f, d[6].g, input_NumPeople*d[6].h, d[6].i); 

	}
	else if (strcmp(input_FoodName, "뜨거운돌체라떼") == 0) // 사용자가 '뜨거운돌체라떼'를 입력했다면
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[7].a, input_NumPeople*d[7].b, d[7].c, input_NumPeople*d[7].d, d[7].e,
			input_NumPeople*d[7].f, d[7].g, input_NumPeople*d[7].h, d[7].i); 

	}
	else if (strcmp(input_FoodName, "스팸마요덮밥") == 0) // 사용자가 '스팸마요덮밥'을 입력했다면
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[8].a, input_NumPeople*d[8].b, d[8].c, input_NumPeople*d[8].d, d[8].e,
			input_NumPeople*d[8].f, d[8].g, input_NumPeople*d[8].h, d[8].i); 

	}
	else if (strcmp(input_FoodName, "카레") == 0) // 사용자가 '카레'를 입력했다면
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[9].a, input_NumPeople*d[9].b, d[9].c, input_NumPeople*d[9].d, d[9].e,
			input_NumPeople*d[9].f, d[9].g, input_NumPeople*d[9].h, d[9].i); 

	}
	else // 잘못된 음식 이름 값을 입력받았다면
	{
		printf("음식 이름을 잘못 입력하셨습니다. \n");
	}
	

	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n");







	return 0;

}

void showing_Menu(char list[][30]) // 메뉴판을 출력하여 보여주는 함수 정의
{

	printf("-------------------------\n");
	printf("           MENU          \n");
	printf("-------------------------\n");

	for (int m = 0; m < num_of_food; m++)
	{
		printf(" %23s \n", list[m]);
	}


}