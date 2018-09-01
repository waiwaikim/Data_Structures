// File: a6.hpp
// Waiwai Kim
// Kim
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A6_HPP
#define A6_HPP

#include <ostream>
#include "symbol.hpp"

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT ALL REQUIRED FUNCTIONS BELOW
// YOU ARE NOT ALLOWED TO ALTER ANY INTERFACE
// INSIDE A FUNCTION YOU CAN DO WHATEVER YOU LIKE




struct compare_bnode {
  bool operator()(const bnode<symbol>* lhs, const bnode<symbol>* rhs) {

    return ((lhs->value).count > (rhs->value).count|| (!((rhs->value).count > (lhs->value).count) && ((lhs->value).value > (rhs->value).value)));
  }
};
template <typename Iter>
void test(Iter first, Iter last){

    std::sort(first,last);
    for (; first != last ; ++first){
      std::cout << (*first).value << " " << (*first).count <<std::endl;
    }
}

// IMPLEMENT YOUR FUNCTION huffman_tree
template <typename Iter>
bnode<symbol>* huffman_tree(Iter first, Iter last){


    std::priority_queue<bnode<symbol>*, std::vector<bnode<symbol>*>, compare_bnode> huffman_queue;

    for (; first != last ; ++first){
      bnode<symbol>* new_node = new bnode<symbol>(*first);
      huffman_queue.push(new_node);
    }

    bnode<symbol>* combined_node = nullptr;

     while(huffman_queue.size() >= 2){

       bnode<symbol>* left = huffman_queue.top();
       //std::cout << "left : "<< (left->value).value << " " << (left->value).count << std::endl;
       huffman_queue.pop();

       bnode<symbol>* right = huffman_queue.top();
       // std::cout << "right: "<< (right->value).value << " " << (right->value).count << std::endl;
       huffman_queue.pop();


       symbol new_symbol = symbol(std::min((left->value).value,(right->value).value), (left->value).count + (right->value).count);

       combined_node = new bnode<symbol>(new_symbol,left, right);

       // std::cout <<"combined : "<< (combined_node->value).value<<" "<< (combined_node->value).count << std::endl;
       // std::cout<<std::endl;

       huffman_queue.push(combined_node);
     }

     //std::cout<<"top " <<((huffman_queue.top()->right)->value).value<<((huffman_queue.top()->right)->value).count<< std::endl;
     // bnode<symbol>* last = huffman_queue.top() ;
     // symbol new_symbol = symbol((combined_node->value).value, (combined_node->value).count + (last->value).count);
     // bnode<symbol>* root = new bnode<symbol>*(new_symbol,combined_node, last);

     // while( !huffman_queue.empty()){
     //     std::cout <<(huffman_queue.top()->value).value<<" "<< (huffman_queue.top()->value).count << std::endl;
     //     huffman_queue.pop();
     // }

    return huffman_queue.top() ;

    // sreturn root;
};

// IMPLEMENT YOUR FUNCTION print_dictionary


void traverse_tree(bnode<symbol>* root, std::string return_string){


  //std::cout << "current traverse_tree : " << (root->value).value<< " "<< (root->value).count  <<std::endl;


    if (root->left == nullptr && root->right == nullptr){
        std::cout << (root->value).value << " "<< return_string  << std::endl;

    }
    if (root->left){
      // std::cout << (root->value).value <<std::endl;
      // std::cout << (root->value).count <<std::endl;
      // std::cout << "after left  :" << return_string << std::endl;
      traverse_tree(root->left, return_string+"0");
    }
    if(root->right){
      // std::cout << (root->value).value <<std::endl;
      // std::cout << (root->value).count <<std::endl;
      // std::cout << "after  right :" << return_string << std::endl;
      traverse_tree(root->right, return_string+"1");
    }
};
void print_dictionary(std::ostream& os, bnode<symbol>* root){


    // std::cout << ((root->left)->value).value <<std::endl;
    // std::cout << ((root->left)->value).count <<std::endl;
    std::string huffman_print = "";
    traverse_tree(root, huffman_print);

};
// IMPLEMENT YOUR FUNCTION release_tree
void release_tree(bnode<symbol>* root){

    if (root==nullptr) return ;

    release_tree(root->left);
    release_tree(root->right);

    delete root;

};

#endif // A6_HPP
