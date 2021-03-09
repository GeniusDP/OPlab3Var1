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
class PreorityQueue
{
    Node<T>* head;
    bool dir;
    public:
        PreorityQueue()
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
        }
        bool empty()
        {
            return head == nullptr;
        }
        void pop()
        {
            Node<T>* pointer = head;
            Node<T>* prev = head;
            while(pointer->left != nullptr || pointer->right != nullptr)
            {
                if (pointer->right == nullptr)
                {
                    swap(pointer->value, pointer->left->value);
                    prev = pointer;
                    pointer = pointer->left;
                }
                else
                if (pointer->left == nullptr)
                {
                    swap(pointer->value, pointer->right->value);
                    prev = pointer;
                    pointer = pointer->right;
                }
                else
                {
                    if (pointer->left->value <= pointer->right->value)
                    {
                        swap(pointer->value, pointer->left->value);
                        prev = pointer;
                        pointer = pointer->left;
                    }
                    else
                    {
                        swap(pointer->value, pointer->right->value);
                        prev = pointer;
                        pointer = pointer->right;
                    }
                }
            }
            if (pointer == head)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                if (prev->left == pointer)
                    prev->left = nullptr;
                if (prev->right == pointer)
                    prev->right = nullptr;
                delete pointer;
            }
        }
        void deleteAll(Node<T>* node)
        {
            if (node == nullptr)
                return;
            if (node->left != nullptr)
                deleteAll(node->left);
            if (node->right != nullptr)
                deleteAll(node->right);
            delete node;
        }
        ~PreorityQueue()
        {
            deleteAll(head);
            head = nullptr;
        }
};
