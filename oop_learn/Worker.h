//
// Created by shucheng on 17-10-14.
//
#include <string>
#include "Person.h"

class Worker : public Person
{
public:
    Worker();
    ~Worker();
    void work();

    int m_iSalary;
};