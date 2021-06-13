#pragma once
#include <vector>
class Matrix
{
public: 
	std::vector<std::vector<int>> m;
	int sizeX, sizeY;

	int add(int a);
	Matrix();
	Matrix(const Matrix& x);
	Matrix(Matrix&& x);
	int determinant();
	bool is_square();
	Matrix operator= (const Matrix& x);
};