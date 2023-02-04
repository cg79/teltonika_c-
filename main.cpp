#include <iostream>
#include <stdio.h>

// #include "http_get_post/HttpRequest.h"
#include "json/json.hpp"

// #include "curlpp/cURLpp.hpp"
// #include "curlpp/Options.hpp"
#include <curl/curl.h>

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


size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);

    return size * nmemb;
}

string httpgetRequest(string url){

	const char* url3 = stringToCharArray(url);

	string response_string;

	curl_global_init(CURL_GLOBAL_DEFAULT);
    auto curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url3);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 50L);
        curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

        
        string header_string;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header_string);

        curl_easy_perform(curl);
        // cout << response_string;
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        curl = NULL;
    }

	return response_string;
}




int main()
{

	string response = httpgetRequest("https://api.coindesk.com/v1/bpi/currentprice.json");
	cout << response;

	 jsonExample();

	// char* str = httpgetRequest("https://api.coindesk.com/v1/bpi/currentprice.json");
	// printf("%s\n", str);

	// free(str);

	// httpGet();
	// printf("%s\n", str);
	

	
	return 0;
}



