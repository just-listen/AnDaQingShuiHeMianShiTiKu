/*
 * @Author: Xuefeng Zhang 
 * @Date: 2021-08-03 15:44:17 
 * @Last Modified by: LISTEN
 * @Last Modified time: 2021-08-03 16:01:27
 */
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

mutex mylock;
condition_variable cond;
int flag = 0;   // 共享全局变量
const int times = 6;

void printA(){
    unique_lock<mutex> lock(mylock);
    int count = 0;
    while(count < times){
        while(flag != 0) cond.wait(lock);
        cout << "A " << count << endl;
        flag = 1;
        cond.notify_all();
        ++count;
    }
    cout << "A finished" << endl;
}

void printB(){
    unique_lock<mutex> lock(mylock);
    int count = 0;
    while(count < times){
        while(flag != 1) cond.wait(lock);
        cout << "B " << count << endl;
        flag = 2;
        cond.notify_all();
        ++count;
    }
    cout << "B finished" << endl;
}

void printC(){
    unique_lock<mutex> lock(mylock);
    int count = 0;
    while(count < times){
        while(flag != 2) cond.wait(lock);
        cout << "C " << count << endl;
        flag = 0;
        cond.notify_all();
        ++count;
    }
    cout << "C finished" << endl;
}

int main(){
    thread th1(printA);
    thread th2(printB);
    thread th3(printC);

    th1.join();
    th2.join();
    th3.join();
    cout << "All finished" << endl;
    return 0;
}