#pragma once
//зјБъ
class Coord {
public:
	int row;
	int column;
	Coord(){}
	Coord(int row, int column)
	{
		this->row = row;
		this->column = column;
	}
	void setCoord(int row, int column)
	{
		this->row = row;
		this->column = column;
	}
	void setRow(int row)
	{
		this->row = row;
	}
	void setColumn(int column)
	{
		this->column = column;
	}
};
