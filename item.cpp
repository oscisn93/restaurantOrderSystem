//
// Created by Oscar Cisneros on 1/17/20.
//
#include <string>
#include <iostream>
#include "utils.cpp"

//container for item data-->will become part of button component in GUI phase
struct item {
    std::string name;
    double price;
    std::string special_instructions;
    explicit item(std::string& s)
    {
      // find the three member values in the string 
      // using the fact that they are seperated 
      // by a space and assign them respectively
      int first_idx=0;
      int substr_idx = s.find(' ');
      name=s.substr(first_idx, substr_idx);
      first_idx=substr_idx+1;
      substr_idx=s.find(' ',first_idx);
      std::string p=s.substr(first_idx, substr_idx).substr(0, substr_idx-first_idx);
      std::cout<<p<<std::endl;
      price = utils::to_double(p);
      special_instructions=s.substr(substr_idx+1, s.size());
    }
};
