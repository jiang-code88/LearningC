#include<iostream>

// 复制构造函数的深复制-保证按值传递的复制对象中的成员变量时独立的存储空间。
class Tricycle
{
private:
    int *speed;
public:
    Tricycle(); // default constructor
    Tricycle( const Tricycle& ); // copy constructor
    ~Tricycle();
    int getSpeed() const { return *speed; }
    void setSpeed( int newSpeed ) { *speed = newSpeed; }
    void pedal();
    void brake();
};

// 构造函数-在堆中创建 speed 变量
Tricycle::Tricycle()
{
    speed = new int;
    *speed = 5; // 默认速度
}

// 复制构造函数-在堆中创建 speed 变量
// 按值将对象传入传出函数时将调用复制构造函数
Tricycle::Tricycle( const Tricycle& rhs )
{
    speed = new int;
    *speed = rhs.getSpeed();
}

// 每次销毁对象，都使用这个函数进行成员变量的空间释放
Tricycle::~Tricycle()
{
    delete speed;
    speed = NULL;
}

void Tricycle::pedal()
{
    setSpeed(*speed + 1);
    std::cout << "Pedaing " << getSpeed() << "mph\n";
}
void Tricycle::brake()
{
    setSpeed(*speed - 1);
    std::cout << "\n Braking " << getSpeed() << "mph\n";
}

int main(int argc, char const *argv[])
{
    std::cout << "Creating thrike named wichita ...\n";
    Tricycle wichita;
    wichita.pedal();

    std::cout << "Creating thrike named dallas ...\n";
    Tricycle dallas(wichita);
    
    std::cout << "Wichita's speed: " << wichita.getSpeed() << "\n";
    std::cout << "Dallas's speed: " << dallas.getSpeed() << "\n";
    
    std::cout << "setting wichta's speed to 10 ... \n";
    wichita.setSpeed(10);
    std::cout << "Wichita's speed: " << wichita.getSpeed() << "\n";
    std::cout << "Dallas's speed: " << dallas.getSpeed() << "\n";

    return 0;
}

