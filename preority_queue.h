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

        Node<T>* getMinEdge(Node<T>* node)
        {
            if (node == nullptr)
                return node;
            if (node->right != nullptr)
                return ((node->left->value < node->right->value)? node->left : node->right);
            if (node->left != nullptr)
                return node->left;
            return nullptr;
        }

        void pop()
        {
            Node<T>* pointer = head;
            if (N == 1)
            {
                delete head;
                head = nullptr;
                N--;
                return;
            }
            Node<T>* minEdge = getMinEdge(pointer);
            while (minEdge != nullptr)
            {
                swap(pointer->value, minEdge->value);
                pointer = minEdge;
                minEdge = getMinEdge(pointer);
            }
            Node<T>* node = getEdge(N);
            if (N % 2 == 0)
                minEdge = node->left;
            else
                minEdge = node->right;
            swap(pointer->value, minEdge->value);
            if (minEdge != pointer)
                liftUpNode(pointer);
            if (node->left == minEdge)
                node->left = nullptr;
            else
                node->right = nullptr;
            delete minEdge;
            N--;
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
