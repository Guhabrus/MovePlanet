#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsEllipseItem>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    void onTimeout();

private:
    QGraphicsScene* _scene;
    QGraphicsView* _view;
    QTimer* _timer;
    QGraphicsEllipseItem* _point;

};
#endif // MAINWINDOW_H
