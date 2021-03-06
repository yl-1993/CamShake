#ifndef CAMSHAKE_H
#define CAMSHAKE_H

#include <QtWidgets/QMainWindow>
#include "ui_camshake.h"
#include "camera.h"
class CamShake : public QMainWindow
{
	Q_OBJECT

public:
	CamShake(QWidget *parent = 0);
	Camera* cam;
	~CamShake();

public:
	Ui::CamShakeClass ui;

protected:
	void closeEvent(QCloseEvent* ev);
	void keyPressEvent(QKeyEvent *e);
public slots:
		void startConCam();
		void startDisCam();
		void stopCam();
		void setKeyBind();
		void setMenuDisabled();
		void setMenuAble();
		string q2s(const QString &s);
		void setRect();
};

#endif // CAMSHAKE_H
