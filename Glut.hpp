//
//  Glut.hpp
//  myOpencv
//
//  Created by U7 on 11/24/15.
//  Copyright © 2015 U7. All rights reserved.
//

#ifndef Glut_hpp
#define Glut_hpp

#include <stdio.h>

#import <OpenGL/OpenGL.h>
#import <OpenGL/gl.h>
#import <OpenGL/glu.h> /* Glut_hpp */
// i am not sure about the compatibility with this...
#define MOUSE_WHEEL_UP   3
#define MOUSE_WHEEL_DOWN 4

namespace nl_uu_science_gmt
{
    
    class Scene3DRenderer;
    
    class Glut
    {
        Scene3DRenderer &m_scene3d;
        
        static Glut* m_Glut;
        
        static void drawGrdGrid();
        static void drawCamCoord();
        static void drawVolume();
        static void drawArcball();
        static void drawVoxels();
        static void drawWCoord();
        static void drawInfo();
        
        static inline void perspectiveGL(
                                         GLdouble, GLdouble, GLdouble, GLdouble);
        
#ifdef _WIN32
        static void SetupPixelFormat(HDC hDC);
        static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
#endif
        
    public:
        Glut(
             Scene3DRenderer &);
        virtual ~Glut();
        
        void initializeLinux(
                             const char*, int, char**);
        static void mouse(
                          int, int, int, int);
#ifdef _WIN32
        int initializeWindows(const char*);
        void mainLoopWindows();
#endif
        
        static void keyboard(
                             unsigned char, int, int);
        static void motion(
                           int, int);
        static void reshape(
                            int, int);
        static void reset();
        static void idle();
        static void display();
        static void update(
                           int);
        static void quit();
        
        Scene3DRenderer& getScene3d() const
        {
            return m_scene3d;
        }
    };
    
} /* namespace nl_uu_science_gmt */

#endif /* GLUT_H_ */
