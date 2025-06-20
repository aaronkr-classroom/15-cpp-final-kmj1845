// Intl.h
#ifndef GUARD_Intl_h
#define GUARD_Intl_h

#include <iostream>
#include "Core.h"

using namespace std;

class Intl : public Core {
public:
	Intl() : toeic(0) {}
	Intl(istream& is) { read(is); }
	
	double grade() const override;
	istream& read(istream& in) override;

private:
	double toeic;
	Intl* clone() const override { return new Intl(*this); }
};

#endif