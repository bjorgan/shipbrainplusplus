#include "mainwindow.h"
#include "ocean.h"
#include <QWidget>
#include <QToolBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
	Ocean *ocean = new Ocean(this);
	setCentralWidget(ocean);
	// Defines the toolbar for the wave;
	QToolBar *toolbar = addToolBar("main tool bar");
	QAction *sstop = toolbar->addAction("Start/stop wave");
	connect(sstop, SIGNAL(triggered()),ocean , SLOT(flipTimeState()));
}
