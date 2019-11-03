#pragma once
//定义一个节点类
#include<iostream>
class Vertex
{
public:
	int row;
	int column;
	Vertex *next;

	Vertex(){}

	//初始化的构造函数
	Vertex(int row=0,int column=0, Vertex *p = NULL) {
		this->row = row;
		this->column = column;
		this->next = p;
	}
};