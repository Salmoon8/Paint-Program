#ifndef DRAWLINE_H
#define DRAWLINE_H
#include "rectangle.h"
#include "line.h"
#include "circle.h"
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class DrawLine;
}

class DrawLine : public QDialog
{
    Q_OBJECT

public:
    explicit DrawLine(QWidget *parent = nullptr);
    ~DrawLine();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DrawLine *ui;
};

#endif // DRAWLINE_H
