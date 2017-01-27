#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // configuration de la gui
    ui->setupUi(this);

    // allocation dynamique de la view, de la scene, de l'item et de la route
    /*view = ui->centralWidget;
    view->
    scene = new QGraphicsScene;
    route = new QGeoRoute;*/




}

MainWindow::~MainWindow()
{
    delete ui;
    delete view;
    delete scene;
    delete route;
}
