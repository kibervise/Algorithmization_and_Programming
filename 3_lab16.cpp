#include <iostream>
using namespace std;

struct stack
{
    int data;
    stack *next;
};

void PushEl(stack *&head, int data)
{
    stack *elem = new stack;
    elem->data = data;
    elem->next = head;
    head = elem;
}

int PopEl(stack *&head)
{
    int elem = head->data;
    stack *hpos = head;
    head = head->next;
    delete hpos;
    return elem;
}

void RandNum(stack *&head, int n)
{
    for (int i = 0; i < n; i++)
    {
        int elem = rand() % 101;
        PushEl(head, elem);
    }
}

void Action()
{
    int num, p, sum = 0;
    
    cout << "Enter number of elements: ";
    cin >> num;
    
    stack *firststack = new stack;
    firststack->next = NULL;
    
    stack *secondstack = new stack;
    secondstack->next = NULL;
    
    RandNum(firststack , num);
    
    cout << "Elements of I stack: ";
    for(int i = 0; i < num; i++)
    {
        p = PopEl(firststack);
        cout << p << " ";
        PushEl(secondstack, p);
        sum += p;
    }
    int av_value = sum/num;
    cout << endl << "Average value: " << av_value << endl;
    
    stack *thirdstack = new stack;
    thirdstack->next = NULL;
    
    cout << "Elements of II stack: ";
    for (int i =0; i < num; i++)
    {
        p = PopEl(secondstack);
        if(p > av_value)
        {
            PushEl(thirdstack, p);
            cout << p << " ";
        }
    }
    cout << endl;
    
    delete firststack ;
    delete secondstack;
    delete thirdstack;
}

int main()
{
    Action();
}


