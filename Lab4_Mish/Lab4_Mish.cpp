#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

bool addressCheck(string adr, int& countBeforeSobaka, int& countAfterSobaka);

int main()
{
	setlocale(LC_ALL,"RUS");
	string adress;
    cout << "Введит адрес\n";
	getline(cin, adress);
	bool flag = true;
	int countB = 0, countA = 0;
	if (addressCheck(adress, countB, countA))
	{
		for (int i = 0; i < countB - 1; i++)
			if ((int)adress[i] < 48 || (int)adress[i] > 57 && (int)adress[i] < 64 || (int)adress[i] > 90 && (int)adress[i] < 97 || (int)adress[i] == 95 || (int)adress[i] == 45 || (int)adress[i] == 46)
				flag = false;
		if (flag)
			cout << "Корректно\n";
		else
			cout << "Не корректно\n";
	}
	else
		cout << "Не является адресом\n";
	cout << "CountBefore " << countB << " CountAfter " << countA << endl;
}

bool addressCheck(string adr, int &countBeforeSobaka, int &countAfterSobaka) 
{
	bool sobaka = false;
	for (int i = 0; i < adr.length(); i++) 
	{
		if ((int)adr[i] != 64 && sobaka == false)
			countBeforeSobaka++;
		else if (sobaka == true)
			countAfterSobaka++;

		if ((int)adr[i] == 64)
			sobaka = true;
	}
	if (sobaka && countAfterSobaka && countBeforeSobaka)
		return true;
	return false;
}