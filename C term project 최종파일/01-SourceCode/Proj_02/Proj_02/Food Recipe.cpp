#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 


#define num_of_food 10 // ���� ������ 10���� ����

#pragma warning (disable:4996)

void showing_Menu(char list[][30]); // �Լ��� ����

struct dish { 

	char a[20]; //����
	int b; //����
	char c[20];//����
	int d; //����
	char e[20];//����
	int f; //����
	char g[20];//����
	int h; //����
	char i[20];//����

}; // ����ü ����

int main()
{

	struct dish d[num_of_food]; // ����ü �迭 ����

	char input_FoodName[100]; // ����ڷκ��� �Է¹���  �����̸�
	int input_NumPeople; // ����ڷκ��� �Է¹���  ���� �Դ� ��� ��

	char list_of_foods[num_of_food][30] = { "���", "�˸����ø���", "�������", "��������", "������",
		                                    "���̽�ī��Ḷ���߶�", "���̱ۻ�����ġ", "�߰ſü��",
	                                        "���Ը��䵤��", "ī��" }; // 10���� ���� ���. ���� ���ڿ� �迭




	/*  �� ������ ���� ������ �Է�	*/

	//���
	strcpy(d[0].a, "- ���: ");
	d[0].b = 1;
	strcpy(d[0].c, "����,\n- ��: ");
	d[0].d = 500;
	strcpy(d[0].e, "ml,\n- ��: ");
	d[0].f = 20;
	strcpy(d[0].g, "grams,\n- ���: ");
	d[0].h = 1;
	strcpy(d[0].i, "��.\n");

	//�˸����ø���
	strcpy(d[1].a, "- ���İ�Ƽ ��: ");
	d[1].b = 1;
	strcpy(d[1].c, "�κ�,\n- ��: ");
	d[1].d = 700;
	strcpy(d[1].e, "ml,\n- �ø�����: ");
	d[1].f = 5;
	strcpy(d[1].g, "TS,\n- �븶��: ");
	d[1].h = 7;
	strcpy(d[1].i, "��.\n");

	//�������
	strcpy(d[2].a, "- ���: ");
	d[2].b = 5;
	strcpy(d[2].c, "��,\n- ��: ");
	d[2].d = 700;
	strcpy(d[2].e, "ml,\n- �ұ�: ");
	d[2].f = 1;
	strcpy(d[2].g, "TS,\n- ����: ");
	d[2].h = 1;
	strcpy(d[2].i, "TS.\n");

	//��������
	strcpy(d[3].a, "- ���: ");
	d[3].b = 2;
	strcpy(d[3].c, "��,\n- ����: ");
	d[3].d = 1;
	strcpy(d[3].e, "TS,\n- ���⸧: ");
	d[3].f = 1;
	strcpy(d[3].g, "TS,\n- ��: ");
	d[3].h = 1;
	strcpy(d[3].i, "����.\n");

	//������
	strcpy(d[4].a, "- �����: ");
	d[4].b = 4;
	strcpy(d[4].c, "��,\n- ����: ");
	d[4].d = 13;
	strcpy(d[4].e, "��,\n- ũ��ġ��: ");
	d[4].f = 100;
	strcpy(d[4].g, "g,\n- ������Ż�ҽ�: ");
	d[4].h = 20;
	strcpy(d[4].i, "ml.\n");

	//���̽�ī��Ḷ���߶�
	strcpy(d[5].a, "- ����: ");
	d[5].b = 500;
	strcpy(d[5].c, "ml,\n- ����������: ");
	d[5].d = 2;
	strcpy(d[5].e, "��,\n- ī���÷�: ");
	d[5].f = 1;
	strcpy(d[5].g, "����,\n- ����: ");
	d[5].h = 7;
	strcpy(d[5].i, "��.\n");

	//���̱ۻ�����ġ
	strcpy(d[6].a, "- ���̱�: ");
	d[6].b = 1;
	strcpy(d[6].c, "��,\n- ũ��ġ��: ");
	d[6].d = 30;
	strcpy(d[6].e, "g,\n- �����̽���: ");
	d[6].f = 1;
	strcpy(d[6].g, "��,\n- �����: ");
	d[6].h = 1;
	strcpy(d[6].i, "��.\n");

	//�߰ſü��
	strcpy(d[7].a, "- ��������: ");
	d[7].b = 500;
	strcpy(d[7].c, "ml,\n- ����������: ");
	d[7].d = 2;
	strcpy(d[7].e, "��,\n- ����: ");
	d[7].f = 20;
	strcpy(d[7].g, "g,\n- �÷�: ");
	d[7].h = 1;
	strcpy(d[7].i, "����.\n");

	//���Ը��䵤��
	strcpy(d[8].a, "- ��: ");
	d[8].b = 1;
	strcpy(d[8].c, "����,\n- ����: ");
	d[8].d = 100;
	strcpy(d[8].e, "g,\n- �������: ");
	d[8].f = 50;
	strcpy(d[8].g, "g,\n- ����: ");
	d[8].h = 1;
	strcpy(d[8].i, "TS.\n");

	//ī��
	strcpy(d[9].a, "- ī������: ");
	d[9].b = 50;
	strcpy(d[9].c, "g,\n- ����: ");
	d[9].d = 1;
	strcpy(d[9].e, "��,\n- ���: ");
	d[9].f = 1;
	strcpy(d[9].g, "��,\n- �������: ");
	d[9].h = 100;
	strcpy(d[9].i, "g.\n");









	showing_Menu(list_of_foods); // �޴��� �����ִ� �Լ� ȣ��









	printf("\n\n\n\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf(" Insert Food Name (by Hangeul):  ");
	scanf_s("%s", &input_FoodName, 30 ); // ������ �̸��� �Է¹ޱ�
	printf(" How many people:  ");
	scanf_s("%d", &input_NumPeople); //������ �� ���̼� ������ �Է¹ޱ�




	
	
	
	if ( strcmp(input_FoodName, "���") == 0 ) // ����ڰ� '���'�� �Է��ߴٸ�
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[0].a, input_NumPeople*d[0].b, d[0].c, input_NumPeople*d[0].d, d[0].e,
			input_NumPeople*d[0].f, d[0].g, input_NumPeople*d[0].h, d[0].i); 

	}
	else if( strcmp(input_FoodName, "�˸����ø���") == 0 ) // ����ڰ� '�˸����ø���'�� �Է��ߴٸ�
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[1].a, input_NumPeople*d[1].b, d[1].c, input_NumPeople*d[1].d, d[1].e,
			input_NumPeople*d[1].f, d[1].g, input_NumPeople*d[1].h, d[1].i); 

	}
	else if (strcmp(input_FoodName, "�������") == 0) // ����ڰ� '�������'�� �Է��ߴٸ�
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[2].a, input_NumPeople*d[2].b, d[2].c, input_NumPeople*d[2].d, d[2].e,
			input_NumPeople*d[2].f, d[2].g, input_NumPeople*d[2].h, d[2].i); 

	}
	else if (strcmp(input_FoodName, "��������") == 0) // ����ڰ� '��������'�� �Է��ߴٸ�
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[3].a, input_NumPeople*d[3].b, d[3].c, input_NumPeople*d[3].d, d[3].e,
			input_NumPeople*d[3].f, d[3].g, input_NumPeople*d[3].h, d[3].i); 

	}
	else if (strcmp(input_FoodName, "������") == 0) // ����ڰ� '������'�� �Է��ߴٸ�
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[4].a, input_NumPeople*d[4].b, d[4].c, input_NumPeople*d[4].d, d[4].e,
			input_NumPeople*d[4].f, d[4].g, input_NumPeople*d[4].h, d[4].i); 

	}
	else if (strcmp(input_FoodName, "���̽�ī��Ḷ���߶�") == 0) // ����ڰ� '���̽�ī��Ḷ���߶�'�� �Է��ߴٸ�
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[5].a, input_NumPeople*d[5].b, d[5].c, input_NumPeople*d[5].d, d[5].e,
			input_NumPeople*d[5].f, d[5].g, input_NumPeople*d[5].h, d[5].i); 

	}
	else if (strcmp(input_FoodName, "���̱ۻ�����ġ") == 0) // ����ڰ� '���̱ۻ�����ġ'�� �Է��ߴٸ�
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[6].a, input_NumPeople*d[6].b, d[6].c, input_NumPeople*d[6].d, d[6].e,
			input_NumPeople*d[6].f, d[6].g, input_NumPeople*d[6].h, d[6].i); 

	}
	else if (strcmp(input_FoodName, "�߰ſü��") == 0) // ����ڰ� '�߰ſü��'�� �Է��ߴٸ�
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[7].a, input_NumPeople*d[7].b, d[7].c, input_NumPeople*d[7].d, d[7].e,
			input_NumPeople*d[7].f, d[7].g, input_NumPeople*d[7].h, d[7].i); 

	}
	else if (strcmp(input_FoodName, "���Ը��䵤��") == 0) // ����ڰ� '���Ը��䵤��'�� �Է��ߴٸ�
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[8].a, input_NumPeople*d[8].b, d[8].c, input_NumPeople*d[8].d, d[8].e,
			input_NumPeople*d[8].f, d[8].g, input_NumPeople*d[8].h, d[8].i); 

	}
	else if (strcmp(input_FoodName, "ī��") == 0) // ����ڰ� 'ī��'�� �Է��ߴٸ�
	{
		printf("\n%s%d%s%d%s%d%s%d%s", d[9].a, input_NumPeople*d[9].b, d[9].c, input_NumPeople*d[9].d, d[9].e,
			input_NumPeople*d[9].f, d[9].g, input_NumPeople*d[9].h, d[9].i); 

	}
	else // �߸��� ���� �̸� ���� �Է¹޾Ҵٸ�
	{
		printf("���� �̸��� �߸� �Է��ϼ̽��ϴ�. \n");
	}
	

	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n\n");







	return 0;

}

void showing_Menu(char list[][30]) // �޴����� ����Ͽ� �����ִ� �Լ� ����
{

	printf("-------------------------\n");
	printf("           MENU          \n");
	printf("-------------------------\n");

	for (int m = 0; m < num_of_food; m++)
	{
		printf(" %23s \n", list[m]);
	}


}