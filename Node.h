#ifndef NODE_H_
#define NODE_H
using namespace std;

template <class T>
class Node
{
public:
    Node(T value);
    ~Node();
    T data;
    Node <T> *next;
};

template <class T>
Node<T>::Node(T value) : data(value), next(nullptr)
{
}

template <class T>
Node<T>::~Node()
{
}
#endif /* NODE_H_ */