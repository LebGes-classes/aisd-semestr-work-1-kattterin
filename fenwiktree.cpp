#include "fenwiktree.h"

FenwikTree::FenwikTree(int size) :
    size(size),
    tree(size + 1, 0) {}

void FenwikTree::update(int index, int x) {
    index++;
    while (index <= size) {
        tree[index] += x;
        index += index & -index;
    }
}

int FenwikTree::sum(int index) {
    index++;
    int summa = 0;
    while (index > 0) {
        summa += tree[index];
        index -= index & -index;
    }
    return summa;
}

int FenwikTree::rangeSum(int l, int r) {
    return sum(r) - sum(l - 1);

}

