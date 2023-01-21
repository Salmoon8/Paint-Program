#include "sort.h"
#include "ui_sort.h"
bool comparator ( Shape* a, Shape*b) {
    return  ( a->getPer() < b-> getPer() );
}

sort::sort(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sort)
{
    ui->setupUi(this);
    std::vector<class Shape*> shapes_copy = Shape::shapes;
    std::sort(shapes_copy.begin(), shapes_copy.end(),comparator);
    for (unsigned long long i = 0 ; (i <Shape::shapes.size()) ; i++){
       // std::cout<<(shapes_copy.at(i)->getName()).toStdString()<<std::endl;
        QLabel* l1 = new QLabel(this);
        QLabel* l2 = new QLabel(this);
        QLabel* l3 = new QLabel(this);
         QLabel* l4 = new QLabel(this);
         QLabel* l5 = new QLabel(this);
        l1->setText(shapes_copy.at(i)->getName());
        ui->gridLayout->addWidget(l1);
        l3->setText(shapes_copy.at(i)->getColor());
        ui->gridLayout->addWidget(l3);
        l2->setText(QString("%1").arg(shapes_copy.at(i)->getPer()));
        ui->gridLayout->addWidget(l2);
         l4->setText(shapes_copy.at(i)->gettype());
        ui->gridLayout->addWidget(l4);
      //  l5->setText(shapes_copy.at(i)->getmaincord());
     //   ui->gridLayout->addWidget(l5);


    }
}

sort::~sort()
{
    delete ui;
}
