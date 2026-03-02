#pragma once
#include "program.h"
#include <iostream>
#include "SMatrix.h"
#include <algorithm>

using namespace std;

bool program::run()
{

	
	char input;
	cin >> input;
	switch (input) {
	case 'a':
		CmdMatrixInput();
		break;
	case 'p':
	{
		char c;
		cout << "Name of matrix to be printed?";
		cin >> c;

		int i = 0;
		if (i = FindMatrixByID(c) != -1) {
			matrixArray[i].print();
		}

		break;
	}
	case 'b':
	{


		char newMatrixID;
		char matrix1;
		char matrix2;

		int matrixID;

		cout << "Name of result Matrix:";
		cin >> newMatrixID;
		cout << endl << "Matrix1:";
		cin >> matrix1;

		matrixID = FindMatrixByID(matrix1);
		if (matrixID == -1) { cout << "Matrix does not exist. ";  break; }

		cout << endl << "Matrix2";
		cin >> matrix2;

		matrixID = FindMatrixByID(matrix2);
		if (matrixID == -1) { cout << "Matrix does not exist. ";  break; }


		matrixID = FindMatrixByID(matrix1);

		SMatrix M1 = matrixArray[matrixID];

		matrixID = FindMatrixByID(matrix2);

		SMatrix M2 = matrixArray[matrixID];

		SMatrix R = M1 * M2;

		R.ID = newMatrixID;

		matrixArray.push_back(R);

		R.print();
	}
	case 'c':
		break;
	case 'd':


	case '1':
	case '2':
	case '3':
	case '4':


	case 'h':
		helpMenu();
		break;
	}


	return false;

}

void program::CmdMatrixInput()
{
	int columns, rows;
	char MatrixName;
	

	cout << "Enter Matrix name (char)" << endl;

	cin >> MatrixName;
	auto result = find(spentChars.begin(), spentChars.end(), MatrixName);

	if (result != spentChars.end() && spentChars.size() != 0) {
		cout << "Matrix name already used. Please use another." << endl;
		return;
	}
	spentChars.push_back(MatrixName);

	cout << "Enter # of columns" << endl;

	cin >> rows;

	cout << "Enter # of rows" << endl;

	cin >> columns;

	SMatrix* newMatrix = new SMatrix(rows, columns, MatrixName);

	//Read input.

	for (int i = 0; i < rows; i++) {
		cout << "Enter row " << i << ". (" << columns << " numbers, spaced.)" << endl;
		for (int j = 0; j < columns; j++) {
			float newVal = 0;
			cin >> newVal;
			newMatrix->setValue(i, j, newVal);
		}
	}

	//Receipt.

	newMatrix->print();

	matrixArray.push_back(*newMatrix);
	
}

void program::helpMenu()
{
	cout << "\033[1;33m"
		<< "MENU:\nPress a for manual input of a matrix.\n"
		<< "Press p to print a matrix (name).\n"
		<< "Press b to multiply a matrix with another matrix.\n"
		<< "Press c to LU-factorize a matrix.\n"
		<< "Press d solve 'Ax = b' by finding 'x = A^(-1)b'.\n\n"

		<< "Press 1 to solve 4.6.4.\n"
		<< "Press 2 to solve 4.6.7.\n"
		<< "Press 3 to solve 4.6.14.\n"
		<< "Press 3 to solve 4.6.15."

		<< "\n\nPress h for help "

		<< "\033[0m" << endl;
}

int program::FindMatrixByID(char _c)
{
	for (int i = 0; i < matrixArray.size(); i++) {
		if (matrixArray[i].ID == _c) {
			return i;
		}
	}
	cout << "Cannot find matrix '" << _c << "'." << endl;
	return -1;

}
