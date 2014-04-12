#include<iostream>
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

class Multiply
{
public:
	vector<int> multiply(vector<int> num1, vector<int> num2)
	{
	vector<int> vResult;
	int res,min,max;
	LinkedList LL;
	vector<int> temp;
		for (int i=0; i<num1.size();i++)
        	{
                	for (int j=0;j<num2.size();j++)
                	{
                	res=num1[i]*num2[j];
			vResult.push_back(res);
                	temp.push_back(res);
                	}
		LL.AddList(temp);
        	}
	return vResult;
	}

	void Display(vector<int> v)
	{
    		for(int i = 0; i < v.size(); i++)
    		{
        	cout << v[i] << "\n";
    		}
	}	
};
int main()
{
vector<int> v1;
vector<int> v2;
vector<int> result;
v1.push_back(1);
v1.push_back(2);
v2.push_back(2);
v2.push_back(3);
Multiply m;
result=m.multiply(v1,v2);
m.Display(result);
return 0;
}
