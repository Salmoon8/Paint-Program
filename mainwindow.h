#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "drawline.h"
#include "drawcircle.h"
#include "drawrectangle.h"
#include "search.h"
#include "sort.h"
#include <QMainWindow>
#include <QVector>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class DrawRectangle;
class DrawCircle;
class DrawLine;
class search;
class sort;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static QGraphicsScene* scene;
    QList<QGraphicsItem *>	list;
    QList<QGraphicsItem *>	listredo;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionLine_triggered();

    void on_actionRectangle_triggered();

    void on_actionCircle_triggered();

    void on_actionsearch_triggered();

    void on_actionSort_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

private:
    DrawLine* line;
    DrawRectangle* rect;
    DrawCircle* cir;
    search* s;
    sort* r;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
