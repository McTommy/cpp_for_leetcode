//
// Created by shucheng on 17-12-12.
//

#ifndef ALGORITHM_TEACHER_H
#define ALGORITHM_TEACHER_H
#include <string>
#include <iostream>

using namespace std;
class Teacher
{
public:
    explicit Teacher(string name="jim", int age = 12);
    //拷贝构造函数
    Teacher(const Teacher &teacher);
    ~Teacher();
    void setName(string name);
    string getName();
    void setGender(string gender);
    string getGender();
    void teach();
private:
    string m_strName;
    string m_strGender;
    int m_iAge;
};
#endif //ALGORITHM_TEACHER_H
