#include "SortedLinkedList.h"

using namespace std;

SortedLinkedList() {
    SortedLinkedList::ResetList();
}

int SortedLinkedList::Length() const {
    return length;
}

void SortedLinkedList::insertItem(ItemType item) {
    struct ListNode node;
    ListNode tempNode = head;
    node.item = item;
    for (int i = 0; i < length; i++) {
        Comparison val = node.item.compareTo(tempNode.item);
        if (val == EQUAL) {
            cout << "Sorry. You cannot insert the duplicate item\n";
            return;
        } else if (val == LESS) { //Needs to be inserted before the current node
            node.next = tempNode;
        }
        tempNode = tempNode.next;
    }
}
void SortedLinkedList::ResetList() {
    currentPos = null;
    length = 0;
}
