#include <bits/stdc++.h>
#include "Singlist.cpp"
using namespace std;

int main() {
    Singlist<int> hehe;
    hehe.insert_front(0);
    hehe.insert_front(1);
    hehe.insert_front(2);
    hehe.insert_back(10);
    for (auto i : hehe) cout << i << " ";
    cout << "\n";
    hehe.insert_front(999);
    hehe.insert_back(11);
    for (auto i : hehe) cout << i << " ";
    cout << "\n" << hehe.length() << " " << hehe.empty() << "\n";
    return 0;
}
