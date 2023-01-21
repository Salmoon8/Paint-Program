#include "drawrectangle.h"
#include "ui_drawrectangle.h"
#include <QMessageBox>

DrawRectangle::DrawRectangle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawRectangle)
{
    ui->setupUi(this);
    ui->xpoint->setValidator( new QIntValidator(-100000, 100000 ));
    ui->ypoint->setValidator( new QIntValidator(-100000, 100000));
    ui->width->setValidator( new QIntValidator(-100000, 100000));
    ui->height->setValidator( new QIntValidator(-100000, 100000 ));
}


DrawRectangle::~DrawRectangle()
{
    delete ui;
}

void DrawRectangle::on_pushButton_clicked()
{
    class Rectangle* r = new class Rectangle();
    r->setName(ui->name->displayText());
    r->setColor(ui->comboBox->currentText());
    r->set_xcoor((ui->xpoint->displayText()).toInt());
    r->set_ycoor((ui->ypoint->displayText()).toInt());
    r->set_width((ui->width->displayText()).toInt());
    r->set_height((ui->height->displayText()).toInt());
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
                MainWindow::scene->addRect(r->get_xcoor(),r->get_ycoor(),r->get_width(),r->get_height());
                Shape::shapes.push_back(r);
                this->close();
            }
            else if (ui->comboBox->currentText() == "Blue"){
                MainWindow::scene->addRect(r->get_xcoor(),r->get_ycoor(),r->get_width(),r->get_height(),QPen(Qt::blue));
                Shape::shapes.push_back(r);
                this->close();
            }
            else if (ui->comboBox->currentText() == "Red"){
                MainWindow::scene->addRect(r->get_xcoor(),r->get_ycoor(),r->get_width(),r->get_height(),QPen(Qt::red));
                Shape::shapes.push_back(r);
                this->close();
            }
            else{
                QMessageBox::information(this,"Color","Please choose a color for the shape");
            }
        }

}

