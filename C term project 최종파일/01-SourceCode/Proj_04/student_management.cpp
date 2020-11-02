#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

#define student_num 10


struct student {

	char name[10]; //성명
	char sex[3]; //성별
	int age; //나이
	char PhoneNumber[12]; //전화번호
	char university[30]; //학교명
	int score_Korea; //국어점수
	int score_English; //영어점수
	int score_Math; //수학점수 
	int score_Science; //과학점수

};


int main()
{

	struct student s[student_num];

	/* 정렬 시 사용할 임시변수들 */
	char tstring[15]; //긴 문자열을 저장해놓기 위한 임시변수
	char tchar[3]; //상대적으로 짧은 문자열을 저장해놓기 위한 임시변수
	int tint; //숫자를 저장 해놓기 위한 임시변수
	int tscores; //숫자형인 점수를 저장해놓기 위한 임시변수
	
	int i;

	int criterion_Number = 0; //사용자로부터 입력받는 기준 항목 번호







	FILE *fp;
	fp = fopen("10 students' information.txt", "a+"); //텍스트 파일 추가모드로 열기


	if (fp == NULL)
	{
		printf("이 파일은 존재하지 않습니다.\n");
	} //예외 처리







	// 파일에 입력된 데이터 읽어오기
	for(i = 0; i < student_num; i++)
		fscanf(fp, "%s %s %d %s %s %d %d %d %d \n",
			        &s[i].name, &s[i].sex, &s[i].age, &s[i].PhoneNumber, &s[i].university, &s[i].score_Korea, &s[i].score_English, &s[i].score_Math, &s[i].score_Science);
	

	// 텍스트파일에 있는 데이터들을 잘 읽어왔는지 확인해보기 위해 실행결과 화면에 출력해보기
	printf("              [ Original form ]              \n\n");
	for (i = 0; i < student_num; i++) { 
		printf("%s %s %d %s %s %d %d %d %d \n",
			s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
	}







	while (1)   
	{  // 루프를 돌려 사용자로부터 계속해서 기준 항목 번호를 입력받는다.
       // 항목 번호를 입력 받을 때마다 그 주어진 번호를 중심으로 정렬한 모습을 보여준다. 


		if (criterion_Number == 2) // 루프를 빠져나가고 싶다면 2를 입력하면 된다.
			break; 

		printf("\n\n\n\n (더이상 정렬을 원하지 않는다면 2를 입력)\n");

		printf(" 2번을 제외한 8개 항목 번호 중 하나의 번호를 입력하세요. 주어진 번호를 중심으로 정렬해드리겠습니다. -> "); //사용자로부터 기준 번호 입력받기
		scanf("%d", &criterion_Number);






		if (criterion_Number == 1) { //사용자가 '(1)성명' 기준으로 정렬을 원한다면,
			


			// ********** (1) 이름 순 정렬 **********

			for (int i = 0; i < student_num; i++)//이름순으로 정렬하기 
			{
				for (int j = i; j < student_num; j++)
				{
					if (strcmp(s[i].name, s[j].name) > 0) //후자가 더 크다
					{
						strcpy(tstring, s[j].name);
						strcpy(s[j].name, s[i].name);
						strcpy(s[i].name, tstring);

						strcpy(tchar, s[j].sex);
						strcpy(s[j].sex, s[i].sex);
						strcpy(s[i].sex, tchar);

						tint = s[j].age;
						s[j].age = s[i].age;
						s[i].age = tint;


						strcpy(tstring, s[j].PhoneNumber);
						strcpy(s[j].PhoneNumber, s[i].PhoneNumber);
						strcpy(s[i].PhoneNumber, tstring);


						//s[i].university
						strcpy(tstring, s[j].university);
						strcpy(s[j].university, s[i].university);
						strcpy(s[i].university, tstring);

						tscores = s[j].score_Korea;   //s[i].score_Korea
						s[j].score_Korea = s[i].score_Korea;
						s[i].score_Korea = tscores;

						tscores = s[j].score_English;   //s[i].score_English
						s[j].score_English = s[i].score_English;
						s[i].score_English = tscores;

						tscores = s[j].score_Math;   //s[i].score_Math
						s[j].score_Math = s[i].score_Math;
						s[i].score_Math = tscores;

						tscores = s[j].score_Science;   //s[j].score_Science
						s[j].score_Science = s[i].score_Science;
						s[i].score_Science = tscores;
					}
				}

			}


			// 실행 결과화면에 이름 순으로 정렬된 모습 출력.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Name' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// 파일로도 출력하기!
			fprintf(fp, "\n\n\n\n\n  @@@ Let's sort  based on various criteria !!!!!! @@@  \n");
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Name' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


		}
		else if (criterion_Number == 3) { //사용자가 ' (3)나이' 기준으로 정렬을 원한다면,



			// ********** (3) 나이 순 정렬 **********

			for (int i = 0; i < student_num; i++)
			{
				for (int j = i; j < student_num; j++)
				{
					if (s[i].age > s[j].age)
					{
						strcpy(tstring, s[j].name);
						strcpy(s[j].name, s[i].name);
						strcpy(s[i].name, tstring);

						strcpy(tchar, s[j].sex);
						strcpy(s[j].sex, s[i].sex);
						strcpy(s[i].sex, tchar);

						tint = s[j].age;
						s[j].age = s[i].age;
						s[i].age = tint;


						strcpy(tstring, s[j].PhoneNumber);
						strcpy(s[j].PhoneNumber, s[i].PhoneNumber);
						strcpy(s[i].PhoneNumber, tstring);


						//s[i].university
						strcpy(tstring, s[j].university);
						strcpy(s[j].university, s[i].university);
						strcpy(s[i].university, tstring);

						tscores = s[j].score_Korea;   //s[i].score_Korea
						s[j].score_Korea = s[i].score_Korea;
						s[i].score_Korea = tscores;

						tscores = s[j].score_English;   //s[i].score_English
						s[j].score_English = s[i].score_English;
						s[i].score_English = tscores;

						tscores = s[j].score_Math;   //s[i].score_Math
						s[j].score_Math = s[i].score_Math;
						s[i].score_Math = tscores;

						tscores = s[j].score_Science;   //s[j].score_Science
						s[j].score_Science = s[i].score_Science;
						s[i].score_Science = tscores;
					}
				}

			}


			// 실행 결과화면에 나이 순으로 정렬된 모습 출력.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Age' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// 파일로도 출력하기!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Age' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}

		}
		else if (criterion_Number == 4) { //사용자가 '(4)전화번호' 기준으로 정렬을 원한다면,
		


			// ********** (4) 전화번호 순 정렬 **********

			for (int i = 0; i < student_num; i++)
			{
				for (int j = i; j < student_num; j++)
				{
					if (strcmp(s[i].PhoneNumber, s[j].PhoneNumber) > 0)
					{
						strcpy(tstring, s[j].name);
						strcpy(s[j].name, s[i].name);
						strcpy(s[i].name, tstring);

						strcpy(tchar, s[j].sex);
						strcpy(s[j].sex, s[i].sex);
						strcpy(s[i].sex, tchar);

						tint = s[j].age;
						s[j].age = s[i].age;
						s[i].age = tint;


						strcpy(tstring, s[j].PhoneNumber);
						strcpy(s[j].PhoneNumber, s[i].PhoneNumber);
						strcpy(s[i].PhoneNumber, tstring);


						//s[i].university
						strcpy(tstring, s[j].university);
						strcpy(s[j].university, s[i].university);
						strcpy(s[i].university, tstring);

						tscores = s[j].score_Korea;   //s[i].score_Korea
						s[j].score_Korea = s[i].score_Korea;
						s[i].score_Korea = tscores;

						tscores = s[j].score_English;   //s[i].score_English
						s[j].score_English = s[i].score_English;
						s[i].score_English = tscores;

						tscores = s[j].score_Math;   //s[i].score_Math
						s[j].score_Math = s[i].score_Math;
						s[i].score_Math = tscores;

						tscores = s[j].score_Science;   //s[j].score_Science
						s[j].score_Science = s[i].score_Science;
						s[i].score_Science = tscores;
					}
				}

			}


			// 실행 결과화면에 전화번호 순으로 정렬된 모습 출력.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Phone Number' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// 파일로도 출력하기!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Phone Number' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


		}
		else if (criterion_Number == 5) { //사용자가 '(5)학교명' 기준으로 정렬을 원한다면,



			// ********** (5) 학교명 순 정렬 **********

			for (int i = 0; i < student_num; i++)
			{
				for (int j = i; j < student_num; j++)
				{
					if (strcmp(s[i].university, s[j].university) > 0)
					{
						strcpy(tstring, s[j].name);
						strcpy(s[j].name, s[i].name);
						strcpy(s[i].name, tstring);

						strcpy(tchar, s[j].sex);
						strcpy(s[j].sex, s[i].sex);
						strcpy(s[i].sex, tchar);

						tint = s[j].age;
						s[j].age = s[i].age;
						s[i].age = tint;


						strcpy(tstring, s[j].PhoneNumber);
						strcpy(s[j].PhoneNumber, s[i].PhoneNumber);
						strcpy(s[i].PhoneNumber, tstring);


						//s[i].university
						strcpy(tstring, s[j].university);
						strcpy(s[j].university, s[i].university);
						strcpy(s[i].university, tstring);

						tscores = s[j].score_Korea;   //s[i].score_Korea
						s[j].score_Korea = s[i].score_Korea;
						s[i].score_Korea = tscores;

						tscores = s[j].score_English;   //s[i].score_English
						s[j].score_English = s[i].score_English;
						s[i].score_English = tscores;

						tscores = s[j].score_Math;   //s[i].score_Math
						s[j].score_Math = s[i].score_Math;
						s[i].score_Math = tscores;

						tscores = s[j].score_Science;   //s[j].score_Science
						s[j].score_Science = s[i].score_Science;
						s[i].score_Science = tscores;
					}
				}

			}


			// 실행 결과화면에 학교명 순으로 정렬된 모습 출력.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'University's Name' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// 파일로도 출력하기!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'University's Name' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}

		}
		else if (criterion_Number == 6) { //사용자가 '(6)국어' 기준으로 정렬을 원한다면,



			// ********** (6) 국어성적 순 정렬 **********

			for (int i = 0; i < student_num; i++)
			{
				for (int j = i; j < student_num; j++)
				{
					if (s[i].score_Korea > s[j].score_Korea)
					{
						strcpy(tstring, s[j].name);
						strcpy(s[j].name, s[i].name);
						strcpy(s[i].name, tstring);

						strcpy(tchar, s[j].sex);
						strcpy(s[j].sex, s[i].sex);
						strcpy(s[i].sex, tchar);

						tint = s[j].age;
						s[j].age = s[i].age;
						s[i].age = tint;


						strcpy(tstring, s[j].PhoneNumber);
						strcpy(s[j].PhoneNumber, s[i].PhoneNumber);
						strcpy(s[i].PhoneNumber, tstring);


						//s[i].university
						strcpy(tstring, s[j].university);
						strcpy(s[j].university, s[i].university);
						strcpy(s[i].university, tstring);

						tscores = s[j].score_Korea;   //s[i].score_Korea
						s[j].score_Korea = s[i].score_Korea;
						s[i].score_Korea = tscores;

						tscores = s[j].score_English;   //s[i].score_English
						s[j].score_English = s[i].score_English;
						s[i].score_English = tscores;

						tscores = s[j].score_Math;   //s[i].score_Math
						s[j].score_Math = s[i].score_Math;
						s[i].score_Math = tscores;

						tscores = s[j].score_Science;   //s[j].score_Science
						s[j].score_Science = s[i].score_Science;
						s[i].score_Science = tscores;
					}
				}

			}


			// 실행 결과화면에 국어성적 순으로 정렬된 모습 출력.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Score of Korea' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// 파일로도 출력하기!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Score of Korea' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}

		}
		else if (criterion_Number == 7) { //사용자가 '(7)영어' 기준으로 정렬을 원한다면,



			// ********** (7) 영어성적 순 정렬 **********

			for (int i = 0; i < student_num; i++)
			{
				for (int j = i; j < student_num; j++)
				{
					if (s[i].score_English > s[j].score_English)
					{
						strcpy(tstring, s[j].name);
						strcpy(s[j].name, s[i].name);
						strcpy(s[i].name, tstring);

						strcpy(tchar, s[j].sex);
						strcpy(s[j].sex, s[i].sex);
						strcpy(s[i].sex, tchar);

						tint = s[j].age;
						s[j].age = s[i].age;
						s[i].age = tint;


						strcpy(tstring, s[j].PhoneNumber);
						strcpy(s[j].PhoneNumber, s[i].PhoneNumber);
						strcpy(s[i].PhoneNumber, tstring);


						//s[i].university
						strcpy(tstring, s[j].university);
						strcpy(s[j].university, s[i].university);
						strcpy(s[i].university, tstring);

						tscores = s[j].score_Korea;   //s[i].score_Korea
						s[j].score_Korea = s[i].score_Korea;
						s[i].score_Korea = tscores;

						tscores = s[j].score_English;   //s[i].score_English
						s[j].score_English = s[i].score_English;
						s[i].score_English = tscores;

						tscores = s[j].score_Math;   //s[i].score_Math
						s[j].score_Math = s[i].score_Math;
						s[i].score_Math = tscores;

						tscores = s[j].score_Science;   //s[j].score_Science
						s[j].score_Science = s[i].score_Science;
						s[i].score_Science = tscores;
					}
				}

			}


			// 실행 결과화면에 영어성적 순으로 정렬된 모습 출력.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Score of English' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// 파일로도 출력하기!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Score of English' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}

		}
		else if (criterion_Number == 8) { //사용자가 '(8)수학' 기준으로 정렬을 원한다면,



			// ********** (8) 수학성적 순 정렬 **********

			for (int i = 0; i < student_num; i++)
			{
				for (int j = i; j < student_num; j++)
				{
					if (s[i].score_Math > s[j].score_Math)
					{
						strcpy(tstring, s[j].name);
						strcpy(s[j].name, s[i].name);
						strcpy(s[i].name, tstring);

						strcpy(tchar, s[j].sex);
						strcpy(s[j].sex, s[i].sex);
						strcpy(s[i].sex, tchar);

						tint = s[j].age;
						s[j].age = s[i].age;
						s[i].age = tint;


						strcpy(tstring, s[j].PhoneNumber);
						strcpy(s[j].PhoneNumber, s[i].PhoneNumber);
						strcpy(s[i].PhoneNumber, tstring);


						//s[i].university
						strcpy(tstring, s[j].university);
						strcpy(s[j].university, s[i].university);
						strcpy(s[i].university, tstring);

						tscores = s[j].score_Korea;   //s[i].score_Korea
						s[j].score_Korea = s[i].score_Korea;
						s[i].score_Korea = tscores;

						tscores = s[j].score_English;   //s[i].score_English
						s[j].score_English = s[i].score_English;
						s[i].score_English = tscores;

						tscores = s[j].score_Math;   //s[i].score_Math
						s[j].score_Math = s[i].score_Math;
						s[i].score_Math = tscores;

						tscores = s[j].score_Science;   //s[j].score_Science
						s[j].score_Science = s[i].score_Science;
						s[i].score_Science = tscores;
					}
				}

			}


			// 실행 결과화면에 수학성적 순으로 정렬된 모습 출력.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Score of Math' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// 파일로도 출력하기!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Score of Math' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


		}
		else if (criterion_Number == 9) { //사용자가 '(9)과학' 기준으로 정렬을 원한다면,



			// ********** (9) 과학성적 순 정렬 **********

			for (int i = 0; i < student_num; i++)
			{
				for (int j = i; j < student_num; j++)
				{
					if (s[i].score_Science > s[j].score_Science)
					{
						strcpy(tstring, s[j].name);
						strcpy(s[j].name, s[i].name);
						strcpy(s[i].name, tstring);

						strcpy(tchar, s[j].sex);
						strcpy(s[j].sex, s[i].sex);
						strcpy(s[i].sex, tchar);

						tint = s[j].age;
						s[j].age = s[i].age;
						s[i].age = tint;


						strcpy(tstring, s[j].PhoneNumber);
						strcpy(s[j].PhoneNumber, s[i].PhoneNumber);
						strcpy(s[i].PhoneNumber, tstring);


						//s[i].university
						strcpy(tstring, s[j].university);
						strcpy(s[j].university, s[i].university);
						strcpy(s[i].university, tstring);

						tscores = s[j].score_Korea;   //s[i].score_Korea
						s[j].score_Korea = s[i].score_Korea;
						s[i].score_Korea = tscores;

						tscores = s[j].score_English;   //s[i].score_English
						s[j].score_English = s[i].score_English;
						s[i].score_English = tscores;

						tscores = s[j].score_Math;   //s[i].score_Math
						s[j].score_Math = s[i].score_Math;
						s[i].score_Math = tscores;

						tscores = s[j].score_Science;   //s[j].score_Science
						s[j].score_Science = s[i].score_Science;
						s[i].score_Science = tscores;
					}
				}

			}


			// 실행 결과화면에 과학성적 순으로 정렬된 모습 출력.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Score of Science' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// 파일로도 출력하기!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Score of Science' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}

		}
		else //만약 벗어난 항목 번호를 입력한다면,
		{
		     if (criterion_Number == 2) 
				 break;

			printf("항목 번호를 다시 입력하세요.\n");
		}




	} //while문 종료









	/* 마지막으로 각 과목에 대한 성적 평균 구하기 */

	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0; // 국어 성적의 합, 영어 성적의 합, 수학 성적의 합, 과학 성적의 합


	for (int k = 0; k < 10; k++)
	{
		sum1 += s[k].score_Korea ;
		sum2 += s[k].score_English;
		sum3 += s[k].score_Math;
		sum4 += s[k].score_Science;
	}

	//실행 결과 화면에 평균을 출력하여 준다.
	printf("\n\n\n\n===================================================\n");
	printf("학생 %d명의 국어 평균 성적: %12d \n", student_num, sum1/student_num);
	printf("학생 %d명의 영어 평균 성적: %12d \n", student_num, sum2/student_num);
	printf("학생 %d명의 수학 평균 성적: %12d \n", student_num, sum3/student_num);
	printf("학생 %d명의 과학 평균 성적: %12d \n", student_num, sum4/student_num);
	printf("===================================================\n");

	//파일에도 평균을 출력한다.
	fprintf(fp, "\n\n\n===================================================\n");
	fprintf(fp, "학생 %d명의 국어 평균 성적: %12d \n", student_num, sum1/student_num);
	fprintf(fp, "학생 %d명의 영어 평균 성적: %12d \n", student_num, sum2/student_num);
	fprintf(fp, "학생 %d명의 수학 평균 성적: %12d \n", student_num, sum3/student_num);
	fprintf(fp, "학생 %d명의 과학 평균 성적: %12d \n", student_num, sum4/student_num);
	fprintf(fp, "===================================================\n");









	fclose(fp);    // 파일 포인터 닫기


	return 0;
}

