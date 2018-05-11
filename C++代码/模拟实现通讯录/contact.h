#ifndef __CONTACT_H__
#define __CONTACT_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//#define MAX 1000    //ͨѶ¼�������
#define NAMEMAX 10
#define TELE 12
#define ADDR 25
#define SEX 5
#define CAPACITY 3   //��ǰ����
#define FILENAME "daima.txt"

typedef struct Peoinfo
{
	char name[NAMEMAX];
	char sex[SEX];
	int age;
	char addr[ADDR];
	char tele[TELE];
}Pof;
typedef struct Contact
{
	Pof *data;   //��Ϣ���������
	int sz;  //��ЧԪ�صĸ���
	int capacity;  //����
	char filename[100];  //�ļ���
}Contact,*p;

void Init(p list);         //��ʼ������
void Add(p pcon);          //¼�뺯��
void Show(const p pcon);   //��ʾ����
void Delete(p pcon);       //ɾ������
void Search(p pcon);      //Ѱ�Һ���
void Modify(p pcon);     //�޸ĺ���
void Sort(p pcon);      //������
void Clear(p pcon);     //��պ���
void Addcapacity(p pcon); //���ݺ���
void Save(p pcon);    //�����ļ�
void display(p pcon);  //�ļ����뺯��
void Destory(p pcon); //�ͷ��ڴ溯��

#endif