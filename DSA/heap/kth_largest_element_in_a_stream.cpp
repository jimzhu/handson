//ref: http://www.geeksforgeeks.org/kth-largest-element-in-a-stream/
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void minheapify(vector<T>& array, int node, int heap_size) {
    int left = 2 * node + 1;
    int right = 2 * node + 2;
    int smallest = node;
    if (left < heap_size) {
        if (array[smallest] > array[left]) {
            smallest = left;
        }
    }
    if (right < heap_size) {
        if (array[smallest] > array[right]) {
            smallest = right;
        }
    }
    if (smallest != node) {
        swap(array[smallest], array[node]);
        minheapify(array, smallest, heap_size);
    }
}

template<typename T>
void build_minheap(vector<T>& array) {
    int heap_size = array.size();
    int non_leaf = heap_size / 2 - 1;
    for (int i = non_leaf; i >= 0; i--) {
        minheapify(array, i, heap_size);
    }
}

int main() {
    int k = 3;
    cout << "k is " << k << endl;
    vector<double> heap (k);
    int cnt = 0;
    while (1) {
        int in;
        cout << "input: ";
        cin >> in;
        if (cnt < k - 1) {
            heap[cnt] = in;
            cnt++;
        }
        else {
            if (cnt == k - 1) {
                heap[cnt] = in;
                build_minheap(heap);
                cnt++;
            }
            else {
                if (in > heap[0]) {
                    heap[0] = in;
                    minheapify(heap, 0, heap.size());
                }
            }
            cout << "kth largest: " << heap[0] << endl;
        }
    }
    return 0;
}


