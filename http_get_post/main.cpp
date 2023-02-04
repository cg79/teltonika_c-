#include <iostream>
#include "HttpRequest.h"
using namespace std;

int main()
{
	HttpRequest* Http = new HttpRequest;
	
	char* str = (char*)malloc(BUFSIZE);
	
    const char* url3 = "https://api.coindesk.com/v1/bpi/currentprice.json";
       
	memset(str, 0, BUFSIZE);  // memset 函数是内存赋值函数，用来给某一块内存空间进行赋值的
	if(Http->HttpGet(url3, str)) {
		printf("%s\n", str);
	} else {
		cout<< url3 <<"HttpGet请求失败!"<<endl;
	}
    
	/*
	memset(str, 0, BUFSIZE);	
	//安装Tomcat
	if(Http->HttpGet("127.0.0.1", str)) {
		printf("%s\n", str);
	} else {
		printf("127.0.0.1 HttpGet请求失败!\n");
	}
	*/

	free(str);
	return 0;
}
