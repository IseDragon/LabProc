#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Film.h"

using namespace std;

struct node
{
	film* f;
	node* next;
};

struct container
{
	int kol;
	int n;
	node** mas;
};