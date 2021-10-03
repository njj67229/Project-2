#include "ItemType.h"

using namespace std;

Comparison ItemType::compareTo(ItemType item) {
    if (item.getValue() == value) {
        return EQUAL;
    } else if (item.getValue() > value) {
        return LESS;
    } else {
        return GREATER;
    }
}

int ItemType::getValue() const {
    return value;
}

void ItemType::initialize(int num) {
    value = num;
}
