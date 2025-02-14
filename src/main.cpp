#include "List.h"
#include <iostream>

using std::cout, std::endl;


int main(){

    //create new object:
    List<int> L(4,5);
    List<int> l2 = std::move(L);
    List<int>::iterator i = l2.begin();
    if(++(--l2.end()) == l2.end()){
        cout << 1;
    }
    return 0;
}