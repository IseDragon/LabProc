#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Film.h"
#include "Cartoon.h"
#include "Feature.h"

using namespace std;

void InCartoon(cartoon &c, ifstream &ifst);
void InFeature(feature &f, ifstream &ifst);
void InDocumental(documental &d, ifstream &ifst);

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

film* In(ifstream &ifst) {
	CheckInputFile(ifst);
	film *f = new film;
	int k1;
	ifst >> k1;
	CheckWrongInput(ifst);
	if (k1 <= 0 || k1 > 3) {
		cerr << "Wrong type of film!" << endl;
		exit(1);
	}
	char t[256];
	ifst.getline(t, 256);
	CheckWrongInput(ifst);
	ifst.getline(f->name, 256);
	CheckWrongInput(ifst);
	ifst.getline(f->country, 256);
	CheckWrongInput(ifst);
	switch (k1) {
	case 1:
		f->k = film::key::FEATURE;
		InFeature(f->f, ifst);
		return f;
	case 2:
		f->k = film::key::CARTOON;
		InCartoon(f->c, ifst);
		return f;
	case 3:
		f->k = film::key::DOCUMENTAL;
		InDocumental(f->d, ifst);
		return f;
	default:
		cerr << "Wrong type of film!" << endl;
		exit(1);
	}
}