#include "Input.h"

void InputMessage(Cipfer* List, Files& FileIO, fstream& FileRAW, string& Input)
{
	FileRAW.open(FileIO.FileInput, ios_base::in);
	if (FileRAW.is_open())
	{
		cout << "File open!";
		getline(FileRAW, Input);

		if (Input == "")// проверка на пустоту файла
		{
			cout << "¬ведите сообщение дл€ шифровки: \n";
			getline(cin, Input);
			FileRAW.close();
			
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

	cout << "File close!";
	FileRAW.close();
	system("cls");
}

void InputData(Files& FileIO, fstream& FileRAW, int& Shift)
{
	bool bFlag = true;

	FileRAW.open(FileIO.FileData, ios_base::in);
	if (FileRAW.is_open()) //проверка на наличие числа дл€ сдвига в файле Data.txt
	{
		cout << "FileData open!(in)" << endl;
		system("cls");

		string sTempShift = "";

		getline(FileRAW, sTempShift);

		if (sTempShift != "")
			Shift = stoi(sTempShift);
		else
		{
			Shift = QuestionDataInstall();
			FileRAW.close();

			FileRAW.open(FileIO.FileData, ios_base::out);
			if (FileRAW.is_open()) 
			{
				cout << "FileData open!(out)" << endl;

				FileRAW << Shift << endl;
			}
			else
			{
				cout << "FileData close!(out)" << endl;
				FileRAW.close();
			}
			FileRAW.close();
			cout << "FileData close!(out)" << endl;
		}
	}
	else
	{
		cout << "FileData close!(in)" << endl;
		FileRAW.close();
	}

	cout << "FileData close!" << endl;
	system("cls");
	FileRAW.close();
}

