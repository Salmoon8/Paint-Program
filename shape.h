#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <vector>
#include <QtCore>
#include <QtGui>
#include <QString>
#include <QColor>

class Shape
{
private:
    QString name;
    QString color;
    double per;
   QString type;

public:
    Shape();
    static std::vector<Shape*> shapes;
    static std::vector<Shape*> shapesredo;

    void setName(QString n){
        name = n;
    }
    void setColor(QString c){
        color = c;
    }
    void setPer(double p){
        per = p;
    }
    double get_per(){
        return per;
    }
    QString getName(){
        return name;
    }
    QString getColor(){
        return color;
    }
    virtual double getPer() = 0;
    virtual QString gettype() = 0;
   //  virtual QString getmaincord() = 0;
};

#endif // SHAPE_H
