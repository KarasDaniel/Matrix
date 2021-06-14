#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Matrix
{
public: 
	std::vector<std::vector<int>> m;
	int sizeX, sizeY;
	
	Matrix();
	Matrix(const Matrix& x);
	
	Matrix(int y, int x);

	friend istream& operator>>(istream& in, Matrix& M);
	friend ostream& operator<<(ostream& out, Matrix M);

	int determinant();
	bool is_square();


	//Matrix operator= (const Matrix& x);
};