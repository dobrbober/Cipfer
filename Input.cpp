#include "Input.h"

string InputMessage(Cipfer* List, Files& FileIO, fstream& FileRAW)
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
			cout << "¬ведите сообщение дл€ шифровки: \n";
			getline(cin, Input);
			FileRAW.close();
			
			FileRAW.open(FileIO.FileInput, ios_base::out);
			FileRAW << Input << endl;
			FileRAW.close();
			
			system("cls");
			system("cls");
		}
	}
	else
	{
		cout << "File close!";
		FileRAW.close();
		system("cls");
	}

	cout << "File close!";
	FileRAW.close();
	system("cls");

	return Input;
}

int InputData(Files& FileIO, fstream& FileRAW)
{
	int iShift = -1;

	bool bFlag = true;

	FileRAW.open(FileIO.FileData, ios_base::in);
	if (FileRAW.is_open()) //проверка на наличие числа дл€ сдвига в файле Data.txt
	{
		cout << "FileData open!(in)" << endl;
		system("cls");

		string sTempShift = "";

		getline(FileRAW, sTempShift);

		if (sTempShift != "")
			iShift = stoi(sTempShift);
		else
		{
			iShift = QuestionDataInstall();
			FileRAW.close();

			FileRAW.open(FileIO.FileData, ios_base::out);
			if (FileRAW.is_open()) 
			{
				cout << "FileData open!(out)" << endl;
				system("cls");
				FileRAW << iShift << endl;
			}
			else
			{
				cout << "FileData close!(out)" << endl;
				system("cls");
				FileRAW.close();
			}
			FileRAW.close();
			cout << "FileData close!(out)" << endl;
			system("cls");
		}
	}
	else
	{
		cout << "FileData close!(in)" << endl;
		system("cls");
		FileRAW.close();
	}

	cout << "FileData close!" << endl;
	system("cls");
	FileRAW.close();

	return iShift;
}

