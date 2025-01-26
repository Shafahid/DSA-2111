#include<iostream>
using namespace std;
struct MinHeap{
    int *arr;
    int capacity;
    int heap_size;
    MinHeap(int n){
        capacity = n;
        heap_size = 0;
        arr = new int[n];
    }
    int left(int index)
    {
        return index * 2 + 1;
    }

    int right(int index)
    {
        return index * 2 + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void heapify(int index)
    {
        int smallest = index;
        int l = left(index);
        int r = right(index);

        if(l<heap_size&&arr[smallest]>arr[l]){
            smallest = l;
        }
        if(r<heap_size&&arr[smallest]>arr[r]){
            smallest = r;
        }
        if(smallest!=index){
            swap(arr[index],arr[smallest]);
            heapify(smallest);
        }
    }


    void insert_node(int value){
        if(heap_size==capacity){
            cout<<"Heap Overflow"<<endl;
            return;
        }

        arr[heap_size] = value;
        int index = heap_size;
        heap_size++;

        while(index>0&&arr[parent(index)]>arr[index]){
        swap(arr[index],arr[parent(index)]);
        index = parent(index);    
        }
    }

    void delete_node(int value){
        if(heap_size==0){
            cout<<"Heap Underflow"<<endl;
            return;
        }
        // arr[0] will be deleted
        arr[0] = arr[heap_size-1];
        heap_size--;
        if(heap_size==0){
            return;
        }
        heapify(0);
    }

    void print(){
        for(int i=0;i<heap_size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    

};

int main(){
    MinHeap *m = new MinHeap(8);
    m->insert_node(7);
    m->insert_node(1);
    m->insert_node(11);
    m->insert_node(114);
    m->insert_node(24);

    m->print();
    m->delete_node(114);
    m->print();
    return 0;
}
