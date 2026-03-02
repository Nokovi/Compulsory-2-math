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
	Vec4 x;
	Vec4 b_perm({ b[permutasjon[0]], b[permutasjon[1]], b[permutasjon[2]], b[permutasjon[3]] });
	int n = 4;
	int m = 4;

	for (int k = 0; k < n - 1; k++) // m==n
		for (int i = k + 1; i < n; i++)
			b_perm[i] = b_perm[i] - matrix[i][k] * b_perm[k];
	for (int i = n - 1; i >= 0; i--)
	{
		x.val[i] = b_perm[i];
		for (int j = i + 1; j < n; j++)
			x.val[i] = x.val[i] - matrix[i][j] * x.val[j];
		x.val[i] = x.val[i] / matrix[i][i];
	}
	return x;
}

void SMatrix::m4x4LU()
{
	int m = 4;
	int n = 4;
	if (rows != 4 || columns != 4) return;

	for (int k = 0; k < m - 1; k++)
	{
		pivot(k);
		// By row operations we obtain 0 under diagonal element
		// in all rows below (column k)
		// We subtract a multiplum of kth row
		// from the rows below, starting from left
		for (int i = k + 1; i < m; i++) {
			// Multiply with this and subtract from row i
			// This becomes zero, store factor here
			matrix[i][k] = matrix[i][k] / matrix[k][k];
			for (int j = k + 1; j < n; j++) {
				// column to the right of the column which gets zeros
				matrix[i][j] = matrix[i][j] - matrix[i][k] * matrix[k][j];
			}
		}
	}
	print();
}

void SMatrix::pivot(int k)
{
	float EPS = 0.00001;
	float debug = false;
	int m = 4;
	int n = 4;

	if (-EPS <= matrix[k][k] && matrix[k][k] < EPS) // zero diagonalelement
	{
			// pivotering/swap - find row with largest element in column
			if (debug) std::cout << "must pivot.\n";
			int pivot = k + 1; // initiate for row pivoting
			for (int i = k + 2; i < m; i++)
			{
				if (matrix[i][k] > matrix[pivot][k])
					pivot = i;
			}
			if (-EPS <= matrix[k][k] && matrix[k][k] < EPS)
				// std::cout << "Can not make inverse\n";
				; // exception
				// swapper rows
			for (int j = k; j < n; j++)
				std::swap(matrix[k][j], matrix[pivot][j]);
			std::swap(permutasjon[k], permutasjon[pivot]);
	}

}


