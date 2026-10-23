#include "Question.h"

using namespace std;

int Question()
{
	int iSwitcher = 0;

	bool bFlag = true;

	while (bFlag)
	{
		cout << "\t\t\t\tEncryption/Шифровка - 'E'\n\t\t\t\tDecoding/Дешифровка - 'D'\n\t\t(Убедитесь, что вы ввели верное сообщение в файл 'Input.txt')\n\t(При дешифровке убидитесь что файл 'Data.txt' заполнен верным числом)\n";
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