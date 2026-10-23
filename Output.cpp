#include "Output.h"

using namespace std;

void Output(Files& FileIO, fstream& FileRAW, string& Message)
{
	string sLimiter = "";

	FileRAW.open(FileIO.FileInput, ios_base::in);

	if(FileRAW.is_open())
	{
		cout << "File open!";
		system("cls");
		
		getline(FileRAW, sLimiter);
	}
	else
	{
		cout << "File close!";
		FileRAW.close();
	}
	FileRAW.close();

	FileRAW.open(FileIO.FileOutput, ios_base::in);
	if (FileRAW.is_open())
	{
		cout << "File open!";
		system("cls");

		for(int i = 0; i < sLimiter.length()+1; ++i)
		{
			cout << Message[i];
		}
	}
	else
	{
		cout << "File close!";
		FileRAW.close();
		system("cls");
	}
	FileRAW.close();
}
