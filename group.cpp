#include "group.h"

void swap(int &a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
Group::Group() :_size(0), _head(NULL), _tail(NULL)
{}
// Работа с набором из студентов
// Добавить студента в группу
// Это не организационная единица
// Это база данных студентов из разных групп
void Group::Add(Student newbie)
{
	// Добавление студента в нужное место
	if (_size == 0)
	{
		_head = new ListItem;
		_head->next = NULL;
		_head->st = newbie;
	} 
	else if (_size == 1)
	{
		_tail = new ListItem;
		_tail->next = NULL;
		_head->next = _tail;
		_tail->st = newbie;
	}
	else
	{
		// Найти подходящее место по возрастанию номера группы
		ListItem* p = _tail;
		
		_tail = new ListItem;
		_tail->st = newbie;
		_tail->next = NULL;
		p->next = _tail;
	}
	
	_size = _size + 1;
}
Group::ListItem * Group::GetListItem(int index)
{
	int i = 0;
	ListItem* p = _head;
	while (i < index)
	{
		p = p->next;
		i = i + 1;
	}
	return p;
}
Student Group::GetByIndex(int index)
{

	return GetListItem(index)->st;
}

int Group::GetSize()
{
	return _size;
}

// Сортировка по номеру группы
void Group::Sort()
{
	// Составить массив номеров групп
	// Отсортировать его
	// Сохранить
	if (_size <= 1)
	{
		return; // Сортировать нечего
	}

	int *sts = new int[_size];
	int *grn = new int[_size];
	int i = 0, k;
	ListItem* p = _head;
	while (i < _size)
	{
		sts[i] = i;
		grn[i] = GetListItem(i)->st.GetGroup();
		i = i + 1;
	}
	// Отсортировать группу по возрастанию
	// Сортировка пузырьком
	// Порядок внутри группы сохраняется
	for (i = 0; i < _size - 1; i=i+1)
	{
		for (k = 0; k < _size - i - 1; k=k+1)
		{
			if (grn[k + 1] < grn[k])
			{
				swap(grn[k+1], grn[k]);
				swap(sts[k+1], sts[k]);
			}
		}
	}
	

	ListItem **n = new ListItem*[_size];
	i = 0;
	while (i < _size)
	{
		n[i] = GetListItem(sts[i]); // вот здесь порядок уже есть
		i = i + 1;
	}
	i = 0;
	while (i < _size)
	{
		n[i]->next = n[i + 1]; // Здесь упорядочивается исходный список
		i = i + 1;
	}
	n[_size - 1]->next = NULL;
	_head = n[0];
	_tail = n[_size - 1];

	delete[] n;
	delete[] sts;
	delete[] grn;
}

Group::~Group()
{
	// Сброс данных на диск
	// Удаление из памяти
	int i = 0;
	ListItem* p = _head, *pp;

	while (i < _size)
	{
		pp = p;
		p = p->next;
		delete pp;
		i = i + 1;
	}
}