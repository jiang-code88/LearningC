#include<iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND };

class Mammal
{
protected:
    int age;
    int weight;
public:
    // constructor
    Mammal() { std::cout << "Mammal constructro ... \n"; }
    ~Mammal() { std::cout << "Mammal destructor ... \n"; }

    // accessors
    int getAge() const { return age; }
    int getWeight() const { return weight; }
    void setAge(int newAge) { age = newAge; } 
    void setWeight(int newWeight) { weight = newWeight; } 

    // other methods
    void speak() const { std::cout << " Mammal speak ! \n"; }
    void sleep() const { std::cout << " Mammal sleep ! \n"; }

    void move() const { std::cout << " Mammal move one step\n"; }
    void move( int distance ) const { std::cout << " Mammal move " << distance << " steps\n"; }
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

    // other method
    // 子类可以访问父类 protected 或 public 的成员方法和成员变量
    void wagTail() { 
        std::cout << " Tail wagging ... " << breed << " + " << age << "\n"; 
    }
    void begForFood() { std::cout << " Begging for food ... \n"; }
    // 子类重写覆盖父类方法
    void speak() const { std::cout << " woof ! \n"; }
    void move() const { std::cout << " Dog move five step\n"; }
    void dog_sleep() const;
};

void Dog::dog_sleep() const
{
    // 子类中调用父类的方法
    Mammal::sleep();
}

int main(int argc, char const *argv[])
{
    Mammal bigAnimal;
    Dog fido;
    bigAnimal.speak();
    fido.speak();

    bigAnimal.move();
    bigAnimal.move(10);
    fido.move();
    // 子类重写函数会覆盖父类所有同名的函数
    //fido.move(10); // 编译出错
    // 子类中调用父类的方法
    fido.Mammal::move(6);
    fido.dog_sleep();
    return 0;
}
