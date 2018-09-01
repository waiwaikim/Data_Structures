// File: a3.hpp
// Waiwai
// Kim
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A3_HPP
#define A3_HPP

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT MISSING FUNCTIONALITY OF key_value_sequences IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS THAN
// <algorithm>, <list>, <vector>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>
#include <list>
#include <vector>

class key_value_sequences {
public:
    // YOU SHOULD USE C++ CONTAINERS TO AVOID RAW POINTERS
    // IF YOU DECIDE TO USE POINTERS, MAKE SURE THAT YOU MANAGE MEMORY PROPERLY
    key_value_sequences(){

      std::vector<int> keys_ ;
      std::vector<std::vector<int>> values_;
      // std::vector<std::list<int>> values_ ;
    }

    // IMPLEMENT ME: SHOULD RETURN SIZE OF A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN 0
    int size(int key) const{

      int i = 0 ;

      // find if key is already in the vector
      for (i = 0 ; i < keys_.size();  ++i ){
        if (keys_[i] == key ) break ;
      }

      if (keys_.size() == 0 ){
        return 0 ;
      }
      else if ( i == keys_.size() ){
        return 0 ;
      }

      return values_[i].size() ;

    }

    // IMPLEMENT ME: SHOULD RETURN POINTER TO A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN nullptr
    const int* data(int key) const{

      int i = 0 ;

      const int* return_ptr;

      // find if key is already in the vector
      for (i = 0 ; i < keys_.size();  ++i ){
        if (keys_[i] == key ) break ;
      }

      if (keys_.size() == 0 ){
        return_ptr =  nullptr ;
      }
      else if ( i == keys_.size() ){
        return_ptr = nullptr ;
      }

      return_ptr = values_[i].data();



      return return_ptr;

    }

    // IMPLEMENT ME: INSERT VALUE INTO A SEQUENCE IDENTIFIED BY GIVEN KEY
    void insert(int key, int value){

      int i = 0 ;

      // find if key is already in the vector
      for (i = 0 ; i < keys_.size();  ++i ){
        if (keys_[i] == key ) break ;
      }

      //std::cout << "key is " << key << " index is " << i <<" size is " << keys_.size() << std::endl;

      if (keys_.size() == 0 ){
        //the very first insert of (key, value ) == when keys_ is empty
        //std::cout << " first timeer " << std::endl;
        keys_.push_back(key);
        std::vector<int> it ;
        it.push_back(value);
        values_.push_back(it);

    }
      else if ( i == keys_.size()) {
        //first key == when keys_ is NOT empty, but a new key
        keys_.push_back(key);
        std::vector<int> it ;
        it.push_back(value);
        values_.push_back(it);
        //std::cout << " i is "<< i << std::endl;
      }
      else if (i < keys_.size() ){
          //std::cout << "keys is "<< keys_[i] << std::endl;
          values_[i].push_back(value);
      }

    }

    // void print() const {
    //
    //   int k = 0 ;
    //
    //   for (std::vector<int>::const_iterator iter =  keys_.begin() ; iter != keys_.end() ; ++iter){
    //     std::cout << std::to_string(*iter) << " : " ;
    //
    //     for (std::vector<int>::const_iterator iter2 = values_[k].begin(); iter2 != values_[k].end() ; ++iter2){
    //       std::cout << std::to_string(*iter2 )<< ' ';
    //     }
    //     std::cout << std::endl;
    //     ++k;
    //   }
    //   std::cout << std::endl;
    // }

private:

  std::vector<int> keys_;
  // std::vector<std::list<int>> values_;
  std::vector<std::vector<int>> values_;
}; // class key_value_sequences

#endif // A3_HPP
