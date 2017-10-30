/*
Вариант 24.
1. Отсортировать массив простых делителей по степени кратности.
2. Отсортировать массив делителей числа по сумме цифр.
3. Вывести все делители натурального числа, являющиеся  палиндромами.
*/

#include <iostream>
#include <cmath>

using namespace std;
int SumSigns(int a)
{
	if (a < 0)
	{
		return 0;
	}
	int sum = 0;
	while (a > 0)
	{
		sum += a % 10;
		a /= 10;
	}
	return sum;
}
bool IsSimple(int a)
{
	if (a <= 1)
	{
		return false;
	}
	else
	{
		for (int i = 1; i < sqrt(a) + 1; i++)
		{
			if (a%i == 0)
			{
				return false;
			}
		}
		return true;
	}
}
bool IsPolindrom(int a)
{
	int c = 0, aCopy = a, numbers = 0;
	if (a <= 0)
	{
		return false;
	}
	while (aCopy > 0)
	{
		numbers++;
		aCopy /= 10;
	}
	aCopy = a;
	for (int i = 0; i < numbers / 2 ; i++)
	{
		c = pow(10, numbers - 1);
		if ((aCopy % 10) != (aCopy / c))
		{
			return false;
		}
		aCopy /= 10;
		aCopy = aCopy - pow(10, --numbers);
		numbers--;
	}
	return true;
}
int main()
{
	int n;
	cout << "Enter n\n";
	cin >> n;
	while (n <= 0)
	{
		cout << "ERROR! Does not make any sense!\n";
		cin >> n;
	}
	cout << "Polindroms: \n";
	for (int i = 1; i < sqrt(n) + 1; i++)
	{
		if (n % i == 0)
		{
			if (IsPolindrom(i))
			{
				cout << i << " ";
			}
		}
	}
	cout << endl;
	//cout << IsPolindrom(n);
	system("pause");
	return 0;
}