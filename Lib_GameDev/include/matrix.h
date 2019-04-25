#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

#include <QDebug>

#include <lib_gamedev_global.h>

template<class T>
class LIB_GAMEDEVSHARED_EXPORT Matrix
{
public:
    Matrix(int width, int height, T const& t = T{}) : width(width), height(height), datas(width*height, t){}

    T& operator()(int x,int y){
        return datas[width*y+x];
    }

//    Matrix<T>& operator =(Matrix<T>& data){
//        width = data.getWidth();
//        height = data.getHeight();
//    }

    int getWidth(){
        return width;
    }
    int getHeight(){
        return height;
    }

private:
    int width;
    int height;

    std::vector<T> datas;
};

#endif // MATRIX_H
