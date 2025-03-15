#include<iostream>
using namespace std;
#include "cylinder.h"
#include "point.cpp"
#include "circle.cpp"
#include "cylinder.cpp"
int main()
{
    cylinder cy(3.5, 6.4, 5.2, 10);
    cout << "\noriginal cylinder:\nx=" << cy.getx() << ", y=" << cy.gety() << ", r=" << cy.getRadius() << ", h="
         << cy.getHeight() << "\narea=" << cy.area() << ", volume=" << cy.volume() << endl;
    cy.setHeight(15);
    cy.setRadius(7.5);
    cy.setPoint(5, 5);
    cout << "\nnew cylinder:\n"
         << cy;
    point &pRef = cy;
    cout << endl<<"pRef as a point: " << pRef;
    circle &cRef = cy;
    cout <<endl<< "cRef as a circle: " << cRef;
    system("pause");
    return 0;
}