#include "Manual.hpp"
#include "Book.hpp"
#include <regex>

Manual::Manual(){
    std::string url_ = " ";
    std::string devname_ = " "; 
    website_ = false; 
    aid_ = false; 
}

Manual::Manual(const std::string title, const std::string author, const int page_count
, const std::string devname, const bool is_digital, const std::string url, const bool aid) 
: Book(title, author, page_count, is_digital){
    url_ = url;
    devname_ = devname;
    aid_ = aid;
    website_ = false;
    setWebsite(url);
    if(url_ == "Broken Link"){
        url_ = "";
        website_ = false;
    }


    };        


void Manual::setDevice(const std::string &devname){
    devname_ = devname;
}

std::string Manual::getDevice() const{
    return devname_;
} 

bool Manual::setWebsite(const std::string &url) {
    if(std::regex_match(url, std::regex("(https?://)([\\w\\d-]+\\.?)+[A-Za-z]{2,}(/[\\w\\d-]*)*"))){
        url_ = url;
        website_ = true;
        return website_;
    }
    else
    {
        url_ = "Broken Link";
        website_ = true;
        return website_;
    }
}

std::string Manual::getWebsite() const{
    return url_;
} 

void Manual::setVisualAid(const bool &aid){
    aid_ = aid;
}

bool Manual::hasVisualAid() const{
    return aid_;
}

bool Manual::hasWebsite() const{
    return website_;
}