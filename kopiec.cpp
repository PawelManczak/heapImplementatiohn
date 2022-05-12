// kopiec.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BHeap {
public:
    bool max = true;
    bool compare(string a, string b);
    bool compareNumbers(string& str1, string& str2);
    vector <string> heap;
    int l(int parent);
    int r(int parent);
    int par(int child);
    void heapifyup(int index);
    void heapifydown(int index);

    BHeap() {}
    void Insert(string element);
    void DeleteMin();
    void showHeap();
    void buduj();
};
void BHeap::Insert(string ele) {
    heap.push_back(ele);
    heapifyup(heap.size() - 1);
}
void BHeap::DeleteMin() {
    if (heap.size() == 0) {
        //cout << "Heap is Empty" << endl;
        return;
    }
    //heap.erase(heap.begin());
    cout << heap[0] << endl;
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
}

void BHeap::showHeap() {
    //cout << "Heap --> ";
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
   /* while (pos != heap.end()) {
        cout << *pos << " ";
        pos++;
    }*/
    cout << endl;
}
bool BHeap::compare(string a, string b)
{
    if (max) return compareNumbers(a, b);
    else return compareNumbers(b, a);
}

bool BHeap::compareNumbers(string& str1, string& str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    // If lengths are same
    for (int i = 0; i < n1; i++)
    {
        if (str1[i] < str2[i])
            return true;
        if (str1[i] > str2[i])
            return false;
    }

    return false;
}

int BHeap::l(int parent) {
    int l = 2 * parent + 1;
    if (l < heap.size())
        return l;
    else
        return -1;
}
int BHeap::r(int parent) {
    int r = 2 * parent + 2;
    if (r < heap.size())
        return r;
    else
        return -1;
}
int BHeap::par(int child) {
    int p = (child - 1) / 2;
    if (child == 0)
        return -1;
    else
        return p;
}
void BHeap::heapifyup(int in) {
    if (in >= 0 && par(in) >= 0 && compare(heap[par(in)], heap[in])) {
       // cout << "PARENT: " << heap[in] << " to " << heap[par(in)] << endl;
        string temp = heap[in];
        heap[in] = heap[par(in)];
        heap[par(in)] = temp;
        heapifyup(par(in));
    }
}
void BHeap::heapifydown(int in) {
    int child = l(in);
    int child1 = r(in);
    if (child >= 0 && child1 >= 0 && compare(heap[child], heap[child1])) { //! tut ez
        child = child1;
    }
    if (child > 0 && compare(heap[in], heap[child])) { //!zmiana
        string t = heap[in];
        heap[in] = heap[child];
        heap[child] = t;
        heapifydown(child);
    }
}

void BHeap::buduj() {
    for (int i = heap.size() - 1; i >= 0; i--) {
        heapifydown(i);
    }
}

int main()
{
    BHeap kopiec;
    int n;
    string s, command;
    string data;
    while (cin>>command) {
        if (command == "+") {
            cin >> data;
            kopiec.Insert(data);

        }
        else if (command == "-") {
            kopiec.DeleteMin();
        }
        else if (command == "p") {
            
            kopiec.showHeap();
        }
        else if (command == "r") {
            kopiec.heap.clear();
            cin >> n;
            vector <string> h;
            for (int i = 0; i < n; i++) {
                cin >> data;
                h.push_back(data);
            }
            kopiec.heap = h;
            kopiec.buduj();
        }
        else if (command == "s") {
            kopiec.max ? kopiec.max = false : kopiec.max = true;
            kopiec.buduj();
        }
        else if(command == "q") break;
        
    }

}

