#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Matrix
{
public:
	std::vector<std::vector<int>> m;
	int sizeX, sizeY;
	int** arr;

	Matrix();
	Matrix(const Matrix& x);

	Matrix(int y, int x);

	const std::vector<int>& at(const int i);
	const int& at(const int i, const int j);

	friend istream& operator>>(istream& in, Matrix& M);
	friend ostream& operator<<(ostream& out, Matrix M);

	Matrix submatrix(int y, int x);

	int determinant();
	bool is_square();
	bool is_two_matrix_equivalent(const Matrix& leftMatrix, const Matrix& rightMatrix);

	friend Matrix operator + (const Matrix& leftMatrix, const Matrix& rightMatrix);
	friend Matrix operator - (const Matrix& leftMatrix, const Matrix& rightMatrix);





	//Matrix operator= (const Matrix& x);
};