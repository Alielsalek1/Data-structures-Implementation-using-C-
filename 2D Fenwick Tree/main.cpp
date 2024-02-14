#include "fenwick2D.h"

int main() {
    fenwick2D ali(5, 3);
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 3; ++j)
            ali.update(i, j, j);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << ali.query(i, j, i, j) << " ";
        cout << "\n";
    }
    return 0;
}
