#include "Node.h"
class UnsortedType
{
public:
    UnsortedType();
    void makeEmpty();
    bool isFull() const;
    int getLength() const;
    void insertData(int value);
    void removeData(int value);
    void display();
    ~UnsortedType();
private:
    int length;
    Node* start;
};