#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
	
	if (head == NULL)
    {
        smaller = NULL;
        larger = NULL;
    }
    llpivot(head->next, smaller, larger, pivot);
	if ((head -> val) > pivot)
    {
       head -> next = larger;
       larger = head;
    }
    else 
    {
        head -> next = smaller;
        smaller = head;
    }
    head = NULL;
}



// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code

    // Node* small = NULL;
    // Node* large = NULL;

    // llpivot(head, small, large, 9);

    // cout << "llpivot head: ";
    // print(head);
    // cout << "\n llpivot small: ";
    // print(small);
    // cout << "\n llpivot large: ";
    // print(large);
    // dealloc(small);
    // dealloc(large);
    
    

    return 0;
}
