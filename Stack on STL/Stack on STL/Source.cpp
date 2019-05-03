#include <stack>
#include <iostream>

using namespace std;

stack <double> st;

void add()
{
	double n = 0;

	cout << "enter the value: ";
	if (!(cin >> n)) n = 0;   //defend from fool
	cout << '\n';

	st.push(n);
}

void view()
{
	stack<double> temp(st);
	int amount = temp.size();

	cout << "\n==========View Stack==================\n";
	for(int i=0;i<amount;i++)
	{
		cout << temp.top() << endl;
		temp.pop();
	}
	if (!amount)cout << "So, there no elements in our stack!\n";
	else cout << "So there are " << amount << " elements in out stack\n";
	cout << "========================================\n";
}

void del()
{
	int choise;
	cout << "would you like to delete 1 element(print 1) or hole stack(any key). By default delete hole stack!\n";
	cout << "choise: "; 

	if(cin>>choise)
		if (choise == 1)
		{
			st.pop();
			cout << "top element deleted!\n";
			return;
		}			//delete 1 element

	int amount = st.size();
	for (int i = 0; i < amount; i++)
	{
		st.pop();
	}
	cout << "stack deleted!\n";
}

double findAverage()
{
	double average=0;
	stack<double> temp(st);
	int size = temp.size();

	for (int i = 0; i < size; i++)
	{
		average += temp.top();
		temp.pop();
	}
	average /= size;
	cout << "the average value in stack is " << average << '\n';
	return average;
}

void invertStack() //here i invert stack for doing stupid tasks
{
	stack<double> inverted;
	int size = st.size();

	for (int i = 0; i < size; i++)
	{
		inverted.push(st.top());
		st.pop();
	}
	st = inverted;			//comebutzk!
}

void task()
{
	double average = findAverage();
	int n = 0;
	stack<double> temp;
	int size = st.size();
	invertStack();

	for (int i = 0; i < size; i++)
	{
		if (i % 2)
			temp.push(average);
		else
			temp.push(st.top());
		st.pop();
	}
	st = temp;

	view();					//and show
	return;
}

void main()
{
	int kod = 1;
	while (kod)
	{
		cout << "Choose what you would like to do:\n" <<
			"press 1 to add a new element to stack\n" <<
			"press 2 to view stack\n" <<
			"press 3 to del element from stack\n" <<
			"press 4 to do the task\n" <<
			"press 0 to quit\n" <<
			"your choise: ";
		if (!(cin >> kod)) kod = 0; cout << '\n'; //defend from fool
		switch (kod)
		{
		case 1: add(); break;
		case 2: view(); break;
		case 3: del(); break;
		case 4: task(); break;
		default: kod = 0;
			break;
		}
	}
	return;
}
