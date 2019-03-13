/*
    CH08-320143
    a2_p4.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de

                 Doubly Linked List
        ----<----<---<-----------------
back -> \ 0 \ 1 \ 2 \  ....       \ n \  <-front
        ___>____>___>_____________>____
                                    ^
                                  count

*/
#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node *previous;
    Node(T info)
    {
        data  = info;
        next = previous = NULL;
    };
};

template<class T>
class DoubleLinked
{
private:
    Node<T> *front;
    Node<T> *back;
    int count;
public:
    DoubleLinked();
    DoubleLinked(T);
    ~DoubleLinked();

    void push_front(T);	//Add to front of list
    void push_back(T);	//add to end of list
    T pop_front();	//Show and removes the first (front) element
    T pop_back();	//Show and removes the end (back) element
    int getSize();	//Number of elements in list
    T getfront();	//returns first element
    T getback();	//Returns last/end element

    void Print();	/*Not required, but included for illustrating the results
    			of the other methodes*/

};

template<class T>
DoubleLinked<T>::DoubleLinked()
{
    front = back = NULL;
    count = 0;
}

template<class T>
DoubleLinked<T>::DoubleLinked(T info)
{
    Node<T>  *new_node = new Node<T> (info);
    front = back = new_node;
    count = 1;
}

template<class T>
DoubleLinked<T>::~DoubleLinked()
{
    Node<T> *temp,*del;
    temp = back;
    while(temp !=NULL)//Free space allocated to the remaining list
    {
        del = temp;
        temp = temp->previous;
        delete del;
    }
}

template<class T>
void DoubleLinked<T>::push_front(T info)
{
    Node<T>  *new_node = new Node<T> (info);
    if(front == NULL)//List empty
    {
        front = new_node;
        back = front;
    }
    else
    {
        //Link new element to its predecessor
        new_node -> next = front;
        front->previous = new_node;
        front = new_node;
    }
    count++;
}
template <class T>
void DoubleLinked<T>::push_back(T info)
{
    Node<T> *new_node = new Node<T> (info);
    if (front == NULL)//List empty
    {
        front = new_node;
        back = front;
    }
    else
    {
        //Link new element to its sucessor

        back->next = new_node;
        new_node->previous = back;
        back =new_node;
    }
    count++;
}

template <class T>
T DoubleLinked<T>::pop_front()
{
    Node<T> *temp;//element to delete
    T info;	//value of deleted element
    info = front -> data;
    temp = front;
    front = front->next; //update front element
    front->previous = NULL;
    count--;
    delete temp;
    return info;
}
template <class T>
T DoubleLinked<T>::pop_back()
{
    Node<T> *temp;//to be deleted
    T info;	//return value
    info = back -> data;
    temp = back;
    back = back->previous;//update back element
    back -> next = NULL;
    count--;
    delete temp;
    return info;

}
template <class T>
int DoubleLinked<T>::getSize()
{
    return count;
}

template <class T>
T DoubleLinked<T>::getfront()
{
    return front->data;
}

template <class T>
T DoubleLinked<T>::getback()
{
    return back->data;
}
/*________________________________END________________________________________*/

template <class T>
void DoubleLinked<T>::Print()
{
    Node<T> *temp;
    temp = back;
    while(temp !=NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->previous;
    }
    cout<<endl;
}
