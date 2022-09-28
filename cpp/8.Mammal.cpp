#include<iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND };

class Mammal
{
protected:
    int age;
    int weight;
public:
    // constructor
    Mammal();
    Mammal( int age );
    ~Mammal();

    // accessors
    int getAge() const { return age; }
    int getWeight() const { return weight; }
    void setAge(int newAge) { age = newAge; } 
    void setWeight(int newWeight) { weight = newWeight; } 

    // other methods
    void speak() const { std::cout << " Mammal speak ! \n"; }
    void sleep() const { std::cout << " Mammal sleep ! \n"; }
};

Mammal::Mammal():
age( 1 ),
weight( 5 )
{
    std::cout << "Mammal constructro ... \n";
}
Mammal::~Mammal()
{
    std::cout << "Mammal destructor ... \n";
}
Mammal::Mammal( int age ):
age( age ),
weight( 5 )
{
    std::cout << "Mammal constructro ... \n";
} 

// Dog 继承 Mammal
class Dog : public Mammal
{
private:
    BREED breed;
public:
    // constructor
    Dog();
    Dog( int age );
    Dog( int age, int weight, BREED breed );
    ~Dog();

    // accessors
    BREED getBreed() const { return breed; }
    void setBreed( BREED newBreed ) { breed = newBreed; }

    // other method
    // 子类可以访问父类 protected 或 public 的成员方法和成员变量
    void wagTail() { 
        std::cout << " Tail wagging ... " << breed << " + " << age << "\n"; 
    }
    void begForFood() { std::cout << " Begging for food ... \n"; }
};

Dog::Dog():
Mammal(), // 这个可以不加，默认都将调用，但是加了会更清晰
breed(YORKIE)
{
    std::cout << "Dog constructor ... \n";
}
Dog::Dog( int age ):
Mammal(age),
breed(YORKIE)
{
    std::cout << "Dog constructor ... \n";
}
Dog::Dog( int age, int weight, BREED breed ):
Mammal( age ), // base constructor
breed( breed ) // initialization
{
    // 初始化阶段，不能给父类变量直接赋值，如 weight( weight ),
    // 要使用以下这种方式，给父类中的变量分配值。
    weight = weight; // assignment
    std::cout << "Dog constructor ... \n";
}
Dog::~Dog()
{
    std::cout << "Dog destructor ... \n";
}


int main(int argc, char const *argv[])
{
    Dog fido; // reate a dog
    // 继承自父类 public 或 protected 的成员方法
    fido.speak();
    // 子类的成员方法
    fido.wagTail();
    std::cout << " Fido is " << fido.getAge() << " years old \n";
    Dog rover(5);
    rover.wagTail();
    std::cout << "rover is " << rover.getAge() << " years old \n";
    return 0;
}
