/*
 * @Author: Xuefeng Zhang 
 * @Date: 2021-08-03 16:19:36 
 * @Last Modified by:   LISTEN 
 * @Last Modified time: 2021-08-03 16:19:36 
 */
#include<iostream>

using namespace std;

class Animal{
public:
    virtual void speak(){
        cout << "Animal Speaking" << endl;
    }
    void run(){
        cout << "Animal running" << endl;
    }
    void run(string& str){
        cout << str << " running" << endl;
    }
};

class Cat : public Animal{
public:
    virtual void speak(){
        cout << "Cat speaking" << endl;
    }
};

class Dog : public Animal{
public:
    virtual void speak(){
        cout << "Dog speaking" << endl;
    }
};

//我们希望传入什么对象，那么就调用什么对象的函数
//如果函数地址在编译阶段就能确定，那么静态联编
//如果函数地址在运行阶段才能确定，就是动态联编
void DoSpeak(Animal& animal){
    animal.speak();
}
void testDuoTai(){
    Cat cat;
    DoSpeak(cat);
    Dog dog;
    DoSpeak(dog);
}
void testChongZai(){
    Animal animal;
    animal.run();
    string str("cat");
    animal.run(str);
}
int main(){
    // testDuoTai();
    // testChongZai();

    Cat p1;
    Dog p2;
    Animal* fa = &p2;
    fa->speak();
    return 0;
}