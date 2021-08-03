/*
 * @Author: Xuefeng Zhang 
 * @Date: 2021-08-03 16:46:46 
 * @Last Modified by:   LISTEN 
 * @Last Modified time: 2021-08-03 16:46:46 
 */
#include<iostream>

using namespace std;

string& trim(string &str, string::size_type pos = 0)
{
    static const string delim = " \t"; //删除空格或者tab字符
    pos = str.find_first_of(delim, pos);
    if (pos == string::npos)
        return str;
    return trim(str.erase(pos, 1));
}

class Animal {
public:
	Animal(){
		cout << "Animal 构造函数调用！" << endl;
	}
	virtual void Speak() = 0;

    // 方式1
    // ~Animal(){
    //     cout << "Animal 析构调用，会造成内存泄漏！" << endl;
    // }
    // 方式2
	//析构函数加上virtual关键字，变成虚析构函数
	virtual ~Animal(){
		cout << "Animal虚析构函数调用！" << endl;
	}
    // 方式3
	// virtual ~Animal() = 0; // = 0变成纯虚函数
};

// Animal::~Animal(){
// 	cout << "Animal 纯虚析构函数调用！" << endl;
// }
class JiafeiCat{
public:
    JiafeiCat(){
        cout << "JiafeiCat构造函数" << endl;
    }
    ~JiafeiCat(){
        cout << "JiafeiCat析构函数" << endl;
    }
};
//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。
class Cat : public Animal {
public:
	Cat(string name){
		cout << "Cat构造函数调用！" << endl;
		m_Name = new string(name);
	}

    //重载赋值运算符 
	Cat& operator=(Cat& cat){
		if (m_Name != nullptr){
			delete m_Name;
			m_Name = NULL;
		}
		//编译器提供的代码是浅拷贝
		//m_Age = p.m_Age;

		//提供深拷贝 解决浅拷贝的问题
		m_Name = new string(*cat.m_Name);

		//返回自身
		return *this;
	}
    
	virtual void Speak(){
		cout << *m_Name <<  "小猫在说话!" << endl;
	}
	~Cat(){
		cout << "Cat析构函数调用!" << endl;
		if (this->m_Name != NULL) {
			delete m_Name;
			m_Name = NULL;
		}
	}
public:
    JiafeiCat jfcat;
	string *m_Name;
};

void test01(){
	Animal *animal = new Cat("Tom");
	animal->Speak();

	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete animal;
}

int main() {
	test01();
	return 0;
}