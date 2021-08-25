#include<iostream>
using namespace std;

void testDump(){
	int a = 10;
	a = a/0;
}

int main(){
	testDump();
	return 0;
}
