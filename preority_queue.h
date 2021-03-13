#include<bits/stdc++.h>

using namespace std;

template <typename T>
struct Node
{
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* prev;
};

template <typename T>
class PreorityQueue
{
    Node<T>* head;
    int N;
    bool dir;
    public:
        PreorityQueue()
        {
            head = nullptr;
            dir = false;
            N = 0;
        }

        Node<T>* getEdge(int N)
        {
            int pow2 = 1;
            while (pow2 <= N)
                pow2 <<= 1; // pow2 *= 2
            pow2 >>= 1; // pow2 /= 2
            int number = N & (pow2 - 1); // N % pow2
            Node<T>* pointer = head;
            while (pow2 > 2)
            {
                if (number < pow2 / 2)
                    pointer = pointer->left;
                else
                    pointer = pointer->right;
                pow2 /= 2;
                number %= pow2;
            }
            return pointer;
        }

        void liftUpNode(Node<T>* pointer)
        {
            while (pointer->prev != nullptr && pointer->prev->value > pointer->value)
            {
                swap(pointer->value, pointer->prev->value);
                pointer = pointer->prev;
            }
        }

        void push(T value)
        {
            Node<T>* newNode = new Node<T>;
            newNode->value = value;
            newNode->left = nullptr;
            newNode->right = nullptr;
            newNode->prev = nullptr;
            N++;
            if (N == 1)
            {
                head = newNode;
            }
            else
            {
                Node<T>* pointer = getEdge(N);
                if (N % 2 == 0)
                {
                    pointer->left = newNode;
                    newNode->prev = pointer;
                }
                else
                {
                    pointer->right = newNode;
                    newNode->prev = pointer;
                }
                pointer = newNode;
                liftUpNode(pointer);
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
