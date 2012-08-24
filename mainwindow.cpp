#include "mainwindow.h"
#include "ocean.h"
#include <QWidget>
<<<<<<< HEAD
#include <QToolBar>
#include <QIcon>
#include <QAction>
=======
#include <QMenu>
#include <QMenuBar>
>>>>>>> 6b426f95ea4a0405f52fa384ca833dd89be078a5

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
	Ocean *ocean = new Ocean(this);
	setCentralWidget(ocean);
<<<<<<< HEAD
	QPixmap sstoppix("new.png");
	QToolBar *toolbar = addToolBar("main tool bar");
	QAction *sstop = toolbar->addAction(QIcon(sstoppix), "Start/stop wave");
	connect(sstop, SIGNAL(triggered()),ocean , SLOT(flipTimeState()));


=======
	QAction * sstop = new QAction ("&Sstop", this);
	QMenu * menu;
	menu->addAction(sstop);
	connect(sstop, SIGNAL(triggered()), this, SLOT(ocean->flipTimeState));
>>>>>>> 6b426f95ea4a0405f52fa384ca833dd89be078a5
	

}
