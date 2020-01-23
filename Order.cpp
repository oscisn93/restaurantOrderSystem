//
// Created by Oscar Cisneros on 1/21/20.
//
#include "Order.h"

Order::Order(int n, int m)
  :order_num(n), table_num(m)
  {
    grabData();
  }

void Order::grabData(){
  // int to string conversion:
  // TODO: test performance and possibly
  //  implement faster/less expensive method(s)
  std::stringstream ss;
  std::string index;
  ss<<table_num;
  ss>>index;
  // open file of the name by table number plus .txt extension
  std::ifstream iFile(std::string("table") + index + std::string(".txt"));
  // separate into strings that hold lines
  // of the file: these represent individual
  // orders, reserve space for ten(so we don't
  // resize often and maybe even leave space for add-ons
  if(iFile.fail())
    //TODO: define/add file exception
    std::cout<<"nope"<<std::endl;
  // first line will always be server name
  std::getline(iFile, server_name);
  // rest will fill item vector
  itemList.reserve(defaultOrderSize);
  std::string lineString;
  while(!iFile.eof())
  {
    std::getline(iFile, lineString);
    itemList.__emplace_back(lineString);
  }
}

void Order::printOrder() {
  tip = addTip();
  std::cout<<"Order: "<<order_num<<"\n";
  std::cout<<"Server: "<<server_name<<"\ttable "<<table_num<<"\n";
  for(auto&&i : itemList)
      std::cout<<i.name<<" "<<i.price<<"\n";
  std::cout<<"\t\tsubtotal: "<<subtotal<<"\n";
  std::cout<<"\t\ttaxes: "<<tax<<"\n";
  std::cout<<"\t\ttip: "<<tip<<"\n";
  std::cout<<"\t\ttotal: "<<total;
  std::cout<<std::endl;
}

void Order::addItem(std::string itemString) {
  itemList.__emplace_back(itemString);
}

double Order::addTip() {
  double t;
  std::cout<<"How much was the tip: ";
  std::cin>>t;
  return t;
}
