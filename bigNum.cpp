#include<iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class bigNum
{
public:
    int digit;
};
bool check(vector<int> num1, vector<int> num2)
{
    bool test;
    if(num1.size() !=0 || num2.size()!= 0)
    {test = true;}
    else
    {test = false;}
    return test;
}

void Add(vector<int> num1, vector<int> num2, vector<int> ans)
{
    int carryBit;
    for(int i = 0; check(num1, num2) == true; i++)
    {
        ans[i] = num1[i] + num2[i];
    }
    for(unsigned long j = ans.size(); j > 0; j--)
    {
        if(ans[j+1] != NULL)
        {
            if(ans[j] > 10)
            {
                carryBit = ans[j]%10;
                ans[j] -= 10;
                ans[j+1] += carryBit;
            }
        }
    }
}
int main()
{
    
}
