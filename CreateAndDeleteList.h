#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Files
{
	string FileInput  = "Input.txt" ;
	string FileOutput = "Output.txt";
	string FileData   = "Data.txt"  ;
};

struct Cipfer
{
	char Data = ' ';

	Cipfer* Next = nullptr;
	Cipfer* Before = nullptr;
};

void CreateList(Cipfer*& List);

void DeleteList(Cipfer*& List);