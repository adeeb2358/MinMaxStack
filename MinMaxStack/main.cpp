//
//  main.cpp
//  MinMaxStack
//
//  Created by adeeb mohammed on 15/04/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>
#include<unordered_map>
#include <string>

class MinMaxStack {
private:
    
    std::vector<int> stack = {};
    std::vector<std::unordered_map<std::string, int>> minMaxStack = {};
    
public:
  int peek() {
    return stack[stack.size()-1];
  }

  int pop() {
      minMaxStack.pop_back();
      int result = stack[stack.size()-1];
      stack.pop_back();
      return result;
  }

  void push(int number) {
      std::unordered_map<std::string,int> newMinMax = {{"min",number},{"max",number}};
      if(minMaxStack.size()){
          std::unordered_map<std::string, int> lastMinMax = minMaxStack[minMaxStack.size() - 1];
          newMinMax["min"] = std::min(lastMinMax["min"],number);
          newMinMax["max"] = std::max(lastMinMax["max"],number);
      }
      minMaxStack.push_back(newMinMax);
      stack.push_back(number);
  }

  int getMin() {
    return minMaxStack[minMaxStack.size()-1]["min"];
  }

  int getMax() {
    return minMaxStack[minMaxStack.size()-1]["max"];
  }
    
};

int main(int argc, const char * argv[]) {
    std::cout<<"The program for min max stack o(1) time and o(1) space";
    return 0;
}
