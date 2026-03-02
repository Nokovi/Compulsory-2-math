#pragma once
#include <iostream>
#include <vector>
#include "SMatrix.h"



class program
{


public:
	//default constructor and destructor.
	program() {}
	~program() {}

	std::vector<char> spentChars;

	bool run();

	std::vector < SMatrix > matrixArray;


	void CmdMatrixInput();

	void solveExercise1();
	void solveExercise2();
	void solveExercise3();
	void solveExercise4();

	void printMatrix(char matrixID);
	void LUFactorizeMatrix(SMatrix&);
	
	void helpMenu();


	int FindMatrixByID(char _c);
};

