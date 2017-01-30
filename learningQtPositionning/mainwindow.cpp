#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // configuration de la gui
    ui->setupUi(this);

    // création de la gridLayout, de la view et allocation dynamique de la scene

    ui->graphicsView;
    scene = new QGraphicsScene(ui->graphicsView);

    // construction de la scene
    QRect dimScene(-180,-90,360,180);
    scene->setSceneRect(dimScene);

    // on inverse l'axe des ordonnées
    ui->graphicsView->scale(1.0,-1.0);

    // association de la scene à la view
    ui->graphicsView->setScene(scene);

    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}
