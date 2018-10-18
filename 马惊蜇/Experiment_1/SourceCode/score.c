/*************************************************
** Դ�ļ�   : score.c
** ����˵�� : Function Definations
** ����ʱ�� : 2018-9-21/17:35
/**************************************************/

/*----------------ͷ�ļ�--------------*/

#include "score.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include<Windows.h>
#define _CRT_SECURE_NO_WARNINGS��

/*----------------��������-------------*/

SS* ReadDataFromFile(int *N)
{
	printf("\n\n------------��һ�������ļ���ȡѧ����Ϣ---------------\n\n");

	SS *stu;
		FILE *fp = NULL;
		int cnt = 0;
		int index = 0;
		fp = fopen("data.txt", "r");
		//��ȡѧ����Ŀ
		if (fp == NULL){
			printf("Failed to open the file!!!\n");
			getchar();
		}
		else{
			fscanf(fp, "%d", &cnt);
			*N = cnt;
		}
		printf("ѧ����ĿΪ��%d\n", cnt);
		Sleep(1000);

		//����ѧ������洢�ռ�
		stu = (SS*)malloc(cnt*sizeof(SS));

		//��ȡѧ����Ϣ
		while ((!feof(fp)) && (index < cnt))
		{
			fscanf(fp,"%s %s %f%f%f\n", stu[index].num, stu[index].name, &stu[index].dayscr, &stu[index].expscr, &stu[index].finscr);
			printf("* ѧ�ţ�%s	����:%s		ƽʱ�ɼ���%4.2f��		ʵ��ɼ�:%4.2f��		��ĩ�ɼ�:%4.2f��\n", stu[index].num, stu[index].name, stu[index].dayscr, stu[index].expscr, stu[index].finscr);
			index++;

		}
		fclose(fp);
		return stu;


}

void CalcuGenscr(SS stu[], int N)
{
	printf("\n\n-------------�ڶ���: ����ÿ��ѧ���������ɼ�-----------\n\n");
	
	for (int i = 0; i < N; i++)
	{
		stu[i].genscr = 0.2*stu[i].dayscr + 0.2*stu[i].expscr + 0.6*stu[i].finscr;
		printf("* %s			�ܳɼ�:%4.2f��\n", stu[i].num, stu[i].genscr);

	}

}

int cmpBigtoSmall(const void *a, const void *b)
{

	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);



	if ((*aa).genscr < (*bb).genscr)  return 1;

	else if ((*aa).genscr >(*bb).genscr)  return -1;

	else
		return 0;

}

void SortScore(SS stu[], int N)
{

	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);

}

void PrintOut(SS stu[], int N)
{
	printf("\n------������: �����ܳɼ����ѧ��������Ϣ!------\n\n");

	for (int i = 0; i < N; i++)
	{
		printf("��%d�� %s ��Ϣ %s			�ܳɼ�:%4.2f��\n", i + 1,&(stu[i].name[0]), &(stu[i].num[0]), stu[i].genscr);

	}
}

void Ave_Variance(SS stu[], int N)
{
	printf("\n-------���Ĳ��� ͳ�Ƹÿγ̳ɼ��ľ�ֵ�ͷ���--------\n\n");
	float ave;
	ave = 0.2*(stu[0].genscr + stu[1].genscr + stu[2].genscr + stu[3].genscr + stu[4].genscr);
	float var;
	var = 0.2*(pow(stu[0].genscr - ave, 2) + pow(stu[1].genscr - ave, 2) + pow(stu[2].genscr - ave, 2) + pow(stu[3].genscr - ave, 2) + pow(stu[4].genscr - ave, 2));

	printf("�ܳɼ�ƽ��ֵΪ��%4.2f���ܳɼ�����Ϊ��%4.2f\n", ave, var);

}

void SearchScore(SS stu[])
{
	printf("\n-------���岽�� ��ѯĳλѧ����Ϣ----------\n\n");
	char number[10];
	int flag = 1;
	printf("������ѧ�ţ�\n");

	for (int j = 0; j < 10; j++)
	{
		scanf("%c", &number[j]);
	}
	getchar();

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (stu[i].num[j] != number[j]){
				flag = 0;
				break;
			}
		}
		if (flag == 1){
			printf("* %s	ƽʱ�ɼ���%4.2f��	ʵ��ɼ���%4.2f��	��ĩ�ɼ�:%4.2f��    �ܳɼ�Ϊ:%4.2f��\n", (stu[i].name), stu[i].dayscr, stu[i].expscr, stu[i].finscr, stu[i].genscr);
			break;

		}
		else if (i == 5){

			printf("���޴��ˣ���\n");

		}
		flag = 1;
				
				
	}

}
