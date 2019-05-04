#include <iostream>
#include <string>

using namespace std;
struct List
{
	List() { info = 0; prev = nullptr; next = nullptr; }
	double info;
	List *prev,*next;
};
List *lBeg = nullptr, *lEnd = nullptr;//list beg/end

template <typename MyType>	//here use templates to make choises with <int> specializtion and <double> for fees and debts
MyType inputNumber(string &s)
{
	MyType temp;
	while (1)
	{
		s = "";
		bool irInput = false, isPointHere = false, isMinusHere = false;
		getline(cin, s);
		int size = s.size();					//remember this value for cycle par
		if (size == 0) continue;				//empty string has 1 byte (null-term)
		for (int i = 0; i < size; i++)     //check if user pressed not number
		{
			if ((int)s[i] == 45)		//minus
			{
				if (!isMinusHere)
					isMinusHere = true;
				else
				{
					cout << "please, press one minus!\nOk, again: ";
					irInput = true;
				}
			}
			else
				if ((int)s[i] == 46)	//point
				{
					if (!isPointHere)
						isPointHere = true;
					else
					{
						cout << "please, press one point!\nOk, again: ";
						irInput = true;
					}
				}
				else
					if ((int)s[i] < 48 || (int)s[i]>57)		//numbers
					{
						irInput = true;
						cout << "please, enter the numbers only!\nOk, again: ";
						break;
					}
		}

		if (irInput) continue; else //if input is regular-convert string to double or int and return it
		{
			cout << '\n';
			if (isPointHere)
				return(temp = stod(s));
			else
				return(temp = stoi(s));
			break;
		}
	}
}

bool toBegin()
{
	while (true)
	{
		cout << "select side of list?\n"
			<< "1-begin\n"
			<< "0-end\n"
			<< "choise: ";
		string s;
		int choise = inputNumber<int>(s);
		switch (choise)
		{
		case 1: return true;
		case 0: return false;
		default: cout << "please, enter valid numbers!\n";
		}
	}
}

void add()
{
	List *temp = new List;
	cout << "ok, enter the value: ";
	string s;		//template variable for input function
	temp->info = inputNumber<double>(s);
	//choose where to add
	if (toBegin())
	{
		if (lBeg == nullptr)	//first el-t in list
		{
			lBeg = temp; lEnd = temp;
		}
		else
		{
			lBeg->prev = temp;
			temp->next = lBeg;
			lBeg = temp;
		}
	}
	else
	{
		if (lEnd == nullptr)
		{
			lBeg = temp; lEnd = temp;
		}
		else
		{
			lEnd->next = temp;
			temp->prev = lEnd;
			lEnd = temp;
		}
	}
	cout << "ok, info added!\n";
}

void view()
{
	if (toBegin())
	{
		if (lBeg != nullptr)
		{
			int number = 0;
			List *temp = lBeg;
			while (temp!=nullptr)
			{
				cout << ++number << ".  " << temp->info << '\n';
				temp = temp->next;
			}
		}	else
			cout << "list haven't got any information!\n";
	}
	else
	{
		if (lEnd != nullptr)
		{
			int number = 0;
			List *temp = lEnd;
			while (temp != nullptr)
			{
				cout << ++number << ".  " << temp->info << '\n';
				temp = temp->prev;
			}
		}	else
			cout << "list haven't got any information!\n";
	}
}

bool yesOrNo()
{
	while (1)
	{
		cout << "choise: ";
		string s;
		int choise = inputNumber<int>(s);
		if (choise == 0) return 0; else
			if (choise == 1) return 1; else
				cout << "irregular command!\n";
	}
}

void del()
{
	if (lBeg == nullptr)
	{
		cout << "list haven't get any information!\n";
		return;
	}
	else
	{
		view();	//show user all data in list

		int numberFoundVariables = 0;
		List *temp = lBeg;
		cout << "enter the value, which would like to delete from list?\n";
		string s;
		double value = inputNumber<double>(s);

		while (temp!=nullptr)
			{
				if (temp->info == value)
				{
					numberFoundVariables++;
					cout << "are you sure what you want to delete found element from list(0-No,1-Yes)?\n";
					if (yesOrNo()) //ask uder for delete suct element from list
					{

						if (temp->prev != nullptr)	//link the elements in List
						{
							temp->prev->next = temp->next;
						}
						else
							lBeg = temp->next;//if deleted first el-t

						if (temp->next != nullptr)
						{
							temp->next->prev = temp->prev;
							temp = temp->next;
							delete temp->prev;
						}
						else
						{
							lEnd = temp->prev;//if deleted last el-t
							delete temp;
							break;
						}

					}
					else
						temp = temp->next;
				}
				else
					temp = temp->next;
			}
			if (!numberFoundVariables)
				cout << "value not found!\n";
			else
				cout << numberFoundVariables << " found in list!\n";
		}
}

void sort(bool order)
{
	List *i = lBeg;
	while (i->next!= nullptr)	//if not the last one
	{
		List *j = i->next;
		while (j!= nullptr)
		{
			if (order)
			{
				if (i->info < j->info)
					swap(i->info, j->info);
			}
			else
			{
				if (i->info > j->info)
					swap(i->info, j->info);
			}
			j = j->next;
		}
		i = i->next;
	}
	cout << "information sorted!\n";
}

void askOrderForSort()
{
	if (lBeg == nullptr)
	{
		cout << "there is no elements to sort\n";
			return;
	}

	cout << "choose order to sort information(0-ascending,1-descending)!\n";
	if (yesOrNo())
		sort(true);
	else
		sort(false);
}

void task()
{
	if (lBeg != nullptr)
	{
		double average = 0;
		int number = 0;

		List *temp = lBeg;
		while (temp != nullptr)
		{
			average += temp->info;
			number++;
			temp = temp->next;
		}
		average /= number;
		cout << "the average is " <<average<<'\n';

		//now stupid task//
		bool isEven=false;
		temp = lBeg;
		while (temp != nullptr)
		{
			if (isEven)
			{
				isEven = false;
				temp->info = average;
			}
			else
				isEven = true;
			temp = temp->next;
		}
		
	}
	else
		cout << "list haven't got any information!\n";
}

void deleteAll()
{
	List *temp=lBeg;
	while (temp != nullptr)
	{
		if (temp->next != nullptr)
		{
			temp = temp->next;
			delete temp->prev;
		}
		else
		{
			delete temp;
			break;
		}
	}
	lBeg = nullptr;
	lEnd = nullptr;
	cout << "all elements deleted!\n";
}

void main()
{
	int choise = 1;
	while (choise)
	{
		cout << "what would you like to choose?\n"
			<<"0-quit\n"
			<< "1-view info in list\n"
			<< "2-add info in list\n"
			<< "3-delete info from list\n"
			<< "4-sort\n"
			<< "5-calculate the arithmetic mean and replace it with all even elements\n"
			<< "6-delete all\n"
			<< "choise: ";
		string s;
		choise=inputNumber<int>(s);	//use my template function to defend from fool
		switch (choise)
		{
		case 0: break;
		case 1: view(); break;
		case 2: add(); break;
		case 3: del(); break;
		case 4: askOrderForSort(); break;
		case 5: task(); break;
		case 6: deleteAll(); break;
		default: cout << "irregular command!!!\n";
		}
	}
	deleteAll();
	system("pause");
}