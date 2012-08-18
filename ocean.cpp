#include "ocean.h"
#include <QLabel>
#include <QGridLayout>
#include <QPainter>
#include <QPainterPath>
#include <cmath>
#include <QTimer>

Ocean::Ocean(QWidget *parent) : QWidget(parent){
	QLabel *dust = new QLabel("dette er en sjø....");
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(dust);

	//prepare x-coordinates NEJ set width of wave
	x = 1000;
	//fire a timer which will update time
	time = 0;
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
	timer->start(100);
}

void Ocean::paintEvent(QPaintEvent *){
	QPainter painter(this);
	painter.setPen(Qt::red);

	//create ocean path
	QPainterPath path;
	for (int i=0; i < x; i++){
		path.lineTo(i, 100+50*cos(0.03*i-time));
	}
	painter.drawPath(path);
}

void Ocean::updateTime(){
	time += 0.1;
	update();
}
