#include <iostream>
#include <math.h>

using namespace std;

double f(double x) //возвращает значение функции f(x) = x^2-2
{
	return 0.1*x*x*x+x*x-10*sin(x)-8;
}

double df(double x) //возвращает значение производной
{
	return 0.3*x*x+2*x-10*cos(x);
}

double d2f(double x) // значение второй производной
{
	return 0.6*x+10*sin(x)+2;
}

int main()
{
	int exit = 0, i = 0;//переменные для выхода и цикла
	double x0, xn;// вычисляемые приближения для корня
	double a=-4, b=4, eps;// границы отрезка и необходимая точность

	do {
		i = 0;
		cout << "Please input epsilon:";
		cin >> eps; cout << '\n'; // вводим нужную точность вычислений

		if (f(a)*f(b)>0) // если знаки функции на краях отрезка одинаковые, то здесь нет корня
			cout << "\nError! No roots in this interval\n";
		else
		{
			if (f(a)*d2f(a)>0) x0 = a; // для выбора начальной точки проверяем f(x0)*d2f(x0)>0 ?
			else x0 = b;
			xn = x0 - f(x0) / df(x0); // считаем первое приближение
			cout << ++i << "-th iteration = " << xn << "\n";

			while (fabs(x0 - xn) > eps) // пока не достигнем необходимой точности, будет продолжать вычислят
			{
				x0 = xn;
				xn = x0 - f(x0) / df(x0); // непосредственно формула Ньютона
				cout << ++i << "-th iteration = " << xn << "\n";
			}
			cout << "\nRoot = " << xn; // вывод вычисленного корня
		}

		cout << "\nExit(0)?";
		cin >> exit;
		cout << '\n';

	} while (exit != 0);

	return 0;
}