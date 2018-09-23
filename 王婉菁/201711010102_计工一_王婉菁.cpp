#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 100
#define OK 0
typedef int Status;


typedef struct Student_type
{
	int number[20];
	char name[20];
	double score;
	double experiment;
	double test;
	double final;
	int ranking;


}Student;//�ṹ�嶨��ѧ������

typedef struct
{
	Student *elem;
	int length;
} Sqlist;

Status InitList(Sqlist &L)
{
	int i;
	L.elem = new Student[MAXSIZE];
	if (!L.elem)
		std::cout << "��ʼ���ռ�ʧ�ܣ�";
	L.length = 0;
	for (i = 1; i <= MAXSIZE; i++)
	{
		L.elem[i].number[20] = 0;
		L.elem[i].name[20] = 0;
		L.elem[i].score = 0;
		L.elem[i].experiment = 0;
		L.elem[i].test = 0;
		L.elem[i].final = 0;
		L.elem[i].ranking = 0;
	}
	return OK;
}//��ʼ��

Status count(Sqlist &L)
{
	int i;
	for (i = 1; i <= L.length; i++)
	{
		L.elem[i].final = 0.2*L.elem[i].score + 0.2*L.elem[i].experiment + 0.6*L.elem[i].test;
	}
	return OK;
}

void sort(Sqlist &L)
{
	int i, j, k;
	Student t;
	for (i = 1; i <= L.length; i++)
	{
		k = i;
		for (j = i + 1; j <= L.length; j++)
		{
			if (L.elem[j].final < L.elem[i].final)
				k = j;
			if (k != i)
			{
				t = L.elem[i];
				L.elem[i] = L.elem[j];
				L.elem[j] = t;
			}
		}
		L.elem[i].ranking = i;
	}
}

void search(Sqlist L)
{
	int i, j;
	int search[20];
	cout << "������Ҫ��ѯͬѧ��ѧ����Ϣ��" << endl;
	cin >> search[20];
	for (i = 1; i <= L.length; i++)
	{
		for (j = 1; j <= 20; j++)
		{
			if (L.elem[i].number[j] == search[j])
				j++;
			break;
		}
		if (j == 20 && L.elem[i].number[20] == search[20])
			break;
		i++;
	}
	if (i = 20 && L.elem[i].number[20] != search[20])
		cout << "�Բ����ļ��в����ڸ�ѧ�ţ�" << endl;
	else
	{
		cout << "������ѯ��ͬѧ����Ϣ���£�" << endl;
		cout << "������" << L.elem[i].name << "     ";
		cout << "ƽʱ�ɼ���" << L.elem[i].score << "      ";
		cout << "ʵ��ɼ���" << L.elem[i].experiment << "      ";
		cout << "��ĩ�ɼ���" << L.elem[i].test << "     ";
		cout << "�ܳɼ���" << L.elem[i].final << "      ";
		cout << "������" << L.elem[i].ranking << "    ";
	}


}

void calculate(Sqlist L)
{
	double average, variance;
	double sum, Sum;
	int i, k;
	double j[MAXSIZE];
	sum = 0, Sum = 0;
	for (i = 1; i <= L.length; i++)
		sum = sum + L.elem[i].final;
	average = sum / L.length;
	j[i] = pow((L.elem[i].final - average), 2);
	for (k = 1; k <= L.length; k++)
		Sum = Sum + j[i];
	variance = Sum / L.length;
	cout << "����Ŀ�ɼ��ľ�ֵΪ��" << endl << average;
	cout << "����Ŀ�ɼ��ķ���Ϊ��" << endl << variance;
}

int main()
{
	Sqlist L;
	int i=0,j,k;
	InitList(L);
	cout << "ѧ���ɼ�ϵͳ��ʼ���У�" << endl;
	FILE *fp;
	fopen_s(&fp,"stu.txt", "r");
	if(fp == NULL)
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		exit(0);
	}
	while (!feof(fp))
	{
		fscanf_s(fp, "%d, %s, %lf, %lf, %lf", &L.elem[i].number, &L.elem[i].name,sizeof(L.elem[i].name) ,&L.elem[i].score, &L.elem[i].experiment, &L.elem[i].test);
		i++;
	}
	for (j = i; j <= i; j++)
	{
		for (k = 1; k <= 20; k++)
			printf("%d", L.elem[j].number[k]);
		printf("%s",  L.elem[j].name);
		printf("%lf,%lf,%lf",  L.elem[j].score, L.elem[j].experiment, L.elem[j].test);
	}
	fclose(fp);
	count(L);
	sort(L);
	search(L);
	calculate(L);
	return 0;
}