#include "score.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
void readData(SS stu[], int N)
{
	printf("�밴�����¸�ʽ����ѧ����Ϣ��ѧ��,����,ƽʱ�ɼ�,��ĩ�ɼ�\n");
	for (int i = 0; i < N; i++)
	{
		printf("��%d��ѧ��:", i + 1);
		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf("\n");
	}
	printf("------�ɼ�¼�����!--------\n");
}
SS* readDataFromFile(int *N)
{
	printf("\n\n------��һ��: ���ļ���ȡѧ���ĳɼ���Ϣ--------\n\n");
	SS *stu;// �����¿ռ�,��ȡ�ļ��е�ÿ��ѧ����Ϣ
	FILE *fp = NULL;
	int count = 0;
	int index = 0;
	fp = fopen("data.txt", "r");
	//1.��ȡѧ����Ŀ
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
	printf("failed to open the info file\n");
	getchar();
	}
	printf("ѧ����ĿΪ:%d\n", count);
	getchar();
	//2.������ѧ������洢�ռ�
	stu = (SS*)malloc(count * sizeof(SS));
	//3.��ȡÿ��ѧ������Ϣ
	while ((!feof(fp)) && (index < count))
	{
		//�����ļ����ݵ��ڴ�	
		fscanf(fp, "%s%s%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore, &stu[index].finalScore);

		//���ԭʼѧ����Ϣ
		printf("* ѧ�ţ�%s	����:%s		ƽʱ�ɼ���%4.2f��		��ĩ�ɼ�:%4.2f��\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].finalScore);
		index++��
	}
	fclose(fp);
	return stu;
}
//2.����N��ѧ�����Ե������ɼ�
void calcuScore(SS stu[], int N)
{
	printf("\n\n------�ڶ���: ����ÿ��ѧ���������ɼ�--------\n\n");
	for (int i = 0; i < N; i++)
	{
		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.8*stu[i].finalScore;
		printf("* ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", (stu[i].number), (stu[i].name), stu[i].generalScore);
	}
}
//3.���������ɼ�����
int cmpBigtoSmall(const void *a, const void *b)��
	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);
	if ((*aa).generalScore < (*bb).generalScore)  return 1;
	else if ((*aa).generalScore > (*bb).generalScore)  return -1��
	else
		return 0��
}
void sortScore(SS stu[], int N)
{
	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);

}
//4.����һ���ĸ�ʽ���N��ѧ������Ϣ
void printOut(SS stu[], int N)
{
printf("\n------������: �����ܳɼ����ѧ��������Ϣ!------\n\n");
    for (int i = 0; i < N; i++)
	{
		printf("��%d����Ϣ ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
	}
}
//5ͳ�Ƴ�ѧ���ľ�ֵ�ͷ���
	double aver=0;
	void array_input(int array[],int n)
	{
		for(int i=0;i!=n;++i)
			cin>>array[i];
	}
	double calculate (int array[],int n)
	{
		int sum=0;
		int i=0;
		for(i=0;i!=n;++i)
			sum+=array[i];
		aver=(sum*1.0)/n;
		double sum2=0.0;
		for(i=0;i!=n;++i)
		{
			sum2+=(array[i]-aver*(array[i]-aver);
		}
		return(sum2*1.0)/n;
	}
	int main()
	{
		int array[10]={0};
		array_input(array,10);
		double s=calculate(aeeay,10);
printf("��ֵ%lf  ����%lf\n", ave, s);
	}
	//6��ѧ�Ų�ѯ�Լ��ĳɼ�
	typedef struct
	{
		char no [20];
		int score;
	}STU;
	int main()
	{
		STU s[10],t;
		char no[20];
		int i.j;
		for(i=0;i<10;i++)
		{
			scanf("%s%d",t.no,&t.score);
			for(j=i;j>=0;j--)
				if(s[j].score<t.score)
					s[j+1]=s[j];
				else berak;
				s[j+1]=t;
		}
		for(i=0;i<10;i++)
			printf("%s   %d\n",s[i].no,s[i].score);
		printf("����Ҫ��ѯ��ѧ�ţ�");
		scanf("%s",no);
		for(i=0;i<10;i++)
			if(strcmp(s[i].no,no==0) break;
			if(i==10)
				printf("�����⼸��ͬѧ֮��\n");
			else printf("��ѧ���ķ���%d\n",s[i].score);
			return 0;
	}






