#pragma once
#include"stu.h"
void addall(student*p)
{
	for(int i=0;i<a;i++)
	{
		p[i].addall=p[i].daily*0.2+p[i].expscore*0.2+p[i].finalscore*0.6;
	}
}
void average(student*p)
{
	double m=0,n=0;
	for(int i=0;i<a;i++)
		m=m+p[i].addall;
	m=m/a;
	for(int i=0;i<a;i++)
		n=n+(p[i].addall-m)*(p[i].addall-m);
	n=n/a;
	printf("ƽ����Ϊ%lf������Ϊ%lf\nƽ����",m,n);
	if(m>=90)printf("����\n");
	else if(m>=80)printf("����\n");
	else if(m>=70)printf("�Ϻ�\n");
	else if(m>=60)printf("����\n");
	else printf("�ϲ�\n");
	if(n>=5)printf("�����ֲ�����\n");
	else printf("�����ֲ���Ϊ����\n");
}
	