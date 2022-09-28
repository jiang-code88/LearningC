#include<iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND };

class Mammal
{
protected:
    int age;
public:
    // constructor
    Mammal() { std::cout << "Mammal constructro ... \n"; }
    ~Mammal() { std::cout << "Mammal destructor ... \n"; }


    // accessors
    int getAge() const { return age; }
    void setAge(int newAge) { age = newAge; } 

    // other methods
    // 虚拟函数：允许子类重写，然后多态调用的父类方法。
    virtual void speak() const { std::cout << " Mammal speak ! \n"; }
    void move() const { std::cout << " Mammal move one step\n"; }
    
};

// Dog 继承 Mammal
class Dog : public Mammal
{
private:
    BREED breed;
public:
    // constructor
    Dog() { std::cout << "Dog constructor ... \n"; }
    ~Dog() { std::cout << "Dog destructor ... \n"; }

    // accessors
    BREED getBreed() const { return breed; }
    void setBreed( BREED newBreed ) { breed = newBreed; }

    void wagTail() { 
        std::cout << " Tail wagging ... " << breed << " + " << age << "\n"; 
    }
    void speak() const { std::cout << " woof ! \n"; }
    void move() const { std::cout << " Dog move five step\n"; }
};

int main(int argc, char const *argv[])
{
    // 多态的指针用法
    Mammal *pMammal = new Dog();
    // 父类可以允许使用的子类多态方法。
    pMammal->speak();
    // 父类中未指定子类可以使用的多态方法，所以还是使用的父类的方法。
    pMammal->move();

    // 多态的引用用法
    Mammal &rMammal = *(new Dog());
    rMammal.speak();
    rMammal.move();
    return 0;
}
