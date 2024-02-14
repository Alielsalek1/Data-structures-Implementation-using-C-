#include "fenwick.h"

int main() {
    fenwick ali(10);
    for (int i = 0; i < 10; ++i) {
        ali.update(i, i + 1);
    }
    for (int i = 1; i < 10; ++i) {
        cout << ali.query(i, i) << " ";
    }
    return 0;
}
