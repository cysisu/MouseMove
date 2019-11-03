#pragma once

//ÿһ���ڵ����ӵ������ڵ������
#include"Vertex.h"
#include<iostream>
class AdjList
{
public:
	Vertex *head;
	Vertex *currentPtr;
	int count;      //���ӵĽڵ����
	AdjList();
	//��ͷ�ڵ����һ���ڵ����data�ڵ�
	void insert(int row,int column);
	//������һ���ڵ�����
	Vertex * next();

};
AdjList::AdjList()
{
	head = new Vertex(0,0, NULL);
	currentPtr = head;
	count = 0;
}

//��ͷ�ڵ����һ���ڵ����data�ڵ�
void AdjList::insert(int row, int column)
{
	Vertex *nowPtr = new Vertex(row, column, head->next);
	head->next = nowPtr;
	count++;
	currentPtr = head;
}




//������һ���ڵ�����
Vertex * AdjList::next()
{
	currentPtr = currentPtr->next;
	return currentPtr;
}