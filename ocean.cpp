#include "ocean.h"
#include <QLabel>
#include <QGridLayout>

Ocean::Ocean(QWidget *parent) : QWidget(parent){
	QLabel *dust = new QLabel("dette er en sjø....");
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(dust);
}
