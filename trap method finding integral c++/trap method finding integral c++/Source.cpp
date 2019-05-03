#include <iostream>
#include <math.h>
using namespace std;

double f(double x) //���� �������
{ 
	return sin(x)*sin(x) - x/5; 
}

double I(double a, double b, int n, double y) //���������� ��������� ������� ��������
{ 
	return (b - a) / n * y;
}
				//��� ��� �������� ���������, ����� ������������ ���������
double IN_L_Verification(double x)   //����������� �������� ��������� � ����� a and b ��� �������� �� ������� �������-��������
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
		cin >> n;	cout << '\n'; //n-���������� �������� ���������; a,b - ���������� ��������������

		if (n > 1) {
			dy = (b - a) / n;			//����� ������� ������� �������������� �� �(���)
			y = (f(a) + f(b))/2;			//����� �������� ��������������� ������� �� ������ ��������(�� �������)
			for (int i = 1; i < n; i++)	//����� �������� ��������������� ������� �� ��������(� ������� � �� ��������������)
				y += f(a + dy*i);	//����������� ������ �������� � ��� ��������� �� ������
			In = I(a, b, n, y);			//� ����� �������� �� ��� ��������� 
			cout <<"finded integral is equal " << In << '\n';
		}
		else { cout << "Wrong data!\n"; }		//������� ���� �������� ���������

		cout << "and now i did verification by Newton-Leibniz formula:" << IN_L_Verification(b) - IN_L_Verification(a)<<'\n';

		cout << "would you like to exit(any char)?\n";
		if (!(cin >> exit)) break;
	} while (true);
	system("pause");
}