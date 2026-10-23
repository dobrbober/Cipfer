#include <iostream>
#include <fstream>
#include <Windows.h>
#include "CreateAndDeleteList.h"
#include "EncryptionProcess.h"
#include "Question.h"
#include "Input.h"
#include "Output.h"

using namespace std;

/*
* Работа с файлами
*
* #include <fstream>
*
* ВАЖНО №1 - На имена файлов распространяются те же правила, что и на имена всего в C++ (За исключением того, что они могут быть Кириллистичными)
*
* ВАЖНО №2 - ВСЕ имена библиотеки fstream находятся в пространстве имен std
*
* ofstream - для записи в файл
* ifstream - для чтения из файла
*
* Функции ifstream:
*
* open("полное имя файла") - пытается открыть указаный файл
*
* close() - закрыть файл
*
* is_open() - возвращает логическое значение открыт ли файл. Если открыт - вернет true
*
* eof() - вернет true, если вы достигли конца файла. В любом другом случае - false
*
* getline(<переменная файла>, <переменная string>) - считывает целую строку из <переменная файла> и записывает ее в <переменная string>
*
* read(<массив char>, <кол-во символов>) - считывает из файла <кол-во символов> и записывает в <массив char>
*
* ВАЖНО - Если вы указываете четкое кол-во символов в каждой строке - используйте read. В ином случае используйте функцию getline
*
* Режимы ios_base:
*
* Открытие файла:
*
* ios_base::app - открыть файл для записи в конец
* ios_base::in - открыть файл для чтения с начала
* ios_base::out - открыть файл для записи с начала
*
*
*/

/*
3) Реализовать систему Шифрования
 Пользователь вводит необходимое сообщение, которое вам нужно зашифровать в файл одной из Криптосистем. Соответственно необходимо реализовать саму систему, возможность чтения и записи в файл, а так же расшифровки сообщения по уже готовому коду зашифрованного.
 */

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	fstream FileReadAndWrite;

	Files File;

	Cipfer* List = nullptr;

	CreateList(List, File, FileReadAndWrite); //Создание списка

	InputMessage(List, File, FileReadAndWrite); // Ввод и чтение файла
	
	switch (Question()) //Вопрос шифровка или дешифровка
	{
	case(0): 
		
		Encrypting (List, File, FileReadAndWrite); 
		break;
	case(1): 
		
		EncryptingR(List, File, FileReadAndWrite);
		break;
	default:
		cout << "Неверное возращённое значение от вопроса!";
		system("pause");
		break;
	}; 

	Output(List, File, FileReadAndWrite); //Вывод и запись в файл
	
	DeleteList(List); //Удаление списка
}