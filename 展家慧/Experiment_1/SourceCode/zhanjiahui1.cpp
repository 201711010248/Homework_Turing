#include <iostream>
#include<fstream>
#include<string>
#include<math.h>
using namespace std;
#define SIZE 20
struct student {
	int number;
	string name;
	int usual_score;
	int experment_score;
	int final_score;
	int rank;
}student[SIZE],temp;
int main(void) {
	int n = 0;

	ifstream read("data.txt",ios::in);//��.txt�ĵ�һ��6ɾ����
	if (!read.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		//exit(1);
		return 0;
	}
	while(!read.eof() && n<SIZE){
		read >> student[n].number >> student[n].name >> student[n].usual_score >> student[n].experment_score >> student[n].final_score;
		student[n].rank = (2 * student[n].usual_score + 2 * student[n].experment_score + 6 * student[n].final_score) / 10;
		n++;
	}
	int record = n - 1;
	int maxIndex;
	for (int i = 0; i < record; i++) {
		maxIndex = i;
		for (int j = i + 1; j < record; j++) {
			if (student[j].rank > student[maxIndex].rank) {     // Ѱ�������
				maxIndex = j;                 // �����������������
			}
			temp = student[maxIndex];
			student[maxIndex] = student[i];
			student[i] = temp;
		}
	}
	cout << "�ɼ�����Ϊ��" << endl;
	for (int i = 0; i < record; ++i)
		cout<< "��" <<i+1<<": "<< "number:" << student[i].number << " name: " << student[i].name << " ƽʱ�ɼ�: " << student[i].usual_score << " ʵ��ɼ���" << student[i].experment_score << " ��ĩ�ɼ�: " << student[i].final_score << " �ܳɼ�: " << student[i].rank << endl;
	cout << "ͨ��ѧ�Ų�ѯѧ����Ϣ?��y/n��" << endl;
	char flag;
	int numbs;
	cin >> flag;
	if (flag == 'y') {
		cout << "������ѧ��" << endl;
		cin >> numbs;
		//˳�����
		int l = 0;
		for (int i = 0; i < record; i++) {
			if (student[i].number == numbs) {
				cout << "number:" << student[i].number << " name: " << student[i].name << " ƽʱ�ɼ�: " << student[i].usual_score << " ʵ��ɼ���" << student[i].experment_score << " ��ĩ�ɼ�: " << student[i].final_score << " �ܳɼ�: " << student[i].rank << endl;
				l++;
			}
		}
		if(l == 0)
		cout << "���ǲ�������ˣ�" << endl;
	}
	if(flag == 'n') {
	//	exit(1);
	return 0;
	}

	double average,fangcha,sum=0;
	for(int i = 0; i < record; i++)
	{
	    sum = sum + student[i].rank;
	}
	average = sum / record;
	int a=0;
	for(int i = 0; i < record; i++)
	{
	    a = a + pow(student[i].rank - average,2);
	}
	fangcha = a / record;
	cout<<"ƽ����Ϊ��"<<average<<"����Ϊ��"<<fangcha<<endl;
	read.close();
}
