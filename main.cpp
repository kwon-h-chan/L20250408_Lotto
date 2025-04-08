#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
#define LottoSize   45

int LottoArray[LottoSize] = { 0, };

void Init()
{
	for (int i = 0; i < 45; i++)
	{
		LottoArray[i] = i + 1;
	}
}

void Shuffle()
{
	int Temp = 0;
	for (int i = 0; i < LottoSize * 100; i++)
	{
		int First = rand() % LottoSize;
		int Second = rand() % LottoSize;
		Temp = LottoArray[First];
		LottoArray[First] = LottoArray[Second];
		LottoArray[Second] = Temp;
	}
}

void Print()
{
	for (int i = 0; i < 6; i++)
	{
		cout << LottoArray[i] << ", ";
	}
}

void Sort_Temp(int First, int Second)
{
	int Temp = LottoArray[First];
	LottoArray[First] = LottoArray[Second];
	LottoArray[Second] = Temp;
}

void Sorting()
{
	int pivot = 1;
	for (int i = 0; i < 6; i++)
	{
		for (int j = pivot; j < 6; j++)
		{
			if (LottoArray[i] > LottoArray[j])
			{
				Sort_Temp(i,j);
			}		
		}
		pivot++;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	Init();
	Shuffle();
	Sorting();
	Print();
}