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
		cout << "������� ����� ����� �������:   ";
		kod = defendFromFool();
		if (kod)
		{
			n = kod; break;
		}
		else
			cout << "\n����� �� ������� �������������� ���� ��� �� ����� ����\n";
	}

	cout << '\n';

	while (1)
	{
		cout << "����� ���-�� �������� �������:   ";
		kod = defendFromFool();
		if (kod)
		{
			m = kod; break;
		}
		else
			cout << "\n����� �� ������� �������������� ���� ��� �� ����� ����\n";
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
		cout << "���������������� ������\n";
		cout << "====================================================================\n";
		cout << '\n';

		for (int i = 0; i < n; i++)  //output array
		{
			for (int j = 0; j < m; j++)
				cout << setw(3) << arr[i][j] << ' ';
			cout << endl;
		}
		cout << "�����-���������� � ���� �� �����������, �����-�����   ";
		if (cin >> kod) continue; 
		else
			break;
	}

	system("pause");
	return;
}

void doRecFunc(vector<vector<int> > &arr, int i, int j, int n, int m)
{
	if (i > 0)          //������� ��-�� �������,������� ���� ��������� 1, ������� ��� �� �������, ���� ������ ������ ��-�=1
	{
		if (j > 0) 
		{
			if (arr[i - 1][j - 1] == 1) 
			{
				arr[i - 1][j - 1] = 0;     //��� � ����� ����� ����� ���������� ��-� ����,����� �� ���� ����������� ���������
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

	if (i < n - 1)        //������� ��-�� �������,������� ���� ��������� 1, ������� ��� �� �������, ���� ������ ������ ��-�=1
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

	if (j > 0)           //������� ��-�� �������,������� �� ����� ������������ ��������� 1, ������� ��� �� �������, ���� ������ ������ ��-�=1
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