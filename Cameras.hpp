//
//  Cameras.hpp
//  myOpencv
//
//  Created by U7 on 11/24/15.
//  Copyright © 2015 U7. All rights reserved.
//

#ifndef Cameras_hpp
#define Cameras_hpp

#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <vector>
using namespace cv;
using namespace std;
namespace nl_uu_science_gmt
{
    
#define MAIN_WINDOW "Checkerboard Marking"
    
    class Camera
    {
        static vector<Point>* m_BoardCorners;  // marked checkerboard corners
        static vector<Point>four_external_corners;
        bool m_initialized;                             // Is this camera successfully initialized
        
        const string m_data_path;                  // Path to data directory
        const string m_cam_props_file;             // Camera properties filename
        const int m_id;                                 // Camera ID
        
        vector<Mat> m_bg_hsv_channels;               // Background HSV channel images
        Mat m_foreground_image;                      // This camera's foreground image (binary)
        
        VideoCapture m_video;                        // Video reader
        
        Size m_plane_size;                           // Camera's FoV size
        long m_frame_amount;                             // Amount of frames in this camera's video
        
        Mat m_camera_matrix;                         // Camera matrix (3x3)
        Mat m_distortion_coeffs;                     // Distortion vector (5x1)
        Mat m_rotation_values;                       // Rotation vector (3x1)
        Mat m_translation_values;                    // Translation vector (3x1)
        
        float m_fx, m_fy, m_cx, m_cy;                   // Focal lenghth (fx, fy), camera center (cx, cy)
        
        Mat m_rt;                                    // R matrix
        Mat m_inverse_rt;                            // R's inverse matrix
        
        Point3f m_camera_location;                   // Camera location in the 3D space
        vector<Point3f> m_camera_plane;         // Camera plane of view
        vector<Point3f> m_camera_floor;         // Projection of the camera itself onto the ground floor view
        
        Mat m_frame;                                 // Current video frame (image)
        
        static void onMouse(int, int, int, int, void*);
        void initCamLoc();
        inline void camPtInWorld();//inline 函数没有定义？？
                Point3f ptToW3D(const Point &);
        Point3f cam3DtoW3D(const Point3f &);
        
    public:
        Camera(const string &, const string &, int);//构造函数
        virtual ~Camera();//虚函数：用于多态继承！！
        
        bool initialize();
        
        Mat& advanceVideoFrame();
        Mat& getVideoFrame(int);
        void setVideoFrame(int);
        
        static bool detExtrinsics(const string &, const string &, const string &, const string &);
        
        static Point projectOnView(const Point3f &, const Mat &, const Mat &, const Mat &, const Mat &);
        static void calPoints(Mat&canvas,Point a,Point b,Point c,vector<Point>&points);

        Point projectOnView(const Point3f &);
        
        const string& getCamPropertiesFile() const
        {
            return m_cam_props_file;
        }
        
        const string& getDataPath() const
        {
            return m_data_path;
        }
        
        const int getId() const
        {
            return m_id;
        }
        
        const VideoCapture& getVideo() const
        {
            return m_video;
        }
        
        void setVideo(const VideoCapture& video)
        {
            m_video = video;
        }
        
        long getFramesAmount() const
        {
            return m_frame_amount;
        }
        
        const vector<Mat>& getBgHsvChannels() const
        {
            return m_bg_hsv_channels;
        }
        
        bool isInitialized() const
        {
            return m_initialized;
        }
        
        const Size& getSize() const
        {
            return m_plane_size;
        }
        
        const Mat& getForegroundImage() const
        {
            return m_foreground_image;
        }
        
        void setForegroundImage(const Mat& foregroundImage)
        {
            m_foreground_image = foregroundImage;
        }
        
        const Mat& getFrame() const
        {
            return m_frame;
        }
        
        const vector<Point3f>& getCameraFloor() const
        {
            return m_camera_floor;
        }
        
        const Point3f& getCameraLocation() const
        {
            return m_camera_location;
        }
        
        const vector<Point3f>& getCameraPlane() const
        {
            return m_camera_plane;
        }
    };
    
} /* namespace nl_uu_science_gmt */

#endif /* CAMERA_H_ */
