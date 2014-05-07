#include "camshake.h"

CamShake::CamShake(QWidget *parent)
	: QMainWindow(parent)
{
	this->setAttribute(Qt::WA_LayoutUsesWidgetRect, true);
	ui.setupUi(this);
	//this->setWindowFlags(Qt::FramelessWindowHint);//无框
	this->ui.Face->setChecked(true);
	//this->ui.groupBox->setStyleSheet("*{background-image: url(:/1.jpg);}");
	//信号与槽
	connect(this->ui.ContinuousBtn, SIGNAL(clicked()), this, SLOT(startConCam()));
	connect(this->ui.DiscreteBtn, SIGNAL(clicked()), this, SLOT(startDisCam()));
	connect(this->ui.StopBtn, SIGNAL(clicked()), this, SLOT(stopCam()));
	//this->ui.plainTextEdit->setFocusPolicy(Qt::StrongFocus);
}

void CamShake::keyPressEvent(QKeyEvent *e)
{
	qWarning("Taste::keyPressEvent(QKeyEvent *e)");
	//e->accept();  // Annehmen des KeyEvents
	qDebug("keyPressEvent(QKeyEvent *e) here");
	/*
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
	*/
}

CamShake::~CamShake()
{

}
void CamShake::startConCam()
{
	//control racing game etc
	this->ui.statusBar->setToolTip("Continuous control running!");
	setKeyBind();
	this->cam->isContinuous = true;
	setMenuDisabled();
	this->cam->start();
}
void CamShake::startDisCam()
{
	//control ppt etc
	this->ui.statusBar->setToolTip("Discrete control running!");
	setKeyBind();
	this->cam->isContinuous = false;
	setMenuDisabled();
	this->cam->start();
}
void CamShake::stopCam()
{
	if(this->cam->isExist)
		return;
	setMenuAble();
	this->ui.statusBar->setToolTip("This head-control widget is used for triggering key event.");

	//this->cam->quit();
}

void CamShake::setMenuDisabled()
{
	this->ui.ContinuousBtn->setDisabled(true);
	this->ui.DiscreteBtn->setDisabled(true);
	this->ui.label_detection->setVisible(true);
	this->ui.plainTextEdit->setDisabled(true);
	this->ui.plainTextEdit_2->setDisabled(true);
	this->ui.plainTextEdit_3->setDisabled(true);
	this->ui.plainTextEdit_7->setDisabled(true);
	this->ui.Face->setDisabled(true);
	this->ui.Fist->setDisabled(true);
	this->cam->isExist = false;
}

void CamShake::setMenuAble()
{
	this->ui.ContinuousBtn->setDisabled(false);
	this->ui.DiscreteBtn->setDisabled(false);
	this->ui.plainTextEdit->setDisabled(false);
	this->ui.plainTextEdit_2->setDisabled(false);
	this->ui.plainTextEdit_3->setDisabled(false);
	this->ui.plainTextEdit_7->setDisabled(false);
	this->ui.Face->setDisabled(false);
	this->ui.Fist->setDisabled(false);
	this->cam->isExist = true;	
}

string CamShake::q2s(const QString &s)  
{  
	return string((const char *)s.toLocal8Bit());  
}  

void CamShake::setKeyBind()
{
	//设置键盘绑定
	int str_size = 4;
	string *str_arr = new string[str_size];
	str_arr[0] = q2s(this->ui.plainTextEdit->m_str);  //left
	str_arr[1] = q2s(this->ui.plainTextEdit_2->m_str);//right
	str_arr[2] = q2s(this->ui.plainTextEdit_3->m_str);//up
	str_arr[3] = q2s(this->ui.plainTextEdit_7->m_str);//down
	this->cam->set_key_bind(str_arr);
	if(this->ui.Face->isChecked())
		this->cam->cascade_name = "haarcascade_frontalface_alt.xml";
	if(this->ui.Fist->isChecked())
		this->cam->cascade_name = "fist.dat";
}
void CamShake::closeEvent(QCloseEvent* evn)
{
	this->cam->isExist = true;
	while(this->cam->isRunning());
}

