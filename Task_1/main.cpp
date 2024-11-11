#include <iostream>
#include <cpr/cpr.h>

int main() {    
    std::string choice;
    while(choice != "exit") {
        std::cout<<"\nEnter choice \nget\npost\nput\ndelete\npatch\nexit\nEnter : ";
        std::cin>>choice;
        if(choice == "get"){
            cpr::Response r = cpr::Get(cpr::Url("https://httpbin.org//get"));
            std::cout<<"\nResponse on \"get\" : "<<std::endl;
            std::cout<<r.text<<std::endl;
        }
        else if(choice == "post"){
            cpr::Response r = cpr::Post(cpr::Url("http://httpbin.org//post"));
            std::cout<<"\nResponse on \"post\" : "<<std::endl;
            std::cout<<r.text<<std::endl;
        }
        else if(choice == "put"){
            cpr::Response r = cpr::Put(cpr::Url("http://httpbin.org//put"));
            std::cout<<"\nResponse on \"put\" : "<<std::endl;
            std::cout<<r.text<<std::endl;
        }
        else if(choice == "delete"){
            cpr::Response r = cpr::Delete(cpr::Url("http://httpbin.org//delete"));
            std::cout<<"\nResponse on \"delete\" : "<<std::endl;
            std::cout<<r.text<<std::endl;
        }
        else if(choice == "patch"){
            cpr::Response r = cpr::Patch(cpr::Url("http://httpbin.org//patch"));
            std::cout<<"\nResponse on \"patch\" : "<<std::endl;
            std::cout<<r.text<<std::endl;
        }
        else if(choice != "exit"){
            std::cout<<"\nInvalid option !"<<std::endl;
        }
    }
}
