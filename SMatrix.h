#pragma once
#include <vector>
#include <string>


//simple struct.
struct Vec4 {
	float X, Y, Z, W;
};


//complicated struct with methods and private members. Classy.
struct SMatrix
{
	std::vector<std::vector<float>> matrix;
public:

//variables
	int rows;
	int columns;
	
	char ID = ' ';
	




	SMatrix(int, int, char);
	~SMatrix();


//methods

	void readMatrix(std::string file);

	//because this matrix can have very different sizes, please use this function to read values.
	float getValue(int _row, int _column);
	bool setValue(int _row, int _column, float value);

	void setMatrix(std::vector<std::vector<float>>);
	std::vector<std::vector<float>> getMatrix();


	SMatrix operator*(const SMatrix& _m);

	void print();


	Vec4 Solve(Vec4 &b);



};

