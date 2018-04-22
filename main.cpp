#include "Container.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "gtest/gtest.h"
#include "Test.h"
#include "Protect.h"

using namespace std;

void Init(container &c);
void Clear(container &c);
void In(container &c, ifstream & ifst);
void Out(container c, ofstream &ofst);
void OutOnlyFeature(container c, ofstream &ofst);
void OutOnlyCartoon(container c, ofstream &ofst);
void Sort(container &c);

int main(int argc, char* argv[]) 
{
	if (argc != 3) 
	{
		cout << "incorrect command line! Waited: command in_file out_file" << endl;
		exit(1);
	}

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);

	cout << "Start" << endl;

	container c;
	Init(c);

	In(c, ifst);
	ofst << "Filled container. " << endl;
	Out(c, ofst);

	Clear(c);
	ofst << "Empty container. " << endl;
	
	cout << "Stop" << endl;
	return 0;
	//::testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
}
