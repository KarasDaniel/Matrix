#include "Header.h"

int Matrix::add(int a)
{
	
}

Matrix::Matrix()
{
	sizeX = 0;
	sizeY = 0;
}

Matrix::Matrix(const Matrix& x) //конструктор копирования
{
	sizeX = x.sizeX;
	sizeY = x.sizeY;

	m.reserve(sizeY);
	for (int i = 0; i < sizeY; i++)
		m[i].reserve(sizeX);

	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
		{
			m[i][j] = x.m[i][j];
		}
	}
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
}

Matrix Matrix:: operator= (const Matrix& x) //перегрузка опреатора =
{
	m.reserve(x.sizeY);
	for (int i = 0; i < sizeY; i++)
		m[i].reserve(x.sizeX);
}