#include <iostream>
#include <concepts>

template <typename T>
requires std::integral<T>
T add(T a,T b){
return a+b;
}

int main(){
     std::cout << "Hello from c++20 with cmake"<<std::endl;
     std::cout << "the sum is : "<<add(7,5)<< std:: endl;
 
 return 0;
} 