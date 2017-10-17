//
// Created by shucheng on 17-10-14.
//
#include <iostream>
#include "Teacher.h"

using namespace std;

Teacher::Teacher(int age) {
    this->age = age;
}

Teacher::~Teacher() {
    cout << "~Teacher" << endl;
}

int Teacher::getAge() {
    return this->age;
}

void Teacher::setAge(int age) {
    this->age = age;
}
