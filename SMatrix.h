#pragma once
#include <vector>
#include <string>
#include <iostream>

//simple struct.
struct Vec4 {
	float val[4];



	void print() {
		std::cout << "< ";
		for (int i = 0; i < 4; i++) {
			std::cout << i << " ";
		}
		std::cout << ">" << std::endl;
	}

	float& operator[](int i) {
		return val[i];
	}
};


//complicated struct with methods and private members. Classy.
struct SMatrix
{
	std::vector<std::vector<float>> matrix;

	int permutasjon[4] = {0,1,2,3};

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

	void m4x4LU();

	void pivot(int k);
};

