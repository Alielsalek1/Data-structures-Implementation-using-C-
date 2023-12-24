#include "Stack.h"
using namespace std;

int main() {
    Stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    st.push(0);
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
