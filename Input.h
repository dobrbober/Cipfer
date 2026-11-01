#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "CreateAndDeleteList.h"
#include "Question.h"

using namespace std;

void InputMessage(Cipfer* List, Files& FileIO, fstream& FileRAW, string& Input);

void InputData(Files& FileIO, fstream& FileRAW, int& Shift);