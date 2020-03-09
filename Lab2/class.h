#ifndef LAB2_CLASS_H
#define LAB2_CLASS_H

#include <iostream>
#include <stack>

using namespace std;

class Stack
{
private:
    struct Node
    {
        int value;
        Node *pointer;
        Node(int x, Node *y);
    };

public:
    Node *top;
    int max_size;
    int count_el;

    Stack();
    Stack(Stack &x);
    Stack(int max_size_input);
    Stack(int max_size_input, stack <int> &x);

    void add(int x);
    void remove();
    void count();
    void check_empty();
    void print_top();
    void print_stack();
};


class Menu
{
public:
    void print_menu(Stack &st);
};

#endif