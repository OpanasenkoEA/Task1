#include "Matrix.h"
using namespace std;


int main()
{
	cout << "Enter the dimension of the first matrix: ";
	int a, b;
	cin >> a >> b;
	Matrix matriza1(a, b);
	matriza1.matrix_enter();
	system("cls");
	cout << "Enter the dimension of the second matrix: ";
	cin >> a >> b;
	Matrix matriza2(a, b);
	matriza2.matrix_enter();
	system("cls");
	int buf; 
	while (true)
	{
		cout << "What kind of operation do you want to perform with them?\n1.+\n2.*\n3.-\n Enter the number: ";
		cin >> buf;
		try
		{
			switch (buf)
			{
			case 1:
				(matriza1 + matriza2).show();
				break;
			case 2:
				(matriza1 * matriza2).show();
				break;
			case 3:
				(matriza1 +(-matriza2)).show();
				break;
			}
		}
		catch (const char* str)
		{
			cout << str;
			cin.get();
			system("cls");
			continue;
		}
	}
	
	
}