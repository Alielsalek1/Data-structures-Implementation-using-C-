#include <bits/stdc++.h>
#include "Singlist.cpp"
using namespace std;

int main() {
    //test
    Singlist<int> lst;
    lst.insert_front(0);
    lst.insert_front(1);
    lst.insert_front(2);
    lst.insert_back(10);
    for (auto i : lst) cout << i << " ";
    cout << "\n";
    lst.insert_front(999);
    lst.pop_front();
    lst.insert_back(11);
    lst.pop_back();
    lst.insert_back(11);
    lst.insert_front(999);
    for (auto i : lst) cout << i << " ";
    lst.reverse();
    cout << "\n";
    for (auto i : lst) cout << i << " ";
    cout << "\n" << lst.length() << " " << lst.empty() << "\n";
    Singlist<int> temp;
    temp = lst;
    temp.pop_back();
    temp.reverse();
    cout << temp.length() << "\n";
    for (auto i : temp) cout << i << " ";
    cout << "\n";
    for (auto i : lst) cout << i << " ";
    cout << "\n\n";
    lst.insert_at(5, 2);
    temp.remove_at(3);
    cout << "\n";
    for (auto i : lst) cout << i << " ";
    cout << "\n";
    for (auto i : temp) cout << i << " ";
    return 0;
}
