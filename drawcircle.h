#ifndef DRAWCIRCLE_H
#define DRAWCIRCLE_H
#include "rectangle.h"
#include "line.h"
#include "circle.h"
#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class DrawCircle;
}

class DrawCircle : public QDialog
{
    Q_OBJECT

public:
    explicit DrawCircle(QWidget *parent = nullptr);
    ~DrawCircle();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DrawCircle *ui;
};

#endif // DRAWCIRCLE_H
