#include "drawcircle.h"
#include "ui_drawcircle.h"
#include <QMessageBox>

DrawCircle::DrawCircle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawCircle)
{
    ui->setupUi(this);
    ui->centerx->setValidator( new QIntValidator(-100000, 100000 ));
    ui->centery->setValidator( new QIntValidator(-100000, 100000));
    ui->diameter->setValidator( new QIntValidator(-100000, 100000 ));
}

DrawCircle::~DrawCircle()
{
    delete ui;
}

void DrawCircle::on_pushButton_clicked()
{
    class Circle* c = new class Circle();
    c->setName(ui->name->displayText());
    c->setColor(ui->comboBox->currentText());
    c->set_centerx((ui->centerx->displayText()).toInt());
    c->set_centery((ui->centery->displayText()).toInt());
    c->set_diameter((ui->diameter->displayText()).toInt());
    bool found = false;
    for (unsigned long long i = 0 ; (i <Shape::shapes.size()) ; i++){
        class Shape* r = Shape::shapes.at(i);
        if (r->getName() == ui->name->displayText())
            found = true;
    }
        if (found){
            QMessageBox::information(this,"Shape Name","The name is already used \n Try another name");
        }
        else {
            if (ui->comboBox->currentText() == "Black"){
                MainWindow::scene->addEllipse(c->get_centerx(),c->get_centery(),c->get_diameter(),c->get_diameter());
                Shape::shapes.push_back(c);
                this->close();
            }
            else if (ui->comboBox->currentText() == "Blue"){
                MainWindow::scene->addEllipse(c->get_centerx(),c->get_centery(),c->get_diameter(),c->get_diameter(),QPen(Qt::blue));
                Shape::shapes.push_back(c);
                this->close();
            }
            else if (ui->comboBox->currentText() == "Red"){
                MainWindow::scene->addEllipse(c->get_centerx(),c->get_centery(),c->get_diameter(),c->get_diameter(),QPen(Qt::red));
                Shape::shapes.push_back(c);
                this->close();
            }
            else{
                QMessageBox::information(this,"Color","Please choose a color for the shape");
            }
        }

}

