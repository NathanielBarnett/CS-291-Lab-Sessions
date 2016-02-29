// This is the header file for the class Word
/*
Name: nathaniel A. Barnett
Date: 02/29/2016
Lab06
*/

#pragma once
#include <string>
#include <fstream>
using namespace std;

class Word
{
public:
	Word();
	Word(string W);
	void increment();
	string getWord();
	int getCount();
	void setWord(string W);
	void setCount(int count);

private:
	string word;
	int freq;
};