#include <iostream>
#include "mylist.h"
#include <string>

using namespace std;


int main (){

    List s;
    s.push_back("apple");
    s.push_back("pear");
    s.push_back("banana");

     s.print();

     cout << endl;

    s.swap_nodes();

    s.print();


    return 0;
}




