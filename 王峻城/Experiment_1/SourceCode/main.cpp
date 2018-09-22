#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

FILE *fp = NULL;
int num, cnt;
struct stuff{
    char number[10];
    char name[10];
    float dailyScore;
    float testScore;
    float finalScore;
    float generalScore;
};
bool cmp(stuff a, stuff b) //�����ܳɼ����������ɼ���ͬ��ѧ��С������
{
    if(a.generalScore > b.generalScore)
        return 1;
    else if(a.generalScore == b.generalScore)
    {
        if(a.number < b.number)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
void ReadStudent(stuff *stu)
{
    //¼��ѧ���ɼ�
    printf("�����ѧ���ɼ�Ϊ��\n");
    while((!feof(fp)) && (cnt < num))
    {
        fscanf(fp, "%s%s%f%f%f\n", (stu[cnt].number),(stu[cnt].name),&stu[cnt].dailyScore,&stu[cnt].testScore,&stu[cnt].finalScore);

        printf("ѧ�ţ�%s\t������%s\tƽʱ�ɼ���%.2f\tʵ��ɼ���%.2f\t��ĩ�ɼ���%.2f\n", (stu[cnt].number),(stu[cnt].name),(stu[cnt].dailyScore),(stu[cnt].testScore),(stu[cnt].finalScore));
        cnt++;
    }
}
void TotalScore(stuff *stu)
{
    //�ܳɼ�
    printf("\nѧ�����ܳɼ�:\n");
    for(int i=0; i<num; i++)
    {
        stu[i].generalScore = stu[i].dailyScore * 0.2 + stu[i].testScore * 0.2 + stu[i].finalScore * 0.6;
        printf("ѧ�ţ�%s\t������%s\t�ܳɼ���%.2f\n",(stu[i].number),(stu[i].name),(stu[i].generalScore));
    }
}
void StudentRank(stuff *stu)
{
    //����
    printf("\nѧ������:\n");
    sort(stu, stu+num, cmp);
    for(int i=0; i<num; i++)
    {
        printf("ѧ�ţ�%s\t������%s\t�ɼ���%.2f\t���Σ�%d\n",(stu[i].number),(stu[i].name),(stu[i].generalScore),i+1);
    }
}
int myPow(int x)
{
    return (x*x);
}
void OtherScore(stuff *stu)
{
    printf("\n��ֵ:\n");
    int ans1 = 0;
    for(int i=0; i<num; i++)
    {s
        ans1 += stu[i].generalScore;
    }
    cout << ans1/num <<endl;
    ans1 /= num;
    printf("\n����:\n");
    int ans2 = 0;
    for(int i=0; i<num; i++)
    {
        ans2 += myPow(stu[i].generalScore - ans1);
    }
    cout << ans2/num << endl;
}
int main()
{
    fp = fopen("data.txt", "r");
    //ѧ����Ŀ
    num = 0;
    if(fp != NULL)
    {
        fscanf(fp,"%d",&num);
    }
    printf("ѧ����ĿΪ��%d\n",num);
    cnt = 0;
    stuff stu[num];
    //¼��ѧ���ɼ�
    ReadStudent(stu);
    //�ܳɼ�
    TotalScore(stu);
    //����
    StudentRank(stu);
    OtherScore(stu);
    fclose(fp);
    return 0;
}
