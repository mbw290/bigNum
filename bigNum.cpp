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

vector<int> Subtract(vector<int> num1, vector<int> num2)
{
    vector<int> ans;
    int difference;
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
        difference = num1.at(i) - num2.at(i);
        if(difference < 0)
        {
            if(i == 0)
            {
                ans.push_back(difference);
            }
            else
            {
                difference+=10;
                ans.at(i-1)--;
                ans.push_back(difference);
            }
        }
      
    }
    return ans;
}

vector<int> Add(vector<int> num1, vector<int> num2)
{
    vector<int> ans;
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
//negative numbers?
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
            if(ans[j] >= 10)
            {
                carryBit = ans[j]/10;
                ans[j] = ans[j]-10;
                ans[j-1]=ans[j-1]+carryBit;
                //ans.insert(ans.begin(), carryBit);
            }
        }
        else
        {
            
            if(ans[j] >= 10)
            {
                carryBit = ans[j]/10;
                ans[j] = ans[j]-10;
                ans[j-1] = ans[j-1]+carryBit;
            }
        }
    }
    return ans;
}

void Display(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}




vector<int> Multiply(vector<int> num1, vector<int> num2)
{
    vector <vector<int>> list;
    vector<int> ans;
    vector<int> prod;
    int result;
    for (int i = 0; i < num1.size(); i++)
    {
        prod.clear();
        for(int j = 0; j < num2.size(); j++)
        {
          
            result = num1.at(i) * num2.at(j);
            prod.push_back(result);
        }
        for(int k = 0; k < i; k++)
        {
            prod.push_back(0);
        }
        Display(prod);
        list.push_back(prod);
        
    }
    
    for(int p = 0; p < list.size()-1; p++)
    {
       if(p == 0)
       {
          ans = Add(list.at(0), list.at(1));
       }
       else
       {
        ans = Add(ans, list.at(p+1));
       }
        
    }
    
    return ans;
}

int main()
{
    string strA, strB;
    int enter1,enter2;
    vector<int> num1, num2, ans; //num1 vector, num2 vector, answer vector
    
    cout << "Please enter the first number: " << endl;//input first num
    cin >> strA;
    for(int i = 0; i < strA.size(); i++)
    {
        enter1=(int)strA[i]-48;
        num1.push_back(enter1);
    }
    cout << "Please enter the second number: " << endl;//input second num
    cin >> strB;
    for(int i = 0; i < strB.size(); i++)
    {
        enter2=(int)strB[i]-48;
        num2.push_back(enter2);//fill vector 2
    }
    ans= Multiply(num1,num2);
   // cout << "1--------"<<endl;
   // Display(num1);
   // cout << "\n2--------"<<endl;
   // Display(num2);
   // cout << "\n3--------"<<endl;
    cout << "\n";
    
    Display(ans);
    cout << "\n";
    
}
