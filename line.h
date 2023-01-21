#ifndef LINE_H
#define LINE_H
#include "shape.h"
#include <cmath>
#include <iostream>
#include <vector>
#include <QtCore>
#include <QtGui>
#include <QString>
#include <QColor>
#include <QString>

class Line : public Shape
{
private:
    int startx;
    int starty;
    int endx;
    int endy;
    const QString type = "line";
//    double per;
public:
    Line();
//    static std::vector<Line*> lines;
    void set_startx(int x){
        startx = x;
    }
    void set_starty(int y){
        starty = y;
    }
    void set_endx(int x){
        endx = x;
    }
    void set_endy(int y){
        endy = y;
    }
    int get_startx(){
        return startx;
    }
    int get_starty(){
        return starty;
    }
    int get_endx(){
        return endx;
    }
    int get_endy(){
        return endy;
    }
    virtual double getPer(){
        setPer(sqrt(((endy-starty)*(endy-starty))+((endx-startx)* (endx-startx))));
        return get_per();
    }
    virtual QString gettype() { return type; }
   // virtual QString getmaincord() {
   // QString ret = "(" +QString::number(get_startx(),  10 ) + "," +QString::number(get_starty(),  10 ) + ")" ;
   // return ret; }

};
#endif // LINE_H
