#pragma once
#include <iostream>
#include"AdjList.h"
#include"Coord.h"
#include<time.h>
#include <stdlib.h>

class Graph{
public:
	AdjList LGrap[8][8];
	AdjList hinderGrap[8][8];
	Coord source;
	Coord destination;
public:
	Graph();
	void setHinder();  //�����谭
	void remove(Coord start,int direction);   //ȥ��ĳһ��ǽ���ߵ�������
};

Graph::Graph()
{
	//ÿ���ڵ����Χ4���ڵ�������
	int tmp[4][2] = { { 0,1 },{ 1,0 },{ -1,0 },{ 0,-1 } };
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			for (int j = 0; j < 4; j++)
			{
				//(r,c)���ڵĵ�Ϊ(r1,c1)
				int r1 = row + tmp[j][0];
				int c1 = column + tmp[j][1];
				if (r1 >= 0 && r1 < 8&&c1 >= 0 && c1 < 8)
				{
					LGrap[row][column].insert(r1,c1);
				}
			}
		}
	}
	setHinder();
};

void Graph::setHinder()
{
	int direction;  //�谭�ķ���,0��ʾ���£�1��ʾ����,2��ʾ����4��ʾ����
	int length;   //�谭�ĳ���
	Coord start;  //�谭�����
	
	srand(1);
	//srand((unsigned)time(NULL));
	for (int i = 0; i < 3; i++)  //10����������谭��ͼ
	{
		direction = rand() % 4;
		length = 5;
		start.row = rand() % 8;
		start.column = rand() % 8;
		for (int j = 0; j < length; j++)
		{
			remove(start, direction);
			switch (direction)
			{
			case 0:  //down
				start.column += 1;
				break;
			case 1:  //up
				start.column -= 1;
				break;
			case 2:  //left
				start.row -= 1;
				break;
			case 3:
				start.row += 1;
				break;
			default:
				break;
			}
		}
	}

	for (int i = 0; i < 10; i++)  //10����������谭��ͼ
	{
		direction = rand() % 4;
		length = 5;
		start.row = rand() % 8;
		start.column = rand() % 8;
		for (int j = 0; j < length; j++)
		{
			remove(start, direction);
			switch (direction)
			{
			case 0:  //down
				start.column += 1;
				break;
			case 1:  //up
				start.column -= 1;
				break;
			case 2:  //left
				start.row -= 1;
				break;
			case 3:
				start.row += 1;
				break;
			default:
				break;
			}
		}
	}

	for (int i = 0; i < 10; i++)  //10����������谭��ͼ
	{
		direction = rand() % 4;
		length = 5;
		start.row = rand() % 8;
		start.column = rand() % 8;
		for (int j = 0; j < length; j++)
		{
			remove(start, direction);
			switch (direction)
			{
			case 0:  //down
				start.column += 1;
				break;
			case 1:  //up
				start.column -= 1;
				break;
			case 2:  //left
				start.row -= 1;
				break;
			case 3:
				start.row += 1;
				break;
			default:
				break;
			}
		}
	}
}

void Graph::remove(Coord start, int direction)
{
	if (start.row < 0 || start.column < 0 || start.row > 8 || start.column > 8)
		return;
	Coord coord1;
	Coord coord2;
	switch (direction)
	{
	case 0:  //down
		 coord1.setCoord(start.row, start.column - 1);
		 coord2.setCoord(start.row, start.column);
		break;
	case 1:  //up
		 coord1.setCoord(start.row-1, start.column - 1);
		 coord2.setCoord(start.row-1, start.column);
		break;
	case 2:  //left
		 coord1.setCoord(start.row-1, start.column - 1);
		 coord2.setCoord(start.row, start.column-1);
		break;
	case 3:   //right
		 coord1.setCoord(start.row-1, start.column);
		 coord2.setCoord(start.row, start.column);
		break;
	default:
		return;
	}
	if (coord1.row < 0 || coord1.row>7 || coord1.column <0 || coord1.column>7)
		return;
	if (coord2.row < 0 || coord2.row>7 || coord2.column <0 || coord2.column>7)
		return;
	LGrap[coord1.row][coord1.column].remove(coord2.row, coord2.column);
	LGrap[coord2.row][coord2.column].remove(coord1.row, coord1.column);
	hinderGrap[coord1.row][coord1.column].insert(coord2.row, coord2.column);
	hinderGrap[coord2.row][coord2.column].insert(coord1.row, coord1.column);
}