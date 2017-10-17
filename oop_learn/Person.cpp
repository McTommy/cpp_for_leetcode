//
// Created by shucheng on 17-10-14.
//

#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() {
    cout << "Person" << endl;
}

Person::~Person() {
    cout << "~Person()" << endl;

}

void Person::eat() {
    cout << "eat" << endl;

}
