// File: a0.cpp
// Waiwai
// Kim
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES
#include <iostream>
#include <string>

int main(){
  // set your name
  std::string name = "Waiwai";
  // set to true if code was tested
  bool  has_tested =  true;
  // set number of tests
  int num_tests = 1;

  std::cout << name;

  if (has_tested)
  {
  std::cout << " performed " << num_tests << " test(s)" << std::endl;
  }
  else
  {
  std::cout << " was lazy" << std::endl;
  }
  return
  0;
}
