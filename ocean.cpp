#include "ocean.h"
#include <QLabel>
#include <QGridLayout>
#include <QPainter>
#include <QPainterPath>
#include <cmath>
#include <QTimer>

Ocean::Ocean(QWidget *parent) : QWidget(parent){
	// initiate a timer which will update time
	time = 0;
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
	timer->start(100);
}

void Ocean::paintEvent(QPaintEvent *){

	x = width();

	QPainter painter(this);
	painter.setPen(Qt::red);
	
	// create ocean path
	QPoint start (0,height());
	QPoint end (width(),height());
	QPainterPath path (start);
	for (int i=0; i < x; i++){
		path.lineTo(i,400+ 50*cos(0.03*i-time));
	}
	path.lineTo(end);
	QBrush brush (Qt::red, Qt::Dense6Pattern);
	painter.setBrush(brush);
	painter.drawPath(path);
}

void Ocean::updateTime() {
	time += 0.1;
	update();
}
