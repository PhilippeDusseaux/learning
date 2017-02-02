#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QDesktopWidget>

class CustomScene : public QGraphicsScene
{
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event)
    {

        qDebug() << "Scene coordinates position : " << event->scenePos();
        /*qDebug() << "Item coordinates pos : " << event->pos();
        qDebug() << "Screen coordinates pos : " << event->screenPos();*/
    }
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // création du widget screens
    QDesktopWidget * screens = QApplication::desktop();
    // mainwindow récupère les dimensions de l'écran
    this->setBaseSize(screens->width(),screens->height());

    QPixmap terre;
    terre.load("Mercator_projection_SW","jpeg");
    terre.scaled(Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    // configuration de la gui
    ui->setupUi(this);

    // allocation dynamique de la scene
    scene = new CustomScene();

    // construction de GraphicsPixmapItem à partir de terre et il n'a pas de parent
    QGraphicsPixmapItem * PixmapItem = new QGraphicsPixmapItem(terre,Q_NULLPTR);

    // on place la terre au milieu de la carte
    QPoint origineTerre(-(terre.width()/2),-(terre.height()/2));
    PixmapItem->setOffset(origineTerre);

    QTransform pixmapItemTransform;
    pixmapItemTransform.scale(360.0/terre.width(),-180.0/terre.height());
    PixmapItem->setTransform(pixmapItemTransform);

    // association de la scene à la view
    ui->graphicsView->setScene(scene);

    // ajout de la carte du monde
    scene->addItem(PixmapItem);

    // on inverse l'axe des ordonnées
    ui->graphicsView->scale(this->width()/360,-this->height()/180);

    //ui->graphicsView->adjustSize();
    //ui->graphicsView->viewport()->updateGeometry();

    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}


