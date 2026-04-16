	#include <iostream>
	#include <fstream>
	#include <string>
	#include <vector>
	#include <algorithm>


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
		cout << "" << endl;
		cin >> s.surname;
		cout << "" << endl;
		cin >> s.name;
		cout << "" << endl;
		cin >> s.reviews;
		cout << "" << endl;
		cin >> s.shop;
		cout << "" << endl;
		cin >> s.salary;
		ofstream file("objekt.txt", ios::app);
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
		ifstream file("Objket.txt");
		if (!file.is_open()) {
			return ObjektList;
		}
	}
	Objekt s;
	{
		while (file >> s.surname >> s.name >> s.reviwes >> s.salary >> s.shop) {
		ObjektList.push_back 
		}

		file.close();
		return ObjektList;
		}
		
	void ShowAllObjekts()
	{
		vector <Objekt> Objekt = ReadAllObjekt();
		if (Objekt.empty())
			cout << "Empty";
		return;

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
				vector <Objekt> Objekt = ReadAllObjekt;
				if (Objekt.empty()) {
					cout << "Empty" << endl; 
					sort(Objekt.begin(), Objekt.end(), CompareByReviews);
					cout << "--- ТОП 3 ПРОДАВЦІ ЗА ВІДГУКАМИ ---";
