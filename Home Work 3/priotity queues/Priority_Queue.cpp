/*
    CH08-320143
    a3_p6.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de

A priority Queue using vector as a container.
Sorts the elements in decreasing order by allowing prime numbers in the list to
appear before any other (even bigger) non- Prime nummber

*/

#include <queue>
#include <iostream>
using namespace std;

//function to test if given number is a prime number
bool isPrime(int n)
{
   if( n < 2){
   	return false;
   }

    for (int i = 2 ; i <=  n/2; i++)
    {
        if(n % i  == 0)
            return false;
    }

    return true;
}

//sorts the array in in decreasing order with high priority for prime numbers
struct Compare
{
    bool operator()(const int b,const int a)
    {
        if (isPrime(a) && isPrime(b)) //if a and b are both prime
        {
            return a > b; //then take the largest of them
        }
        else if(isPrime(a))  //if a is prime, a is the bigest
        {
            return true;
        }
        else if (isPrime(b))  //if b is prime, b is largest
        {
            return false;
        }
        else   //neither number is prime, use normal comparison
        {
            return a > b;
        }
    }
};

int main()
{
    priority_queue<int,vector<int>,Compare> P_Queue;

    //Add elements to queue
    for(int n :{1 , 7 , 8, 4, 11, 17,56,0, -17 , 16, 7})
        P_Queue.push(n);

    // Size of Queue
    cout<< "Number of element " <<P_Queue.size()<<endl;

    //Access Top element
    if(isPrime(P_Queue.top()))
        cout<<"/> Greatest prime number in Queue "<< P_Queue.top()<<endl;

    //Print priority queue
    cout<<"Elements in priority Queue :"<<endl;

    while(!P_Queue.empty())
    {
        cout<<P_Queue.top()<<" ";
        P_Queue.pop();
    }
    cout<<endl;

    return 0;
}
