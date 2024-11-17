#include <iostream>

class Vector {
private:
    double x; // 向量的x分量
    double y; // 向量的y分量
 
public:
    // 默认构造函数，初始化向量分量为0
    Vector() : x(0.0), y(0.0) {}
 
    // 带参数的构造函数，可以初始化向量分量
    Vector(double x_, double y_) : x(x_), y(y_) {}
 
    // 获取向量的x分量
    double getX() const {
        return x;
    }
 
    // 获取向量的y分量
    double getY() const {
        return y;
    }
 
    // 设置向量的x分量
    void setX(double x_) {
        x = x_;
    }
 
    // 设置向量的y分量
    void setY(double y_) {
        y = y_;
    }
 
    // 输出向量的信息
    void print() const {
        std::cout << "Vector(" << x << ", " << y << ")" << std::endl;
    }
};
 
int main() {
    // 创建并初始化一个向量
    Vector v(3.0, 4.0);
 
    // 输出向量的分量
    v.print();
 
    // 设置向量的x分量
    v.setX(5.0);
 
    // 输出修改后的向量信息
    v.print();
 
    return 0;
}

