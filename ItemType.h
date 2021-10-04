#ifndef ITEMTYPE_H
#define ITEMTYPE_H

class ItemType {
public:
    enum Comparison {GREATER, LESS, EQUAL};
    ItemType();
    Comparison compareTo(ItemType item);
    int getValue() const;
    void initialize(int num);
private:
    int value;
};
#endif
