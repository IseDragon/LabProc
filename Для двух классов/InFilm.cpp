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

film* In(ifstream &ifst) {
	film *f = new film;
	int k1;
	ifst >> k1;
	char t[256];
	ifst.getline(t, 256);
	ifst.getline(f->name, 256);
	switch (k1) {
	case 1:
		f->k = film::key::FEATURE;
		InFeature(f->f, ifst);
		return f;
	case 2:
		f->k = film::key::CARTOON;
		InCartoon(f->c, ifst);
		return f;
	default:
		return 0;
	}
}