#include "priority_queue.h"
using namespace std;

int main() {
    PQ<int> pq;
    pq.insert(10), pq.insert(5), pq.insert(0), pq.insert(0), pq.insert(0), pq.insert(8), pq.insert(10);
    cout << "size : " << pq.size() << "\n";
    while (!pq.empty()) {
        cout << pq.top() << "\n";
        pq.poll();
    }
    return 0;
}
