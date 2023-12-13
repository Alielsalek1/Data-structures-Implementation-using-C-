#include <iostream>
#include "Doublist.cpp"
using namespace std;

int main() {
    Doublist<int> ali;
    ali.insert_back(5);
    ali.pop_front();
    ali.insert_front(1);
    ali.pop_back();
    ali.insert_front(2);
    ali.insert_back(8);
    ali.pop_back();
    return 0;
}
