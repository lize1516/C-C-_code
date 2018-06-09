#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#define MAX 10
#define CATACITY 2

typedef int Datatype;

typedef struct Seqlist
{
	Datatype* data;
	int sz;
	int catacity;
}Seq, *p;

void InitSeqlist(p ps);
void PushBack(p ps, Datatype d);
void PopBack(p ps);
void Display(const p ps);
void PushFront(p ps, Datatype d);
void PopFront(p ps);
int  Find(p ps, Datatype d);
void Insert(p ps, Datatype d, int pos);
void Remove(p ps, Datatype d);
void RemoveAll(p ps, Datatype d);
void Reverse(p ps);
void Sort(p ps);
int BinarySearch(p ps, Datatype d);
void ReleaseSpace(p ps);    //释放空间

#endif //__SEQLIST_H__
