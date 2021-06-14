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

Matrix operator + (const Matrix& leftMatrix, const Matrix& rightMatrix)
{
	if (leftMatrix.sizeY == rightMatrix.sizeY && leftMatrix.sizeX == rightMatrix.sizeX)
	{
		Matrix summMatrix(leftMatrix.sizeY, leftMatrix.sizeX);

		for (int i = 0; i < summMatrix.sizeY; i++)
		{
			for (int j = 0; j < summMatrix.sizeX; j++)
			{
				summMatrix.m[i][j] = leftMatrix.m[i][j] + rightMatrix.m[i][j];
			}
		}

		return summMatrix;
	}
	else
	{
		cout << "Enter the correct matrix" << endl;
	}
}

Matrix operator - (const Matrix& leftMatrix, const Matrix& rightMatrix)
{
	if (leftMatrix.sizeY == rightMatrix.sizeY && leftMatrix.sizeX == rightMatrix.sizeX)
	{
		Matrix summMatrix(leftMatrix.sizeY, leftMatrix.sizeX);

		for (int i = 0; i < summMatrix.sizeY; i++)
		{
			for (int j = 0; j < summMatrix.sizeX; j++)
			{
				summMatrix.m[i][j] = leftMatrix.m[i][j] - rightMatrix.m[i][j];
			}
		}

		return summMatrix;
	}
	else
	{
		cout << "Enter the correct matrix" << endl;
	}
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

const std::vector<int>& Matrix::at(const int i)
{
	if (i > m.size()) throw std::out_of_range("Invalid index");

	std::vector<int> vector;

	vector = m[i];

	return vector;
}

const int& Matrix::at(const int i, const int j)
{
	if (j > m.size()) throw std::out_of_range("Invalid index");

	std::vector<int> vector = m.at(i);

	return vector[j];
}

Matrix Matrix::submatrix(int y, int x)
{
	Matrix submatrix(sizeY - 1, sizeX - 1);

	int spaceY = 0;
	int spaceX = 0;

	for (int i = 0, i1 = 0; i < sizeY - 1; i++, i1++)
	{
		for (int j = 0, j1 = 0; j < sizeX - 1; j++, j1++)
		{
			if (i1 == y)
				i1++;
			if (j1 == x)
				j1++;
			submatrix.m[i][j] = m[i1][j1];
		}
	}
	return submatrix;
}

bool Matrix::is_square() // является ли матрица квадратной
{
	if (sizeX == sizeY && sizeX != 0 && sizeX != 1)
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