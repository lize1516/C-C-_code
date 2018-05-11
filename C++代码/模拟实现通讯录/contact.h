#ifndef __CONTACT_H__
#define __CONTACT_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//#define MAX 1000    //通讯录最大容量
#define NAMEMAX 10
#define TELE 12
#define ADDR 25
#define SEX 5
#define CAPACITY 3   //当前容量
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
	Pof *data;   //信息储存的区域
	int sz;  //有效元素的个数
	int capacity;  //容量
	char filename[100];  //文件名
}Contact,*p;

void Init(p list);         //初始化函数
void Add(p pcon);          //录入函数
void Show(const p pcon);   //显示函数
void Delete(p pcon);       //删除函数
void Search(p pcon);      //寻找函数
void Modify(p pcon);     //修改函数
void Sort(p pcon);      //排序函数
void Clear(p pcon);     //清空函数
void Addcapacity(p pcon); //增容函数
void Save(p pcon);    //保存文件
void display(p pcon);  //文件读入函数
void Destory(p pcon); //释放内存函数

#endif