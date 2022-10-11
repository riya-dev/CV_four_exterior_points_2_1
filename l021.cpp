// Riya Dev
// Period 5
// // grid jumps down and across
// cd project2
// g++ -std=c++11 -o l021 -Wall l021.cpp
// ./l021

#include <iostream>
#include <fstream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>       /* pow */
#include <iomanip>      /* set precision*/
#include <climits>
#include <algorithm>    // std::max

const int size = 1000;

bool insidetriangle(double rx1, double ry1, double rx2, double ry2, double rx3, double ry3, double rx4, double ry4, double m23, double m34, double m24) {
    // triangle 234, p1 is the point i'm testing
    // 1 = true
    // 0 = false

    /*int count = 0;

    for (int j = ry1; j <= 1; j += 1) {
        if (rx1 == ((j - ry2) / m23) + rx2)
            count++;
        if (rx1 == ((j - ry4) / m34) + rx4)
            count++;
        if (rx1 == ((j - ry4) / m24) + rx4)
            count++;
    }

    if (count == 1)
        return true;
    return false;*/

    int count = 0;

    if (std::min(rx2, rx3) < rx1 && rx1 < std::max(rx2, rx3))
        if (rx1 < m23 * (rx1 - rx2) + ry2)
            count++;
    if (std::min(rx3, rx4) < rx1 && rx1 < std::max(rx3, rx4))
        if (m34 * (rx1 - rx3) + ry3 > rx1)
            count++;
    if (std::min(rx2, rx4) < rx1 && rx1 < std::max(rx2, rx4))
        if (m24 * (rx1 - rx4) + ry4 > rx1)
            count++;

    /*if (count == 3)
        return true;*/
    if (count == 1)
        return true;
    return false;

}

void part1() {
    std::ofstream file;
    file.open("points.txt");

    srand(time(NULL));
    double rx1 = double(rand()) / RAND_MAX;
    double ry1 = double(rand()) / RAND_MAX;

    double rx2 = double(rand()) / RAND_MAX;
    double ry2 = double(rand()) / RAND_MAX;

    double rx3 = double(rand()) / RAND_MAX;
    double ry3 = double(rand()) / RAND_MAX;

    double rx4 = double(rand()) / RAND_MAX;
    double ry4 = double(rand()) / RAND_MAX;

    double m12 = (ry1 - ry2) / (rx1 - rx2); //12
    double m23 = (ry2 - ry3) / (rx2 - rx3); //23
    double m13 = (ry1 - ry3) / (rx1 - rx3); //13
    double m14 = (ry1 - ry4) / (rx1 - rx4); //14
    double m24 = (ry2 - ry4) / (rx2 - rx4); //24
    double m34 = (ry3 - ry4) / (rx3 - rx4); //34

    //std::cout << rx1 << " " << ry1 << "  " << rx2 << " " << ry2 << "  " << rx3 << " " << ry3 << "  " << rx4 << " " << ry4 << "\n";

    //if a horizontal line intersects a slope one time, it is inside the triangle
    // triangle 234 - point 1
    //std::cout << insidetriangle(rx1, ry1, rx2, ry2, rx3, ry3, rx4, ry4, m23, m34, m24) << "\n";
    while (insidetriangle(rx1, ry1, rx2, ry2, rx3, ry3, rx4, ry4, m23, m34, m24)) {
        rx4 = double(rand()) / RAND_MAX;
        ry4 = double(rand()) / RAND_MAX;
    }

    //triangle 134 - point 2
    //std::cout << insidetriangle(rx2, ry2, rx1, ry1, rx3, ry3, ry4, ry4, m13, m34, m14) << "\n";
    while (insidetriangle(rx2, ry2, rx1, ry1, rx3, ry3, ry4, ry4, m13, m34, m14)) {
        rx4 = double(rand()) / RAND_MAX;
        ry4 = double(rand()) / RAND_MAX;
    }

    //triangle 124 - point 3
    //std::cout << insidetriangle(rx3, ry3, rx1, ry1, rx2, ry2, rx4, ry4, m12, m24, m14) << "\n";
    while (insidetriangle(rx3, ry3, rx1, ry1, rx2, ry2, rx4, ry4, m12, m24, m14)) {
        rx4 = double(rand()) / RAND_MAX;
        ry4 = double(rand()) / RAND_MAX;
    }

    // triangle 123 - point 4
    //std::cout << insidetriangle(rx4, ry4, rx1, ry1, rx2, ry2, rx3, ry3, m12, m23, m13) << "\n";
    while (insidetriangle(rx4, ry4, rx1, ry1, rx2, ry2, rx3, ry3, m12, m23, m13)) {
        rx4 = double(rand()) / RAND_MAX;
        ry4 = double(rand()) / RAND_MAX;
    }

    std::cout << std::setprecision(17) << "(" << rx1 << "," << ry1 << ") , (" << rx2 << "," << ry2 << ") , (" << rx3 << "," << ry3 << ") , (" << rx4 << "," << ry4 << ")\n";
    file << std::setprecision(17) << "(" << rx1 << "," << ry1 << ") , (" << rx2 << "," << ry2 << ") , (" << rx3 << "," << ry3 << ") , (" << rx4 << "," << ry4 << ")";
}
int main() {
    part1();
    //file << "P3" << " " << size << " " << size << " " << "1\n";
}