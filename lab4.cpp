#include < iostream>
using namespace std;
#include "Table.h"
Product b, b2;
Product* buf = &b, * buf2 = &b2;
Tabl t(3, buf);
#include <windows.h>
int main()
{
	//SetConsoleCP(1251);// гбв ­®ўЄ Є®¤®ў®© бва ­Ёжл win-cp 1251 ў Ї®в®Є ўў®¤
	//SetConsoleOutputCP(1251); // гбв ­®ўЄ Є®¤®ў®© бва ­Ёжл win-cp 1251 ў Ї®в®Є ўлў®¤
	//setlocale(LC_ALL, "ru_RU.UTF-8");
	setlocale(LC_ALL, "Russian");
	// SetConsoleOutputCP(866);
	//SetConsoleOutputCP(866);
	//SetConsoleCP(1251);
	char c, endline;
	do
	{
		cout << "for get case input number and press enter" << endl;
		cout << "0-exit" << endl;
		cout << "1-input elements" << endl;
		cout << "2-output elements" << endl;
		cout << "3-find" << endl;
		cout << "4-erase" << endl;
		cout << "5-remove" << endl;
		cout << "6-replace" << endl;
		cout << "7-sort" << endl;
		cin.get(c);
		if (c == '\n')cin.get(c);
		cin.get(endline);
		switch (c)
		{
		case'1':
		{
			cout << "input elements " << endl;
			//t.input(cin); 
			cin >> t;
			cin.clear();
			break;
		}
		case'2':
		{
			cout << "elements:" << endl;
			//t.output(cout);
			cout << t;
			break;
		}
		case '3':
		{
			cout << "input element for find" << endl;
			cin >> *buf;
			int i = t.find(buf);
			if (i >= 0)
				cout << "position=" << i << endl;
			else
				cout << "no found" << endl;
			break;
		}
		case '4':
		{
			cout << "input position for erase" << endl;
			int pos;
			cin >> pos;
			cin.get(endline);
			t.erase(t.begin() + pos);
			break;
		}
		case '5':
		{
			cout << "input element for remove" << endl;
			cin >> *buf;;
			int i = t.remove(buf);
			if (i == 0)
				cout << "no found" << endl;
			break;
		}
		case '6':
		{
			cout << "input OLD element for replace" << endl;
			cin >> *buf;
			cout << "input NEW element for replace" << endl;
			cin >> *buf2;
			int i = t.replace(buf, buf2);
			if (i == 0)
				cout << "no found" << endl;
			break;
		}
		case '7':
		{
			t.sort();
			break;
		}
		}
	} while (c != '0');
	return 0;
}