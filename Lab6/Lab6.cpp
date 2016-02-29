// This is the source file for lab06
/*Name: nathaniel A.Barnett
Date : 02 / 29 / 2016
Lab06
Algorithm :
1. create array of Word objects.
2. read in from input file word by word
3. if word read in is not already in array, then set the current Word
	object to the values of the word read in.
4. if word read in is already in the array, increment the frequency of that object.
5. if array is full, then resize it to double the current size.
6. repeat steps 2 - 5 until entire file is read.
7. output the words and the frequency per word to output file.
*/

#include <fstream>
#include <string>
#include "Word.h"
using namespace std;

int resizeArray(Word* &oldArray, int oldSize);

void main()
{
	// file handling
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	if (!fin.good())
	{
		exit(1);
	}

	if (!fout.good())
	{
		exit(1);
	}

	// Main Body
	string tempWord;
	bool found;
	int currentSize = 10, numberOfWords = 0;
	Word* wordArray = new Word[currentSize];

	while (fin.good())
	{
		fin >> tempWord;
		found = false;

		if (numberOfWords == currentSize)  // resize array if need be
		{
			currentSize = resizeArray(wordArray, currentSize);
		}

		for (int i = 0; i < currentSize; i++) // make sure word not in array
		{
			if (tempWord == wordArray[i].getWord())
			{
				wordArray[i].increment();
				found = true;
				break;
			}
		}
		if (!found)			// if word not in array, add to array
		{
				wordArray[numberOfWords] = Word(tempWord);
				numberOfWords++;
		}
	}

	// write output to output file
	
	fout << "Words found: " << numberOfWords << endl;
	fout << "Array's max size: " << currentSize << endl << endl;
	for (int i = 0; i < numberOfWords; i++)
	{
		fout << wordArray[i].getWord() << "- " << wordArray[i].getCount() << endl;
	}
	

}

// Resizing function
int resizeArray(Word* &oldArray, int oldSize)
{
	int newSize = oldSize * 2;
	Word *newArray = new Word[newSize];

	for (int i = 0; i < oldSize; i++)
	{
		newArray[i] = oldArray[i];
	}

	delete[] oldArray;
	oldArray = newArray;

	return newSize;
}