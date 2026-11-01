#include "Question.h"

using namespace std;

int Question()
{
	int iSwitcher = 0;

	bool bFlag = true;

	while (bFlag)
	{
		cout << "\t\t\t\tEncryption/Шифровка - 'E'\n\t\t\t\tDecoding/Дешифровка - 'D'\n\t\t(Убедитесь, что вы ввели верное сообщение в файл 'Input.txt')\n\t(При дешифровке убидитесь что файл 'Data.txt' заполнен числом от 1 до 255)\n";
		char chek = _getch();

		if (chek == 'd' || chek == 'D' || chek == 'В' || chek == 'в')
		{
			iSwitcher = 1;
			system("cls");
			bFlag = false;
		}
		if (chek == 'e' || chek == 'E' || chek == 'У' || chek == 'у')
		{
			system("cls");
			bFlag = false;
		}
		system("cls");
	}

	return iSwitcher;
}

int QuestionDataChange()
{
	int iShift = -1;
	
	while(true)
	{
		cout << "Хотите изменить число для сдвига?\n\t\t\t Да(Y)\t\t Нет(N)";
		char cCheck = _getch();
		system("cls");

		if (cCheck == 'Y' || cCheck == 'y' || cCheck == 'Н' || cCheck == 'н')
		{
			iShift = QuestionDataInstall();
			return iShift;
		}
		if (cCheck == 'N' || cCheck == 'n' || cCheck == 'Т' || cCheck == 'т')
		{
			return iShift;
		}
	}
}

int QuestionDataInstall()
{
	int iShift = -1;
	
	while (true)
	{
		cout << "Установите число для сдвига от 1 до 255: ";
		
		cin >> iShift;

		system("cls"); system("cls");

		if(iShift > 0 && iShift <= 255)
		{
			return iShift;
		}
	}
}

