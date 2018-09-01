// File: a2.hpp
// Waiwai
// Kim
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A2_HPP
#define A2_HPP

// IMPLEMENT MISSING FUNCTIONALITY OF sorted_sc_array IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS EXCEPT OF <algorithm>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION AS PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>


class sorted_sc_array {
public:


    sorted_sc_array() : size_(0), ptr_(nullptr), capacity_(0), sorted_(0) { }

    ~sorted_sc_array() { delete[] ptr_; }

    // IMPLEMENT ME
    sorted_sc_array(const sorted_sc_array& A) : size_(A.size_), capacity_(A.capacity_), sorted_(A.sorted_){
        if (size_ ==0 ) ptr_=nullptr;
        else {
          ptr_ = new signed char[capacity_];
          std::copy(A.ptr_, A.ptr_ + size_, ptr_);
        }
    }


    // IMPLEMENT ME
    sorted_sc_array& operator=(const sorted_sc_array& A){
        if (this == &A) return *this ; // self-assignment
        delete[] ptr_; // release current memory
        size_ = A.size_;
        capacity_ = A.capacity_;
        sorted_ = A.sorted_;
        if (size_ == 0 ) ptr_=nullptr;
        else {
            ptr_  = new signed char[capacity_];
            std::copy(A.ptr_, A.ptr_ + size_ , ptr_);
        }
        return *this ;

    }

    //signed char& operator[](int n){ return ptr_[n];}

    //const signed char& operator[](int n) const { return ptr_[n];}

    // RETURNS SIZE OF THE ARRAY (i.e. HOW MANY ELEMENTS IT STORES)
    int size() const { return size_; }
    int capacity() const { return capacity_; }

    // RETURNS RAW POINTER TO THE ACTUAL DATA, CAN BE INVOKED AT ANY TIME
    const signed char* data() const {

      std::sort(ptr_, ptr_+ (size_));


      return ptr_;

    }

    //access
    signed char& front() { return *ptr_; }

    const signed char& front() const { return *ptr_; }

    signed char& back() { return *(ptr_ + (size_ - 1 )); }

    const signed char& back() const  { return *(ptr_ + (size_ -1) ); }

    //modify


    void push_back(const signed char& c){

        if (capacity_ == size_) { resize() ; }
        *(ptr_ + size_) = c ;
        size_++;
    }


    void resize(){

      int new_capacity ;
      if (capacity_== 0) new_capacity = 2 ;
      else { new_capacity = 2* capacity_;}

      signed char* temp = new signed char[ new_capacity ];
      std::copy(ptr_, ptr_+size_, temp);
      delete[] ptr_;
      ptr_ = temp;
      capacity_ = new_capacity;
      size_ = size_;

      // std::cout << "resize is being done" << std::endl;
    }

    //Binary search
    // signed char* binary_search(signed char* first, signed char* last, signed char const key){
    //
    //     signed char* mid;
    //
    //     while (first <= last ){
    //       mid = first + ((last-first)>>1);
    //
    //       if (key == *mid) break;
    //       else if (key < *mid) last = mid -1 ;
    //       else if (*mid <key) first = mid+1 ;
    //     }
    //     return mid;
    // }

    // IMPLEMENT ME: AFTER INSERT COMPLETES THE ARRAY MUST BE IN ASCENDING ORDER

    // void mergesort(signed char* first, , int size){
    //
    //
    //   int left_size = size /2 ;
    //
    //   signed char* mid = first + ((last-first)>>1);
    //
    //   signed char* left_temp = new signed char[left_size];
    //   signed char* right_temp = new signed char[size - left_size];
    //
    //   std::copy(first, mid, left_temp);
    //   std::copy(mid+1, first + (size-1), right_temp);
    //
    //   mergesort(left_temp, left_size);
    //   mergesort(right_temp, size - left_size);
    //   merge(first, mid+1, sorted);
    // }

    void insert(signed char c){

        if (capacity_ == size_) resize();

        push_back(c);
        sorted_ = 0 ;
    }

    // void insert(signed char c){
    //
    //     if (capacity_ == size_) resize();
    //
    //     if (size_ == 0 ) push_back(c);
    //
    //     else{
    //       signed char* npos = binary_search(ptr_, ptr_+ (size_-1) , c);
    //         //std::cout <<"npos : " << int(*(npos)) << std::endl;
    //        // std::cout << std::endl;
    //
    //       if ((ptr_+size_-1)==npos && (*npos) <= c){
    //
    //         //std::cout << "corner case: appending at the end  " << std::endl;
    //         *(npos+1) = c;
    //         ++size_;
    //       }
    //       else if( *npos < c){
    //
    //         // std::cout << "general case: not shifting npos " << std::endl;
    //         std::copy(npos+1, ptr_+size_, npos+2);
    //         // for (auto i =(ptr_ + size_ - 1); i != (npos); --i){
    //         //   *(i+1) = *i;
    //         // }
    //         *(npos+1) = c;
    //         ++size_;
    //       }
    //       else{
    //         // std::cout << "general case : shifting npos  " << std::endl;
    //
    //         std::copy(npos, ptr_+size_, npos+1);
    //
    //         // for (auto i =(ptr_ + size_ - 1); i != (npos-1); --i){
    //         //   *(i+1) = *i;
    //         // }
    //         *(npos) = c;
    //         ++size_;
    //       }
    //     }
    // }
    //

private:
    int size_;         // size of the array
    int capacity_;
    signed char* ptr_; // pointer to the array
    bool sorted_;


}; // class sorted_sc_array

#endif // A2_HPP
