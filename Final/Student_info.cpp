// Student_info.cpp
#include <iostream>
#include "Student_info.h"
#include "Core.h"
#include "Grad.h"
#include "Intl.h"     

using namespace std;

// 복사 생성자
Student_info::Student_info(const Student_info& s) : cp(0) {
    if (s.cp) cp = s.cp->clone();
}

// read 함수 수정
istream& Student_info::read(istream& is) {
    delete cp; // 이전 객체 삭제

    char ch;
    is >> ch; // 'U', 'G', 'I'

    if (ch == 'U') {
        cp = new Core(is);
    }
    else if (ch == 'G') {
        cp = new Grad(is);
    }
    else if (ch == 'I') {
        cp = new Intl(is);     // ✅ Intl 타입 처리
    }
    else {
        cp = nullptr;
    }

    return is;
}

// 대입 연산자
Student_info& Student_info::operator=(const Student_info& s) {
    if (&s != this) {
        delete cp;
        cp = s.cp ? s.cp->clone() : 0;
    }
    return *this;
}

// read_hw 함수
istream& read_hw(istream& in, Vec<double>& hw) {
    if (in) {
        hw.clear();
        double x;
        while (in >> x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}
