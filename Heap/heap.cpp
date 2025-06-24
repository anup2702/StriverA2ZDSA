#include <bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;

        heap(){
            arr[0] = -1;
            size = 0;
        }

        void insert(int val){
            size += 1;
            int idx = size;
            arr[idx] = val; // insert at last

            while(idx > 1){
                int parent = idx/2;
                if(arr[parent] < arr[idx]){ // compare with parent
                    swap(arr[parent], arr[idx]);
                    idx = parent;
                } else return;
            }
        } // TC - O(logn)

        void deletion(){
            if(size == 0) return;
            arr[1] = arr[size]; // Replace root by last element
            size -= 1; // remove last element

            int i = 1;
            while(i <= size){
                int leftIdx = 2*i;
                int rightIdx = 2*i + 1;

                if(leftIdx < size and arr[i] < arr[leftIdx]){
                    swap(arr[i], arr[leftIdx]);
                    i = leftIdx;
                }
                else if(rightIdx < size and arr[i] < arr[rightIdx]){
                    swap(arr[i], arr[rightIdx]);
                    i = rightIdx;
                } else return;
            }
        }
        // TC - O(logn)


        void print(){
            for(int i=1; i<=size; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

};

void heapify(int arr[], int n, int i){
    // one-based indexing for zero- add 1 to left and right
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left<=n and arr[largest] < arr[left]){
        largest = left;
    }
    if(right<=n and arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
} // TC - O(logn)

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[1], arr[size]); // Swap first to last node
        size--; // remove last node
        heapify(arr, n, 1); // build heap 
    }
}

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletion();
    h.print();


    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    // in CBT leaf nodes are from n/2+1 to n
    for(int i = n/2; i>0; i--){ // leave leaf nodes
        heapify(arr, n, i);
    }

    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr, n);
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
}