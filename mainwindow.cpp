#include "mainwindow.h"
#include "ocean.h"
#include <QWidget>
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
	Ocean *ocean = new Ocean(this);
	setCentralWidget(ocean);
	QAction * sstop = new QAction ("&Sstop", this);
	QMenu * menu;
	menu->addAction(sstop);
	connect(sstop, SIGNAL(triggered()), this, SLOT(ocean->flipTimeState));
	

}
