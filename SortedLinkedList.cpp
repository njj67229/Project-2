#include "SortedLinkedList.h"
#include "ItemType.h"
#include "ListNode.h"
#include <iostream>

using namespace std;

SortedLinkedList::SortedLinkedList() {
    SortedLinkedList::ResetList();
}

SortedLinkedList::~SortedLinkedList() {

}
int SortedLinkedList::length() const {
    return len;
}

void SortedLinkedList::insertItem(ItemType item) {
    ListNode *node = head;
    ListNode *tempNode = new ListNode();
    tempNode -> item = item;
    cout << "Val: " << item.getValue() << endl;
    if (length() == 0) {
        head = new ListNode();
        head -> item = item;
        len++;
    } else {
        for (int i = 0; i < length(); i++) {
            cout << "B";
            ItemType::Comparison c = item.compareTo(node -> item);
            switch (c) {
                case ItemType::EQUAL:
                    cout << "Sorry. You cannot insert the duplicate item\n" << endl;
                    return;
                case ItemType::LESS: //Needs to be inserted before the current node
                    cout << "here\n";
                    tempNode -> next = node;
                    node -> next = tempNode;
                    len++;
                case ItemType::GREATER:
                    if (i == length() - 1) {
                        cout << "Present\n";
                        node -> next = tempNode;
                    } else {
                        node = node -> next;
                    }
            }
        }
    }
}
void SortedLinkedList::deleteItem(ItemType item) {
    if (length() == 0) {
        cout << "You cannot delete from an empty list." << endl;
        return;
    }
    int loc = searchItem(item);
    ListNode *node = head;
    if (loc == -1) {
        return;
    } else if (loc == 0) {
        head = head -> next;
        len--;
    } else { //Need to check if its last index
        for (int i = 0; i < loc - 1; i++) {
            node = node -> next;
        }
        node -> next = (node -> next) -> next;
        len--;
    }
}

//could be coded in binary search. Would do if we had the time
int SortedLinkedList::searchItem(ItemType item) {
    ListNode* tempNode = head;
    for (int i = 0; i < length(); i++) {
        if (item.compareTo(tempNode -> item) == ItemType::EQUAL) {
            return i;
        }
        tempNode = tempNode -> next;
    }
    cout << "Item not found." << endl;
    return -1;
}

ItemType SortedLinkedList::GetNextItem() {
    ItemType it;
    if (length() == 0) {
        cout << "List is empty." << endl;
        return it;
    } else if (currentPos == NULL) {
        currentPos = head;
    }
    it = currentPos -> item;
    currentPos = currentPos -> next;
    iterPos++;
    if (iterPos >= length()) {
        cout << "The end of the list had been reached. Reseting." << endl;
        ResetList();
    }
    return it;
    //todo
}

void SortedLinkedList::ResetList() {
    currentPos = NULL;
    len = 0;
    iterPos = 0;
}

void SortedLinkedList::deleteAlt() {
    ListNode *cp = head;
    if(length() < 2) {
        return;
    }
    cp = cp -> next;
    for (int i = 1; i < length(); i+=2) {
        deleteItem(cp->item);
        cp = (cp -> next) -> next;
    }
}

void SortedLinkedList::printList() {
    ListNode *temp = head;
    for (int i = 0; i < length(); i++) {
        cout << head -> item.getValue() << " ";
        temp = temp -> next;
    }
    cout << endl;
}

//Resets both lists, iterates through them and compares the values
SortedLinkedList SortedLinkedList::intersection(SortedLinkedList list) {
    int l;
    if (list.length() < length()) {
        l = list.length();
    } else {
        l = length();
    }
    SortedLinkedList mergedList;
    for (int i = 0; i < l; i++) {
        ItemType it = GetNextItem();
        if (it.compareTo(list.GetNextItem()) == ItemType::EQUAL) {
            mergedList.insertItem(it);
        }
    }
    mergedList.printList();
    return mergedList;
}

void SortedLinkedList::merge(SortedLinkedList list) {
    int dupe = 0;
    for(int i = 0; i < list.length(); i++) {
        int j = searchItem(list.GetNextItem());
        if (j != -1) {
            dupe = 1;
            cout << "Sorry. You cannot insert the duplicate item." << endl;
            break;
        }
    }
    list.ResetList();
    if (dupe == 0) {
        for(int i = 0; i < list.length(); i++) {
            insertItem(list.GetNextItem());
        }
    }
}
