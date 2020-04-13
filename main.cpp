#include <iostream>
#import "LinkedList.h"

using namespace utec;

int main() {
    CLinkedList ll;
    CLinkedList ll2;
    for ( auto i = 0 ; i < 8 ; ++i )
        ll.push_back(i);
    for ( auto i = 0 ; i < 8 ; i += 2 )
        ll2.push_back(i);
    std::cout << ll.complete_list() << std::endl;
    std::cout << ll2.complete_list() << std::endl;
    ll = ll2;
    std::cout << ll.complete_list() << std::endl;
}