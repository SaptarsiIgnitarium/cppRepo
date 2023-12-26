#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    // Create a singly linked list
    forward_list<int> myList;

    // Insert elements at the front of the list
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);

    // Iterate through the list and print its elements
    cout << "Elements in the linked list: ";
    for (const auto& elem : myList) {
        cout << elem << " ";
    }
    cout << endl;

    // Insert an element after the first element
    auto it = myList.begin();
    ++it; // Move the iterator to the second element
    myList.insert_after(it, 25);

    // Print the updated list
    cout << "Updated elements in the linked list: ";
    for (const auto& elem : myList) {
        cout << elem << " ";
    }
    cout << endl;

    // Remove elements from the list
    myList.pop_front(); // Remove the first element

    // Print the list after removal
    cout << "Elements after removal: ";
    for (const auto& elem : myList) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
