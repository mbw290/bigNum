#include<iostream>
#include <sstream>
#include <math.h> 
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
/* Matthew Wimpelberg and Rob Mancuso
 * Aribitrary Precision Calculator
*/ 

//Linked list of integers that when combined will form a big number entered by the user
class bigNum
{
  public:
    vector<int> list;
};

//we need a link to point to the list of integers and the next item something to hold the list and methods to add to the list and remove etc.
class Link
{
  public:
//First and last pointer to go through list when necessary
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

//Add a whole list of ints from a vector to the given linkedlist

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

//Similar to add, but it makes sure to add after the last node by looping through and making a new node after the last
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

//Remove an entire list function just in case

  void RemoveList()
  {
   delete First->bNum;
   First=First->Next;
  }

//Remove the entire linked list

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

//Return a vector and remove it from the list and point to the next one to be popped

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


//Feed in two integer vectors of big numbers and return the sum in a vector

vector<int> Add(vector<int> num1, vector<int> num2)
{
    vector<int> ans;
    int carryBit, sum;
    unsigned long max;
//Check which number is larger to place the smaller number underneath the larger using the grade school algorithm
    if(num1.size() > num2.size())
    {
        max = num1.size();
    }
    else
    {
        max = num2.size();
    }
//Fill up the vectors with 0s to make sure that they will be added properly
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

//Add each pair of digits together and push them into an answer vector

        sum = num1.at(i) + num2.at(i);
        ans.push_back(sum);
    }

//Check the answer vector for any values over 10 and divide to find the number to carry to the next 10s place

    for(unsigned long j = ans.size(); j > 0; j--)
    {
        if(j == 0)
        {
            if(ans[j] >= 10)
            {
                carryBit = ans[j]/10;
                ans[j] = ans[j]-10;
                ans[j-1]=ans[j-1]+carryBit;
                ans.insert(ans.begin(), carryBit);
            }
        }
     
    }
    return ans;
}

//Simply loop through the vector printing each integer next to the previous to appear like one big number

void Display(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
}

//To multiply two numbers, we will feed in two vectors and return one

	vector<int> multiply(vector<int> num1, vector<int> num2)
	{
		vector<int> temp1,temp2;
	        //Find the larger number
        	if(num1.size() > num2.size())
    		{
        	num1=temp1;num2=temp2;
		num1=temp2;
		num2=temp1;
    		}
	//Setup vectors to hold answer
	vector<int> ans;
	int res,min,max,count;
	int jcount=0;
	int icount=0;
	//Linked list that will hold vectors given that the number of vectors vary on the amount of digits in the smaller number
	LinkedList LL;
	vector<int> temp;
	//Populate the vectors accounting for adding trailing 0s 
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
		//Add vector of the results  one digit of the smaller number to all of the larger to be added later
		LL.AddList(temp);
		count++;
		//Clear temp to be used again in the next iteration
		temp.clear();
        	}
		ans=LL.pop();

		//Add each line after multiplication to produce a final vector		

		for (int k=0;k<count-1;k++)
		{
		ans=Add(ans,LL.pop());
		}
	return ans;
	}



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
result=multiply(v2,v1);
Display(result);
return 0;
}
