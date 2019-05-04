#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;
void doRecFunc(vector<vector<int> > &arr, int i, int j, int n, int m);
int defendFromFool();

void main()
{
	setlocale(LC_ALL, "rus");
	int n,m,kod;
	while (1)
	{
		cout << "введите число строк массива:   ";
		kod = defendFromFool();
		if (kod)
		{
			n = kod; break;
		}
		else
			cout << "\nвыход за пределы целочисленного типа или вы ввели нуль\n";
	}

	cout << '\n';

	while (1)
	{
		cout << "едите кол-во столбцов массива:   ";
		kod = defendFromFool();
		if (kod)
		{
			m = kod; break;
		}
		else
			cout << "\nвыход за пределы целочисленного типа или вы ввели нуль\n";
	}
	
	cout << '\n';

	vector<vector<int> > arr(n, vector<int>(m));

	while (1)
	{
		cout << '\n';
		for (int i = 0; i < n; i++)  //input  array
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];

		for (int i = 0; i < n; i++)  //do some changes
			for (int j = 0; j < m; j++)
				if (arr[i][j] == 1) doRecFunc(arr, i, j, n, m);

		cout << '\n';
		cout << "====================================================================\n";
		cout << "преобразованныйй массив\n";
		cout << "====================================================================\n";
		cout << '\n';

		for (int i = 0; i < n; i++)  //output array
		{
			for (int j = 0; j < m; j++)
				cout << setw(3) << arr[i][j] << ' ';
			cout << endl;
		}
		cout << "цифру-продолжить с теми же параметрами, букву-выйти   ";
		if (cin >> kod) continue; 
		else
			break;
	}

	system("pause");
	return;
}

void doRecFunc(vector<vector<int> > &arr, int i, int j, int n, int m)
{
	if (i > 0)          //замен€ю эл-ты матрицы,которые выше найденной 1, вызываю эту же функцию, если сверху нахожу эл-т=1
	{
		if (j > 0) 
		{
			if (arr[i - 1][j - 1] == 1) 
			{
				arr[i - 1][j - 1] = 0;     //тут и везде далее сразу присваюваю эл-т нулю,чтобы не было бесконечной регрессии
				doRecFunc(arr, i - 1, j - 1, n, m); 
			} else
				arr[i - 1][j - 1] = 0; 
		}
		if (j < m - 1) 
		{
			if (arr[i - 1][j + 1] == 1) 
			{
				arr[i - 1][j + 1] = 0; 
				doRecFunc(arr, i - 1, j + 1, n, m); 
			} else
				arr[i - 1][j + 1] = 0;
		}
		if (arr[i - 1][j] == 1) 
		{
			arr[i - 1][j] = 0;
			doRecFunc(arr, i - 1, j, n, m); 
		} else
			arr[i - 1][j] = 0;
	}

	if (i < n - 1)        //замен€ю эл-ты матрицы,которые ниже найденной 1, вызываю эту же функцию, если сверху нахожу эл-т=1
	{
		if (j > 0) 
		{
			if (arr[i + 1][j - 1] == 1) 
			{
				arr[i + 1][j - 1] = 0; 
				doRecFunc(arr, i + 1, j - 1, n, m); 
			} else 
				arr[i + 1][j - 1] = 0;
		}
		if (j < m - 1) 
		{
			if (arr[i + 1][j + 1] == 1) 
			{
				arr[i + 1][j + 1] = 0;
				doRecFunc(arr, i + 1, j + 1, n, m); 
			} else
				arr[i + 1][j + 1] = 0;
		}
		if (arr[i + 1][j] == 1) 
		{
			arr[i + 1][j] = 0; 
			doRecFunc(arr, i + 1, j, n, m);
		} else
			arr[i + 1][j] = 0;
	}

	if (j > 0)           //замен€ю эл-ты матрицы,которые по бокам относительно найденной 1, вызываю эту же функцию, если сверху нахожу эл-т=1
	{
		if (arr[i][j - 1] == 1) 
		{
			arr[i][j - 1] = 0;
			doRecFunc(arr, i, j - 1, n, m); 
		} else
		arr[i][j - 1] = 0;
	}
	if (j < m - 1)
	{
		if (arr[i][j + 1] == 1) 
		{
			arr[i][j + 1] = 0; 
			doRecFunc(arr, i, j + 1, n, m);
		} else
		arr[i][j + 1] = 0;
	}
	return;
}

int defendFromFool ()
{
	string s = "";
	char c;
	int n;
	while (1)
{
	c = _getch();
	if ((int)c > 47 && (int)c < 58)
	{
		s += c; cout << c;
	}
	else
		if (c == '\r') break;
}
	if (n = stoi(s)) return n; else return 0;
}