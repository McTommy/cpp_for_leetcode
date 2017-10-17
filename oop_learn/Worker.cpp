//
// Created by shucheng on 17-10-14.
//

#include "Worker.h"
#include <iostream>

using namespace std;

void Worker::work() {
 cout << "work" << endl;
}

Worker::~Worker() {
 cout << "~Worker" << endl;
}

Worker::Worker() {
 cout << "Worker" << endl;
}
