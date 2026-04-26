#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Objekt
{
	string surname;
	string name;
	int reviews;
	double salary;
	string shop;
};
void AddObjekt()
{
	Objekt s;
	cout << "Введіть прізвище" << endl;
	cin >> s.surname;
	cout << "Введіть ім'я" << endl;
	cin >> s.name;
	cout << "Введіть відгуки" << endl;
	cin >> s.reviews;
	cout << "Введіть магазин" << endl;
	cin >> s.shop;
	cout << "Введіть ЗП" << endl;
	cin >> s.salary;
	ofstream file("Objekt.txt", ios::app);
	if (file.is_open())
	{
		file << s.surname << " " << s.name << " " << s.reviews << " " << s.salary << " " << s.shop << endl;
		file.close();
		cout << "Данні додані в файл" << endl;
	}
	else {
		cout << "" << endl;
	}

}

vector<Objekt> ReadAllObjekt()
{
	vector<Objekt> ObjektList;
	ifstream file("Objekt.txt");
	if (!file.is_open()) {
		return ObjektList;
	}

	Objekt s;
	{
		while (file >> s.surname >> s.name >> s.reviews >> s.salary >> s.shop) {
			ObjektList.push_back(s);
		}

		file.close();
		return ObjektList;
	}
}

void ShowAllObjekts()
{
	vector <Objekt> Objekt = ReadAllObjekt();
	if (Objekt.empty()) {
		cout << "Empty";
		return;
	}
	cout << "--- ВСІ ПРОДАВЦІ В БАЗІ ---" << endl;
	for (const auto& s : Objekt) {
		cout << "Прізвище: " << s.surname << " | Ім'я: " << s.name
			<< " | Відгуки: " << s.reviews << " | ЗП: " << s.salary
			<< " | Магазин: " << s.shop << endl;
	}
}
bool CompareByReviews(const Objekt& a, const Objekt& b) {
	return a.reviews > b.reviews;
}

void Top3()
{
	{
		vector<Objekt> Objekt = ReadAllObjekt();

		if (Objekt.empty()) {
			cout << "Empty" << endl;
			return;
		}
		sort(Objekt.begin(), Objekt.end(), CompareByReviews);
		cout << "--- ТОП 3 ПРОДАВЦІ ЗА ВІДГУКАМИ ---" << endl;
		int count = min(3, (int)Objekt.size());
		for (int i = 0; i < count; i++) {
			cout << i + 1 << ". " << Objekt[i].surname << " " << Objekt[i].name
				<< " - Відгуків: " << Objekt[i].reviews << endl;
		}
	}
}



int main()
{
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	int choice;
	while (true) {
		cout << "1. Додати | 2. Всі | 3. Топ-3 | " << endl << "Вихід 0" << endl << "Обирай" << endl;
		cin >> choice;

		if (choice == 1) AddObjekt();
		else if (choice == 2) ShowAllObjekts();
		else if (choice == 3) Top3();
		else if (choice == 0) break;
	}

	return 0;
}