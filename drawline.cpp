#include "drawline.h"
#include "ui_drawline.h"
#include <QMessageBox>

DrawLine::DrawLine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawLine)
{
    ui->setupUi(this);
    ui->startx->setValidator( new QIntValidator(-100000, 100000 ));
    ui->starty->setValidator( new QIntValidator(-100000, 100000));
    ui->endx->setValidator( new QIntValidator(-100000, 100000 ));
    ui->endy->setValidator( new QIntValidator(-100000, 100000 ));
}

DrawLine::~DrawLine()
{
    delete ui;
}

void DrawLine::on_pushButton_clicked()
{
    class Line* l = new class Line();
    l->setName(ui->name->displayText());
    l->setColor(ui->comboBox->currentText());
    l->set_startx((ui->startx->displayText()).toInt());
    l->set_starty((ui->starty->displayText()).toInt());
    l->set_endx((ui->endx->displayText()).toInt());
    l->set_endy((ui->endy->displayText()).toInt());
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
                MainWindow::scene->addLine(l->get_startx(),l->get_starty(),l->get_endx(),l->get_endy());
                Shape::shapes.push_back(l);
                this->close();
            }
            else if (ui->comboBox->currentText() == "Blue"){
                MainWindow::scene->addLine(l->get_startx(),l->get_starty(),l->get_endx(),l->get_endy(),QPen(Qt::blue));
                Shape::shapes.push_back(l);
                this->close();
            }
            else if (ui->comboBox->currentText() == "Red"){
                MainWindow::scene->addLine(l->get_startx(),l->get_starty(),l->get_endx(),l->get_endy(),QPen(Qt::red));
                Shape::shapes.push_back(l);
                this->close();
            }
            else{
                QMessageBox::information(this,"Color","Please choose a color for the shape");
            }
        }


}

