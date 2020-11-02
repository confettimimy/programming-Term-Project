#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

#define student_num 10


struct student {

	char name[10]; //����
	char sex[3]; //����
	int age; //����
	char PhoneNumber[12]; //��ȭ��ȣ
	char university[30]; //�б���
	int score_Korea; //��������
	int score_English; //��������
	int score_Math; //�������� 
	int score_Science; //��������

};


int main()
{

	struct student s[student_num];

	/* ���� �� ����� �ӽú����� */
	char tstring[15]; //�� ���ڿ��� �����س��� ���� �ӽú���
	char tchar[3]; //��������� ª�� ���ڿ��� �����س��� ���� �ӽú���
	int tint; //���ڸ� ���� �س��� ���� �ӽú���
	int tscores; //�������� ������ �����س��� ���� �ӽú���
	
	int i;

	int criterion_Number = 0; //����ڷκ��� �Է¹޴� ���� �׸� ��ȣ







	FILE *fp;
	fp = fopen("10 students' information.txt", "a+"); //�ؽ�Ʈ ���� �߰����� ����


	if (fp == NULL)
	{
		printf("�� ������ �������� �ʽ��ϴ�.\n");
	} //���� ó��







	// ���Ͽ� �Էµ� ������ �о����
	for(i = 0; i < student_num; i++)
		fscanf(fp, "%s %s %d %s %s %d %d %d %d \n",
			        &s[i].name, &s[i].sex, &s[i].age, &s[i].PhoneNumber, &s[i].university, &s[i].score_Korea, &s[i].score_English, &s[i].score_Math, &s[i].score_Science);
	

	// �ؽ�Ʈ���Ͽ� �ִ� �����͵��� �� �о�Դ��� Ȯ���غ��� ���� ������ ȭ�鿡 ����غ���
	printf("              [ Original form ]              \n\n");
	for (i = 0; i < student_num; i++) { 
		printf("%s %s %d %s %s %d %d %d %d \n",
			s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
	}







	while (1)   
	{  // ������ ���� ����ڷκ��� ����ؼ� ���� �׸� ��ȣ�� �Է¹޴´�.
       // �׸� ��ȣ�� �Է� ���� ������ �� �־��� ��ȣ�� �߽����� ������ ����� �����ش�. 


		if (criterion_Number == 2) // ������ ���������� �ʹٸ� 2�� �Է��ϸ� �ȴ�.
			break; 

		printf("\n\n\n\n (���̻� ������ ������ �ʴ´ٸ� 2�� �Է�)\n");

		printf(" 2���� ������ 8�� �׸� ��ȣ �� �ϳ��� ��ȣ�� �Է��ϼ���. �־��� ��ȣ�� �߽����� �����ص帮�ڽ��ϴ�. -> "); //����ڷκ��� ���� ��ȣ �Է¹ޱ�
		scanf("%d", &criterion_Number);






		if (criterion_Number == 1) { //����ڰ� '(1)����' �������� ������ ���Ѵٸ�,
			


			// ********** (1) �̸� �� ���� **********

			for (int i = 0; i < student_num; i++)//�̸������� �����ϱ� 
			{
				for (int j = i; j < student_num; j++)
				{
					if (strcmp(s[i].name, s[j].name) > 0) //���ڰ� �� ũ��
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


			// ���� ���ȭ�鿡 �̸� ������ ���ĵ� ��� ���.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Name' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// ���Ϸε� ����ϱ�!
			fprintf(fp, "\n\n\n\n\n  @@@ Let's sort  based on various criteria !!!!!! @@@  \n");
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Name' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


		}
		else if (criterion_Number == 3) { //����ڰ� ' (3)����' �������� ������ ���Ѵٸ�,



			// ********** (3) ���� �� ���� **********

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


			// ���� ���ȭ�鿡 ���� ������ ���ĵ� ��� ���.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Age' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// ���Ϸε� ����ϱ�!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Age' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}

		}
		else if (criterion_Number == 4) { //����ڰ� '(4)��ȭ��ȣ' �������� ������ ���Ѵٸ�,
		


			// ********** (4) ��ȭ��ȣ �� ���� **********

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


			// ���� ���ȭ�鿡 ��ȭ��ȣ ������ ���ĵ� ��� ���.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Phone Number' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// ���Ϸε� ����ϱ�!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Phone Number' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


		}
		else if (criterion_Number == 5) { //����ڰ� '(5)�б���' �������� ������ ���Ѵٸ�,



			// ********** (5) �б��� �� ���� **********

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


			// ���� ���ȭ�鿡 �б��� ������ ���ĵ� ��� ���.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'University's Name' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// ���Ϸε� ����ϱ�!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'University's Name' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}

		}
		else if (criterion_Number == 6) { //����ڰ� '(6)����' �������� ������ ���Ѵٸ�,



			// ********** (6) ����� �� ���� **********

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


			// ���� ���ȭ�鿡 ����� ������ ���ĵ� ��� ���.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Score of Korea' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// ���Ϸε� ����ϱ�!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Score of Korea' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}

		}
		else if (criterion_Number == 7) { //����ڰ� '(7)����' �������� ������ ���Ѵٸ�,



			// ********** (7) ����� �� ���� **********

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


			// ���� ���ȭ�鿡 ����� ������ ���ĵ� ��� ���.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Score of English' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// ���Ϸε� ����ϱ�!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Score of English' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}

		}
		else if (criterion_Number == 8) { //����ڰ� '(8)����' �������� ������ ���Ѵٸ�,



			// ********** (8) ���м��� �� ���� **********

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


			// ���� ���ȭ�鿡 ���м��� ������ ���ĵ� ��� ���.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Score of Math' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// ���Ϸε� ����ϱ�!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Score of Math' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


		}
		else if (criterion_Number == 9) { //����ڰ� '(9)����' �������� ������ ���Ѵٸ�,



			// ********** (9) ���м��� �� ���� **********

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


			// ���� ���ȭ�鿡 ���м��� ������ ���ĵ� ��� ���.
			printf("\n---------------------------------------------------\n\n");
			printf("              [ Sorts  by 'Score of Science' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				printf("%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}


			// ���Ϸε� ����ϱ�!
			fprintf(fp, "\n---------------------------------------------------\n\n");
			fprintf(fp, "              [ Sorts  by 'Score of Science' ]              \n\n");

			for (i = 0; i < student_num; i++)
			{
				fprintf(fp, "%s %s %d %s %s %d %d %d %d\n", s[i].name, s[i].sex, s[i].age, s[i].PhoneNumber, s[i].university, s[i].score_Korea, s[i].score_English, s[i].score_Math, s[i].score_Science);
			}

		}
		else //���� ��� �׸� ��ȣ�� �Է��Ѵٸ�,
		{
		     if (criterion_Number == 2) 
				 break;

			printf("�׸� ��ȣ�� �ٽ� �Է��ϼ���.\n");
		}




	} //while�� ����









	/* ���������� �� ���� ���� ���� ��� ���ϱ� */

	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0; // ���� ������ ��, ���� ������ ��, ���� ������ ��, ���� ������ ��


	for (int k = 0; k < 10; k++)
	{
		sum1 += s[k].score_Korea ;
		sum2 += s[k].score_English;
		sum3 += s[k].score_Math;
		sum4 += s[k].score_Science;
	}

	//���� ��� ȭ�鿡 ����� ����Ͽ� �ش�.
	printf("\n\n\n\n===================================================\n");
	printf("�л� %d���� ���� ��� ����: %12d \n", student_num, sum1/student_num);
	printf("�л� %d���� ���� ��� ����: %12d \n", student_num, sum2/student_num);
	printf("�л� %d���� ���� ��� ����: %12d \n", student_num, sum3/student_num);
	printf("�л� %d���� ���� ��� ����: %12d \n", student_num, sum4/student_num);
	printf("===================================================\n");

	//���Ͽ��� ����� ����Ѵ�.
	fprintf(fp, "\n\n\n===================================================\n");
	fprintf(fp, "�л� %d���� ���� ��� ����: %12d \n", student_num, sum1/student_num);
	fprintf(fp, "�л� %d���� ���� ��� ����: %12d \n", student_num, sum2/student_num);
	fprintf(fp, "�л� %d���� ���� ��� ����: %12d \n", student_num, sum3/student_num);
	fprintf(fp, "�л� %d���� ���� ��� ����: %12d \n", student_num, sum4/student_num);
	fprintf(fp, "===================================================\n");









	fclose(fp);    // ���� ������ �ݱ�


	return 0;
}

