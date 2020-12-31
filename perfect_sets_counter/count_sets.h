#ifndef COUNT_SETS_H
#define COUNT_SETS_H

#include <binary_conv.h>
using namespace std;

class count_sets
{
public:
    count_sets();

    int k;
    int size_of_set;
    vector<int> rank;
    vector<int> value;
    vector<int> base_set;
    vector<int> uncond_indeces;
    int maxElement;
    int counter = 0;

    void input_values();
    int count_perfect_sets();
    void apply_initial_conditions();
    bool verifyXOR(vector<int> test_set);
    bool myFind(vector<int> test_set, int XOR_value);
    void outVec(vector<int> test_set);


};

#endif // COUNT_SETS_H
