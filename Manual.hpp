#ifndef MANUAL_HPP
#define MANUAL_HPP

#include <iostream>
#include <string> 
#include <regex>
#include "Book.hpp"
class Manual:public Book {
  
private:
  std::string url_;
  std::string devname_;
  bool website_;
  bool aid_;

  public:
    Manual();
    Manual(const std::string title,const
std::string author, const int page_count, const std::string devname, const bool is_digital_ = false
    , const std::string url=" ", const bool aid = false);

    void setDevice(const std::string &devname_);
    std::string getDevice() const;

    bool setWebsite(const std::string &url_);

std::string getWebsite() const;

void setVisualAid(const bool &aid_);
bool hasVisualAid() const;
bool hasWebsite() const;

};
#endif