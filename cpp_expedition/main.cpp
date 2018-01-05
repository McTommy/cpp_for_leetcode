#include <iostream>
#include <string>

#include "cpp_expedition/Teacher.h"
//静态多态　早绑定　重载
//动态多态　晚绑定　子父类定义虚函数

using namespace std;

class Line;
class Coordinate {
    friend Line;
    //只能以友元函数重载
    friend Coordinate operator+(const Coordinate &coord1, const Coordinate &coord2) {
        Coordinate temp;
        temp.m_iX = coord1.m_iX + coord2.m_iX;
        temp.m_iY = coord1.m_iY + coord2.m_iY;
        return temp;
    }
    friend ostream& operator<<(ostream &out, const Coordinate &coord) {
        out << coord.m_iX << "," << coord.m_iY;
        return out;
    }
//    friend Coordinate& operator-(Coordinate &coordinate){}
    friend void printTime(Coordinate &coord){}
public:
    Coordinate(){}
    Coordinate(int x, int y){}

    bool operator==(const Coordinate &rhs) const {
        return m_iX == rhs.m_iX &&
               m_iY == rhs.m_iY;
    }

    bool operator!=(const Coordinate &rhs) const {
        return !(rhs == *this);
    };

    Coordinate& operator-() {
        m_iX = -m_iX;
        m_iY = -m_iY;
        return *this;
    }

    Coordinate& operator++() {
        m_iX++;
        m_iY++;
        return *this;
    }

    Coordinate& operator++(int) {
        Coordinate old(*this);
        m_iX++;
        m_iY++;
        return old;
    }

    //成员函数　第一个参数为this 指针
    Coordinate operator+(const Coordinate &coord) {
        Coordinate temp;
        temp.m_iX = coord.m_iX + this->m_iX;
        temp.m_iY = coord.m_iY + this->m_iY;

        return temp;
    }

    int operator[](int index) {
        if (index == 0)
            return m_iX;
        if (index == 1)
            return m_iY;
    }
//    Coordinate(const Coordinate &){cout << 123 << endl;};
private:
    int m_iX{};
    int m_iY{};
};

class Line
{
public:
    Line(int x1, int y1, int x2, int y2):coor1(x1, y1), coor2(x2, y2){}

    Line() {}

private:
    Coordinate coor1;
    Coordinate coor2;
};

class Person{
public:
    //虚析构函数
    virtual ~Person(){}
    //无法重载　只能隐藏
    void eat(){}
    //重载　虚函数与虚析构函数　在虚函数表中　类实例化存在一个四个字节的虚函数表指针
    virtual void hand(){}
};

//虚继承　解决菱形继承问题
class Student : virtual public Person, public Line
{
public:
    Student(){}
    Student(int x1, int y1, int x2, int y2) : Line(x1, y1, x2, y2) {}

    void eat(){};
    void setName(string name) {
        m_strName = name;
    }

    string getName() { return m_strName; }

    void setGender(string gender) {
        m_strGender = gender;
    }

    string getGender() {
        return m_strGender;
    }

    int getScore()
    {
        return m_intScore;
    }
    void initScore()
    {
        m_intScore = 0;
    }

    void study(int score)
    {
        m_intScore += score;
    }

private:
    string m_strName;
    string m_strGender;
    int m_intScore{};
};

class Circle
{
public:
    Circle():m_dpi(3.14){};

private:
    const double m_dpi;
};

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    Student student;
    student.Person::eat();

    int a = max<int>(10, 21);
    return 0;
}

