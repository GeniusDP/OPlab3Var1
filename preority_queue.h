#include<bits/stdc++.h>

using namespace std;

template <typename T>
struct Node
{
    T value;
    Node<T>* left;
    Node<T>* right;
};

template <typename T>
class Priority_queue
{
    Node<T>* head;
    bool dir;
    public:
        Priority_queue()
        {
            head = nullptr;
            dir = false;
        }

        void push(T value)
        {
            Node<T>* newNode = new Node<T>;
            newNode->value = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            Node<T>* pointer = head;
            if (pointer == nullptr)
                head = newNode;
            else
            if (pointer->value > value)
            {
                newNode->left = head->left;
                head->left = nullptr;
                newNode->right = head;
                head = newNode;
            }
            else
            {
                while (1)
                {
                    if (pointer->left == nullptr)
                    {
                        pointer->left = newNode;
                        break;
                    }
                    if (pointer->right == nullptr)
                    {
                        pointer->right = newNode;
                        break;
                    }
                    if (pointer->left->value <= value && pointer->right->value <= value)
                    {
                        if (dir)
                            pointer = pointer->left;
                        else
                            pointer = pointer->right;
                        dir = !dir;
                    }
                    else
                    if (pointer->left->value > value)
                    {
                        newNode->left = pointer->left->left;
                        pointer->left->left = nullptr;
                        newNode->right = pointer->left;
                        pointer->left = newNode;
                        break;
                    }
                    else
                    {
                        newNode->right = pointer->right->right;
                        pointer->right->right = nullptr;
                        newNode->left = pointer->right;
                        pointer->right = newNode;
                        break;
                    }
                }
            }
        }

        T top()
        {
            if (head != nullptr)
                return head->value;
            else
                return -1;
        }
        bool empty()
        {
            return head == nullptr;
        }
};
