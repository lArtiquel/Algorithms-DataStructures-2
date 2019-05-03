#include <iostream>
#include <math.h>
using namespace std;

double f(double x) //сама функция
{ 
	return sin(x)*sin(x) - x/5; 
}

double I(double a, double b, int n, double y) //вычисление интеграла методом трапеций
{ 
	return (b - a) / n * y;
}
				//так как интеграл берущийся, можно организовать провероку
double IN_L_Verification(double x)   //высчитанное значение интеграла в точке a and b для проверки по формуле Ньютона-Лейбница
{
	return 1. / 10*((-x*(x - 5)) - 5 * sin(x)*cos(x));
}

int main() {
	int exit=0;
	do
	{
		int n;
		double a, b, y = 0, dy, In;
		cout << "enter the integration interval:\n";
		cin >> a >> b;
		cout << "\nnumber of segments of a partition:\n";
		cin >> n;	cout << '\n'; //n-количество отрезков разбиения; a,b - промежуток интегрирования

		if (n > 1) {
			dy = (b - a) / n;			//длина каждого отрезка интегрирования по х(шаг)
			y = (f(a) + f(b))/2;			//сумма значений подынтегральных функций на концах отрезков(по формуле)
			for (int i = 1; i < n; i++)	//сумма значений подынтегральной функции на отрезках(с первого и до предпоследнего)
				y += f(a + dy*i);	//инкрементим данные значения к уже имеющимся на концах
			In = I(a, b, n, y);			//и берем интеграл по уже извесному 
			cout <<"finded integral is equal " << In << '\n';
		}
		else { cout << "Wrong data!\n"; }		//слишком мало отрезков разбиения

		cout << "and now i did verification by Newton-Leibniz formula:" << IN_L_Verification(b) - IN_L_Verification(a)<<'\n';

		cout << "would you like to exit(any char)?\n";
		if (!(cin >> exit)) break;
	} while (true);
	system("pause");
}