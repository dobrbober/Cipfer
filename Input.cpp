#include "Input.h"

void InputMessage(Cipfer* List, Files& FileIO, fstream& FileRAW)
{
	system("cls");

	string Input = "";

	FileRAW.open(FileIO.FileInput, ios_base::in);

	if (FileRAW.is_open())
	{
		cout << "File open!";
		system("cls");
		getline(FileRAW, Input);

		if (Input == "")// проверка на пустоту файла
		{
			cout << "Введите сообщение для шифровки: \n";
			getline(cin, Input);
			FileRAW.close();
			
			FileRAW.open(FileIO.FileInput, ios_base::out);
			FileRAW << Input << endl;
			FileRAW.close();
			
			system("cls");
			system("cls");
		}
		else
		{
			FileRAW.open(FileIO.FileInput, ios_base::out);
			FileRAW << Input << endl;
			FileRAW.close();
				
		}
	}
	else
	{
		cout << "File close!";
		FileRAW.close();
		system("cls");
	}
}
