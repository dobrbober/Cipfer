#include "Output.h"

using namespace std;

void Output(Cipfer*& List, Files& FileIO, fstream& FileRAW)
{
	string sLimiter = "";
	string sOutput = "";

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

		getline(FileRAW, sOutput);

		for(int i = 0; i < sLimiter.length()+1; ++i)
		{
			cout << sOutput[i];
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
