#include "mainwindow.h"
#include "ocean.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
	Ocean *ocean = new Ocean(this);
	setCentralWidget(ocean);
}
