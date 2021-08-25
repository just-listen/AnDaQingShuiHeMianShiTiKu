/*
 * @Author: Xuefeng Zhang 
 * @Date: 2021-08-03 18:47:59 
 * @Last Modified by: LISTEN
 * @Last Modified time: 2021-08-03 18:49:14
 */
#include<iostream>

using namespace std;

// 大端字节序：整数高位存储在内存低地址,网络字节序
// 小端字节序：整数低位存储在内存低地址,又被称为主机字节序
class Solution{
public:
    void byteOrder1(){
        int a = 0x1256;
        char c = (char)a;
        // int转char留下低地址部分
        // cout << c << " " << (bool)(c == '4') << "new" << c == 0x34;
        if( c != 0x56) cout << "大端字节序" << endl;
        else cout << "小端字节序" << endl;
    }
    void byteOrder2(){
        union{
            short value;
            char union_bytes[sizeof(short)];
        }test;
        test.value = 0x1234;
        if(test.union_bytes[0] == 0x12 && test.union_bytes[1] == 0x34) 
            cout << "大端字节序" << endl;
        else if(test.union_bytes[0] == 0x34 && test.union_bytes[1] == 0x12) 
            cout << "小端字节序" << endl;
        else cout << "unkown" << endl;
    }
};

void ByteOrder(){
    union{
        char a;
        int b;
    }un;
    un.b = 0x0001;
    if(un.a == 1) cout << "xiaoduan" << endl;
}
int main(){
    // Solution s;
    // s.byteOrder1();

    ByteOrder();
    int a = 0x1234;
    char c = (char)a;
    if(c == '4')
    cout << c << endl;
    return 0;
}