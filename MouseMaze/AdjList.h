#pragma once

//每一个节点连接到其它节点的链表
#include"Vertex.h"
#include<iostream>
class AdjList
{
public:
	Vertex *head;
	Vertex *currentPtr;
	int count;      //连接的节点个数
	AdjList();
	//在头节点的下一个节点插入data节点
	void insert(int row,int column);
	//返回下一个节点数据
	Vertex * next();
	int remove(int row, int column);

};
AdjList::AdjList()
{
	head = new Vertex(0,0, NULL);
	currentPtr = head;
	count = 0;
}

//在头节点的下一个节点插入data节点
void AdjList::insert(int row, int column)
{
	Vertex *nowPtr = new Vertex(row, column, head->next);
	head->next = nowPtr;
	count++;
	currentPtr = head;
}




//返回下一个节点数据
Vertex * AdjList::next()
{
	currentPtr = currentPtr->next;
	return currentPtr;
}


int AdjList::remove(int row, int column)
{
	Vertex *nowPtr = head;

	while(nowPtr->next!=NULL)
	{
		Vertex *tempPtr = nowPtr->next;
		if (tempPtr->row == row&&tempPtr->column == column)
		{
			nowPtr->next = tempPtr->next;
			delete tempPtr;
			count--;
			return 1;
		}
		nowPtr = nowPtr->next;
	}
	return 0;
}