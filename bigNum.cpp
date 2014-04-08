#include<iostream>
#include <stdio.h>
#include <string>
using namespace std;

class bigNum
{
  public:
    int digit;
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

   void AddDigit(int x)
   {
     Link *newLink = new Link;
     bigNum *newNum = new bigNum;
     //bignum pointer is now pointing to our new bignum
     newLink->bNum=newNum;
     newNum->digit=x;
     newLink->Next=First; //makes next null
     First=newLink;
  }

   void AddDigitEnd(int x)
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
       newNum->digit=x;
       newNode->Next=NULL; 
    }

  void RemoveDigit()
  {
   delete First->bNum;
   First=First->Next;
  }

  void RemoveList(LinkedList LL)
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
  
  void Display()
  {
   Link *current=First;
   while (current != NULL)
   {
     cout << "Digit: " << current->bNum->digit << "\n";
     current = current->Next;
   }
  }
};


int main()
{

string strA,strB;
LinkedList num1,num2;
int iValue;
cout << "Please enter the first number: " << "\n"; cin >> strA;
	for (int i=0;i<strA.length();i++)
	{
	iValue=strA[i]-48;
	num1.AddDigit(iValue);
	cout <<  iValue <<"\n";
	}
return 0;
}
