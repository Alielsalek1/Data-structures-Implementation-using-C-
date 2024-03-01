#include "SparseTable.h"

template <typename T>
SparseTable<T>::SparseTable(const vector<T>& v, const function<T(T, T)>& op) : operation(op) {
    this->size = (int)v.size();
    /* getting the highest power of 2 smaller than the size of the vector by:
       31 (total number of bits for integers) subtracted by
       the leading zeros count for the integer */
    this->LG = 31 - __builtin_clz(size) + 1;
    table.resize(size, vector<int>(LG));
    this->operation = op;

    build(v);
}

template <typename T>
void SparseTable<T>::build(const vector<T>& v) {
    for (int j = 0; j < LG; ++j) {
        for (int i = 0; i + (1 << j) - 1 < this->size; ++i) {
            // copying the vector in the first row as (2^0 = 1)
            if (!j) table[i][j] = v[i];
                /* as every row depends on the row above it.
                   the answer to each row is equal to:
                   1 - the block directly above me which represents the next 2^(k-1) blocks
                   2 - in the above row we add 2^(k-1) to get the 2^(k-1) blocks after the first one we got,
                   then we do our operation on the 2 variables we have,
                   then we have our query for 2^k */
            else table[i][j] = operation(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

//assuming the user inputs the ranges in base 0
template <typename T>
T SparseTable<T>::query(int l, int r) {
    if (r < l) swap(l, r);
    int len = r - l + 1; //length for our query
    //getting the highest power of 2 smaller than the len
    int curr_max_LG = 31 - __builtin_clz(len);
    /* let me explain this with an example
       if we have a range with length 6, then to get our query (4 is the highest power of 2 smaller than 6)
       we will get operation( region(l to l + 4), region(r - 4 to r) ). if you notice, there is an area in between
       which overlaps with both regions. surprisingly, this doesn't matter as we run operations
       in which operation(x, x) = x, therefore this overlapped area will not affect our solution,
       and it enables us to have each query answered in O(1) time */
    return operation(this->table[l][curr_max_LG], table[r - (1 << curr_max_LG) + 1][curr_max_LG]);
}