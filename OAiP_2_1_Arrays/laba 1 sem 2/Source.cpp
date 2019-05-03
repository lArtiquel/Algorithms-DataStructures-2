#include <iostream>

using namespace std;
void foo(int *arr, int n, int &number_of_elements, int &sum)
{
	bool thisArrHasNull = false;
	for (int i = 0; i < n; i++)
	{
		cin >> *(arr + i);
		if (!thisArrHasNull)
		{
			if (arr[i] == 0) thisArrHasNull = true;
		}
		else
		{
			sum += arr[i];
			number_of_elements++;
		}
	}
	delete[]arr;
	return;
}

void printInfoAboutArray(int number_of_elements,int sum)
{
	cout << "number of elements after the first zero in array: " << number_of_elements << '\n';
	cout << "sum of elements arter the first zero in array: " << sum << '\n';
	return;
}

void main()
{
	int n, *arr=NULL,number_of_elements=0, sum=0;
	cout << "Please, enter the number of elements of array\n";
	cin >> n;
	arr = new int[n];
	if (arr != NULL)
	{
		foo(arr, n, number_of_elements, sum);
		printInfoAboutArray(number_of_elements, sum);
	}
	system("pause");
	return;
}