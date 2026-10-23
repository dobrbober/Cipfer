#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "CreateAndDeleteList.h"

using namespace std;

string InputMessage(Cipfer* List, Files& FileIO, fstream& FileRAW);

int InputData(Files& FileIO, fstream& FileRAW);