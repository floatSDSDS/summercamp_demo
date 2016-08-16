#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "queue"
#include <stdio.h>

using namespace std;
using namespace cv;

#define IMAGE_SIZE_SCALE 2


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
void Pixels(InputArray curve,int &a);
void Merge(vector<Mat> src,Mat &dst);
void eraseGroundPro(Mat src);


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
    VideoCapture capture("/home/sd/document/videocapture/5.avi");
    if(!capture.isOpened())  cout<<"Oops"<<endl;
    while(1){
        capture>>src;
/********************************Img tester************************************/
//    src=imread("/home/sd/document/graph/8_7/REGION4/g20160807_021252.112.jpg");
//    src=imread("/home/sd/document/graph/8_7/REGION4/g20160807_021245.088.jpg");
//    src=imread("/home/sd/document/graph/8_7/REGION4/g20160807_021258.515.jpg");
//    src=imread("/home/sd/document/graph/8_7/GRID/SE3/g20160807_021921.218.jpg");
//    src=imread("/home/sd/document/graph/8_7/GRID/SE4/g20160807_021928.246.jpg");
//    src=imread("/home/sd/document/graph/twofour/1749.jpg");
//    src=imread("/home/sd/document/graph/test1/6mm20160801_124316.025.jpg");

/******************************************************************************/
    resize(src,src,Size(src.cols/IMAGE_SIZE_SCALE,src.rows/IMAGE_SIZE_SCALE));


/******************************************************************************/
/*erase Ground*/
//      eraseGround(src);
/******************************************************************************/
/*low exposure mode*/
//    Mat dst,mask;
//    Point2f goal;
//    float minD;
//    bool find_object,WAWA;
/******************************************************************************/
    /*Grid*/
//    Mat img_Red=colorConversion(src,BGR_R);
//    lowExposureGrid(img_Red,dst,goal,minD,find_object,mask);
/******************************************************************************/
    /*WAWA*/
//    lowExposureWAWA(src,dst,goal,minD,find_object,WAWA);
//    if(find_object){
//        if(WAWA){

//            cout<<"octopus"<<endl;
//        }
//        else{
//            cout<<"hippo"<<endl;
//        }

//    }
//    else {
//        if(WAWA){
//            cout<<"need little more closer"<<endl;
//        }
//        else{
//            cout<<"missing WAWA"<<endl;
//        }

//    }
/******************************************************************************/
    /*merge*/
//    Mat src_temp;
//    vector<Mat> src;
//    Mat dst;
//    char s[50];
//    for(int i=164;i<653;i++){

//        src.clear();
//        for(int j=0;j<5
//            ;j++){
//            sprintf(s,"/home/sd/document/graph/gg8_14/%d.jpg",i+j);
//            src_temp=imread(s);
//            src.push_back(src_temp);
//        }

//        imshow("f",src_temp);
//        Merge(src,dst);
//        imshow("ff",dst);
//        waitKey(100);
//    }


/*******************************************************************************************************************************************************************************/
    /*Pixels*/
//    Mat img;
//    src.copyTo(img);
//    Mat img_SOpen;
//    Mat element = getStructuringElement(MORPH_ELLIPSE,Size(19,19));
//    morphologyEx(img,img,MORPH_OPEN,element);
//    img_SOpen=colorConversion(img, HSV_S);
//    GaussianBlur(img_SOpen, img_SOpen, Size(5,5),0,0);
//    imshow("HSV_S",img_SOpen);
//        /*first prepare a series of points send into the function*/
//        /*have troubles using type InuputArray as input so I do the demo here*/
//    Mat img_h,img_canny;
//    img_h=colorConversion(src, BGR_R);
//    imshow("BRG_G",img_h);
//    threshold(img_h,img_h,60,255,1);

//    element = getStructuringElement(MORPH_RECT,Size(3,3));
//    morphologyEx(img_h,img_h,MORPH_ERODE,element);
//    Canny(img_h,img_canny,30,90);

//    vector<vector<Point> > contours;
//    vector<vector<Point> > expand;
//    vector<Point> expandP;
//    vector<Point> approxCurve;
//    vector<Vec4i> hierarchy;
//    Point2f pointsIn[4]={Point2f(0,0)};


//        /*problems here, findContours changes the Mat src*/
//        /*seems like it draws contours automatically*/
//    findContours(img_h,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_NONE);

//        /*find and draw the minimum bounding rect*/
//    vector<RotatedRect> box;
//    Point2f rect_points[4],expand_points[4];
//    Mat mask=Mat(img.size(), img.depth(), Scalar(255,255,255));
//        /*set the scale and */
//    float scale=1.5;
//    int m=src.cols;
//    int n=src.rows;
//    cout<<"m"<<m<<"n"<<n<<endl;



//        /*rotatedrect::points is a method to retrieve the four points*/
//        /*expand the rect*/
//    vector<Mat> ROI;
//    int histSize = 16;
//    float range[] = { 0, 255 } ;
//    const float* histRange = { range };
//    vector<Mat> hist;
//    Mat temp;
//    for(int i=0;i<contours.size();i++){
//        box.push_back(minAreaRect(Mat(contours[i])));
//        cout<<"member_angle:"<<box[i].angle<<endl;
//        box[i].size.width*=scale;
//        box[i].size.height*=scale;
//        box[i].points( expand_points );
//        for(int j=0;j<4;j++){
//            expand_points[j].x = expand_points[j].x>0 ? expand_points[j].x: 1;
//            expand_points[j].y = expand_points[j].y>0 ? expand_points[j].y: 1;
//            expand_points[j].x = expand_points[j].x<m ? expand_points[j].x: m-1;
//            expand_points[j].y = expand_points[j].y<n ? expand_points[j].y: n-1;
//            expandP.push_back(expand_points[j]);
//        }
//        expand.push_back(expandP);
//        expandP.clear();
//        /*create a mask and calculate Hist*/
//        for(int j=0;j<expand.size();j++){
//            drawContours(mask,expand,i,Scalar(0),CV_FILLED);
//            imshow("maskkk",mask);
//            img_SOpen.copyTo(temp,~mask);
//            ROI.push_back(temp);
//            mask=Mat(img.size(), img.depth(), Scalar(255,255,255));
//            imshow("ROI",ROI[i]);
//            waitKey(0);
// //           calcHist(img_SOpen,1,0,mask,hist,1,histSize,&histRange);
//        }
/*******************************************************************************************************************************************************************************/
//        for( int j = 0; j < 4; j++ ){
//            line( src, rect_points[j], rect_points[(j+1)%4],Scalar(0,0,255), 1, 8 );
//            dx=rect_points[j].x-box[i].center.x;
//            dy=rect_points[j].y-box[i].center.y;
//            cout<<"dx: "<<dx<<"dy: "<<dy<<endl;
//            expand_points[j].x=rect_points[j].x+scale*dx;
//            expand_points[j].y=rect_points[j].y+scale*dy;
//            cout<<"re_point:"<<rect_points[j]<<endl;

//            expand_points[j].x = expand_points[j].x>0 ? expand_points[j].x: 1;
//            expand_points[j].y = expand_points[j].y>0 ? expand_points[j].y: 1;
//            expand_points[j].x = expand_points[j].x<m ? expand_points[j].x: n-1;
//            expand_points[j].y = expand_points[j].y<n ? expand_points[j].y: m-1;
//            cout<<"point:"<<expand_points[j]<<endl;
//            circle(src,Point(expand_points[j].x,expand_points[j].y),8,Scalar(0,255,0),2);
//        }

//    }


//    int min_index;
//    float min_x=INT_MAX;
//    for(int i=0;i<contours.size();i++){
//        approxPolyDP(contours[i], approxCurve, double(contours[i].size()) * 0.05, true);
//        drawContours(src,contours,i,Scalar(0,255,0),2,8);
//        if(approxCurve.size()>2){
//            for(int j=0;j<approxCurve.size();j++){
//                circle(src,Point(approxCurve[j].x,approxCurve[j].y),8,Scalar(0,0,255));
//                /*find out the up left corner*/
//                if(sqrt(approxCurve[j].x*approxCurve[j].x+approxCurve[j].y*approxCurve[j].y) < min_x){
//                    min_x = sqrt(approxCurve[j].x*approxCurve[j].x+approxCurve[j].y*approxCurve[j].y);
//                    min_index = j;
//                    cout<<"min_x: "<<min_x<<"min_index: "<<min_index<<endl;
//                }
//            }

//        }
//    }
/*******************************************************************************/

    //imshow("miaomiaomioa",src);

/*******************************************************************************/
    /*findrect pro*/
    imshow("src",src);
    eraseGroundPro(src);




/******************************************************************************/
        waitKey(250);
    }
/******************************************************************************/
    waitKey(0);
    return 0;
}



void Pixels(InputArray curve,int &a){
    if(curve.empty()){
        return;
    }
//    /*recieve boxes and expand them as twice as large*/
//    vector<Rect> box;
//    for(unsigned int i=0;i<curve.size();i++){
//        box.push_back(boundingRect(Mat(curve[i])));
//    }
    return;
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
        imshow("h",img_h);
        imshow("s",img_s);
        imshow("v",img_v);

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
        imshow("b",b_img);
        imshow("g",g_img);
        imshow("r",r_img);

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
/*closing*/
    Mat element = getStructuringElement(MORPH_RECT,Size(35,35));
    morphologyEx(img_h,img_threshold,MORPH_DILATE,element);
    imshow("2_img_dilate",img_threshold);
    /*blur*/
    medianBlur(img_threshold,img_threshold,5);
    element = getStructuringElement(MORPH_RECT,Size(15,15));
    morphologyEx(img_threshold,img_threshold,MORPH_ERODE,element);
    imshow("3_img_close",img_threshold);
/*binary*/
    threshold(img_threshold,img_threshold,60,255,1);
    imshow("4_img_threshold",img_threshold);
    Canny(img_threshold,img_canny,30,90);
    img_canny.copyTo(src);
}

void lowExposureGrid(const Mat src,Mat &result,Point2f &goal,
                float &minD,bool &find_object,Mat &mask)
{
    /*assume src is already a single channel Mat*/
    /*initialize*/
    find_object=false;
    imshow("1src",src);
    minD=22222;
    goal=Point(0,0);
    Mat temp;
    src.copyTo(temp);
    medianBlur(temp,temp,5);
    Mat element = getStructuringElement(2, Size(10,10));
    morphologyEx(temp,temp, MORPH_DILATE,  element);
    imshow("dilate",temp);
    threshold(temp,temp,200,255,1);
    imshow("2binary",temp);
    element = getStructuringElement(2, Size(10,10));
    morphologyEx(temp,temp, MORPH_CLOSE,  element);
    imshow("closing",temp);

//    /*morphology erode*/
//    imshow("3erode",temp);
//    temp=~temp;
//    int top = 0.005*src.rows; int bottom = 0.005*src.rows;
//    int left = 0.005*src.cols; int right = 0.005*src.cols;
//    copyMakeBorder( temp , temp , top, bottom, left, right, BORDER_CONSTANT, Scalar(0));
// /*add border*/
//    result=Mat(src.size(), src.depth(), Scalar(255,255,255));
//    imshow("border",temp);


/*extra lines*/

    // draw the line
//    imshow("4imgLine", result);
/*find contours*/
//    vector<vector<Point> > contours;
//    vector<Vec4i> hierarchy;
//    findContours(temp,contours,hierarchy,RETR_CCOMP,CHAIN_APPROX_SIMPLE);
//    if(contours.size()<1)  return;
//    drawContours(result,contours,1,Scalar(0),2,8);
//    imshow("result",result);
//    return;
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

    /*morphology closing*/
    Mat element = getStructuringElement(MORPH_RECT,Size(15,15));
    morphologyEx(result,result,MORPH_CLOSE,element);
    imshow("CLOSEING",result);

    /*binary*/
    threshold(result,result,25,255,THRESH_BINARY);
    imshow("binary",result);




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



void Merge(vector<Mat> src,Mat &dst)
{
    dst=Mat(src[0].size(),src[0].type(),Scalar(0,0,0));
    for(int i=0;i<src.size();i++){
        colorConversion(src[i], HSV_V);
        threshold(src[i],src[i],50,255,CV_THRESH_BINARY);
        medianBlur(dst,dst,3);
        dst+=src[i]*(1-0.1*i);
    }
    colorConversion(dst,HSV_V);
    threshold(dst,dst,40,255,CV_THRESH_BINARY);
    Mat element = getStructuringElement(MORPH_ELLIPSE,Size(3,3));
    morphologyEx(dst,dst,MORPH_CLOSE,element);
    return;
}


void eraseGroundPro(Mat src){
    Mat element = getStructuringElement(MORPH_RECT,Size(5,5));
    morphologyEx(src,src, MORPH_ERODE, element );
    colorConversion(src, BGR);
    colorConversion(src,HSV);
  //  waitKey(0);
    return;

}
