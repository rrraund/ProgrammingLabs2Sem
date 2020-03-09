#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "class.h"

using namespace std;

Stack::Node::Node(int x, Node *y)
{
    value = x;
    pointer = y;
}

Stack::Stack()
{
    top = nullptr;
    max_size = 3;
    count_el = 0;
}

Stack::Stack(Stack &x)
{
    top = x.top;
    max_size = x.max_size;
    count_el = x.count_el;
}

Stack::Stack(int max_size_input)
{
    top = nullptr;
    max_size = max_size_input;
    count_el = 0;
}

Stack::Stack(int max_size_input, stack<int> &x)

{
    top = nullptr;
    max_size = max_size_input;
    count_el = x.size();

    vector <int> temp(max_size);
    for (int i = 0; i < max_size; i++)
    {
        temp[i] = x.top();
        x.pop();
    }
    for (int i = max_size - 1; i >= 0; i--)
    {
        Node *new_Node = new Node(temp[i], top);
        top = new_Node;
    }
}

void Stack::add(int x)
{
    Node *new_Node = new Node(x, top);
    top = new_Node;
    count_el++;
}

void Stack::remove()
{
    top = top->pointer;
    count_el--;
}

void Stack::count()
{
    cout << count_el << endl;
}

void Stack::check_empty()
{
    if (count_el == 0)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
}

void Stack::print_top()
{
    cout << top->value << endl;
}

void Stack::print_stack()
{
    Node *new_top = top;
    vector <int> temp(count_el);

    for (int i = 0; new_top != nullptr; i++)
    {
        temp[count_el - 1 - i] = new_top->value;
        new_top = new_top->pointer;
    }
    for (int i = 0; i < count_el; i++)
    {
        cout << temp[i] << ' ';
    }
    cout << endl;
}


void Menu::print_menu(Stack &st)
{
    cout << "Enter one of the listed functions:" << endl;
    cout << "Add" << endl;
    cout << "Remove" << endl;
    cout << "Count" << endl;
    cout << "Check_empty" << endl;
    cout << "Print_top" << endl;
    cout << "Print_stack" << endl;
    cout << "Create" << endl;

    string f;
    cin >> f;
    while (f != "Exit" and f != "exit")
    {
        if (f == "Add" or f == "add")
        {
            int x;
            cin >> x;
            st.add(x);
        }
        else if (f == "Remove" or f == "remove")
        {
            st.remove();
        }
        else if (f == "Count" or f == "count")
        {
            st.count();
        }
        else if (f == "Check_empty" or f == "check_empty")
        {
            st.check_empty();
        }
        else if (f == "Print_top" or f == "print_top")
        {
            st.print_top();
        }
        else if (f == "Print_stack" or f == "print_stack")
        {
            st.print_stack();
        }
        else if (f == "Create" or f == "create")
        {
            cout << "Enter a way to initialize the stack:" << endl;
            cout << "By default" << endl;
            cout << "By copy" << endl;
            cout << "By max_size" << endl;
            cout << "By stack" << endl;

            string d;
            cin >> d;
            if (d == "default")
            {
                Stack *new_stack = new Stack;
                st = Stack(*new_stack);
            }
            else if (d == "max_size")
            {
                int max_size;
                cin >> max_size;
                st = Stack(max_size);
            }
            else if (d == "stack")
            {
                int max_size, x;
                cin >> max_size;
                stack<int> stack_input;
                for (int i = 0; i < max_size; i++)
                {
                    cin >> x;
                    stack_input.push(x);
                }
                Stack(max_size, stack_input);
            }
            else
            {
                cout << "Wrong command" << endl;
            }
        }
        else
        {
            cout << "Wrong command" << endl;
        }
        cin >> f;
    }
}