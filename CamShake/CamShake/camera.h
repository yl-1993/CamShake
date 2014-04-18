#ifndef CAMERA_H_
#define CAMERA_H_
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <qthread.h>
#include <stdio.h> 

class CamShake;
class Camera:public QThread
{
	 Q_OBJECT
public:
	CvMemStorage* storage;
	CvHaarClassifierCascade* cascade;
	void detect_and_draw(IplImage* img);
	char* cascade_name;
	int GetKey;
	CvPoint prev;
	int threshold;
	int status;
	CamShake* window;
	bool isExist;
	Camera(QObject *parent = NULL):threshold(15), status(0)
	{
		prev.x = 0;
		prev.y = 0;
		cascade_name = "haarcascade_frontalface_alt.xml";
		isExist = false;
	}
protected:
	void run();
};
#endif