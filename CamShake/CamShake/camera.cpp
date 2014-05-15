#include "camera.h"
#include "camshake.h"
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 
#include <vector>
#include <math.h> 
#include <float.h> 
#include <limits.h> 
#include <time.h> 
#include <ctype.h>
#include <fstream>
#include <Windows.h>
 
void Camera::run()
{
	for(int i = 0 ; i < cascade_name.csize; i++)
	{
		cascade[i] = (CvHaarClassifierCascade*)cvLoad( cascade_name.cname[i].c_str(), 0, 0, 0 );
		storage[i] = cvCreateMemStorage(0);
	}

	CvCapture* pCap = cvCaptureFromCAM(0);//这里-1也可以，不过我的电脑装的有CyberLink YouCam软件，

	if (pCap == NULL){
		return ;
	} 

    if( !cascade ) { 
        fprintf( stderr, "ERROR: Could not load classifier cascade\n" ); 
        return ; 
    } 
     
  
    // IplImage 是结构体类型，用来保存一帧图像的信息，也就是一帧
    // 图像的所有像素值构成的一个矩阵

    IplImage *frame, *frame_copy = 0;
     
     // 创建一个窗口，用“result”作为窗口的标识符
    //cvNamedWindow("Camera", 1 );

	 frame = cvQueryFrame(pCap);
	 while (pCap && !isExist)  {
		frame = cvQueryFrame(pCap);
			
		if(isContinuous)
			con_detect_and_draw(frame); 
		else
			dis_detect_and_draw(frame);
		GetKey = cvWaitKey(10);
		if(GetKey == 27){
			break;
		}
	 }
	 QPixmap map =  QPixmap("bk");
	 this->window->ui.label_detection->setPixmap(map);
	 cvReleaseCapture(&pCap);
     //cvDestroyWindow("Camera");
     return;
}
void Camera::dis_detect_and_draw(IplImage* img)
{
	//用于控制PPT
	double scale=1.2; 
    static CvScalar colors[] = { 
        {{0,0,255}},{{0,128,255}},{{0,255,255}},{{0,255,0}}, 
        {{255,128,0}},{{255,255,0}},{{255,0,0}},{{255,0,255}} 
    };//Just some pretty colors to draw with


    //Image Preparation 
    IplImage* gray = cvCreateImage(cvSize(img->width,img->height),8,1); 
    IplImage* small_img=cvCreateImage(cvSize(cvRound(img->width/scale),cvRound(img->height/scale)),8,1); 
    cvCvtColor(img,gray, CV_BGR2GRAY); 
    cvResize(gray, small_img, CV_INTER_LINEAR);

    cvEqualizeHist(small_img,small_img); //直方图均衡

    //Detect objects if any 

	CvSeq** objects = new CvSeq*[FILE_NUM];
	for(int i = 0; i < cascade_name.csize; ++i)
	{
		cvClearMemStorage(storage[i]); 
		objects[i] = cvHaarDetectObjects(small_img,cascade[i],storage[i],1.1,1,CV_HAAR_DO_CANNY_PRUNING,cvSize(150,150));
	}

    //Loop through found objects and draw boxes around them 
	for(int k = 0; k < cascade_name.csize; k++)
	{
		for( int i = 0; i < (objects[k]? objects[k]->total : 0); i++ ) 
		{ 
			CvRect* r = (CvRect*)cvGetSeqElem(objects[k], i); 
			CvPoint center; 
			int radius; 
			center.x = cvRound((r->x + r->width*0.5)*scale); 
			center.y = cvRound((r->y + r->height*0.5)*scale); 
			radius = cvRound((r->width + r->height)*0.25*scale); 
			cvCircle(img, center, radius, colors[i%8], 3, 8, 0);
			if(prev.x == 0 && prev.y == 0)//初始状态
			{   
				prev = center;
				break;
			}
			else
			{
				allkey_up();
				if(center.x - prev.x < -threshold)
				{
					if(center.y - prev.y > threshold)
					{
						key_press(m_right,0,0,0);
						key_press(m_down,0,0,0);
					}
					else if (center.y - prev.y < -threshold)
					{
						key_press(m_right,0,0,0);
						key_press(m_up,0,0,0);
					}
					else
					{
						key_press(m_right,0,0,0);
					}
				}
				else if(center.x - prev.x > threshold)
				{
					if(center.y - prev.y > threshold)
					{
						key_press(m_left,0,0,0);
						key_press(m_down,0,0,0);
					}
					else if (center.y - prev.y < -threshold)
					{
						key_press(m_left,0,0,0);
						key_press(m_up,0,0,0);
					}
					else
					{
						key_press(m_left,0,0,0);
					}
				}
				else
				{
					if(center.y - prev.y > threshold)
					{
						key_press(m_down,0,0,0);
					}
					else if (center.y - prev.y < -threshold)
					{
						key_press(m_up,0,0,0);
					}
				}
			}
			prev = center;
			break;
		}
	}
	

	cvConvertImage(img, img, CV_CVTIMG_SWAP_RB);
	int labelW = this->window->ui.label_detection->size().width();
	int labelH = this->window->ui.label_detection->size().height();
	QImage temImg((const unsigned char*)img->imageData, (img->width), (img->height), QImage::Format_RGB888);
	QImage newImg = temImg.scaled(labelW, labelH);
	this->window->ui.label_detection->setPixmap(QPixmap::fromImage(newImg));
	this->window->update();
    cvReleaseImage(&gray); 
    cvReleaseImage(&small_img); 
}

void Camera::con_detect_and_draw(IplImage* img)
{
	//用于控制赛车游戏等
	double scale=1.2; 
    static CvScalar colors[] = { 
        {{0,0,255}},{{0,128,255}},{{0,255,255}},{{0,255,0}}, 
        {{255,128,0}},{{255,255,0}},{{255,0,0}},{{255,0,255}} 
    };//Just some pretty colors to draw with


    //Image Preparation 
    IplImage* gray = cvCreateImage(cvSize(img->width,img->height),8,1); 
    IplImage* small_img=cvCreateImage(cvSize(cvRound(img->width/scale),cvRound(img->height/scale)),8,1); 
    cvCvtColor(img,gray, CV_BGR2GRAY); 
    cvResize(gray, small_img, CV_INTER_LINEAR);

    cvEqualizeHist(small_img,small_img); //直方图均衡

    //Detect objects if any 
	CvSeq** objects = new CvSeq*[FILE_NUM];
	for(int i = 0; i < cascade_name.csize; ++i)
	{
		cvClearMemStorage(storage[i]); 
		objects[i] = cvHaarDetectObjects(small_img,cascade[i],storage[i],1.1,1,CV_HAAR_DO_CANNY_PRUNING,cvSize(150,150));
	}

	int left_thr, right_thr, up_thr, down_thr;
	int h = img->height;
	int rectWidth = rect * h / 100;
	CvPoint p1, p2;
	p1.x = img->width / 2 - rectWidth / 2;
	p1.y = img->height / 2 - rectWidth / 2;
	p2.x = img->width / 2 + rectWidth / 2; 
	p2.y = img->height / 2 + rectWidth / 2;
	cvRectangle(img, p1, p2, colors[2]); 
	rectWidth = (h >> 1) - (rectWidth >> 1);
	//up
	p1.x = img->width / 2 - rectWidth / 2;
	p2.x = img->width / 2 + rectWidth /2;
	p1.y = 0;
	p2.y = rectWidth;
	up_thr = p2.y;
	cvRectangle(img, p1, p2, colors[3]);
	//down
	p1.y += h - rectWidth;
	p2.y += h - rectWidth;
	down_thr = p1.y;
	cvRectangle(img, p1, p2, colors[4]);
	int move = (h>>1) - (rectWidth>>1); 
	//left
	p1.y -= move;
	p2.y -= move;
	p1.x -= move;
	p2.x -= move;
	left_thr = p2.x;
	cvRectangle(img, p1, p2, colors[5]);
	//right
	move = move << 1;
	p1.x += move;
	p2.x += move;
	right_thr = p1.x;
	cvRectangle(img, p1, p2, colors[6]);


    //Loop through found objects and draw boxes around them 
	for(int k = 0; k < cascade_name.csize; k++)
	{
		for( int i = 0; i < (objects[k]? objects[k]->total : 0); i++ ) 
		{ 
			CvRect* r = (CvRect*)cvGetSeqElem(objects[k], i); 
			CvPoint center;
			int radius; 
			center.x = cvRound((r->x + r->width*0.5)*scale); 
			center.y = cvRound((r->y + r->height*0.5)*scale); 
			radius = cvRound((r->width + r->height)*0.25*scale); 
			cvCircle(img, center, radius, colors[i%8], 3, 8, 0);

			bool isVertical = true, isHorizontal = true;

			if(center.x > right_thr)
			{
				key_press(m_right,0,KEYEVENTF_KEYUP,0); 
				key_press(m_left,0,0,0);
			}
			else if(center.x < left_thr)
			{
				key_press(m_left,0,KEYEVENTF_KEYUP,0); 
				key_press(m_right,0,0,0);

			}
			else
			{
				isHorizontal = false;
			}
		
			if(center.y < up_thr)
			{
				key_press(m_down,0,KEYEVENTF_KEYUP,0); 
				key_press(m_up,0,0,0);		
			}
			else if(center.y > down_thr)
			{
				key_press(m_up,0,KEYEVENTF_KEYUP,0); 
				key_press(m_down,0,0,0);		
			}
			else
			{
				isVertical = false;
			}

			if(!isHorizontal&&!isVertical)
			{
				allkey_up();
			}
			break;
			/*
			if(prev.x == 0 && prev.y == 0)//初始状态
			{   
				prev = center;
				break;
			}
			else
			{
				if(KeydownList.value[0] != -1)
					key_press(KeydownList,0,0,0);
			
				if(center.x - prev.x < -(0.5*threshold))
				{
					if(center.y - prev.y > threshold)
					{
						allkey_up();
						key_press(m_right,0,0,0);
						key_press(m_down,0,0,0);
					}
					else if (center.y - prev.y < -threshold)
					{
						allkey_up();
						key_press(m_right,0,0,0);
						key_press(m_up,0,0,0);
					}
					else if (center.x - prev.x < -(threshold))
					{
						//弹起左键同时按下右键
						key_press(m_left,0,KEYEVENTF_KEYUP,0); //left
						key_press(m_right,0,0,0);
						KeydownList = m_right;
					
					}
					else
					{
						//弹起左键
						key_press(m_left,0,KEYEVENTF_KEYUP,0); //left
						KeydownList.len = 1;
						KeydownList.value[0] = -1;
					}
				}
				else if(center.x - prev.x > 0.5*threshold)
				{
					if(center.y - prev.y > threshold)
					{
						allkey_up();
						key_press(m_left,0,0,0);
						key_press(m_down,0,0,0);
					}
					else if (center.y - prev.y < -threshold)
					{
						allkey_up();
						key_press(m_left,0,0,0);
						key_press(m_up,0,0,0);
					}
					else if (center.x - prev.x > threshold)
					{
						//弹起右键同时按下左键
						key_press(m_right,0,KEYEVENTF_KEYUP,0); //right
						key_press(m_left,0,0,0);
						KeydownList = m_left;
						put_text_onscreen(img,"right",0,0);
					}
					else
					{
						key_press(m_right,0,KEYEVENTF_KEYUP,0); //right
						KeydownList.len = 1;
						KeydownList.value[0] = -1;
					}
				}
				else
				{
					if(center.y - prev.y > threshold)
					{
						key_press(m_down,0,0,0);
					}
					else if (center.y - prev.y < -threshold)
					{
						key_press(m_up,0,0,0);
					}
				}
			}
			prev = center;
			break;
			*/
		}
	}
	
	//cvShowImage( "Camera", img ); 
	cvConvertImage(img, img, CV_CVTIMG_SWAP_RB);
	int labelW = this->window->ui.label_detection->size().width();
	int labelH = this->window->ui.label_detection->size().height();
	QImage temImg((const unsigned char*)img->imageData, (img->width), (img->height), QImage::Format_RGB888);
	QImage newImg = temImg.scaled(labelW, labelH);
	this->window->ui.label_detection->setPixmap(QPixmap::fromImage(newImg));
	this->window->update();
    cvReleaseImage(&gray); 
    cvReleaseImage(&small_img);
}

void Camera::allkey_up()
{
	key_press(m_left,0,KEYEVENTF_KEYUP,0); //left
	key_press(m_up,0,KEYEVENTF_KEYUP,0); //up
	key_press(m_right,0,KEYEVENTF_KEYUP,0); //right
	key_press(m_down,0,KEYEVENTF_KEYUP,0); //down
}

void Camera::key_press(PressedKey key, int bScan, int eventType, int dwExtraInfo)
{
	int len = key.len;
	for(int i = 0 ; i < len; i++)
	{
		keybd_event(key.value[i],0,eventType,0);
	}
}

void split(std::string& s, std::string delim,std::vector< std::string >* res)  
{  
    size_t last = 0;  
    size_t index=s.find_first_of(delim,last);  
    while (index!=std::string::npos)  
    {  
        res->push_back(s.substr(last,index-last));  
        last=index+1;  
        index=s.find_first_of(delim,last);  
    }  
    if (index-last>0)  
    {  
        res->push_back(s.substr(last,index-last));  
    }  
} 

void Camera::set_key_bind(string* str_arr)
{
	int len = 1;
	//按+号分割组合键
	vector<string> fields;
	//LEFT
	split(str_arr[0],"+",&fields);
	len = fields.size();
	m_left.len = len;
	for(int i = 0 ; i < len; i++)
	{
		if(key_map[fields[i]])
		{
			m_left.value[i] = key_map[fields[i]];
		}
		else
		{
			m_left.len = 1;
			m_left.value[0] = VK_LEFT;
			break;
		}
	}
	fields.clear();
	//RIGHT
	split(str_arr[1],"+",&fields);
	len = (int)fields.size();
	m_right.len = len;
	for(int i = 0 ; i < len; i++)
	{
		if(key_map[fields[i]])
		{
			m_right.value[i] = key_map[fields[i]];
		}
		else
		{
			m_right.len = 1;
			m_right.value[0] = VK_RIGHT;
			break;
		}
	}
	fields.clear();
	//UP
	split(str_arr[2],"+",&fields);
	len = (int)fields.size();
	m_up.len = len;
	for(int i = 0 ; i < len; i++)
	{
		if(key_map[fields[i]])
		{
			m_up.value[i] = key_map[fields[i]];
		}
		else
		{
			m_up.len = 1;
			m_up.value[0] = VK_UP;
			break;
		}
	}
	fields.clear();
	//DOWN
	split(str_arr[3],"+",&fields);
	len = (int)fields.size();
	m_down.len = len;
	for(int i = 0 ; i < len; i++)
	{
		if(key_map[fields[i]])
		{
			m_down.value[i] = key_map[fields[i]];
		}
		else
		{
			m_down.len = 1;
			m_down.value[0] = VK_DOWN;
			break;
		}
	}
	fields.clear();
}

void Camera::put_text_onscreen(IplImage* img, const char* text, int x, int y)
{
	CvFont font;    
    double hScale=1;   
    double vScale=1;    
    int lineWidth=2; //线条      
    // 初始化字体   
    cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth);//初始化字体，准备写到图片上的   
    // cvPoint 为起笔的x，y坐标   
    cvPutText(img,text,cvPoint(x,y),&font,CV_RGB(255,0,0));
}