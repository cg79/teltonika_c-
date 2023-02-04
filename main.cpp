#include <iostream>

#include "http_get_post/HttpRequest.h"
#include "json/json.hpp"

using namespace std;

int jsonExample(){
	nlohmann::json jdEmployees =  {
		{"firstName","Sean"},
		{"lastName","Brown"},
		{"StudentID",21453},
		{"Department","Computer Sc."}};

   string fName = jdEmployees.value("firstName", "oops");
   string lName = jdEmployees.value("lastName", "oops");
   int sID = jdEmployees.value("StudentID", 0);
   string dept = jdEmployees.value("Department", "oops");
   
   cout << "First Name: " << fName << endl;
   cout << "Last Name: " << lName << endl;
   cout << "Student ID: " << sID << endl;
   cout << "Department: " << dept << endl;

   return 0;

}

char* stringToCharArray(string input){
	const int length = input.length();
 
    // declaring character array (+1 for null terminator)
    char* char_array = new char[length + 1];
 
    // copying the contents of the
    // string to char array
    strcpy(char_array, input.c_str());

	return char_array;
}

char* httpgetRequest(string url){

	const char* url3 = stringToCharArray(url);
	HttpRequest* Http = new HttpRequest;
	
	// const char* url3 = "https://api.coindesk.com/v1/bpi/currentprice.json";
	char* str = (char*)malloc(BUFSIZE);
       
	memset(str, 0, BUFSIZE);  // memset 函数是内存赋值函数，用来给某一块内存空间进行赋值的
	if(Http->HttpGet(url3, str)) {
		printf("%s\n", str);
	} else {
		cout<< url3 <<"HttpGet"<<endl;
	}

	free(str);

	return str;
}


int main()
{
	// jsonExample();
	httpgetRequest("https://api.coindesk.com/v1/bpi/currentprice.json");
	// httpGet();
	// printf("%s\n", str);
	



    
	/*
	memset(str, 0, BUFSIZE);	
	//安装Tomcat
	if(Http->HttpGet("127.0.0.1", str)) {
		printf("%s\n", str);
	} else {
		printf("127.0.0.1 HttpGet请求失败!\n");
	}
	*/

	
	return 0;
}



