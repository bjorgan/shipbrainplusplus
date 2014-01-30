#include "ocean.h"

#include <QLabel>
#include <QGridLayout>
#include <QPainter>
#include <QPainterPath>
#include <QTimer>

#include <cmath>
#include <iostream>
#include <unordered_map>

// constants (knuts sin greie!!)
#define PI 3.14159
#define STD_GRAV 9.81 // standard gravity 
#define NUMBER_OF_POINTS 1000

// magic constants
using namespace std;

Ocean::Ocean(QWidget *parent) : QWidget(parent){
  //initialize array of random seeds for wave generation
  initializeWaves();

  // initiate a timer which will update time
  time = 0;
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
  timer->start(10);
}

float *ei;
unordered_map<float, float> spectrum_lookup;

double waveSpectrum(float w) {
  if (w == 0){
    return 0;
  }
  else {
    auto record = spectrum_lookup.find(w);
    if (record != spectrum_lookup.end()) {
      return record->second;
    }
  }

  float Tp = 15;
  float wp = 2*PI/Tp;
  float Hs = 100.0;
  float gamma = 3;
  float sigma;

  if (w <= wp) {
    sigma = 0.07;
  } else {
    sigma = 0.09;
  }
	
  float a = 5.0/(32*PI);
  float b = Hs*Hs*Tp;
  float c = pow((wp/w), 5);
  float d = exp(-5.0/4.0*pow((wp/w), 4));
  float e = (1-0.287*log(gamma));
  float f = pow(gamma, exp(-(pow((w/wp)-1, 2)/(2*sigma*sigma))));
        

  float spectrum = a*b*c*d*e*f;
  spectrum_lookup.emplace(w, spectrum);

  cout<<spectrum<<endl;
  return spectrum;

}

void initializeWaves(){
  /* initializes the wave points randomly */
  ei = new float[NUMBER_OF_POINTS];
  for (int i=0; i < NUMBER_OF_POINTS; i++) {
    ei[i] = rand()/(RAND_MAX*1.0f)*PI;
  }
}

<<<<<<< HEAD
double waterVal(float x, float t) {
  /* Computes the height of the water at point x at time t */
  float a = 0;
  float b = 3;
  float dw = (b-a)/NUMBER_OF_POINTS;
  double retval = 0;

  for (int i=0; i < NUMBER_OF_POINTS; i++){
    float wi = a+i*dw;
    float ki = pow(wi, 2)/STD_GRAV;
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
  time += 1;
  update();
}
