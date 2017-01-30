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
    QRect dimScene(0.0,0.0,1920.0,1080.0);
    scene->setSceneRect(dimScene);

    // creation de text et le placer dans textEdit
    QString text = "Hello, world!";
    ui->textEdit->setText(text);

    // creation d'une PIXMAP
    QPixmap bg_pixmap("map.png");

    // association de la scene à la view
    ui->graphicsView->setScene(scene);

    scene->addPixmap(bg_pixmap);

    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}
