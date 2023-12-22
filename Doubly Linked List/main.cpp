#include "Doublist.h"
using namespace std;

int main() {
    Doublist<int> ali;
    ali.insert_back(5);
    ali.insert_front(1);
    ali.insert_front(2);
    ali.insert_back(8);
    ali.remove_at(1);
    ali.insert_at(1, 1);
    for (auto &i : ali) cout << i << " ";
    ali.reverse();
    cout << "\n";
    for (auto &i : ali) cout << i << " ";
    cout << "\n" << ali.empty() << " " << ali.length();
    return 0;
}
