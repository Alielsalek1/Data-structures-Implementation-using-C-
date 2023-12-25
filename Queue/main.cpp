#include "Queue.h"

int main() {
    Queue<int> qq;
    qq.enqueue(5);
    qq.enqueue(4);
    qq.enqueue(3);
    qq.enqueue(2);
    qq.enqueue(1);
    cout << qq.size() << "\n";
    while (!qq.empty()) {
        cout << qq.front() << " ";
        qq.dequeue();
    }
    return 0;
}
