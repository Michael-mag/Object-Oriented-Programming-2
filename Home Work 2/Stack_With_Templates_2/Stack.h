/*
    CH08-320143
    a2_p3.cpp
    MICHAEL MAGAISA
    m.magaisa@jacobs-university.de
Template Stack;
*/

template <class T>
class Stack
{
private:
    int size; //number starting at 1
    T *data;
    int top; //index starting at 0

public:
    //Constructors
    Stack();
    Stack(const Stack&);
    Stack(int );
    ~Stack();

    //Methods
    bool push(T );
    bool pop(T& );
    T back (void);
    int getNumEntries(void);
    void resize(int);
    int getSize();
};

//Stack.cpp
template <class T>
Stack<T>::Stack()
{
    size = 10;
    data = new T[size];
    top = -1;
}

template< class T>
Stack<T>::Stack(const Stack& S)
{
    size = S.size;
    data = new T[size];
    int i;
    for ( i = 0; i < size; i++)
        data[i] = S.data[i];
    top = S.top;
}
template <class T>
Stack<T>::Stack(int n)
{
    size = n;
    data = new T[n];
    top = -1;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] data;
}

template <class T>
bool Stack<T>::push(T elem)
{
    if(top == size -1)
        return false;
    top++;
    data[top] = elem;
    return true;
}
template <class T>
bool Stack<T>::pop(T& out)
{
    if (top == -1)
        return false;

    out = data[top];
    top--;
    return true;
}

template <class T>
T Stack<T>::back(void)
{
    return data[top];
}

template <class T>
int Stack<T>::getNumEntries()
{
    return top+1;
}

template <class T>
void Stack<T>::resize(int new_size)
{
    T *data2 = new T[new_size];
    int i, delta = top - new_size+1;
    if(new_size == size)
    {
    }
    else if (new_size < top+1)
    {
        for(i = 0; i <new_size; i++)
        {
            data2[i] = data[delta + i];
        }
        top = new_size-1;
    }
    else
    {

        for (int i = 0; i <= top; i++)	// copy the old elements
            data2[i] = data[i];
    }
    delete[] data;
    data = data2;
    size = new_size;
}
template <class T>
int Stack<T>:: getSize()
{
    return size;
}
