#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "circle.h"
#include "line.h"
#include "rectangle.h"
#include <search.h>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::scene = new QGraphicsScene(*&ui->graphicsView);
    MainWindow::scene->setBackgroundBrush(Qt::white);
    ui->graphicsView->setScene(MainWindow::scene);
}
MainWindow::~MainWindow()
{
    delete ui;
}
QGraphicsScene* MainWindow::scene;
void MainWindow::on_actionLine_triggered()
{
    line = new DrawLine(this);
    line->setModal(true);
    line->exec();
}

void MainWindow::on_actionRectangle_triggered()
{
    rect = new DrawRectangle(this);
    rect->setModal(true);
    rect->exec();
}

void MainWindow::on_actionCircle_triggered()
{
    cir = new DrawCircle(this);
    cir->setModal(true);
    cir->exec();
}



void MainWindow::on_actionsearch_triggered()
{
    s = new search(this);
    s->setModal(true);
    s->exec();
}


void MainWindow::on_actionSort_triggered()
{
    r = new sort(this);
    r->setModal(true);
    r->exec();
}


void MainWindow::on_actionUndo_triggered()
{
    QList<QGraphicsItem *>	list= scene->items ();
         if (!list.isEmpty()) {
        QGraphicsItem * item = list.first();
        listredo.push_back(item);
        scene->removeItem(item);
        Shape* item1= Shape::shapes.back();
        Shape::shapes.pop_back();
        Shape::shapesredo.push_back(item1); }
         else {
            QMessageBox::information(this," Undo ","Scene is empty");
        }
}


void MainWindow::on_actionRedo_triggered()
{
    if (!listredo.isEmpty()) {
            QGraphicsItem * item = listredo.last();
            list.push_front(item);
           scene->addItem(item);
           listredo.pop_back();
           Shape* item1= Shape::shapesredo.back();
           Shape::shapesredo.pop_back();
           Shape::shapes.push_back(item1);
        }     else {
             QMessageBox::information(this," Redo ","No shapes were removed");
         }
}


void MainWindow::on_actionSave_triggered()
{
    QString fileName= QFileDialog::getSaveFileName(this, "Save image", QCoreApplication::applicationDirPath(), "BMP Files (.bmp);;JPEG (.JPEG);;PNG (*.png)" );
                    if (!fileName.isNull())
                    {
                        QPixmap pixMap = this->ui->graphicsView->grab();
                        pixMap.save(fileName);
                    }
}


void MainWindow::on_actionLoad_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(
                       this,tr("Open File"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));

            if (fileName.isEmpty())  {
                    return;
                }

                QPixmap p(fileName);
                if (! ui->graphicsView->scene()) {
                    qDebug() << "No Scene!";

                    QGraphicsScene *scene = new QGraphicsScene(this);
                    ui->graphicsView->setScene(scene);
                }
                ui->graphicsView->scene()->addPixmap(p);
}

