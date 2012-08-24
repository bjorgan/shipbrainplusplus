#include "mainwindow.h"
#include "ocean.h"
#include <QWidget>
#include <QToolBar>
#include <QIcon>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
	Ocean *ocean = new Ocean(this);
	setCentralWidget(ocean);
	QPixmap sstoppix("new.png");
	QToolBar *toolbar = addToolBar("main tool bar");
	QAction *sstop = toolbar->addAction(QIcon(sstoppix), "Start/stop wave");
	connect(sstop, SIGNAL(triggered()),ocean , SLOT(flipTimeState()));


	

}
