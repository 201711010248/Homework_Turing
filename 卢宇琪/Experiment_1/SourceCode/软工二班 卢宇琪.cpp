#include<stdio.h>
#include<math.h>
typedef struct//����ѧ����Ϣ
{
	char name[6];
	char number[6];
	float dailyScore;//ƽʱ�ɼ�
	float finalScore;//��ĩ�ɼ�
	float expScore;//ʵ��ɼ�
	float sumScore;//�����ɼ�
}SS;
void readData(SS stu[])//¼��ѧ���ɼ�
{
	for (int i = 0; i < 6; i++)
	{
		printf("�밴������ѧ�ţ�ƽʱ�ɼ�����ĩ�ɼ�����ѧ����Ϣ��\n");
		scanf("%s %s %f %f %f", &stu[i].name, &stu[i].number, &stu[i].dailyScore, &stu[i].finalScore,&stu[i].expScore);
		printf("\n");
	}
}
void calcuScore(SS stu[])//����ѧ���ܳɼ�
{
	for (int i = 0; i < 6; i++)
	{
		stu[i].sumScore = 0.2*stu[i].dailyScore + 0.2*stu[i].expScore + 0.6*stu[i].finalScore;
    }
}
void rankScore(SS stu[])//����ѧ������
{
	int t;
	for (int i = 0; i < 6; i++)
	{
		int k = 1;
		for (int j = i + 1; j <= 6; j++)
			if (stu[j].sumScore < stu[i].sumScore)
				k = j;
		if (k != i)
		{
			t = stu[i].sumScore; stu[i].sumScore = stu[k].sumScore; stu[k].sumScore = t;
		}
	}
}
void Query_name()//��������ѯѧ����Ϣ
{
	int name;
	int j = 0;
	scanf("%s", &name);
	while(j<6)
	{
		if (name != stu[j].name)
			j++;
		else if
			printf("%s,%f,%f,%f\n", &stu[j].number, &stu[j].dailyScore; &stu[j].finalScore, %stu[j].sunScore);
	}
	printf("��ѯ��������Ϣ\n");
}