#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack p(StackContainer::List);
    for (size_t i = 0; i < 9; i++)
    {
        p.push(i);
        cout << p.top() << " ";
    }
    cout << endl;
    p.pop();
    cout << p.top() << endl;
    p.push(8); p.push(9);
     cout << p.top() << endl;

        p.pop();
     Stack c;
     cout << &c << " " << &p << endl;
     c = p;
    c.push(0);
     cout << "ok" << endl;
     p.pop();

     cout << c.top() << endl;

     cout << "ok" << endl;

    return 0;

}
