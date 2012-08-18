#ifndef OCEAN_H_DEFINED
#define OCEAN_H_DEFINED

#include <QWidget>

class Ocean : public QWidget{
	Q_OBJECT
	public:
		Ocean(QWidget *parent = NULL);
		void paintEvent(QPaintEvent *);

	public slots:
		void updateTime(); //update time and redraw

	private:
		//ocean coordinates
		int x;
		double time;
};

#endif
