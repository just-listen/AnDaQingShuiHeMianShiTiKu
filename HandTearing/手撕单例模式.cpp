/*
 * @Author: Xuefeng Zhang 
 * @Date: 2021-08-03 15:16:51 
 * @Last Modified by: LISTEN
 * @Last Modified time: 2021-08-03 15:35:45
 */
#include<iostream>

using namespace std;

// 单例懒汉模式
// 经典的线程安全懒汉模式，使用双检测锁模式。
class Single{
private:
    //私有静态指针变量指向唯一实例
    static Single *p;
    //静态锁，是由于静态函数只能访问静态成员
    static pthread_mutex_t lock;
    //私有化构造函数
    Single(){
        pthread_mutex_init(&lock, NULL);
    }
    ~Single(){}
public:
    //公有静态方法获取实例
    static Single* GetInstance();
};
pthread_mutex_t Single::lock;
Single* Single::p = nullptr;
Single* Single::GetInstance(){
    //若p非空，即已经存在一个实例，则直接返回指针
    if(p == nullptr){
        pthread_mutex_lock(&lock);
        if(p == nullptr){
            p = new Single;
        }
        pthread_mutex_unlock(&lock);
    }
    return p;
}

// 饿汉模式
// 饿汉模式不需要用锁，就可以实现线程安全。原因在于，在程序运行时就定义了对象，并对其初始化。
// 之后，不管哪个线程调用成员函数getinstance()，都只不过是返回一个对象的指针而已。
class single{
private:
    static single* p;
    single(){}
    ~single(){}
public:
    static single* GetInstance();
};
single* single::p = new single();
single* single::GetInstance(){
    return p;
}

// 测试方法
int main(){
    single *p1 = single::GetInstance();
    single *p2 = single::GetInstance();
    if(p1 == p2) 
        cout << "same!" << endl;
    return 0;
}