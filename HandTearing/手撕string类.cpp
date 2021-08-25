#include<iostream>
#include<string.h>
using namespace std;

class String
{
public:
    String(const char *str = NULL);// 普通构造函数
    String(const String &other); // 拷⻉构造函数
    ~ String(void); // 析构函数
    //赋值函数
    String& operate=(const String &other) 
    {
        if(this == &other) //检查⾃赋值
            return *this;
        delete [] m_data; //释放原有的内存资源
        int length = strlen( other.m_data );
        m_data = new char[length+1];
        strcpy( m_data, other.m_data);
        return this; //返回本对象的引⽤
    };
private:
    char *m_data;// ⽤于保存字符串
};
//普通构造函数
String::String(const char *str)
{
    if(str==NULL)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int length = strlen(str);
        m_data = new char[length+1];
        strcpy(m_data, str);
    }
}
// String的析构函数
String::~String(void)
{
    delete [] m_data; // 或delete m_data;
}
//拷⻉构造函数
String::String(const String &other) // 输⼊参数为const型
{
    int length = strlen(other.m_data);
    m_data = new char[length+1];
    strcpy(m_data, other.m_data);
}
