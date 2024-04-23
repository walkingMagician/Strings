#include <iostream>
#include <windows.h>

using namespace std;

int string_lenght(const char str[]);
char* to_lower(char str[], int n);
char* to_upper(char str[], int n);
char* shrink(char str[], int n);
bool is_palindrome(char str[]);
bool is_int_number(char str[]);
int to_int_number(char str[]);

void main()
{
	setlocale(LC_ALL, "");

	const int n = 20;
	char str[n];
	cout << "введите строку: ";
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
	cout << endl;
	
	cout << "string_lenght: ";
	cout << string_lenght(str) << endl;

	cout << "to_upper: ";
	cout << to_upper(str, n) << endl;
	
	cout << "to_lower: ";
	cout << to_lower(str, n) << endl;
	
	cout << "shrink: ";
	cout << shrink(str, n) << endl;

	cout << "is_palindrome: ";
	if (is_palindrome(str)) cout << str << " - палендром " << endl;
	else cout << str << " - не палендром " << endl;
	
	cout << "is_int_number: ";
	if (is_int_number(str)) cout << str << " - число " << endl;
	else cout << str << " - не число " << endl;
	
	cout << "to_int_number: ";
	cout << to_int_number(str) * 2 << endl;

}

int string_lenght(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

char* to_lower(char str[], int n)
{
	for (int i = 0; i < n; i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

char* to_upper(char str[], int n) 
{
	for (int i = 0; i < n; i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

char* shrink(char str[], int n)
{
	for (int i = 0; str[i]; i++)
	{
		while ((str[i] == ' ') && (str[i + 1] == ' '))
		{
			for (int j = i + 1; str[j]; j++)
				str[j] = str[j + 1];
		}
	}
	return str;
}

bool is_palindrome(char str[])
{
	int n = strlen(str);
	to_lower(str, n);
	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n - 1 - i]) return false;
	}
	return true;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9') return false;
	}
	return true;
}

int to_int_number(char str[])
{
	int num = 0;
	if (is_int_number(str))
	{
		for (int i = 0; str[i]; i++)
		{
			num *= 10;
			num += str[i] - '0';
		}
	}
	return num;
}