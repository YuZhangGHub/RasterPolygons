#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ConvexPolRas.h"
#include "QPainter"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void paintPoint(int x, int y, color clr, void* painter)
{
    QPainter* device = (QPainter*)painter;

    if(NULL == device) return;

    device->setPen(QColor(clr.R, clr.G, clr.B, clr.A));

    device->drawPoint(x, y);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QMainWindow::paintEvent(e);

    QPainter painter(this);

    QPolygon polygon;
    const int num = 5;
    int x[5]     = {100, 200, 300, 250, 150};
    int y[5]     = {100, 50, 100, 200, 200};
    color clr[5];

    clr[0].R = 255;
    clr[0].G = 255;
    clr[0].B = 255;
    clr[0].A = 255;

    clr[1].R = 255;
    clr[1].G = 0;
    clr[1].B = 0;
    clr[1].A = 255;

    clr[2].R = 0;
    clr[2].G = 255;
    clr[2].B = 0;
    clr[2].A = 255;

    clr[3].R = 0;
    clr[3].G = 0;
    clr[3].B = 255;
    clr[3].A = 255;

    clr[4].R = 0;
    clr[4].G = 0;
    clr[4].B = 0;
    clr[4].A = 255;

    for(int k = 0; k < num; k++)
    {
        polygon.append(QPoint(x[k], y[k]));
    }

    mpConvexPolRas(x, y, clr, 5, 255, paintPoint, (void*)(&painter));
    //painter.drawPolygon(polygon);
    painter.end();
}
