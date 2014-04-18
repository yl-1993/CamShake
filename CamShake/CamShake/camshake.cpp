#include "camshake.h"

CamShake::CamShake(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(this->ui.pushButton, SIGNAL(clicked()), this, SLOT(startCam()));
	
}

CamShake::~CamShake()
{

}
void CamShake::startCam()
{
	this->cam->start();
}
void CamShake::closeEvent(QCloseEvent* evn)
{
	this->cam->isExist = true;
	while(this->cam->isRunning());
}