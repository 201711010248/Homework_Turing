#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "score.h"

int main()
{


	printf("******************************\n");
	printf("       ѧ���ɼ��������ϵͳ        \n");
	printf("******************************\n\n");
	int N = 0;        //ѧ������

	SS  *pstu = NULL;    //�ṹ������ָ��
	pstu = readDataFromFile(&N);

	printf("������ѧ����Ŀ:");
	scanf("%d", &N);
	readData(pstu, N);
	
    calcuScore(pstu, N);/*����ѧ���ܳɼ����ܳɼ� = ƽʱ�ɼ� + ��ĩ�ɼ�--*/
    sortScore(pstu, N);/*����ѧ���ɼ�����-*/
	printOut(pstu, N);/*�����������ѧ����Ϣ-*/
    free(pstu);//�ͷŶ�̬�ڴ�ռ�

	printf("\n");
	system("pause");


	return 0;
}