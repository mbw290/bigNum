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
    int carryBit, sum;
    unsigned long max;
    if(num1.size() > num2.size())
    {
        max = num1.size();
    }
    else
    {
        max = num2.size();
    }
    for(int i = 0; i < max; i++)
    {
        if(num1.size() < num2.size())
        {
            num1.insert(num1.begin(), 0);
        }
        if(num2.size() < num1.size())
        {
            num2.insert(num2.begin(), 0);
        }
        sum = num1.at(i) + num2.at(i);
        ans.push_back(sum);
    }
    for(unsigned long j = ans.size(); j > 0; j--)
    {
        if(j == 0)
        {
            if(ans[j] > 10)
            {
                carryBit = ans[j]%10;
                ans[j] -= 10;
                ans.insert(ans.begin(), carryBit);
            }
        }
        else
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

void Display(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}

int main()
{
    string strA, strB;
    int digit;
    vector<int> num1, num2, ans; //num1 vector, num2 vector, answer vector
    
    cout << "Please enter the first number: " << endl;//input first num
    cin >> strA;
    for(int i = 0; i < strA.size(); i++)
    {
        num1.push_back(static_cast<int>(strA[i])-48);
    }
    cout << "Please enter the second number: " << endl;//input second num
    
    cin >> strB;
    for(int i = 0; i < strB.size(); i++)
    {
        num2.push_back(static_cast<int>(strB[i])-48);//fill vector 2
    }
    cout << "1--------"<<endl;
    Display(num1);
    cout << "\n2--------"<<endl;
    Display(num2);
    Add(num1, num2, ans);
    cout << "\n3--------"<<endl;
    Display(ans);
    
}
