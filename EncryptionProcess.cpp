#include "EncryptionProcess.h"

void Encrypting(Cipfer* List, string& Process, int& Shift)// Обработка собщения и шифровка
{
	bool bFlag = true;

	int i = 0;

	char* Treatment = new char[Process.length()+1]();// не шифрованное сообщение
	char* EncryptedMessage = new char[Process.length()+1]();// шифрованное сообщение
	
	for (int i = 0; i < Process.length()+1; ++i)//этот цикл перобразовывает строку в динамический массив char
	{
		Treatment[i] = Process[i];
	}

	while (bFlag)//шифровка
	{
		if (i == Process.length()) break;

		if (List->Next == nullptr) while (List->Before != nullptr) List = List->Before;

		if (Treatment[i] == List->Data)
		{
			while (bFlag)
			{

				for (int j = 0; j < Shift; ++j) //отступ
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

	//удаление массивов
	delete[] Treatment;
	delete[] EncryptedMessage;
}


void EncryptingR(Cipfer* List, string& Process, int& Shift)//дешифровка
{
	bool bFlag = true;
	
	int i = 0;

	char* Treatment = new char[Process.length() + 1]();// не шифрованное сообщение
	char* EncryptedMessage = new char[Process.length() + 1]();// шифрованное сообщение

	for (int i = 0; i < Process.length() + 1; ++i)//этот цикл перобразовывает строку в динамический массив char
	{
		Treatment[i] = Process[i];
	}

	while (bFlag)//шифровка
	{
		if (i == Process.length()) bFlag = false;

		if (List->Next == nullptr) while (List->Before != nullptr) List = List->Before;

		if (Treatment[i] == List->Data)
		{
			while (bFlag)
			{

				for (int j = 0; j < Shift; ++j) //отступ
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

	 //удаление массивов
	delete[] Treatment;
	delete[] EncryptedMessage;
}
