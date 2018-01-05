//
// Created by shucheng on 17-12-12.
//

#include "Teacher.h"

void Teacher::setName(string name) {

}

string Teacher::getName() {
    return std::__cxx11::string();
}

void Teacher::setGender(string gender) {

}

string Teacher::getGender() {
    return std::__cxx11::string();
}

void Teacher::teach() {

}

Teacher::Teacher(string name, int age):m_strName(name), m_iAge(age)
{

}

Teacher::Teacher(const Teacher &teacher) {
    cout << "Teacher(const Teacher &teacher)" << endl;
}

Teacher::~Teacher() {
    cout << "hello" << endl;
}
