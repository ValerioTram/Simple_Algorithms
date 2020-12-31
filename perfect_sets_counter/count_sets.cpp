#include "count_sets.h"

count_sets::count_sets()
{
    input_values();
    apply_initial_conditions();
    count_perfect_sets();
}

void count_sets::input_values()
{
    k = 2;
    size_of_set = pow(2,k);
    //Between 1 and 50 elements
    //rank value between 0 and 2^k-1
    //value value between 0 and 1e9
    rank = {3,4,1};
    value = {1,5,2};

    if(rank.size() != value.size())
    {
        cout<<"Wrong input!"<<endl;
        exit(1);
    }
}

int count_sets::count_perfect_sets()
{
    vector<int> test_set = base_set;

    for(int m = 0; m<maxElement; ++m)
    {
        for (int i = 0; i<uncond_indeces.size(); ++i)
        {

            test_set[uncond_indeces[i]]++;
            test_set[uncond_indeces[i+1]] = 0;

            if(i<uncond_indeces.size() - 1)
            {
                for(int j=0; j<maxElement - 1; ++j)
                {
                    test_set[uncond_indeces[i+1]]++;

                    if(verifyXOR(test_set))
                    {
                        if(is_sorted(test_set.begin(),test_set.end()))
                        {
                            counter++;
                            outVec(test_set);
                        }
                    }
                }
            }
        }

    }


    cout<<"The number of perfect sets is: "<<counter<<endl;

   return 1;
}


void count_sets::apply_initial_conditions()
{
    //This function creates the base set with the initial conditions satisfied:
    //1) Size of the set is 2^k
    //2) For every i, base_set[rank[i]] = value[i]
    //3) base_set[0] = 0

    for(int i = 0; i<size_of_set; ++i)
    {
        base_set.push_back(0);
    }

    int r_size = rank.size();

    for (int i = 0; i<r_size; ++i)
    {
        int r_index = rank[i];
        base_set[r_index] = value[i];
    }

    maxElement = *max_element(base_set.begin(),base_set.end());

    //The unconditioned indices are those indices that are not touched by the initial conditions

    for (int i = 1; i<base_set.size(); ++i)
    {
        if(base_set[i] == 0)
            uncond_indeces.push_back(i);
    }

}

bool count_sets::verifyXOR(vector<int> test_set)
{
    int test_size = test_set.size();
    int XOR_value = 0;

    for (int i = 1; i<test_size; ++i)
    {
        for (int j = 1; j<test_size; ++j)
        {
            if(i!=j)
                XOR_value = (test_set[i] | test_set[j]) & (~test_set[i] | ~test_set[j]);
            else
                XOR_value = 0;

            bool isPresent = myFind(test_set, XOR_value);

            if(!isPresent)
            {
                return false;
            }
        }

    }

    return true;
}


bool count_sets::myFind(vector<int> test_set, int XOR_value)
{
    for (int i=0; i<test_set.size(); ++i)
    {
        if(test_set[i] == XOR_value)
            return true;
    }

    return false;
}

void count_sets::outVec(vector<int> test_set)
{
    for(int i =0; i<test_set.size();++i)
    {
        cout<<test_set[i]<<" ";
    }

    cout<<endl;
}
