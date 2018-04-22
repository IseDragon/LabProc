#include <iostream>
#include "Film.h"
#include "Cartoon.h"
#include "Feature.h"

using namespace std;

void OutFeature(feature &f, ofstream &ofst);
void OutCartoon(cartoon &c, ofstream &ofst);
void OutDocumental(documental &d, ofstream &ofst);

void CheckOutputFile(ostream &ofst);

void Out(film *f, ofstream &ofst) {
	CheckOutputFile(ofst);
	ofst << f->name << endl;
	ofst << "It was filmed in " << f->country << endl;
	switch (f->k) {
	case film::key::FEATURE:
		OutFeature(f->f, ofst);
		break;
	case film::key::CARTOON:
		OutCartoon(f->c, ofst);
		break;
	case film::key::DOCUMENTAL:
		OutDocumental(f->d, ofst);
		break;
	default:
		ofst << "Incorrect type of film!" << endl;
		exit(1);
	}
}