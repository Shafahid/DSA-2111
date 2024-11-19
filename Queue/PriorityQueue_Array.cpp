#include <bits/stdc++.h>
using namespace std;
int sz = 0;
// Structure for the elements in the
// priority queue
struct item {
    int value;
    int priority;
};
 
// Store the element of a priority queue
item pr[100000];
 
// Pointer to the last index

 
// Function to insert a new element
// into priority queue
void enqueue(int value, int priority)  // TC - O(1)
{
    // Increase the size
    sz++;
 
    // Insert the element
    pr[sz].value = value;
    pr[sz].priority = priority;
}
 
// Function to check the top element
int peek() // TC - O(N)
{
    int highestPriority = INT_MIN;
    int ind = -1;
 
    // Check for the element with
    // highest priority
    for (int i = 0; i <= sz; i++) {
 
        // If priority is same choose
        // the element with the
        // highest value
        if (highestPriority
                == pr[i].priority
            && ind > -1
            && pr[ind].value
                   < pr[i].value) {
            highestPriority = pr[i].priority;
            ind = i;
        }
        else if (highestPriority
                 < pr[i].priority) {
            highestPriority = pr[i].priority;
            ind = i;
        }
    }
 
    // Return position of the element
    return ind;
}
 
// Function to remove the element with
// the highest priority
void dequeue() // TC - O(N)
{
    // Find the position of the element
    // with highest priority
    int ind = peek();
 
    // Shift the element one index before
    // from the position of the element
    // with highest priority is found
    for (int i = ind; i < sz; i++) {
        pr[i] = pr[i + 1];
    }
 
    // Decrease the size of the
    // priority queue by one
    sz--;
}
 
// Driver Code
int main()
{
    // Function Call to insert elements
    // as per the priority
    enqueue(10, 2);
    enqueue(14, 4);
    enqueue(16, 4);
    enqueue(12, 3);
 
    // Stores the top element
    // at the moment
    int ind = peek();
 
    cout << pr[ind].value << endl;
 
    // Dequeue the top element
    dequeue();
 
    // Check the top element
    ind = peek();
    cout << pr[ind].value << endl;
   
      // Dequeue the top element
    dequeue();
   
      // Check the top element
    ind = peek();
    cout << pr[ind].value << endl;
 
    return 0;
}