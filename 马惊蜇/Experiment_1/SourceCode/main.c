#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include"score.h"
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS��


/*----------------------------------*
			Main Function
*-----------------------------------*/

int main()
{
	printf("------------------------------\n");
	printf("       ѧ���ɼ��������ϵͳ        \n");
	printf("          MJZ��code           \n");
	printf("------------------------------\n\n");

	int N = 0;       

	SS  *pstu = NULL;

	pstu = ReadDataFromFile(&N);
	Sleep(1000);

	/*-3.�����ܳɼ�-*/
	CalcuGenscr(pstu, N);
	Sleep(1000);

	/*-4.����ѧ���ɼ�����-*/
	SortScore(pstu, N);

	/*-5.�����������ѧ����Ϣ-*/
	PrintOut(pstu, N);
	Sleep(1000);


	/*-6.����ɼ��ľ�ֵ�ͷ���*/
	Ave_Variance(pstu, N);
	Sleep(1000);

	//7.��ѯĳ��ѧ���ɼ���Ϣ
	SearchScore(pstu);
	free(pstu);

	printf("\n");
	system("pause");
}