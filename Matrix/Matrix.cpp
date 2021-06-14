#include "Header.h"

int main()
{
	std::cout << "Hello World!\n";
	int y, x;
	int** ptr;


	cout << "Input number of lines: " << endl;
	cin >> y;

	cout << "Input number of columns: " << endl;
	cin >> x;
	Matrix R(y, x);
	cin >> R;
	cout << R;


	Matrix D(R.submatrix(2, 0));
	cout << D;
	cout << "------------" << endl;
	Matrix M(y, x);

	cin >> M;

	cout << M;

	std::vector<int> vector = M.m.at(5);

	for (int i = 0; i < 3; i++)
	{
		cout << vector[i] << " ";
	}
}
