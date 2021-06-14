#include "Header.h"

Matrix::Matrix()
{
	sizeX = 0;
	sizeY = 0;
}

Matrix::Matrix(int y, int x)
{
	sizeX = x;
	sizeY = y;
	m.resize(y);
	for (int i = 0, size = m.capacity(); i < size; ++i)
		m[i].resize(x);
}

Matrix::Matrix(const Matrix& x) //конструктор копирования
{
	sizeX = x.sizeX;
	sizeY = x.sizeY;
	m = x.m;
}

istream& operator>>(istream& in, Matrix& M)
{
	for (int i = 0; i < M.sizeY; ++i)
	{
		for (int j = 0; j < M.sizeX; ++j)
		{
			in >> M.m[i][j];
		}
	}
	return in;
}

ostream& operator<<(ostream& out, Matrix M) {

	for (int i = 0; i < M.sizeY; ++i)
	{

		for (int j = 0; j < M.sizeX; ++j)
		{

			out << M.m[i][j] << " ";

		}
		out << endl;
	}

	return out;
}


bool Matrix::is_square() // является ли матрица квадратной
{
	if (sizeX == sizeY && sizeX!=0 && sizeX!=1)
		return 1;
	return 0;
}

int Matrix::determinant() // работает только для матриц второго порядка
{
	if (is_square())
	{
		if (sizeX == 2)
		{
			return m[0][0] * m[1][1] - m[0][1] * m[1][0];
		}
	}
	return 0;
}
/*
Matrix Matrix:: operator= (const Matrix& x) //перегрузка опреатора =
{
	Matrix M;
	M.m.reserve(x.sizeY);
	m.reserve(x.sizeY);
	for (int i = 0; i < sizeY; i++)
	{
		m[i].reserve(x.sizeX);
		M.m[i].reserve(x.sizeX);
	}
	return M;


}
*/