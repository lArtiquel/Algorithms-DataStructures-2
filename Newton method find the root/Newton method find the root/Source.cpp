#include <iostream>
#include <math.h>

using namespace std;

double f(double x) //���������� �������� ������� f(x) = x^2-2
{
	return 0.1*x*x*x+x*x-10*sin(x)-8;
}

double df(double x) //���������� �������� �����������
{
	return 0.3*x*x+2*x-10*cos(x);
}

double d2f(double x) // �������� ������ �����������
{
	return 0.6*x+10*sin(x)+2;
}

int main()
{
	int exit = 0, i = 0;//���������� ��� ������ � �����
	double x0, xn;// ����������� ����������� ��� �����
	double a=-4, b=4, eps;// ������� ������� � ����������� ��������

	do {
		i = 0;
		cout << "Please input epsilon:";
		cin >> eps; cout << '\n'; // ������ ������ �������� ����������

		if (f(a)*f(b)>0) // ���� ����� ������� �� ����� ������� ����������, �� ����� ��� �����
			cout << "\nError! No roots in this interval\n";
		else
		{
			if (f(a)*d2f(a)>0) x0 = a; // ��� ������ ��������� ����� ��������� f(x0)*d2f(x0)>0 ?
			else x0 = b;
			xn = x0 - f(x0) / df(x0); // ������� ������ �����������
			cout << ++i << "-th iteration = " << xn << "\n";

			while (fabs(x0 - xn) > eps) // ���� �� ��������� ����������� ��������, ����� ���������� ��������
			{
				x0 = xn;
				xn = x0 - f(x0) / df(x0); // ��������������� ������� �������
				cout << ++i << "-th iteration = " << xn << "\n";
			}
			cout << "\nRoot = " << xn; // ����� ������������ �����
		}

		cout << "\nExit(0)?";
		cin >> exit;
		cout << '\n';

	} while (exit != 0);

	return 0;
}