#include "binary_conv.h"


vector<int> dec2bin(int dec_num)
{
    vector<int> bin_num_vec;

    int i = 0;

    while(dec_num>0)
    {
        bin_num_vec.push_back(dec_num%2);
        dec_num = dec_num/2;
        i++;
    }

    return bin_num_vec;
}
