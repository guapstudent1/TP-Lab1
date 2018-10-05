#include "student.h"
// Это не организационная единица
// Это база данных студентов из разных групп
// Добавить студента в базу
// Работа с набором из студентов
class Group{
	int _size;

	struct ListItem	// Реализация списка
	{
		Student st;
		ListItem *next;
	} *_head, *_tail; 

private:

	ListItem *GetListItem(int);

public:
	Group();
	~Group();
	
	void Add(Student);
	Student GetByIndex(int);
	
	int GetSize(); // Всего студентов в коллекции
	void Sort();   // Сортировка по номеру группы
};