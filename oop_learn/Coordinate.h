//
// Created by shucheng on 17-10-15.
//

#ifndef ALGORITHM_COORDINATE_H
#define ALGORITHM_COORDINATE_H

#include <iostream>

using namespace std;

class Coordinate
{
    friend Coordinate operator+(Coordinate &c1, Coordinate &c2);
    friend ostream &operator<<(ostream &output, Coordinate &coor);
public:
    Coordinate(int x, int y);
    // reload - ++
    Coordinate &operator-();
    Coordinate &operator++();
    Coordinate operator++(int);
    int operator[](int index);
//    Coordinate operator+(Coordinate &c);
    int getX();
    int getY();

private:
    int m_iX;
    int m_iY;
};

#endif //ALGORITHM_COORDINATE_H
