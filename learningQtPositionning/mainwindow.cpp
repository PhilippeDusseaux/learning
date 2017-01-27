#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // configuration de la gui
    ui->setupUi(this);

    // création de la gridLayout, de la view et allocation dynamique de la scene

    view = ui->graphicsView;
    scene = new QGraphicsScene();

    // construction de la scene
    QRect dimScene(0.0,0.0,1920.0,1080.0);
    scene->setSceneRect(dimScene);

    // creation de text et le placer dans textEdit
    QString text = "Hello, world!";
    ui->textEdit->setText(text);

    // creation d'une PIXMAP
    QPixmap bg_pixmap("map.png");
    //ui->graphicsView->addScrollBarWidget(bg_pixmap,Qt::AlignCenter);

    // association de la scene à la view
    scene->addPixmap(bg_pixmap);
    view->setScene(scene);

    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete view;
    delete scene;
    delete route;
}
