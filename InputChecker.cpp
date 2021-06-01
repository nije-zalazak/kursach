#include "InputChecker.h"

bool TryParse(string str, int& value)
{
	try
	{
		size_t a = 0;
		value = stoi(str, &a);
		if (a != str.size())
		{
			throw false;
		}
		return true;
	}
	catch (...)
	{
		value = 0;
		return false;
	}
}

bool TryParse(string str, double& value)
{
	try
	{
		size_t a = 0;
		setlocale(LC_ALL, "en");
		value = stod(str, &a);
		setlocale(LC_ALL, "");
		if (a != str.size())
		{
			throw false;
		}
		return true;
	}
	catch (...)
	{
		value = 0;
		return false;
	}
}

int ReadInt()
{
	int value;
	string str;
	cin >> str;
	bool isCorrect = TryParse(str, value);
	while (isCorrect == false)
	{
		cout << "Неверный ввод, повторите попытку: ";
		cin >> str;
		isCorrect = TryParse(str, value);
	}
	return value;
}

bool AskForEnd()
{
	int choice;
	cout << "Хотите продолжить? 1 - да, 2 - нет." << endl;
	choice = GetInt(2);
	if (choice == 2)
	{
		return false;
	}
	else
	{
		return true;
	}
}

double GetDouble()
{
	double value;
	string str;
	cin >> str;
	bool isCorrect = TryParse(str, value);
	while (isCorrect == false)
	{
		cout << "Неверный ввод, повторите попытку: ";
		cin >> str;
		isCorrect = TryParse(str, value);
	}
	return value;
}
double GetDouble(double min, double max) {
	double value;
	string str;
	bool isCorrect;
	while (true)
	{
		cin >> str;
		isCorrect = TryParse(str, value);
		if (isCorrect) {
			if (value >= min && value <= max) {
				return value;
			}
			else {
				cout << "Неверный диапазон, повторите попытку: ";
			}
		}
		else {
			cout << "Неверный ввод данных, повторите попытку: ";
		}
	}

}
string ReadDate()
{
	string date;
	int i;
	bool isCorrected = false;
	while (isCorrected == false)
	{
		cin >> date;
		if (date.length() != 10 || date[2] != '.' || date[5] != '.')
		{
			system("cls");
			cout << "Неверный ввод. Повторите попытку: ";
			continue;
		}
		for (i = 0; date[i] != '\0'; i++)
		{
			if ((date[i] < '0' || date[i] > '9') && i != 2 && i != 5)
			{
				cout << "Неверный ввод. Повторите попытку: ";
				break;
			}
		}
		if (date[i] == '\0')
		{
			isCorrected = true;
		}
	}
	return date;
}

int GetInt(int maxNumber)
{
	int choice = ReadInt();
	while (choice < 0 || choice > maxNumber)
	{
		cout << "Неверный ввод, повторите попытку: " << endl;
		choice = ReadInt();
	}
	return choice;
}

int GetInt(int minNumber, int maxNumber)
{
	int choice = ReadInt();
	while (choice < minNumber || choice > maxNumber)
	{
		cout << "Неверный ввод, повторите попытку: " << endl;
		choice = ReadInt();
	}
	return choice;
}


template<class T>
void Swap(T& t1, T& t2)
{
	T temp1 = t1;
	t1 = t2;
	t2 = temp1;
}
