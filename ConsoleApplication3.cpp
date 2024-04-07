#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
#include <vector>
#include <algorithm>
using namespace std;

//Описать структуру с именем WORKER, содержащую следующие поля : фамилию и инициалы работника(char*, string);
//название занимаемой должности(char*, string); год поступления на работу(int).
//Написать программу, выполняющую следующие действия :
//Ввод данных(файл, клавиатура на выбор пользователя).
//Упорядочить  записи  по алфавиту(фамилию и инициалы)
//Вывод на экран работников, чей стаж работы превышает значение К.
//Вывод на экран работников, работающих в должности N.
//Если  информация не найдена, вывести соответствующее сообщение.
//Предусмотреть возможность редактирования элементов списка – удаление, добавление, изменение.




struct Worker {
	string Name;
	string Employee;
	int Year;

	Worker() {};
	Worker(string _Name, string _Employee, int _Year) : Name(_Name), Employee(_Employee), Year(_Year) {
	}
	friend bool operator<(Worker a, Worker b);
}; 
bool operator<(Worker a, Worker b)
{
	return a.Year < b.Year;
}
vector<Worker> WorkerList;
	void AddWorker(string _Name, string _Employee, int _Year)
	{
		WorkerList.push_back(Worker(_Name, _Employee, _Year));		
	}
	//Добавить нового работников
	void InputWorker(istream& istr)
	{
		int CountWorker; // колличество работников которые надо ввести 
		string Name; 
		string Employee; 
		int Year;
		istr >> CountWorker;
		istr.get();
		for (int i = 0; i < CountWorker; i++)
		{
			getline(istr, Name);
			getline(istr, Employee);
			istr >> Year;
			istr.get();
			AddWorker(Name, Employee, Year);
		}
	}
	// вывод данных на консоль
	void OutputWorker()
	{
		for (int i = 0; i < WorkerList.size(); i++)
		{
			Worker list = WorkerList[i];
			cout << endl << list.Name
				<< endl << list.Employee
				<< endl << list.Year << endl;

		}
			

	}
	void ClearWorkerList()
	{
		WorkerList.clear();
	}

	void WorkerMoreK()
	{
		bool flag = true;
		int K = 0;
		cin >> K;
		if (WorkerList.size() == 0)
		{
			cout << "Список работников пуст." << endl;
		}
		else
		{
			for (int i = 0;i < WorkerList.size();i++)
			{			
				Worker list = WorkerList[i];
				if (list.Year > K)
					cout << endl << list.Name
					<< endl << list.Employee
					<< endl << list.Year << endl;
			
			}
		}
	}
	void WorkerEmployeeN()
	{
		bool flag = true;
		string N;
		getline(cin, N);
		if (WorkerList.size() == 0)
		{
			cout << "Список работников пуст." << endl;
		}
		else
		{
			for (int i = 0; i < WorkerList.size(); i++)
			{
				Worker list = WorkerList[i];
				if (list.Employee == N)
				{
					if (flag) {
						cout << "Список работников на должности " << N << endl;
						cout << endl << list.Name
							<< endl << list.Year << endl;
						flag = false;
				
					}

					
				}

			}
		}
		if (flag)
			cout << "Работников по данной должности не найдено" << endl;
	}
	void DeleteWorkerByName()
	{
		bool flag = true;
		string N;
		getline(cin, N);
		if (WorkerList.size() == 0)
		{
			cout << "Список работников пуст." << endl;
		}
		else
		{
			vector<Worker>::const_iterator it = WorkerList.begin();
			for (; it != WorkerList.end(); it++)
			{
				Worker temp = *it;
				if (temp.Name == N)
				{
					if (flag) {
						cout << "Рабоник "<< N << " Удален" << endl;
						flag = false;
					}
					
					WorkerList.erase(it);
					return;
				}

			}
		}
		if (flag)
			cout << "Работник с данным именем не найден" << endl;
	}
	void ChangeWorker()
	{
		cout << "Введите имя работника" << endl;
		string TakeALook, Name, Employee;
		int Year;
		cin >> TakeALook;
		for (int i = 0; i < WorkerList.size(); i++)
		{
			if (WorkerList[i].Name == TakeALook)
			{
				cout << "Введите в последующих строках:" << endl

					<< "Имя работника" << endl
					<< "Название должности" << endl
					<< "Стаж работы" << endl;
				cin.get(); // считываем из потока символ переноса строки, чтобы корректно считать последующую строку
				getline(cin, Name);
				getline(cin, Employee);
				cin >> Year;
				WorkerList[i].Name = Name;
				WorkerList[i].Employee = Employee;
				WorkerList[i].Year = Year;
				cout << "Данные изменены" << endl;
				return;
			}
		}
		cout << "Товар с данным наименованием не найден" << endl;
	}
	
int main()
{

	setlocale(LC_ALL, "Russian");
	int Case;
	ifstream fin;
	cout << "Выберите способ ввода:" << endl
		<< "1 - с клавиатуры" << endl
		<< "2 - из файла" << endl;
	cin >> Case;
	switch (Case)
	{
	case 1:
		system("cls");
		cout << "Введите в последующих строках:" << endl
			<< "Колличество Работников" << endl
			<< "ФИО" << endl
			<< "Должность" << endl
			<< "Стаж" << endl;
		InputWorker(cin);
		break;
	case 2:
		fin.open("input.txt");
		InputWorker(fin);
		fin.close();
		break;
	default:
		cout << "Введено не верное число.";
		break;
		
	}
	system("cls");
	do
	{
		cout << "Выберите действие:" << endl <<
		"0 - Выход" << endl <<
		"1 - Добавить работника" << endl <<
		"2 - Вывести список всех работников" << endl <<
		"3 - Очистить список  работников" << endl <<
		"4 - Уволить работника" << endl <<
		"5 - Изменить информацию о работнике" << endl <<
		"6 - Поиск работников работающих на указанной должности" << endl <<
		"7 - Поиск работников стаж которых больше указанного значения" << endl<<
		"8 - Сортировка Списка работников по стажу" << endl;
		
	cin >> Case;
	switch (Case)
	{
	case 0:
		system("cls");
		cout << "Завершение программы" << endl;
		break;
	case 1:
		system("cls");
		cout << "Введите в последующих строках:" << endl
			<< "Колличество Работников" << endl
			<< "ФИО" << endl
			<< "Должность" << endl
			<< "Стаж" << endl;
		InputWorker(cin);
		break;
	case 2:
		system("cls");
		cout << "Вывод всех работников" << endl;
	    OutputWorker();
		break;
	case 3:
		system("cls");
		ClearWorkerList();
		break;
	case 4:
		system("cls");
		cout << "Введите ФИО работника" << endl;
		DeleteWorkerByName();
		break;
	case 5:
		system("cls");
		ChangeWorker();
		break;
	case 6:
		system("cls");
		cin.get();
		cout << "Введите название должности" << endl;
		WorkerEmployeeN();
		break;
	case 7:
		system("cls");
		cin.get();
		cout << "Введите стаж работника" << endl;
		WorkerMoreK();
		break;
	case 8:
		system("cls");
		sort(WorkerList.begin(), WorkerList.end());
		break;
	default:
		system("cls");
		cout << "Неверный ввод" << endl;
		break;
	}
	system("pause");
	system("cls");
} while (Case != 0);
	
	return 0;
}