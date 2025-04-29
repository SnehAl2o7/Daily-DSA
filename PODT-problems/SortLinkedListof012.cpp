#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
      int data;
      Node* next;
  
      Node(int x) {
          data = x;
          next = nullptr;
      }
  };
  
  void printList(Node* node) {
      while (node != NULL) {
          cout << node->data << " ";
          node = node->next;
      }
      cout << "\n";
  }
  
  void freeList(struct Node* head) {
      struct Node* temp;
      while (head != NULL) {
          temp = head;
          head = head->next;
          delete temp;
      }
  }

class Solution {
    public:
      Node* segregate(Node* head) {
          // code here
          int cnt0=0, cnt1=0, cnt2=0;
          Node* temp = head;
          while(temp){
              if(temp->data == 0)cnt0++;
              else if(temp->data == 1)cnt1++;
              else cnt2++;
              temp = temp->next;
          }
          
          temp = head;
      while (cnt0--) {
          temp->data = 0;
          temp = temp->next;
      }
      while (cnt1--) {
          temp->data = 1;
          temp = temp->next;
      }
      while (cnt2--) {
          temp->data = 2;
          temp = temp->next;
      }
          
          return head;   
      }
  };

  int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        //cout << "~" << endl;
    }

    return 0;
}