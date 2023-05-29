//
// Created by USER on 30.05.2023.
//

#ifndef HOMEWORK2_HW2_H
#define HOMEWORK2_HW2_H
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <string>

using namespace std;


struct Img{
    int* srcImg;
    int width;
    int height;

    int x_c;
    int y_c;

    Img();
    Img(int w, int h);
    Img(const int* src, int w, int h);
    ~Img();
};

class ImageProcess {
private:
    Img* srcImg;
    Img* processedImg;
    Img* mask;

    void imgOut(Img*& Image);
    int** createMat(int n, int m);
    void deleteMat(int** A);
    void matOut(int** A, int height, int width);
    void putMask(int**& A, int y, int x, int height, int width, int** &Used);
    void checkMask(int** A, int y, int x, int height, int width, int** &Mirror);
    void copyImg(Img* &target, Img* source);
    void copyImg(Img* &target, const Img* source);

public:

    ImageProcess();

    ImageProcess(int w, int h);

    ImageProcess(const Img* img);

    ~ImageProcess();


    int updateMask(const Img& mask);

    int updateSrcImg();

    int dilatation(int srcImg = 1);
    int erosion(int srcImg = 1);

    int loadImgFromFile(const char* fileName, int format = 1);
    int saveImgToFile(const char* fileName, int format = 1);


    std::list<std::list<std::pair<int /*x*/, int /*y*/>>> getListContours();
};
#endif //HOMEWORK2_HW2_H
