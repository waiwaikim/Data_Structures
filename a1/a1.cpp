// File: a1.cpp
// Waiwai
// Kim
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>

void count(const int* first, const int* last, int* const count){

  //empty the array
  for (int j=0 ; j < 5 ; ++j) count[j] = 0 ;

  //increment the count array
  for ( auto i = first ;  i != last ; ++i) count[*i]++;

}

/*
void count_k_mer(const int* first, const int* last, int* const count, int k, int size){

  //empty the array
  for (int j = 0 ; j < size ; ++j)  count[j] = 0 ;

  for ( ; first != (last-k+1) ; ++first){

    int decimal_sum = 0 ;
    bool n = 0  ;
    for (auto l = 0 ; l != k ; ++l){
      // l iterates from 0, 1, 2, 3 ..... to k

      if (*(first+l)==4) {n = 1;}
      // *(i+l) == integer, INT *
      decimal_sum += (*(first+l))*std::pow(4,k-l-1);
    }
    std::cout << " decimal sum  "<< decimal_sum << std::endl;
    if (n == 0 ) count[decimal_sum]++;
  }
}
*/

void count_k_mer(const int* first, const int* last, int* const count, int k, int size){

  //empty the array
  for (int j = 0 ; j < size ; ++j)  count[j] = 0 ;


  //first k-mer
  int decimal_sum = 0 ;
  int n_counter=0;
  for (auto j=0 ; j != k ; ++j){

    int unitamt ;
    unitamt = first[j] *std::pow(4,k-j-1);
    //std::cout << unitamt << std::endl;
    decimal_sum += unitamt;

    if (first[j]==4) {
      n_counter = j+1;
    }
  }

  if (n_counter == 0 ) {
    count[decimal_sum]++;
  }

  //std::cout << "decimal sum is " << decimal_sum << std::endl;
  int and_operand = std::pow(4,k)-1;

  //start from first+k because we already have the first k-mer term
  for ( auto i = first+k ; i != last ; ++i){

    decimal_sum = decimal_sum << 2;
    decimal_sum = decimal_sum & and_operand;
    decimal_sum += *i ;

    if (n_counter != 0 && *i != 4) { n_counter--; }
    else if (*i == 4){ n_counter = k; }

    if (n_counter == 0) {
      count[decimal_sum]++;
      n_counter = 0;
    }
  }

}

void print_k_mer(int* const array, int k, int size){

  for (int i=0 ; i < size ; ++i){

    if (array[i] != 0){


        int divide = i ;
        int remain = 0 ;
        char temp_array[k];

        //std::cout << i << ' ';
        for (auto l = 0 ; l != k ; ++l){

          //iterate from 0, 1, 2, 3 ... to k
          remain =  divide % 4 ;
          divide =  divide / 4 ;

          switch (remain){

            case 0 :
              temp_array[k-l-1] ='A';
              break;
            case 1 :
              temp_array[k-l-1] ='C';
              break;
            case 2 :
              temp_array[k-l-1] ='G';
              break;
            case 3 :
              temp_array[k-l-1] ='T';
              break;
          }
        }

        for (auto j = 0 ; j != k ; ++j){
          std::cout << temp_array[j];
        }

      std::cout << " "<< array[i] << std::endl;
    }
  }
}

int main(int argc, char* argv[]){

  // test argc
  if (argc != 3){
    std::cout << "incorecct number of arguments" << std::endl;
    return -1; // exit the program
  }

  std::string name = argv[1];
  int k = std::atoi(argv[2]);

  //std::cout << "argv[0] is " << argv[0]<<std::endl;
  //std::cout << "argv[1] is " << name <<std::endl;
  //std::cout << "argv[2] is " << k <<std::endl;

  //get DNA sequence from f to DNA_seq
  std::ifstream f(name);
  std::string s= "";
  std::getline(f, s);
  f.close();

  //test
  //std::cout << s << std::endl;

  //std::cout << s<< std::endl;
  int DNA_length = s.length();

  //allocate memory on heap, which pointer DNA_seq points to
  int* DNA_seq = new int[DNA_length];

  //fill in DNA_seq with numeric value of DNA sequence

  for ( int i=0 ; i <DNA_length ; ++i){

    switch (s[i]) {
      case 'A' :
        DNA_seq[i] = 0;
        break;
      case 'C' :
        DNA_seq[i] = 1;
        break;
      case 'G' :
        DNA_seq[i] = 2;
        break;
      case 'T' :
        DNA_seq[i] = 3;
        break;
      case 'N' :
        DNA_seq[i] = 4;
        break;

    }
    //std::cout << DNA_seq[i] ;
  }
  //std::cout << std::endl;

  std::cout << "0 " << k << " "<< DNA_length << std::endl;

  int* count_array  = new int[5];

  count(DNA_seq, DNA_seq+DNA_length, count_array);

  std::cout <<"1 " ;
  for (int i=0 ; i < 5 ; ++i){
    std::cout << count_array[i] ;
    if (i != 4 ) std::cout << " ";
  }
  std::cout <<std::endl;


  if (DNA_length >= k){
    int k_mer_size = std::pow(4,k);
    int* k_mer_array = new int[k_mer_size];

    count_k_mer(DNA_seq, DNA_seq+DNA_length, k_mer_array, k, k_mer_size);
    //print_k_mer_int(k_mer_array, k_mer_size);
    print_k_mer(k_mer_array, k, k_mer_size);

    //std::cout << "k mer array adress : "<<k_mer_array << std::endl;
    delete[] k_mer_array;
  }
  else {
    std::cout << "error"<<std::endl;
  }

  //std::cout << "count array adress : "<<count_array << std::endl;
  //std::cout << "dna_seq adress : "<< DNA_seq << std::endl;

  delete[] count_array;
  delete[] DNA_seq;


  return 0 ;

}
