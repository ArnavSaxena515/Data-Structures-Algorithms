#include <iostream>
#include "linked_list.h"

using namespace std;

main()
{
    LinkedList linkedList = LinkedList();
    linkedList.insertValue(1);
    linkedList.insertValue(5);
    linkedList.insertValue(55);

    linkedList.displayList();
}