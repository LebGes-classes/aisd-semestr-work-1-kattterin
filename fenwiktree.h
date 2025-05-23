#ifndef FENWIKTREE_H
#define FENWIKTREE_H

#include <vector>

using namespace std;

class FenwikTree {
public:
    FenwikTree(int size);

    void update(int index, int x); 
    int sum(int index);             
    int rangeSum(int l, int r);     

private:
    vector<int> tree;
    int size;

};

#endif // FENWIKTREE_H