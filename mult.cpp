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

vector<int> mult(vector<int> num1, vector<int> num2)
{
    vector<int> ans;
    int carryBit, product;
    unsigned long max,min;
    int j=0;
    if(num1.size() > num2.size())
    {
        max = num1.size();
	min=num2.size()
    }
    else
    {
        max = num2.size();
	min = num1.size();
    }
	for (int i=0; i<min;i++)
	{
		while (j<max.size())
		{
		min[i]*max[j];
		j++;
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

int main()
{
    string strA, strB;
    int enter1,enter2;
    int digit;
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
    ans=mult(num1,num2);
    cout << "1--------"<<endl;
    Display(num1);
    cout << "\n2--------"<<endl;
    Display(num2);
    cout << "\n3--------"<<endl;
    Display(ans);
    cout << "\n";
    
}
