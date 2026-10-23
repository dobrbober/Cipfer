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
	return Input;
}

int InputData(Files& FileIO, fstream& FileRAW)
{
	int iShift = 0;

	bool bFlag = true;

	FileRAW.open(FileIO.FileData, ios_base::in);
	if (FileRAW.is_open()) //проверка на наличие числа дл€ сдвига в файле Data.txt
	{
		cout << "File open" << endl;
		system("cls");

		string sTempShift = "";

		getline(FileRAW, sTempShift);

		if (sTempShift != "")
			iShift = stoi(sTempShift);
		else
		{
			cout << "¬ведите сдвиг (число) символов дл€ шифровки (более 0 и не более 255): ";
			cin >> iShift;
			system("cls");
			system("cls");

			while (iShift > 255 || iShift <= 0)//проверка на верность числа дл€ сдвига
			{
				cout << "¬ведите сдвиг (число) более 0 и не более 255 символов: ";
				cin >> iShift;
				system("cls");

			}
			FileRAW.close();

			FileRAW.open(FileIO.FileData, ios_base::out);
			if (FileRAW.is_open())
				FileRAW << iShift << endl;
			else
			{
				cout << "File close" << endl;
				system("cls");
				FileRAW.close();
			}
		}
	}
	else
	{
		cout << "File close" << endl;
		system("cls");
		FileRAW.close();
	}

	return iShift;
}

