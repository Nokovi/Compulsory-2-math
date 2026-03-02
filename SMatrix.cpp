#include "SMatrix.h"
#include <iostream>


SMatrix::SMatrix(int _rows, int _columns, char _name)
{
	rows = _rows;
	columns = _columns;
	ID = _name;
	

	//initialize to size with 0s. Otherwise we might get trouble.
	for (int i = 0; i < _rows; i++) {
		std::vector<float> row;
		for (int i = 0; i < _columns; i++) {
			row.push_back(0.0f);
		}
		matrix.push_back(row);
	}
}

SMatrix::~SMatrix()
{
}

void SMatrix::readMatrix(std::string file)
{
	
}

float SMatrix::getValue(int _row, int _column)
{
	if (matrix.size() > _row) {
		if (matrix[_row].size() > _column) {
			return matrix[_row][_column];
		}
	}
	else return 0;
}


//returns boolean to check if it's possible.
bool SMatrix::setValue(int _row, int _column, float value)
{
	if (matrix.size() > _row) {
		if (matrix[_row].size() > _column) {

			matrix[_row][_column] = value;
			return true;
		}
		else return false;
	}
	else return false;
}

void SMatrix::setMatrix(std::vector<std::vector<float>> _matrix)
{
	if (_matrix.size() == 0) {
		std::cout << "\n[Error!] New matrix has no columns!" << std::endl;
		return;
	}
	matrix = _matrix;
	rows = _matrix.size();
	columns = _matrix[0].size();
}

std::vector<std::vector<float>> SMatrix::getMatrix()
{
	return matrix;
}

SMatrix SMatrix::operator*(const SMatrix& _m)
{
	//can only multiply matrixes if the rows and columns are equal.
	
	if (columns != _m.rows) return SMatrix(0,0, '-'); //do this later.
	else{
		SMatrix tempMatrix = SMatrix(rows, _m.columns, '.'); // remember to set a new name!

		for (int row = 0; row < rows; row++) {
			for (int column = 0; column < _m.columns; column++) {
				float val = 0;

				for (int i = 0; i < columns; i++) {
					
					val += getValue(row, i) * _m.matrix[i][column];
				}
				std::cout << std::endl;
				tempMatrix.setValue(row, column, val);
			}
		}

		return tempMatrix;
	}
	
	return SMatrix(0, 0, '-'); //bogus empty matrix as fallback.
}

void SMatrix::print()
{
	std::cout << "Matrix " << ID << " is:" << std::endl;
	for (int i = 0; i < rows; i++) {
		std::cout << "[";
		for (int j = 0; j < columns; j++) {
			std::cout << " " << getValue(i, j) << " ";
		}
		std::cout << "]" << std::endl;
	}
}

Vec4 SMatrix::Solve(Vec4& b)
{
	return Vec4{0,0,0,0};
}


