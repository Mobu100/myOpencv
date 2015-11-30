
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <numeric>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "General.hpp"
#include "Reconstructor.hpp"
#include "Cameras.hpp"
#include "Scene3DRenderer.hpp"
#include "Glut.hpp"
#include "arcball.hpp"
#ifndef _CRT_SECURE_NO_WARNINGS
# define _CRT_SECURE_NO_WARNINGS
#endif

using namespace std;
using namespace cv;
using namespace nl_uu_science_gmt;
const string camera = "config.xml";
const string datapath0 = "/Users/u7/Library/Developer/Xcode/DerivedData/";
const string datapath1 = datapath0+"cam1/";
const string datapath2 = datapath0+"cam2/";
const string datapath3 = datapath0+"cam3/";
const string datapath4 = datapath0+"cam4/";
void calMode(vector<int>&pixel);
void calMean (vector<vector<int>>&pixels,int&j);
void calModeAll(vector<vector<int>>&pixels);
void calMeanAll (vector<vector<int>>&pixels,int &j);
int main(int argc, char** argv)
{
    vector<Camera*> cams;
    //initialize 4 cameras
    Camera cam1(datapath1,camera,1);
    Camera cam2(datapath2,camera,2);
    Camera cam3(datapath3,camera,3);
    Camera cam4(datapath4,camera,4);
   //cam1.detExtrinsics(datapath1, General::CheckerboadVideo, General::IntrinsicsFile, General::ConfigFile,1);//cam 1?
   //cam2.detExtrinsics(datapath2, General::CheckerboadVideo, General::IntrinsicsFile, General::ConfigFile,2);//cam 2?
  //cam3.detExtrinsics(datapath3, General::CheckerboadVideo, General::IntrinsicsFile, General::ConfigFile,3);//cam 3--反
    //cam4.detExtrinsics(datapath4, General::CheckerboadVideo, General::IntrinsicsFile, General::ConfigFile,4);//cam 4??
   //cam1.initialize();
   //cam2.initialize();
    //cam3.initialize();
    //cam4.initialize();
//    cams.push_back(&cam1);
//    cams.push_back(&cam2);
//    cams.push_back(&cam3);
//    cams.push_back(&cam4);
//    //intialize the reconstructor and Scene3D.
//    Reconstructor reconstructor(cams);
//    Scene3DRenderer renderScene (reconstructor,cams);
//    bool isrendered=renderScene.processFrame();
//    cout<<isrendered<<endl;
//    renderScene.setCamera(1);
//    Glut newGlut(renderScene);
//    newGlut.initializeLinux("windows",argc, argv);
//    
    
    return EXIT_SUCCESS;
}
//Generate background png
void computingBackgroundImage(string&dp,Mat&backgroundImage)
{
    Mat frame,gray,output;
    vector<vector<int>> pixels;
    vector<int> pixel;
    int jjj;
    Mat ffff;
   //A1 computing the mean of  very pixels of all the frame
    VideoCapture cap(dp);
    assert(cap.isOpened());
    for (int i=0; i<gray.rows; i++) {
        for(int j=0;j<gray.cols;j++){
         for(;;)
        {
                cap>>frame;
                cvtColor(frame, gray, CV_RGB2GRAY);
                pixel.push_back(gray.at<uchar>(i,j));
                if ( waitKey (0) == 27 ) break;
        }
            pixels.push_back(pixel);
            calMeanAll(pixels,jjj);
            ffff.at<int>(i,j) = jjj;
      }
    }
    //A2 computing the mode of very pixels of all the frame
}
void calMean(vector<int>pixel,int&mean){
    double sum = std::accumulate(pixel.begin(), pixel.end(), 0.0);
    mean = (int)(sum / pixel.size());
}
void calMeanAll (vector<vector<int>>&pixels,int &j){
    for (int i=0; i<pixels.size(); i++) {
        calMean(pixels[i],j);
    }
}
void calModeAll(vector<vector<int>>&pixels){
    for (int i=0; i<pixels.size(); i++) {
        calMode(pixels[i]);
    }
}
void calMode(vector<int>&pixel){
    int number = pixel[0];
    int mode = number;
    int count = 1;
    int countMode = 1;
    
    for (int i=1; i<pixel.size(); i++)
    {
        if (pixel[i] == number)
        { // count occurrences of the current number
            countMode++;
        }
        else
        { // now this is a different number
            if (count > countMode)
            {
                countMode = count; // mode is the biggest ocurrences
                mode = number;
            }
            count = 1; // reset count for the new number
            number = pixel[i];
        }
    }

}