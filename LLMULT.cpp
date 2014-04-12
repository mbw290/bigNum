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
};

class LinkedList
{
  private:
    Link *First;
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
	vector<int> vResult;
	int res,min,max,count;
	int jcount=0;
	int icount=0;
	LinkedList LL;
	vector<int> temp;
		for (int i=0; i<num1.size();i++)
        	{
                	for (int j=0;j<num2.size();j++)
                	{
			cout << num1[i] << " times " << num2[j] << "\n";
                	res=num1[i]*num2[j];
				if (i>0)
				{
				res=res*pow(10,icount);
				icount++;
				}
				if (i==0)
				{
					if (j>0)
					{
					res=res*pow(10,jcount);
					jcount++;
					}
				}
			temp.push_back(res);
                	}
		LL.AddList(temp);
        	}
	return temp;
	}

	void Display(vector<int> v)
	{
	
	std::ostringstream ostr;
	int result;
	string printme;
    		for(int i = 0; i < v.size(); i++)
    		{
		result=v[i];
		cout << result <<"\n";
        	ostr<<result;
    		}
	}	
};
int main()
{
vector<int> v1;
vector<int> v2;
vector<int> result;
v1.insert(v1.begin(),1);
v1.insert(v1.begin(),0);
v1.insert(v1.begin(),0);
v2.insert(v2.begin(),2);
v2.insert(v2.begin(),3);
Multiply m;
result=m.multiply(v1,v2);
m.Display(result);
return 0;
}
