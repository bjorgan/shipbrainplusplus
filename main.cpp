#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class Dust : public QWidget{
	public:
		Dust(QWidget *parent = NULL);
};


int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	Dust dust;
	dust.show();
	return app.exec();
}

Dust::Dust(QWidget *parent) : QWidget(parent){
	QLabel *dust = new QLabel("hei din dustemikkel");
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(dust, 0, 0);
}
