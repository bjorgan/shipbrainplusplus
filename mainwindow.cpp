#include "mainwindow.h"
#include "ocean.h"
#include <QWidget>
#include <QSize>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
	Ocean *ocean = new Ocean(this);
	setCentralWidget(ocean);
	resize(width(), height());
}
