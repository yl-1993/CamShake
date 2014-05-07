#include "camshake.h"
#include <QtWidgets/QApplication>
#include "camera.h"

void loadStyleSheet(QString qssName)//加入下面函数
{

    QFile qdata(qssName);
    QString qssFile;

    if(qdata.open(QFile::ReadOnly))
    {
        qssFile = qdata.readAll();

        qdata.close();

        qApp->setStyleSheet(qssFile);

    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setAttribute(Qt::AA_MacPluginApplication, true);
	loadStyleSheet(QString(":/camshake.qss"));

	CamShake w;
	Camera cam;
	cam.window = &w;
	w.cam = &cam;

	w.show();
	//cam.run();
	return a.exec();
}
