#include "Window.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    _scene = new QGraphicsScene(0, 0, 600, 600, this);
    _scene->addRect(_scene->sceneRect());

    _view = new QGraphicsView;
    _view->setScene(_scene);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addWidget(_view);

    QWidget* mainWidget = new QWidget;
    mainWidget->setLayout(mainLayout);

    this->setCentralWidget(mainWidget);

    _point = new QGraphicsEllipseItem(0, 0, 10, 10);
    _scene->addItem(_point);

   _timer = new QTimer(this);
   connect(_timer, &QTimer::timeout, this, &MainWindow::onTimeout);
   _timer->start(100);

}

MainWindow::~MainWindow()
{
    
}

void MainWindow::onTimeout()
{
    QPointF oldPos = _point->pos();
    QPointF newPos = QPointF(_point->pos().x() + 1, _point->pos().y() + 1);

    _point->setPos(newPos);

    QGraphicsLineItem* line = new QGraphicsLineItem (QLineF(oldPos, newPos));

    _scene->addItem(line);
}
