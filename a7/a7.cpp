// File: a7.cpp
// Waiwai
// Kim
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>

void make_permutation(const std::string my_name, std::set<std::string>& my_set){

  int my_size = my_name.size();

  //delete
  for (int i = 0 ; i < my_size ; ++i){
    std::string new_name = my_name;
    new_name = new_name.erase(i, 1);
    my_set.insert(new_name);
  }

  //insert
  for (int i = 0 ; i <= my_size ; ++i){
    for (char l='A' ; l <= 'Z' ; ++l){
      std::string new_name = my_name;
      new_name = new_name.insert(i, 1, l);
      my_set.insert(new_name);
    }
  }

  //substitute
  for (int i = 0 ; i < my_size ; ++i){
    for (char l='A' ; l <= 'Z' ; ++l){
      std::string new_name = my_name;
      new_name = new_name.replace(i, 1, 1, l);
      my_set.insert(new_name);
    }
  }
}


struct compare_pair {
  bool operator()(const std::pair<std::string, int> lhs, const std::pair<std::string, int> rhs) {

    return ( lhs.second < rhs.second ) || (!(rhs.second < lhs.second) && (lhs.first > rhs.first ));

  }
};


void make_suggestion(const std::string my_name, const std::set<std::string> my_set, std::unordered_map<std::string, int>& dict ){

  std::priority_queue< std::pair<std::string, int> , std::vector<std::pair<std::string, int>>, compare_pair> dict_queue;

  if (my_set.size() < dict.size()){
    for (auto j = my_set.cbegin() ;j != my_set.cend() ; ++j ){
      std::unordered_map<std::string, int>::iterator found_in_dict_2 = dict.find(*j);

      if (found_in_dict_2 != dict.end()){
        //std::cout << "suggest : " << found_in_dict_2->first << " " << found_in_dict_2->second<< std::endl;
        std::pair<std::string, int> found_pair (found_in_dict_2->first, found_in_dict_2->second);
        dict_queue.push(found_pair);
      }
    }
  }
  else{
    for (auto j = dict.begin() ;j != dict.end() ; ++j ){
      std::set<std::string>::iterator found_in_set= my_set.find(j->first);

      if (found_in_set != my_set.end()){
        std::pair<std::string, int> found_pair (j->first, j->second);
        dict_queue.push(found_pair);
      }
    }
  }

  if (dict_queue.empty() ){
    std::cout << "-" << std::endl;
    dict.insert(std::pair<std::string, int> (my_name, 1));
  }
  else {

    std::pair<std::string, int> top_pair = dict_queue.top();
    std::cout << top_pair.first << " "<< top_pair.second  << std::endl;
  }
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "usage: ./a7 file" << std::endl;
        return -1;
    }

    // get input text
    std::ifstream f(argv[1]);

    std::string name;
    int freq;

    // set dictionary
    std::unordered_map<std::string, int> my_dict ;

    while(f >> name >> freq){
      std::pair<std::string, int> each_pair (name, freq);
      my_dict.insert(each_pair);
    }

    f.close();

    // set vector of inputs
    std::vector<std::string> input_names ;
    std::string string_input;
    while(std::cin >> string_input){
      input_names.push_back(string_input);
    }


    // iterate through input names
    for (auto it = input_names.cbegin() ; it != input_names.cend() ; ++it){

      // examine if input name is already in dictionary
      std::unordered_map<std::string, int>::iterator found_in_dict = my_dict.find(*it);

      if (found_in_dict != my_dict.end()){
        std::cout << found_in_dict-> first <<" "<< found_in_dict -> second << std::endl ;
        found_in_dict->second++;
      }
      else {
        // when input name is NOT found in the dictionary
        // make every possible 1 distance make_permutation
        std::set<std::string> permut_set ;
        make_permutation(*it,  permut_set);


        make_suggestion(*it, permut_set, my_dict);
      }
    }

    return 0;
} // main
