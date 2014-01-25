#include "ocean.h"
#include <QLabel>
#include <QGridLayout>
#include <QPainter>
#include <QPainterPath>
#include <cmath>
#include <QTimer>
#include <iostream>
using namespace std;


Ocean::Ocean(QWidget *parent) : QWidget(parent){
	//initialize array of random seeds for wave generation
	initializeWaves();

	// initiate a timer which will update time
	time = 0;
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
	timer->start(100);
}

//fra knuts
#define PI 3.14159
#define g 9.81

#define N 1000
float *ei;

double waveSpectrum(float w){
	if (w == 0){
		return 0;
	}

	float Tp = 15;
	float wp = 2*PI/Tp;
	float Hs = 100.0;
	float gamma = 3;
	float sigma;
	if (w <= wp){
		sigma = 0.07;
	} else {
		sigma = 0.09;
	}
	
	float a = 5.0/(32*PI);
	float b = Hs*Hs*Tp;
	float c = (wp/w)*(wp/w)*(wp/w)*(wp/w)*(wp/w);
	float d = exp(-5.0/4.0*(wp/w)*(wp/w)*(wp/w)*(wp/w));
	float e = (1-0.287*log(gamma));
	float f = pow(gamma, exp(-(pow((w/wp)-1, 2)/(2*sigma*sigma))));

	return a*b*c*d*e*f;
}

void initializeWaves(){
	ei = new float[N];
	for (int i=0; i < N; i++){
		ei[i] = rand()/(RAND_MAX*1.0f)*PI;
	}
}

double waterVal(float x, float t){
	float a = 0;
	float b = 3;
	float dw = (b-a)/N;
	double retval = 0;

	for (int i=0; i < N; i++){
		float wi = a+i*dw;
		float ki = wi*wi/g;
		retval += sqrt(2*waveSpectrum(wi)*dw)*sin(wi*t - ki*x + ei[i]);
	}
	return retval;
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
		path.lineTo(i,120+waterVal(i, time));
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
