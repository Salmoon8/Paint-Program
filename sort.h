#ifndef SORT_H
#define SORT_H
#include "shape.h"
#include <iostream>
#include <QtCore>
#include <QtGui>
#include <vector>
#include <algorithm>
#include <QDialog>

namespace Ui {
class sort;
}

class sort : public QDialog
{
    Q_OBJECT

public:
    explicit sort(QWidget *parent = nullptr);
    ~sort();

private:
    Ui::sort *ui;
};

#endif // SORT_H
