#ifndef CAMERA_H_
#define CAMERA_H_
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <qthread.h>
#include <stdio.h> 
#include <qsplitter.h>
#include <Windows.h>
#include <hash_map>
using namespace std;

#define FILE_NUM 8

class CamShake;

struct PressedKey
{
	int len;		//按键长度
	int value[5];	//按键的值
};

struct Cascade
{
	string cname[FILE_NUM];
	int csize;
};

class Camera:public QThread
{
	 Q_OBJECT
public:
	CvMemStorage** storage;
	CvHaarClassifierCascade** cascade;

	Cascade cascade_name;
	int GetKey;
	PressedKey KeydownList;
	CvPoint prev;
	int threshold;
	int status;
	CamShake* window;
	bool isExist;
	bool isContinuous;

	//bind key event
	PressedKey m_up;
	PressedKey m_down;
	PressedKey m_left;
	PressedKey m_right;
	int rect;

	//key map
	std::hash_map<std::string, int> key_map;

	Camera(QObject *parent = NULL):threshold(12), status(0)
	{
		rect = 0;
		prev.x = 0;
		prev.y = 0;
		KeydownList.len = 1;
		KeydownList.value[0] = -1;
		storage = new CvMemStorage*[FILE_NUM];
		cascade = new CvHaarClassifierCascade*[FILE_NUM];
		cascade_name.cname[0] = "haarcascade_frontalface_alt.xml";
		cascade_name.csize = 1;
		isExist = true;
		//init default key
		m_up.len = 1;
		m_up.value[0] = VK_UP;
		m_down.len = 1;
		m_down.value[0] = VK_DOWN;
		m_right.len = 1;
		m_right.value[0] = VK_RIGHT;
		m_left.len = 1;
		m_left.value[0] = VK_LEFT;
		//set key hash
		key_map["Left"] = VK_LEFT;
		key_map["Right"] = VK_RIGHT;
		key_map["Up"] = VK_UP;
		key_map["Down"] = VK_DOWN;
		char str_tmp[5];
		for(int i = 0; i < 25; i++)
		{
			str_tmp[0] = 'a'+i;
			str_tmp[1] = '\0';
			key_map[str_tmp] = 65+i;
			str_tmp[0] = 'A'+i;
			str_tmp[1] = '\0';
			key_map[str_tmp] = 65+i;
		}
		for(int i = 0 ; i < 10; i++)
		{
			sprintf(str_tmp,"%d",i);
			key_map[str_tmp] = 48 + i;
		}
		key_map["Ctrl"] = VK_CONTROL;
		//install event
		this->installEventFilter(this);
		
	}

	void con_detect_and_draw(IplImage* img);
	void dis_detect_and_draw(IplImage* img);
	void put_text_onscreen(IplImage* img, const char* text,int x, int y);
	void set_key_bind(string* str_arr);
	void key_press(PressedKey key, int bScan, int eventType, int dwExtraInfo);
	void allkey_up();

protected:
	void run();
};
#endif