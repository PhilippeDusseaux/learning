#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGeoRoute>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGridLayout * gridLayout;
    QGraphicsView * view;
    QGraphicsScene * scene;
    QGeoRoute * route;
};

#endif // MAINWINDOW_H
