//
//  arcball.hpp
//  myOpencv
//
//  Created by U7 on 11/24/15.
//  Copyright © 2015 U7. All rights reserved.
//

#ifndef arcball_hpp
#define arcball_hpp
#include <stdio.h>
#include <cmath>

class vec  // simple 3D vector class
{
public:
    float x, y, z;
    
    vec() :
    x(0), y(0), z(0)
    {
    }
    vec(float xx)
    {
        x = xx;
        y = xx;
        z = xx;
    }
    vec(float xx, float yy, float zz)
    {
        x = xx;
        y = yy;
        z = zz;
    }
    
    inline vec operator +=(vec t)  // self-addition
    {
        *this = *this + t;
        return *this;
    }
    
    inline vec operator +(vec t)  // addition
    {
        return vec(x + t.x, y + t.y, z + t.z);
    }
    inline vec operator -(vec t)  // subtraction
    {
        return vec(x - t.x, y - t.y, z - t.z);
    }
    inline vec operator *(float t)  // dot product
    {
        return vec(x * t, y * t, z * t);
    }
    inline float operator *(vec t)  // scalar product
    {
        return x * t.x + y * t.y + z * t.z;
    }
    inline vec operator ^(vec t)  // cross product
    {
        return vec(y * t.z - z * t.y, t.x * z - x * t.z, x * t.y - y * t.x);
    }
    inline float length()  // pythagorean length
    {
        return sqrt(x * x + y * y + z * z);
    }
    inline vec unit()  // normalized to a length of 1
    {
        float l = length();
        if (l == 0.0) return vec(0.0, 0.0, 0.0);
        return vec(x / l, y / l, z / l);
    }
    inline bool zero()  // returns true if a zero vector
    {
        return x == 0 && y == 0 && z == 0;
    }
    inline bool equals(vec t)  // returns true if exactly equal
    {
        return x == t.x && y == t.y && z == t.z;
    }
};

extern void arcball_setzoom(float radius, vec eye, vec up);
extern void arcball_rotate();
extern void arcball_add_angle(int);
extern void arcball_add_distance(int);
extern void arcball_reset();
extern void arcball_start(int mx, int my);
extern void arcball_move(int mx, int my);

#endif
