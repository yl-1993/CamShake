#include "camshake.h"

CamShake::CamShake(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(this->ui.ContinuousBtn, SIGNAL(clicked()), this, SLOT(startConCam()));
	connect(this->ui.DiscreteBtn, SIGNAL(clicked()), this, SLOT(startDisCam()));
	connect(this->ui.StopBtn, SIGNAL(clicked()), this, SLOT(stopCam()));

}

void CamShake::keyPressEvent(QKeyEvent *e)
{
	qWarning("Taste::keyPressEvent(QKeyEvent *e)");
	//e->accept();  // Annehmen des KeyEvents
	qDebug("keyPressEvent(QKeyEvent *e) here");
	if( e->key() == Qt::Key_Return)
	{
		switch ( e->key() )
		{                     // Hinweis: die Rueckgabecodes der einzelnen Tasten findet man in der "qnamespace.h"
			case Qt::Key_Left:     // Pfeiltaste "links" gedueckt?
				qWarning("Taste links");
				break;
			case Qt::Key_X:     // Taste "x" gedueckt?
				qWarning("Taste x");
				break;
		}
	}
	else
	{
		keyPressEvent(e);
	}
}

CamShake::~CamShake()
{

}
void CamShake::startConCam()
{
	//control racing game etc
	this->ui.statusBar->setToolTip("Continuous control running!");
	
	this->cam->isContinuous = true;
	this->ui.ContinuousBtn->setDisabled(true);
	this->ui.DiscreteBtn->setDisabled(true);
	this->ui.label_detection->setVisible(true);
	this->cam->isExist = false;
	this->cam->start();
}
void CamShake::startDisCam()
{
	//control ppt etc
	this->ui.statusBar->setToolTip("Discrete control running!");
	
	this->cam->isContinuous = false;
	this->ui.ContinuousBtn->setDisabled(true);
	this->ui.DiscreteBtn->setDisabled(true);
	this->ui.label_detection->setVisible(true);
	this->cam->isExist = false;
	this->cam->start();
}
void CamShake::stopCam()
{
	if(this->cam->isExist)
		return;
	this->ui.ContinuousBtn->setDisabled(false);
	this->ui.DiscreteBtn->setDisabled(false);
	this->cam->isExist = true;
	this->ui.statusBar->setToolTip("This head-control widget is used for triggering key event.");



	//this->cam->quit();
}
void CamShake::closeEvent(QCloseEvent* evn)
{
	this->cam->isExist = true;
	while(this->cam->isRunning());
}

