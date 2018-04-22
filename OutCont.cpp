#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void Out(container c, ostream &ofst);
int FuncFilm(film *f);

void CheckOutputFile(ostream &ofst);

void OutOnlyCartoon(container c, ostream &ofst);
void OutOnlyDocumental(container c, ostream &ofst);
void OutOnlyFeature(container c, ostream &ofst);

void OutCont(container &c, ostream &ofst)
{
	int k = 0;
	int k1 = 0;
	while (k1 != 1) {
		cout << "Input number:" << endl;
		cout << "1 - Out all elements" << endl;
		cout << "2 - Out only cartoon" << endl;
		cout << "3 - Out only documental" << endl;
		cout << "4 - Out only feature" << endl;
		cout << "0 - exit" << endl;
		cin >> k;
		if (cout.fail())
		{
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (k < 0 || k > 4) {
			cout << "Incorrect choice! Try again!" << endl;
			continue;
		}
		else {
			k1 = 1;
			switch (k)
			{
			case 1:
				Out(c, ofst);
				break;
			case 2:
				OutOnlyCartoon(c, ofst);
				break;
			case 3:
				OutOnlyDocumental(c, ofst);
				break;
			case 4:
				OutOnlyFeature(c, ofst);
				break;
			default:
				break;
			}
		}
	}
}
