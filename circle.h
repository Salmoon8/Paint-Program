#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <QVector>
#include <QtCore>
#include <QtGui>
#include <QString>
#include <QColor>
#include <QString>
#include <cmath>

class Circle : public Shape
{
private:
    int center_x;
    int center_y;
    int diameter;
    QString type = "circle";
 //   double per;
public:
    Circle();
//    static std::vector<Circle*> circs;
    void set_centerx (int cx){
        center_x = cx;
    }
    void set_centery(int cy){
        center_y = cy;
    }
    void set_diameter(int d){
        diameter = d ;
    }
    int get_centerx(){
        return center_x;
    }
    int get_centery(){
        return center_y;
    }
    int get_diameter(){
        return diameter;
    }
    virtual double getPer(){
        setPer(M_PI *abs( diameter));
        return get_per();
    }
    virtual QString gettype() { return type; }
   // virtual QString getmaincord() {
   // QString ret = "(" +QString::number( get_centerx(),10) + "," +QString::number( get_centery(),10) + ")" ;
   // return ret; }
};

#endif // CIRCLE_H
