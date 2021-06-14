#include "Header.h"

int main()
{
    std::cout << "Hello World!\n";
	int y, x;

	cout << "Input number of lines: " << endl;
	cin >> y;

	cout << "Input number of columns: " << endl;
	cin >> x;

	Matrix M(y, x);
	
	cin >> M;

	cout << M;
}

