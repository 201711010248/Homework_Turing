/*************************************************
* Head File   : SCORE.h
* File Usage  : ѧ������ϵͳͷ�ļ�
* Create Time : 2018-9-2/17:25
/**************************************************/

#ifndef __SCORE_H__
#define __SCORE_H__


#include <stdio.h>

/*----------------------------------*
    Function Declaration
*-----------------------------------*/

struct Student
{
    string sid;   //ѧ��
    string name;
    int score[4];   //���ֳɼ�
    int ran;    //����
};
Student stu[6];


/*---------------��������-------------------*/


//1.����N��ѧ���������ɼ�������
void calcuScore(SS stu[], int N);


//2.��ѯ
void searchScore(SS stu[], int N);


//3.�����ֵ�ͷ���
void printOut(SS stu[], int N);




#endif

