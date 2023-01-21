#ifndef DRAWRECTANGLE_H
#define DRAWRECTANGLE_H
#include "mainwindow.h"
#include "rectangle.h"
#include "line.h"
#include "circle.h"
#include "shape.h"
#include <QtCore>
#include <QtGui>
#include <QDialog>

namespace Ui {
class DrawRectangle;
}

class DrawRectangle : public QDialog
{
    Q_OBJECT

public:
    explicit DrawRectangle(QWidget *parent = nullptr);
    ~DrawRectangle();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DrawRectangle *ui;
};

#endif // DRAWRECTANGLE_H
