#include "camshake.h"
#include <QtWidgets/QApplication>
#include "camera.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CamShake w;
	Camera cam;
	cam.window = &w;
	w.cam = &cam;
	
	w.show();
	//cam.run();
	return a.exec();
}
