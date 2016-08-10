#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

#define IMAGE_SIZE_SCALE 5


#define HsvType int
#define HSV   0
#define HSV_H 1
#define HSV_S 2
#define HSV_V 3

#define BGR   4
#define BGR_B 5
#define BGR_G 6
#define BGR_R 7

void getPosition(const Point2f p1,  const Point2f  p2, Point2f &goal);
void eraseGround(Mat &src);
Mat colorConversion(Mat img, HsvType imgtype);
void lowExposureGrid(const Mat src,Mat &result,Point2f &goal,
                     float &minD,bool &find_object,Mat &mask);
void lowExposureWAWA(const Mat src,Mat &result,Point2f &goal,
                     float &minD,bool &find_object,bool &WAWA);





int main()
{

    Mat src;
/********************************Camera tester*********************************/
//    VideoCapture capture(0);
//    if(capture.isOpened())  cout<<"Oops"<<endl;
//    while(1){
//        capture>>src;
/******************************************************************************/
/********************************Video tester**********************************/
//    VideoCapture capture("/home/sd/document/videocapture/3.avi");
//    if(capture.isOpened())  cout<<"Oops"<<endl;
//    while(1){
//        capture>>src;
/********************************Img tester************************************/
//    src=imread("/home/sd/document/graph/8_7/REGION4/g20160807_021252.112.jpg");
//    src=imread("/home/sd/document/graph/8_7/REGION4/g20160807_021245.088.jpg");
//    src=imread("/home/sd/document/graph/8_7/REGION4/g20160807_021258.515.jpg");
    src=imread("/home/sd/document/graph/8_7/GRID/SE3/g20160807_021921.218.jpg");
    src=imread("/home/sd/document/graph/8_7/GRID/SE4/g20160807_021928.246.jpg");
    src=imread("/home/sd/document/graph/8_7/GRID/SE3/g20160807_021921.218.jpg");
/******************************************************************************/
    resize(src,src,Size(src.cols/IMAGE_SIZE_SCALE,src.rows/IMAGE_SIZE_SCALE));




/******************************************************************************/
/*erase Ground*/
//      eraseGround(src);

/******************************************************************************/
/*low exposure mode*/
    Mat dst,mask;
    Point2f goal;
    float minD;
    bool find_object,WAWA;
/******************************************************************************/
    /*Grid*/
    lowExposureGrid(src,dst,goal,minD,find_object,mask);
/******************************************************************************/
    /*WAWA*/
//        lowExposureWAWA(src,dst,goal,minD,find_object,WAWA);
//    if(find_object){
//        if(WAWA)    cout<<"octopus"<<endl;
//        else        cout<<"hippo"<<endl;
//    }
//    else {
//        if(WAWA)    cout<<"need little more closer"<<endl;
//        else        cout<<"missing WAWA"<<endl;

//    }
/******************************************************************************/




/******************************************************************************/
//        waitKey(100);
//    }
/******************************************************************************/
    waitKey(0);
    return 0;
}

void getPosition(const Point2f p1, const Point2f p2, Point2f &goal)
{
    goal.x=p2.x-p1.x;
    goal.y=p2.y-p1.y;
    cout<<goal<<endl;
}
Mat colorConversion(Mat img, HsvType imgtype)
{
    GaussianBlur(img, img, Size(5,5),0,0);
    if(imgtype==HSV||imgtype==HSV_H||imgtype==HSV_S||imgtype==HSV_V){
        Mat img_hsv, img_h, img_s, img_v;
        cvtColor(img, img_hsv, CV_BGR2HSV);
        vector<Mat> hsv_channels;
        split(img_hsv, hsv_channels);
        img_h = hsv_channels[0];
        img_s = hsv_channels[1];
        img_v = hsv_channels[2];

        /*display*/
//        imshow("h",img_h);
//        imshow("s",img_s);
//        imshow("v",img_v);

        switch (imgtype){
        case 0:
            return img_hsv;
        case 1:
            return img_h;
        case 2:
            return img_s;
        case 3:
            return img_v;
        }
    }

    if(imgtype==BGR||imgtype==BGR_B||imgtype==BGR_G||imgtype==BGR_R){
        Mat b_img, g_img, r_img;
        vector<Mat> bgr_channels;
        split(img,bgr_channels);
        b_img=bgr_channels[0];
        g_img=bgr_channels[1];
        r_img=bgr_channels[2];

        /*display*/
//        imshow("b",b_img);
//        imshow("g",g_img);
//        imshow("r",r_img);

        switch(imgtype){
        case 4:
            return img;
        case 5:
            return b_img;imshow("r",r_img);
        case 6:
            return g_img;
        case 7:

            return r_img;
        }

    }
    return img;
}


void eraseGround(Mat &src)
{
    Mat img_h, img_threshold,img_canny;
    img_h=colorConversion(src, BGR_R);
    imshow("1_img_h",img_h);
    threshold(img_h,img_threshold,60,255,1);
    imshow("2_img_threshold",img_threshold);
    Mat element = getStructuringElement(MORPH_RECT,Size(3,3));
    morphologyEx(img_threshold,img_threshold,MORPH_ERODE,element);
    imshow("3_img_erode",img_threshold);
    Canny(img_threshold,img_canny,30,90);
    img_canny.copyTo(src);
}

void lowExposureGrid(const Mat src,Mat &result,Point2f &goal,
                float &minD,bool &find_object,Mat &mask)
{
    /*initialize*/
    find_object=false;
    imshow("src",src);
    minD=22222;
    goal=Point(0,0);

    Mat temp;
    src.copyTo(temp);
    medianBlur(temp,temp,5);
    Mat element = getStructuringElement(0, Size(15, 15));
    morphologyEx(temp,temp, MORPH_DILATE,  element);
    Mat imgBlue=colorConversion(temp,BGR_B);
    Mat imgRed=colorConversion(temp,BGR_R);
    /*get channel_Red & channel_Blue*/





}


void lowExposureWAWA(const Mat src,Mat &result,Point2f &goal,
                     float &minD,bool &find_object,bool &WAWA)
{
    /*initialize the flag*/
    /*WAWA:false=hippo;*/
    find_object=false;
    WAWA=false;
    result=colorConversion(src,HSV_V);

    /*smooth using medianBlur*/
    medianBlur(result,result,5);

    /*exp change*/

    /*binary*/
    threshold(result,result,50,255,THRESH_BINARY);
    imshow("binary",result);

    /*morphology closing*/
    Mat element = getStructuringElement(MORPH_RECT,Size(15,15));
    morphologyEx(result,result,MORPH_CLOSE,element);
    imshow("CLOSEING",result);


    /*retrieve contours_external*/
    vector<vector<Point> >contours;
    vector<Vec4i> hierarchy;
    findContours(result, contours, hierarchy,CV_RETR_TREE,CHAIN_APPROX_SIMPLE);
    if(contours.size()==0)  return;
    cout<<"size_external"<<contours.size()<<endl;

    /*display source img with every contours*/
    drawContours(src,contours,-1,Scalar(200),3);
    imshow("src",src);
    /*return if there is no WAWA being targeted*/
    Vector<float> area;
    int idx;
    for(int i=0;i<contours.size();i++)
    {
        area.push_back(contourArea(contours[i]));
        if(area[i]==*max_element(area.begin(),area.end()))
            idx=i;
    }
    float Parea=area[idx]/(src.cols*src.rows);
    cout<<"Parea:"<<Parea<<endl;

    /*retrieve moments and output*/
    Moments mom=moments(contours[idx], false);
    Point2f target=Point(mom.m10/mom.m00,mom.m01/mom.m00);
    Point2f center=Point(src.cols/2,src.rows/2);

    if(Parea<0.1)
    {
        getPosition(center,target,goal);
        WAWA=true;
        return;
    }

    /*set ROI with filled contours*/
    int counter=0;
    for(int i=0;i<contours.size();i++){
        if(hierarchy[i][3]==idx)    counter++;
    }
    drawContours(result,contours,-1,Scalar::all(255),2);
    cout<<"contoooooours:"<<counter<<endl;

    /*tell what the WAWA is*/
     find_object=true;
     if(counter>0|contours.size()>1)
     {
         WAWA=true;
         return;
     }
}

