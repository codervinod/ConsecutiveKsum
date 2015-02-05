//
//  main.cpp
//  ConsecutiveKsum
//
//  Created by Vinod Gupta on 2/5/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * Find the largest sum of k consecutive positive integers
 * Input: Array of n positive integers, int k
 * Output: int
 *
 * Example:
 *
 * Input: [1, 7, 4, 3, 11, 15, 2], 3
 * Output: 29
 * 29 because 3 + 11 + 15 is greater than any other consecutive sum of 3 integers
 
 1 + 7 + 4
 7 + 4 + 3
 4 + 3 + 11
 3 + 11 + 15
 
 Input: [50, 50, 50, 1, 2, 3, 4, 5], 3
 Output: 150
 */

int LargestSum(int ar[],int k,int length)
{
    int maxSum = 0,curSum = 0;
    
    for(int i=0;i<k;++i)
        curSum+=ar[i];
    
    maxSum = curSum;
    for(int i=0;k<length;++i,++k)
    {
        curSum += ar[k]-ar[i];
        if(curSum > maxSum)
            maxSum = curSum;
    }
    
    return maxSum;
}

void printArray(int ar[],int len)
{
    for(int i=0;i<len;++i)
        cout<<ar[i]<<"\t";
    
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    int ar[]={1, 7, 4, 3, 11, 15, 2};
    int ar_len = sizeof ar/sizeof(int);
    printArray(ar,ar_len);
    cout<<"Largest sum of consecutive numbers is:"<<LargestSum(ar,3,ar_len)<<endl;
    
    int ar2[]={50, 50, 50, 1, 2, 3, 4, 5};
    int ar2_len = sizeof ar/sizeof(int);
    printArray(ar2,ar2_len);
    cout<<"Largest sum of consecutive numbers is:"<<LargestSum(ar2,3,ar2_len)<<endl;
    
    return 0;
}
