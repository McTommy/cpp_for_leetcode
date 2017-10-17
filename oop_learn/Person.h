//
// Created by shucheng on 17-10-14.
//
#include <string>

using namespace std;

class Person
{
public:
    Person();

    virtual ~Person();
    void eat();

    string m_strName;
    int m_iAge;
};
