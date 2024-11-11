#include <iostream>
#include <cpr/cpr.h>

int main() {
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org//html"));    
    std::string startStr = "h1";
    std::string endStr = "/h1";

    int startStrLen = startStr.length();
    int start = r.text.find(startStr) + startStrLen;
    int end = r.text.find(endStr) - r.text.find(startStr) - startStrLen;  
    
    std::cout << r.text.substr(start, end) <<std::endl;
}
