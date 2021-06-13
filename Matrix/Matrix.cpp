#include "Header.h"
#include <iostream>
using namespace std;
int main()
{
    std::cout << "Hello World!\n";
	int y, x, temp;
    cout << "Input number of lines: " << endl;
    cin >> y;
    cout << "Input number of columns: " << endl;
    cin >> x;
    Matrix M;
	M.m.reserve(y);
	for (int i = 0; i < y; i++)
		M.m[i].reserve(x);

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> temp;
			M.m[i][j] = temp;
		}
	}
}

