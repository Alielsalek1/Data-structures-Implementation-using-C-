#include "Dynamic_array.h"

int main() {
    Dynamic_array<int> dd(2);
    dd[0] = 5, dd[1] = 4;
    for (int i = 0; i < dd.size(); ++i) cout << dd[i] << " ";
    dd.push_back(20);
    dd.reverse();
    cout << "\n" << dd.size() << "\n" << dd.capacity() << "\n";
    for (int i = 0; i < dd.size(); ++i) cout << dd[i] << " ";
    return 0;
}
