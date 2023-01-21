#ifndef SEARCH_H
#define SEARCH_H
#include "mainwindow.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "line.h"
#include <iostream>
#include <vector>
#include <QDialog>


namespace Ui {
class search;
}
class foundshape;
class search : public QDialog
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();

private slots:
    void on_pushButton_clicked();

private:
    Ui::search *ui;
};

#endif // SEARCH_H
