#include <iostream>
#include <cpr/cpr.h>
#include <map>
#include <vector>

int main() {
    std::string choice;
    std::map<std::string , std::string> args;
    while(choice != "get" && choice != "post") {        
        std::cout<<"\nEnter \"get\" \"post\" for request. Or any word to add key : ";
        std::cin>>choice;
        if(choice != "get" && choice != "post") {
            std::string tempArg;
            std::cout<<"\nEnter argument for key \"" << choice <<"\" : ";
            std::cin>>tempArg;
            args[choice] = tempArg;    
        }    
    }
    std::map<std::string,std::string>::iterator iter = args.begin();
    if(iter != args.end()) {
        if(choice == "post") {             
            std::vector<cpr::Pair> pairVec;
            for(;iter != args.end();++iter){
                pairVec.emplace_back(iter->first,iter->second);
            }                
            cpr::Response r = cpr::Post(cpr::Url("http:/httpbin.org/post"),cpr::Payload(pairVec.begin(),pairVec.end()));
            std::cout<<"\nPost response is : "<<std::endl;
            std::cout<<r.text<<std::endl;
        }
        else {          
            std::string url_str;
            for(;iter != args.end();++iter){
                url_str += iter->first + "=" + iter->second + "&";
            }
            cpr::Response r = cpr::Get(cpr::Url(url_str));
            std::cout<<"\nGet response is : "<<std::endl;
            std::cout<<r.text<<std::endl;
        }    
    }
    else {
        std::cout<<"\nNothing to post or get"<<std::endl;
    }
}
