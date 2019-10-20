#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL,"RUS");
	string name;
    cout << "Введит имя\n";
	getline(cin, name);
	bool flag = true;
	for (int i = 0; i < name.length(); i++)
		if ((int)name[i] < 48 || (int)name[i] > 57 && (int)name[i] < 64 || (int)name[i] > 90 && (int)name[i] < 97 || (int)name[i] == 95 || (int)name[i] == 45 || (int)name[i] == 46)
			flag = false;
	cout << flag;
}
