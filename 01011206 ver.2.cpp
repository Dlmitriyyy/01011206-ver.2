#include <iostream>
#include <iomanip>
using namespace std;

double deposit(int money, int term, double percent, double tax_input)
{
	double tax = tax_input;
	double profit = money * percent / 100 * term / 12 * tax;
	cout << endl << "Прибуток від депозиту складе " << fixed << setprecision(1) << profit << " гривень." << endl;
	return profit;
}
int main()
{
	int choice, money, term;
	double percent, tax_input;

	system("chcp 1251 > nul");

	cout << "Ця програма розраховує прибуток від розміщення депозита певної суми на певний період під певний відсоток." << endl;

	while (true)
	{
		cout << endl << "Введіть 0 якщо бажаєте розрахувати прибуток або довільне число якщо бажаєте закінчити розрахунок і вийти з програми. ";
		cin >> choice;

		if (choice == 0)
		{
			do
			{
				cout << endl << "Введіть сумму на яку бажаєте створити депозит: ";
				cin >> money;
				if (money <= 0)
				{
					cout << endl << "Сума депозиту не може бути рівною нулю або від'ємною. Будь ласка, введіть коректне значення." << endl;
				}
			}

			while (money <= 0);

			do
			{
				cout << endl << "Введіть термін на який бажаєте внести депозит від 1 до 15 місяців: ";
				cin >> term;
				if (term < 1 || term > 15)
				{
					cout << endl << "Термін депозиту не може бути менше 1 або більше 15 місяців. Будь ласка, введіть коректне значення." << endl;
				}
			}

			while (term < 1 || term > 15);

			do
			{
				cout << endl << "Введіть відсоткову ставку депозиту: ";
				cin >> percent;
				if (percent <= 0)
				{
					cout << endl << "Відсоткова ставка не може бути рівною нулю або бути від'ємною." << endl;
				}
			}

			while (percent <= 0);

			do
			{
				cout << endl << "Введіть коефіцієнт оподаткування (0.805 або 1): ";
				cin >> tax_input;
				if (tax_input != 1.0 && tax_input != 0.805)
				{
					cout << endl << "Податок може бути тільки 0.805 або 1." << endl;
				}
			}

			while (tax_input != 1.0 && tax_input != 0.805);

			deposit(money, term, percent, tax_input);
		}

		if (choice < 0 || choice >= 1)
			cout << endl << "Ви вийшли з програми.";
		break;
	}
}