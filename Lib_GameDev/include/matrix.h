#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

#include <QDebug>

#include <lib_gamedev_global.h>

template<class T>
class LIB_GAMEDEVSHARED_EXPORT Matrix
{
public:
    Matrix(unsigned int width, unsigned int height, T const& t = T{}) : width(width), height(height), datas(width*height, t){}

    T& operator()(unsigned x, unsigned y){
        return datas[width*y+x];
    }

//    Matrix<T>& operator =(Matrix<T>& data){
//        width = data.getWidth();
//        height = data.getHeight();
//    }

    unsigned int getWidth(){
        return width;
    }
    unsigned int getHeight(){
        return height;
    }

private:
    unsigned int width;
    unsigned int height;

    std::vector<T> datas;
};

#endif // MATRIX_H
