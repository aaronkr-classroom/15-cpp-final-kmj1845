// main.cpp
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Core.h"
#include "Grad.h"
#include "Vec.h"
#include "Student_info.h"
#include "median.h"
#include "Intl.h"

using namespace std;

int main() {
    vector<Core*> students; // 객체가 아닌 포인터를 저장
    Core* record;
    char ch;
    string::size_type maxlen = 0;

    // 데이터 읽고 저장하기
    while (cin >> ch) {
        if (cin.eof()) break;  // 입력 끝 체크

        // 유효하지 않은 학생 유형 입력 무시
        if (ch != 'U' && ch != 'G' && ch != 'I') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (ch == 'U')
            record = new Core; // Core 객체 할당 (Undergrad)
        else if (ch == 'G')
            record = new Grad; // Grad 객체 할당
        else // ch == 'I'
            record = new Intl; // Intl 객체 할당

        record->read(cin);

        maxlen = max(maxlen, record->getName().size());
        students.push_back(record);
    }

    // 포인터 비교 함수로 정렬
    sort(students.begin(), students.end(), compare_Core_ptrs);

    // 이름과 점수 출력
    for (vector<Core*>::size_type i = 0; i != students.size(); ++i) {

        // 타입별로 출력
        if (dynamic_cast<Grad*>(students[i])) {
            cout << "(G) ";
        }
        else if (dynamic_cast<Intl*>(students[i])) {
            cout << "(I) ";
        }
        else { // Undergrad(Core)
            cout << "(U) ";
        }

        cout << students[i]->getName()
            << string(maxlen + 1 - students[i]->getName().size(), ' ');

        try {
            double final_grade = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                << setprecision(prec) << endl;
        }
        catch (const domain_error& e) {
            cout << e.what() << endl;
        }

        delete students[i]; // 동적할당 해제
    }

    return 0;
}