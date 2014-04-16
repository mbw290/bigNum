#include<iostream>
#include <sstream>
#include <math.h> 
#include <stdio.h>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>

using namespace std;
/* Matthew Wimpelberg and Rob Mancuso
 * Arbitrary Precision Calculator
*/ 

void Display(vector<int>);

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
 void llDisplay() 
  { 
   Link *current=First; 
   while (current != NULL) 
   { 
     Display(current->bNum->list);
     current = current->Next; 
   } 
  }


};


//Check which number is bigger to make sure that the algorithms perform the proper operations based on larger and smaller numbers
bool isBigger(vector<int> v1, vector<int> v2)
{
    bool big = false;
    if(v1.size() > v2.size())
    {
        big = true;
    }
    else if(v1.size() == v2.size())
    {
        for(int i = 0; i < v1.size(); i++)
        {
            if(v1[i] > v2[i])
            {
                big = true;
            }
            else if(v1[i] < v2[i])
            {
                big = false;
            }
        }
    }
    else
    {
        big = false;
    }
    return big;
}



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
    for(int i = 0; i<v.size(); i++)
    {
        cout << v[i];
    }
}

//To multiply two numbers, we will feed in two vectors and return one

	vector<int> multiply(vector<int> num1, vector<int> num2)
	{
		vector<int> temp1,temp2;
	        //Find the larger number
	        bool big=isBigger(num1,num2);
        	if(big==true)
    		{
        	temp1=num1;temp2=num2;
		num2=temp1;
		num1=temp2;
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

vector<int> Subtract(vector<int> num1, vector<int> num2)
{
    vector<int> ans,ans1;
    int difference;
    unsigned long max;
	//Check for larger number
    bool big = isBigger(num1,num2);
    if(big==true)
    {
        max = num1.size();
    }
    else
    {
        max = num2.size();
    }
	//Fill the smaller numbers with 0 for ease
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
	//If the difference is < 0 we need to carry by adding 10 and removing 10 from the previous term
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
	//If its not less than 0 just push it
	else
	{
	ans.push_back(difference);
	}
      
    }
    if (ans[0] <0)
    {
	cout << "THIS CALCULATOR DOES NOT HANDLE NEGATIVES" << "  PLEASE REVERSE THE ORDER OF YOUR NUMBERS \n";
	return ans1;
    }
    return ans;
}

LinkedList Divide(vector<int> v1,vector<int> v2)//make this return a linked list. first node is quotient, second node is the remainder
{
    LinkedList ans;
    vector<int> temp = v2;
    vector<int> result;
    int quotient;
    vector<int> quot;
    vector<int> remainder;
    while(isBigger(v1,v2))//while v2 is not bigger than v1, add original v2 to v2
    {
        v2 = Add(v1,v2);
        quotient++;
    }
    remainder = Subtract(v2, temp); // import Subtract method
    quot.push_back(--quotient);
    ans.AddList(quot);
    ans.AddList(remainder);
    
    return ans;
}
vector<int> input()
{
    vector<int> input;
    string str;
    cout << "Please enter your number"<<endl;
    cin >> str;
    int addme;
    for(int i = 0; i < str.size(); i++)
    {
	addme=(int)str[i];
	addme=addme-48;
        input.push_back(addme);
    }
    return input;
}

vector<int> minput()
{
    vector<int> input;
    string str;
    cout << "Please enter your number"<<endl;
    cin >> str;
    int addme;
    for(int i = 0; i < str.size(); i++)
    {
	addme=(int)str[i];
	addme=addme-48;
        input.insert(input.begin(),addme);
    }
    return input;
}

int main()
{
vector<int> v1;
vector<int> v2;
vector<int> result;
char oper;

std::clock_t start;
    double duration;

    start = std::clock();



cout << "Which operation do you wish to perform (+,-,*,/)" << endl;
    cin >> oper;
    LinkedList div;
    switch(oper)
    {
        case '+':
	    v1=input();
	    v2=input();
            result=Add(v1,v2);
            break;
        case '-':
	
	    v1=input();
	    v2=input();
            result=Subtract(v1,v2);
	    break;
        case '*':
	    v1=minput();
	    v2=minput();

            result=multiply(v1,v2);
	    break;
		
        case '/':
                div = Divide(v1,v2);
		div.llDisplay();
        default: return(1);                                                                             
     }


Display(result);
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"This took "<< duration <<'\n';

cout << "\n";
return 0;
}
