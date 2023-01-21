#include "search.h"
#include "ui_search.h"
#include <QMessageBox>
#include <iostream>
#include <algorithm>

search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}

void search::on_pushButton_clicked()
{   bool found = false;
    QString foundShape;
    for (unsigned long long i = 0 ; (i <Shape::shapes.size()) ; i++){
        class Shape* r = Shape::shapes.at(i);
        if (r->getName() == ui->lineEdit->displayText()){
            found = true;
            foundShape = "Name: "+r->getName()+ "\ntype: "+r->gettype()+ "\nColor: "+r->getColor()+QString("\nPerimeter: %1").arg(r->getPer());
        }
    }
    if (found){
        QMessageBox::information(this,"Found Shape",foundShape);
    }
    else {
        QMessageBox::information(this,"Search","Shape not found");
    }
//    std::vector<class Shape*> shapes_copy = Shape::shapes;
//       std::sort(shapes_copy.begin(), shapes_copy.end());
//       for (unsigned long long i = 0 ; (i <Shape::shapes.size()) ; i++){
//           std::cout<<(shapes_copy.at(i)->getName()).toStdString()<<std::endl;
//       }
    this->close();

}

