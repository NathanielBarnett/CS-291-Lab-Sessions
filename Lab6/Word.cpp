// This is the implementation file for the classs Word
/*
Name: nathaniel A. Barnett
Date: 02/29/2016
Lab06
*/
#include "Word.h"

Word::Word()
{
	freq = 1;
	word = "";
}

Word::Word(string W)
{
	freq = 1;
	word = W;
}

void Word::increment()
{
	freq++;
}

string Word::getWord()
{
	return word;
}

int Word::getCount()
{
	return freq;
}

void Word::setWord(string W)
{
	word = W;
}

void Word::setCount(int count)
{
	freq = count;
}

//public:
//	Word();
//	Word(string W);
//	void increment();
//	string getWord();
//	int getCount();
//	void setWord(string W);
//	void setCount(int count);
//
//private:
//	string word;
//	int freq;