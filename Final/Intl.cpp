//Intl.cpp
#include "Intl.h"
#include "grade.h"
#include "read_hw.cpp"

using namespace std;

istream& Intl::read(istream& in) {
	Core::read_common(in);
	in >> toeic;
	read_hw(in, homework);
	return in;
}

double Intl::grade() const {
	return min(Core::grade(), toeic);
}