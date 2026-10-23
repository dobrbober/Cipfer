#include "EncryptionProcess.h"

void Encrypting(Cipfer* List, Files& FileIO, fstream& FileRAW)// ќбработка собщени€ и шифровка
{
	string Processing = "";
	bool bFlag = true;

	FileRAW.open(FileIO.FileInput, ios_base::in);// препоцессинг
	if(FileRAW.is_open())
	{
		cout << "File open" << endl;
		system("cls");

		getline(FileRAW, Processing);
	}
	else
	{
		cout << "File close" << endl;
		system("cls");
		FileRAW.close();
	}
	FileRAW.close();

	char* Treatment = new char[Processing.length()+1]();// не шифрованное сообщение
	char* EncryptedMessage = new char[Processing.length()+1]();// шифрованное сообщение
	
	for (int i = 0; i < Processing.length()+1; ++i)//этот цикл перобразовывает строку в динамический массив char
	{
		Treatment[i] = Processing[i];
	}

	int iShift = 0;
	
	FileRAW.open(FileIO.FileData, ios_base::in);
	if(FileRAW.is_open()) //проверка на наличие числа дл€ сдвига в файле Data.txt
	{
		cout << "File open" << endl;
		system("cls");

		string sTempShift = "";

		getline(FileRAW, sTempShift);

		if(sTempShift != "") 
			iShift = stoi(sTempShift);
		else
		{
			cout << "¬ведите сдвиг (число) символов дл€ шифровки (более 0 и не более 255): ";
			cin >> iShift;
			system("cls");
			system("cls");
			
			while (bFlag)
			{
				if (iShift > 255 || iShift <= 0)//проверка на верность числа дл€ сдвига
				{
					cout << "¬ведите сдвиг (число) более 0 и не более 255 символов: ";
					cin >> iShift;
					system("cls");
				}
				else
				{
					bFlag = false;
				}
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

	bFlag = true;

	int i = 0;

	while (bFlag)//шифровка
	{
		if (i == Processing.length()) break;

		if (List->Next == nullptr) while (List->Before != nullptr) List = List->Before;

		if (Treatment[i] == List->Data)
		{
			while (bFlag)
			{

				for (int j = 0; j < iShift; ++j) //отступ
				{
					List = List->Next;
					if (List->Next == nullptr) 
						while (List->Before != nullptr) 
							List = List->Before;
					if (List->Data == '\0') 
						List = List->Next;
				}
					
				EncryptedMessage[i] = List->Data;
				bFlag = false;
				++i;
			}
			List = List->Next;
			bFlag = true;
		}
		else
		{
			List = List->Next;
		}
	}

	string sEncryptedMessage = EncryptedMessage;

	FileRAW.open(FileIO.FileOutput, ios_base::out);
	if (FileRAW.is_open())//processing
	{
		cout << "File open" << endl;
		system("cls");
		FileRAW << sEncryptedMessage << endl;
		
	}
	else
	{
		cout << "File close" << endl;
		system("cls");
		FileRAW.close();
	}
	FileRAW.close();

	// удаление массивов
	delete[] Treatment;
	delete[] EncryptedMessage;
}


void EncryptingR(Cipfer* List, Files& FileIO, fstream& FileRAW)//дешифровка
{
	string Processing = "";
	bool bFlag = true;

	FileRAW.open(FileIO.FileInput, ios_base::in);// препоцессинг
	if (FileRAW.is_open())
	{
		cout << "File open" << endl;
		system("cls");

		getline(FileRAW, Processing);
	}
	else
	{
		cout << "File close" << endl;
		system("cls");
		FileRAW.close();
	}
	FileRAW.close();

	char* Treatment = new char[Processing.length() + 1]();// не шифрованное сообщение
	char* EncryptedMessage = new char[Processing.length() + 1]();// шифрованное сообщение

	for (int i = 0; i < Processing.length() + 1; ++i)//этот цикл перобразовывает строку в динамический массив char
	{
		Treatment[i] = Processing[i];
	}

	int iShift = 0;

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

			while (bFlag)
			{
				if (iShift > 255 || iShift <= 0)//проверка на верность числа дл€ сдвига
				{
					cout << "¬ведите сдвиг (число) более 0 и не более 255 символов: ";
					cin >> iShift;
					system("cls");
				}
				else
				{
					bFlag = false;
				}
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

	bFlag = true;

	FileRAW.open(FileIO.FileOutput, ios_base::out);
	if (FileRAW.is_open())//processing
	{
		cout << "File open" << endl;
		system("cls");
		int i = 0;

		while (bFlag)//шифровка
		{
			if (i == Processing.length()) bFlag = false;

			if (List->Next == nullptr) while (List->Before != nullptr) List = List->Before;

			if (Treatment[i] == List->Data)
			{
				while (bFlag)
				{

					for (int j = 0; j < iShift; ++j) //отступ
					{
						List = List->Before;
						if (List->Before == nullptr) 
							while (List->Next != nullptr) 
								List = List->Next;
						if (List->Data == '\0')
							while (List->Next != nullptr)
								List = List->Next;
					}
					
					EncryptedMessage[i] = List->Data;
					bFlag = false;
					++i;
				}
				List = List->Next;
				bFlag = true;
			}
			else
			{
				List = List->Next;
			}
		}

		string sEncryptedMessage = EncryptedMessage;

		FileRAW << sEncryptedMessage << endl;
		FileRAW.close();
	}
	else
	{
		cout << "File close" << endl;
		system("cls");
		FileRAW.close();
	}

	// удаление массивов
	delete[] Treatment;
	delete[] EncryptedMessage;
}
