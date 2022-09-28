#include<iostream>

class Mammel
{
protected:
    int age;
public:
    Mammel():age(1) { std::cout << "Mammel constructor ... \n"; }
    ~Mammel() { std::cout << "Mammel destructor ... \n"; }
    // 父类多态方法的标志 virtual
    virtual void speak() const { std::cout << "Mammel speak\n"; }
};

class Cat : public Mammel
{
public:
    Cat() { std::cout << "Cat constructor ... \n"; }
    ~Cat() { std::cout << "Cat destructor ... \n"; }
    void speak() const { std::cout << "Meow !\n"; }  
    void purr() const { std::cout << "Rrrrrrrrrr!\n"; } 
};

int main(int argc, char const *argv[])
{
    // 父类对象
    Mammel *pCat1 = new Mammel;
    pCat1->speak(); // Mammel speak

    std::cout << "-------------------------------\n";
    // 父类指向子类对象
    Mammel *pCat2 = new Cat;
    pCat2->speak(); // Meow !
    // 父类无法访问子类的方法的
    // pCat2->purr();

    std::cout << "-------------------------------\n";
    // 将多态父类指向的子类对象，动态转化为子类对象。
    Cat *pRealCat = dynamic_cast<Cat *> (pCat2) ;
    if ( pRealCat )
    {
        pRealCat->purr();
    }
    else
    {
        std::cout << "Uh oh, not a cat!\n";
    }
    // 如果强转的父类不是多态指向的子类对象，将返回空指针
    Cat *pRealCat2 = dynamic_cast<Cat *> (pCat1) ;
     if ( pRealCat2 )
    {
        pRealCat2->purr();
    }
    else
    {
        std::cout << "Uh oh, not a cat!\n";
    }
    
    std::cout << "-------------------------------\n";
    // 子类对象
    Cat *pCat3 = new Cat;
    pCat3->speak();
    pCat3->purr();

    return 0;
}

