#include "group.h"
#include <iomanip>

Group g_database;

void student_save(string fio, int grn, int marks[5])
{
	Student st;

	st.SetGroup(grn);
	st.SetFullname(fio);

	int i = 0;
	while (i < 5)
	{
		st.SetMark(i, marks[i]);
		i = i + 1;
	}
	g_database.Add(st);
}
// Показать меню ввода студента и определение его в группу
void student_work()
{
	int choise;
	int mark1;
	int mark2;
	int mark3;
	int mark4;
	int mark5;
	int group = 0;

	char  fio[30] = { 0 };
	
	while (true)
	{
		if (group == 0)
		{
			cout << "0. Set current student group" << endl;
		}
			
		cout << "1. Enter student's FIO" << endl;
		cout << "2. Input student's marks" << endl;
		cout << "3. Save current student" << endl;
		cout << "#. Back to top menu" << endl;

		cin >> choise;

		if (choise == 0)
		{
			cout << "Group:" << endl;
			cin >> group;

			cout << "Group accepted" << endl;
			cout << "Current group is " << group << endl;
		}
		else if (choise == 1)
		{
			cout << "FIO: " << endl;
			cin.ignore();
			cin.getline(fio, 30);
			// Вывести ФИО для контроля
			cout << "*" << fio << endl;
			cout << "FIO accepted" << endl;
		}
		else if (choise == 2)
		{
			cout << "Mark 1" << endl;
			cin >> mark1;
			cout << "Mark 2" << endl;
			cin >> mark2;
			cout << "Mark 3" << endl;
			cin >> mark3;
			cout << "Mark 4" << endl;
			cin >> mark4;
			cout << "Mark 5" << endl;
			cin >> mark5;
			cout << "Marks accepted" << endl;
		}
		else if (choise == 3)
		{
			int marks[] = { mark1, mark2, mark3, mark4, mark5 };
			student_save(string(fio), group, marks);
			cout << "Saved..." << endl;
		}
		else
		{
			return;
		}
	}
	
}

// Вывести данные студентов групп по возрастанию номеров группы
void student_show()
{
	int i = 0;
	int all = 0;
	int db_size = g_database.GetSize();
	
	g_database.Sort();	// Реализовано

	while (i < db_size)
	{
		Student st = g_database.GetByIndex(i);
		float avg = st.CalcAverage();

		if (avg >= 4.0)
		{
			
			// Табличный вывод
			cout << setw(6) << st.GetGroup() << " | ";
			cout << setw(12) << st.GetFullname().c_str() << " | ";
			cout << avg << endl;

			all = all + 1;
		}
		
		i = i + 1;
	}
	cout << endl;

	if (all == 0)
	{
		cout << "No students with such criteria" << endl << endl;
	}
}

void show_menu()
{
	int choise;

	while (true)
	{
		cout << "Student database" << endl;
		cout << "1. Enter student data" << endl;
		cout << "2. Show students (if avg >4.0)" << endl;
		cout << "#. Exit" << endl;

		cin >> choise;

		if (choise == 1)
		{
			student_work();
		}
		else if (choise == 2)
		{
			student_show();
		}
		else 
		{
			cout << "Bye!" << endl;
			return;
		}
	}
}
int main()
{
	// Показать меню пользователя
	// Ввод данных для класса студент
	// Объединение студентов в группы
	// Вывод студентов у кого средний балл больше 4.0
	// Если таких студентов нет - вывести сообщение
	char c;

	show_menu();  // Показать меню	

	cin.ignore(); // Вариант как остановить немедленное завершение
	cin.get(c);   // программы
	
	return 0;
}