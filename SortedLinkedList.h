#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include "ListNode.h"
#include "ItemType.h"

class SortedLinkedList {
private:
    ListNode *head;
    ListNode *currentPos;
    int len;
    int iterPos;
public:
    SortedLinkedList();
    ~SortedLinkedList();
    int length() const;
    void insertItem(ItemType item);
    void deleteItem(ItemType item);
    int searchItem(ItemType item);
    ItemType GetNextItem();
    void ResetList();
    void merge(SortedLinkedList list);
    void deleteAlt();
    SortedLinkedList intersection(SortedLinkedList list);
    void printList();
};
#endif
