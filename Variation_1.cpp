/*
Optimal Approach
Algorithm / Intuition
We can optimize this calculation by the following observation. 
Assume, given r = 7, c = 4. 
Now, n = r-1 = 7-1 = 6 and r = c-1 = 4-1 = 3
Let’s calculate 6C3 = 6! / (3! *(6-3)!) = (6*5*4*3*2*1) / ((3*2*1)*(3*2*1))
This will boil down to (6*5*4) / (3*2*1)
So, nCr = (n*(n-1)*(n-2)*.....*(n-r+1)) / (r*(r-1)*(r-2)*....1)
                                
Now, we will use this optimized formula to calculate the value of nCr. But while implementing this into code we will take the denominator in the forward direction like: 

(n / 1)*((n-1) / 2)*.....*((n-r+1) / r).
The code will be like the following:


Approach:
The steps are as follows:

First, we will consider r-1 as n and c-1 as r.
After that, we will simply calculate the value of the combination using a loop. 
The loop will run from 0 to r. And in each iteration, we will multiply (n-i) with the result and divide the result by (i+1).
Finally, the calculated value of the combination will be our answer.
*/


#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "n";
    return 0;
}
        
        
