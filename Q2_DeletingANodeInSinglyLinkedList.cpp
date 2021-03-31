#include <bits/stdc++.h> 
using namespace std; 

// Link list node
class Node { 
public: 
    int value; 
    Node* next; 
};
/* You Should NOT Modify Anything Above This */

/* 
headPtr is a reference to the head node(i.e. pointer to pointer)
deleteNodePtr is the node which is to be deleted.
It is guaranteed that deleteNodePtr will not point to the last element.
*/ 
void deleteNode(Node** headPtr, Node* deleteNodePtr) {

    // Write your code here

    // EFFICIENT CODE:
    Node* temp = deleteNodePtr->next; 
    deleteNodePtr->value = temp->value; 
    deleteNodePtr->next = temp->next;


    // SLOW CODE:
    // if(*headPtr == deleteNodePtr){
    //     *headPtr = (*headPtr)->next;
    //     return;
    // }

    // Node* temp = *headPtr;

    // while(1){
    //     Node* prev = temp;
    //     temp = temp->next;
    //     if(temp == deleteNodePtr){
    //         prev->next = temp->next;
    //         break;
    //     }
    // }

}

/* You Should NOT Modify Anything Below This */
int main() {
    Node* head = NULL;

    int n;
    cin>>n;

    vector <int> values(n);
    vector <Node*> pointers(n);

    for(int i=0;i<n;i++){
        cin>>values[i];
    }

    for(int i=n-1;i>=0;i--){
        
        // creating the node in the linkedList
        Node* newNode = new Node();
        newNode->value = values[i];
        newNode->next = head;
        head = newNode;

        pointers[i] = newNode;
    }

    for(int i=n-2;i>=0;i--){
        deleteNode(&head, pointers[i]);
        if(i>=n-6){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->value<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
}