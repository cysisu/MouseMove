#pragma once
//����һ���ڵ���
#include<iostream>
class Vertex
{
public:
	int row;
	int column;
	Vertex *next;

	Vertex(){}

	//��ʼ���Ĺ��캯��
	Vertex(int row=0,int column=0, Vertex *p = NULL) {
		this->row = row;
		this->column = column;
		this->next = p;
	}
};