// kopiec.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BHeap {
public:
    vector <int> heap;
    int l(int parent);
    int r(int parent);
    int par(int child);
    void heapifyup(int index);
    void heapifydown(int index);

    BHeap() {}
    void Insert(int element);
    void DeleteMin();
    int ExtractMin();
    void showHeap();
    int Size();
};
int BHeap::Size() {
    return heap.size();
}
void BHeap::Insert(int ele) {
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
int BHeap::ExtractMin() {
    if (heap.size() == 0) {
        return -1;
    }
    else
        return heap.front();
}
void BHeap::showHeap() {
    vector <int>::iterator pos = heap.begin();
    //cout << "Heap --> ";
    while (pos != heap.end()) {
        cout << *pos << " ";
        pos++;
    }
    cout << endl;
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
    if (in >= 0 && par(in) >= 0 && heap[par(in)] < heap[in]) {
        int temp = heap[in];
        heap[in] = heap[par(in)];
        heap[par(in)] = temp;
        heapifyup(par(in));
    }
}
void BHeap::heapifydown(int in) {
    int child = r(in);
    int child1 = l(in);
    if (child >= 0 && child1 >= 0 && heap[child] < heap[child1]) { //! tut ez
        child = child1;
    }
    if (child > 0 && heap[in] < heap[child]) { //!zmiana
        int t = heap[in];
        heap[in] = heap[child];
        heap[child] = t;
        heapifydown(child);
    }
}

int main()
{
    BHeap kopiec;
    int n;
    string s, command;
    int data;
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
            vector <int> h;
            for (int i = 0; i < n; i++) {
                cin >> data;
                kopiec.Insert(data);
                cout << "----------" << endl;
                kopiec.showHeap();
                cout << "----------" << endl;
                //kopiec.heap.push_back(data);
                //kopiec.heapifydown(0);
            }//kopiec.heapifyup(kopiec.heap.size() - 1);
            
            

        }
        else if(command == "q") break;
        
    }

}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
