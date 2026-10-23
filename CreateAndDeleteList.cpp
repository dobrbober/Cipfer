#include "CreateAndDeleteList.h"
#include <iostream>


using namespace std;

void CreateList(Cipfer*& List, Files& FileIO, fstream& FileRAW)// создание, заполнение списка и начало работы
{
	List = new Cipfer;

	for (int i = 0; i < 256; ++i)
	{
		List->Data = char(i);
		if (i < 255)
		{
			List->Next = new Cipfer;
			List->Next->Before = List;
			List = List->Next;
		}
		else
			List->Next = nullptr;
	}
	while (List->Before != nullptr) 
		List = List->Before;

	//int i = 0;

	//while (List->Next != nullptr) 
	//{
	//	i++;
	//	cout << i << ':' << List->Data << endl;
	//	List = List->Next;
	//	if (List->Next == nullptr)
	//		cout << i+1 << ':' << List->Data << endl;
	//}
	//system("pause");
}

void DeleteList(Cipfer*& List) // удаление списка и его составляющих
{
	while (List->Next != nullptr) List = List->Next;
	while (List->Before != nullptr)
	{
		List = List->Before;
		delete List->Next;
		List->Next = nullptr;
	}
	delete List;
	List = nullptr;
}
