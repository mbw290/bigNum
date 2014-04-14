#include<iostream>
#include <sstream>
#include <math.h> 
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class bigNum
{
  public:
    vector<int> list;
};

//we need a link to point to the puppy and the next item
//something to hold the list and methods to add to the list and remove etc.
class Link
{
  public:
   bigNum *bNum;
   Link *Next;
   Link *Last;
};

class LinkedList
{
  private:
    Link *First;	
    Link *Last;
  public:
    LinkedList()
    {
      First = NULL;
    }

   void AddList(vector<int> x)
   {
     Link *newLink = new Link;
     bigNum *newNum = new bigNum;
     //bignum pointer is now pointing to our new bignum
     newLink->bNum=newNum;
     newNum->list=x;
     newLink->Next=First; //makes next null
     First=newLink;
  }

   void AddListEnd(vector<int> x)
   {
     Link *lastItem=new Link;
     Link *newNode=new Link;
     bigNum *newNum = new bigNum;
     lastItem=First;
       while (lastItem->Next != NULL)
       {
         lastItem=lastItem->Next;
       }
       lastItem->Next=newNode;
       newNode->bNum=newNum;
       newNum->list=x;
       newNode->Next=NULL; 
    }

  void RemoveList()
  {
   delete First->bNum;
   First=First->Next;
  }

  void RemoveLList(LinkedList LL)
  {
     Link *current=new Link;
     Link *temp = new Link;
     current=First;
       while (current != NULL)
       {
       temp=current->Next; 
       delete current->bNum;
       delete current;
       current=temp;
       }
    delete current->bNum;
    delete current;
  } 


	vector<int> pop()
        {
        vector<int> val = First->bNum->list; // store value to return
        Link *temp = First; // remove card from deck
        if(First == Last)
        {
            First = NULL;
            Last = NULL;
        }
        else
            First = First->Next;
        delete temp;
        return val; //card goes into play
        }


};

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


class Multiply
{
public:
	vector<int> multiply(vector<int> num1, vector<int> num2)
	{
		vector<int> temp1,temp2;
	
        	if(num1.size() > num2.size())
    		{
        	num1=temp1;num2=temp2;
		num1=temp2;
		num2=temp1;
    		}
	vector<int> vResult,ans,ans1,ans2;
	int res,min,max,count;
	int jcount=0;
	int icount=0;
	LinkedList LL;
	vector<int> temp;
		for (int i=0; i<num1.size();i++)
        	{
			
				if (i>0)
				{
					for (int z=0; z<i;z++)
					{
					temp.insert(temp.begin(),0);
					}
				}
                	for (int j=0;j<num2.size();j++)
                	{
			cout << num1[i] << " times " << num2[j] << "\n";
                	res=num1[i]*num2[j];
			temp.insert(temp.begin(),res);
                	}
		LL.AddList(temp);
		count++;
		temp.clear();
        	}
		ans=LL.pop();
		for (int k=0;k<count-1;k++)
		{
		ans=Add(ans,LL.pop());
		}
	return ans;
	}

	void Display(vector<int> v)
	{
	
	std::ostringstream ostr;
	int result;
	string printme;
    		for(int i = 0; i < v.size(); i++)
    		{
		result=v[i];
		cout << result;
        	//ostr<<result;
    		}
	cout << "DONE" << "\n";
	}	
};
int main()
{
vector<int> v1;
vector<int> v2;
vector<int> result;

v1.push_back(0);
v1.push_back(0);
v1.push_back(0);
v1.push_back(2);
v1.push_back(1);
v2.push_back(3);
v2.push_back(2);
v2.push_back(6);
v2.push_back(2);
v2.push_back(2);
Multiply m;
result=m.multiply(v1,v2);
m.Display(result);
return 0;
}
