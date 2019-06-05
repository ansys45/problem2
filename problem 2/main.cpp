#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <climits>
#include <bitset>
#include <algorithm>
#include <climits>

using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next;
    Node* prev;
};

template <typename T>
class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    Node<T>* getHead() {
        return head;
    }

    Node<T>* getTail() {
        return tail;
    }

    void createNode(T val) {
        Node<T>* cur = new Node<T>;
        cur->value = val;
        cur->next = nullptr;
        if (head == nullptr) {
            head = cur;
            tail = cur;
            cur = nullptr;
        }
        else {
            tail->next = cur;
            tail->next->prev = tail;
            tail = cur;
        }
    }

    void print() {
        Node<T>* cur = new Node<T>;
        cur = head;
        while (cur) {
            cout << cur->value << "->";
            cur = cur->next;
        }
        cout << "nullptr" << endl;
    }

    void print_reverse() {
        Node<T>* cur = new Node<T>;
        cur = tail;
        while (cur) {
            cout << cur->value << "->";
            cur = cur->prev;
        }
        cout << "nullptr" << endl;
    }

    void push_front(T val) {
        Node<T>* cur = new Node<T>;
        cur->value = val;
        cur->next = head;
        head = cur;
    }

    void insert(int pos, T val) {
        Node<T>* cur = new Node<T>;
        Node<T>* pre = new Node<T>;
        Node<T>* temp = new Node<T>;
        temp->value = val;
        cur = head;
        for (int i = 1; i < pos; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = temp;
        temp->next = cur;
    }

    int getSize() {
        int res = 0;
        Node<T>* cur = new Node<T>;
        cur = head;
        while (cur) {
            res++;
            cur = cur->next;
        }
        return res;
    }

    T getValue(int pos) {
        Node<T>* cur = new Node<T>;
        cur = head;
        for (int i = 1; i < pos; i++) {
            cur = cur->next;
        }
        return cur->value;
    }

    void setValue(T val, int pos) {
        Node<T>* cur = new Node<T>;
        cur = head;
        for (int i = 1; i < pos; i++) {
            cur = cur->next;
        }
        cur->value = val;
    }

    int getMax() {
        int res = -1000000009;
        Node<int>* cur = new Node<int>;
        cur = head;
        int c;
        while (cur) {
            c = cur->value;
            if (c > res) res = c;
            cur = cur->next; 
        }
        return res;
    }
    
    void swapNodes(int p1, int p2) {
        T v1 = getValue(p1);
        T v2 = getValue(p2);
        setValue(v1, p2);
        setValue(v2, p1);
    }

    void del_pos(int pos, T val) {
        Node<T>* cur = new Node<T>;
        Node<T>* pre = new Node<T>;
        cur = head;
        for (int i = 1; i < pos; i++) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
    }

    ~LinkedList() {
        Node<T>* cur = new Node<T>;
        Node<T>* fol = new Node<T>;
        cur = head;
        while (cur) {
            fol = cur->next;
            delete cur;
            cur = fol;
        }
    }

private:
    Node<T>* head;
    Node<T>* tail;
};


template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& v) {
    for (size_t i = 0; i != v.size(); ++i) {
        if (i > 0)
            out << " ";
        out << v[i];
    }
    out << std::endl;
    return out;
}

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////Vector Sortings/////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void InsertionSort(std::vector<T>& v) {  
    int i, j, n;
    T key;
    n = v.size(); 
    for (i = 1; i < n; i++) {  
        key = v[i];  
        j = i - 1;
        while (j >= 0 && v[j] > key) {  
            v[j + 1] = v[j];  
            j = j - 1;  
        }  
        v[j + 1] = key;  
    }  
}

template <typename T>
void Merge(std::vector<T>& v, int low, int high, int mid) {
    int i, j;
    std::vector<T> temp;
    i = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (v[i] < v[j]) {
            temp.push_back(v[i]);
            i++;
        }
        else {
            temp.push_back(v[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(v[i]);
        i++;
    }
    while (j <= high) {
        temp.push_back(v[j]);
        j++;
    }
    for (i = low; i <= high; i++)
        v[i] = temp[i - low];
}

template <typename T>
void MergeSort(std::vector<T>& v, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2; 
        MergeSort(v, low, mid);
        MergeSort(v, mid + 1, high);
        Merge(v, low, high, mid);
    }
}


template <typename T>
int element(std::vector<T>& v, int low, int high) { 
    T pivot = v[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (v[j] <= pivot) { 
            i++; 
            swap(v[i], v[j]); 
        } 
    } 
    swap(v[i + 1], v[high]); 
    return (i + 1); 
} 

template <typename T>
void QuickSort(std::vector<T>& v, int low, int high) { 
    if (low < high) {
        int pi = element(v, low, high);
        QuickSort(v, low, pi - 1); 
        QuickSort(v, pi + 1, high); 
    } 
} 


template <typename T>
void Templ_CountingSort(std::vector<T>& v) {
    map<T, int> m;
    for (int i = 0; i < v.size(); i++) {
        m[v[i]] += 1;
    }
    int j = 0;
    for (auto i : m) {
        int count = i.second;
        while (count) {
            v[j] = i.first;
            j++;
            count--;
        } 
    }
}

int vec_max(std::vector<int> v) {
    int res = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > res) res = v[i];
    }
    return res;
}
void CountingSort(std::vector<int>& v) {
    int l = vec_max(v);
    std::vector<int> co;
    int i;
    for (i = 0; i < l + 1; i++) {
        co.push_back(0);
    }
    for (i = 0; i < v.size(); i++) {
        co[v[i]] += 1;
    }
    int j = 0;
    for (i = 0; i < l + 1; i++) {
        while (co[i]) {
            v[j] = i;
            co[i]--;
            j++;
        }
    }
}

int takeDigit(int N, int i) {
    return N % (int)pow(10, i) / (int)pow(10, abs(i - 1));
}

int numDigits(int N) {
    return to_string(N).length();
}

void cSortDigit(std::vector<int>& v, int digit) {
    map<int, std::vector<int> > c;
    int i, j, z;
    int l = v.size();
    for (i = 0; i < l; i++) {
        c[takeDigit(v[i], digit)].push_back(v[i]);
    }
    i = 0;
    j = 0;
    for (auto j : c) {
        z = 0;
        while (z < j.second.size()) {
            v[i] = j.second[z];
            ++z;
            ++i;
        }
    }
}

void RadixSort(std::vector<int>& v) {
    int l;
    l = numDigits(vec_max(v));
    for (int i = 1; i <= l; i++) {
        cSortDigit(v, i);
    }
}

int max_len(std::vector<string> v) {
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].length() > res) res = v[i].length();
    }
    return res;
}

void cSortDigitStr(std::vector<string>& v, int digit) {
    map<int, std::vector<string> > c;
    int i, j, z;
    int l = v.size();
    for (i = 0; i < l; i++) {
        int sl = v[i].length();
        if (sl - digit >= 0) {
            c[v[i][sl - digit] - '0'].push_back(v[i]);
        }
        else {
            c[0].push_back(v[i]);
        }
    }
    i = 0;
    j = 0;
    for (auto j : c) {
        z = 0;
        while (z < j.second.size()) {
            v[i] = j.second[z];
            ++z;
            ++i;
        }
    }
}

void RadixSortStr(std::vector<string>& v) {
    int l;
    l = max_len(v);
    for (int i = 1; i <= l; i++) {
        cSortDigitStr(v, i);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////LinkedList Sortings///////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
void InsertionSort_LL(LinkedList<T>* L) {  
    int i, j, n;
    T key;
    n = L->getSize();
    for (i = 1; i <= n; i++) {
        key = L->getValue(i);
        j = i - 1;
        while (j >= 0 && L->getValue(j) > key) {
            L->swapNodes(j, j + 1);
            j--;
        }
        L->setValue(key, j + 1);
    }
}

template <typename T>
void Merge_LL(LinkedList<T>* L, int low, int high, int mid) {
    int i, j;
    std::vector<T> temp;
    i = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        T Li = L->getValue(i);
        T Lj = L->getValue(j);
        if (Li < Lj) {
            temp.push_back(Li);
            i++;
        }
        else {
            temp.push_back(Lj);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(L->getValue(i));
        i++;
    }
    while (j <= high) {
        temp.push_back(L->getValue(j));
        j++;
    }
    Node<T>* cur = new Node<T>;
    cur = L->getHead();
    for (int i = 1; i < low; i++) {
        cur = cur->next;
    }
    for (i = low; i <= high; i++) {
        cur->value = temp[i - low];
        cur = cur->next;
    }
}

template <typename T>
void MergeSort_LL(LinkedList<T>* L, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2; 
        MergeSort_LL(L, low, mid);
        MergeSort_LL(L, mid + 1, high);
        Merge_LL(L, low, high, mid);
    }
}


template <typename T>
int element_LL(LinkedList<T>* L, int low, int high) { 
    T pivot = L->getValue(high);
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (L->getValue(j) <= pivot) { 
            i++; 
            L->swapNodes(i, j); 
        } 
    } 
    L->swapNodes(i + 1, high); 
    return i + 1; 
} 

template <typename T>
void QuickSort_LL(LinkedList<T>* L, int low, int high) { 
    if (low < high) {
        int pi = element_LL(L, low, high);
        QuickSort_LL(L, low, pi - 1); 
        QuickSort_LL(L, pi + 1, high); 
    } 
}

void CountingSort_LL(LinkedList<int>* L) {
    int l = L->getMax();
    std::vector<int> co;
    int i;
    for (i = 0; i < l + 1; i++) {
        co.push_back(0);
    }
    Node<int>* cur = new Node<int>;
    cur = L->getHead();
    for (i = 1; i <= L->getSize(); i++) {
        co[cur->value] += 1;
        cur = cur->next;
    }
    cur = L->getHead();
    for (i = 0; i < l + 1; i++) {
        while (co[i]) {
            cur->value = i;
            co[i]--;
            cur = cur->next;
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////

string my_rnd(int k) {
    srand(clock());
    string res = "";
    int r = 0;
    for (int i = 0; i < k; i++) {
        r = rand() % 10;
        if (i == 0 && r == 0) r += 1;
        res += to_string(r);
    }
    return res;
}

string my_rnd_bin(int k) {
    srand(clock());
    string res = "";
    int r = 0;
    for (int i = 0; i < k; i++) {
        r = rand() % 2;
        if (i == 0 && r == 0) r += 1;
        res += to_string(r);
    }
    return res;
}


std::vector< std::vector<double> > test_VEC_INT() {
    std::vector<double> t1;
    std::vector<double> t2;
    std::vector<double> t3;
    std::vector<double> t4;
    std::vector<double> t5;
    for (int z = 1; z < 6; z++) {
        std::vector<int> init;
        for (int i = 0; i < 1000; i++) {
            int elem = abs(rand() % (int)pow(10, z));
            init.push_back(elem);
        }

        std::vector<int> v;
        for (int i = 0; i < 1000; i++) {
            v.push_back(init[i]);
        }
        clock_t f = clock();
        InsertionSort(v);
        f = clock() - f;
        t1.push_back((double)(f)/CLOCKS_PER_SEC);
        v.clear();


        for (int i = 0; i < 1000; i++) {
            v.push_back(init[i]);
        }
        f = clock();
        MergeSort(v, 0, v.size());
        f = clock() - f;
        t2.push_back((double)(f)/CLOCKS_PER_SEC);
        v.clear();

        for (int i = 0; i < 1000; i++) {
            v.push_back(init[i]);
        }
        f = clock();
        QuickSort(v, 0, v.size());
        f = clock() - f;
        t3.push_back((double)(f)/CLOCKS_PER_SEC);
        v.clear();

        for (int i = 0; i < 1000; i++) {
            v.push_back(init[i]);
        }
        f = clock();
        CountingSort(v);
        f = clock() - f;
        t4.push_back((double)(f)/CLOCKS_PER_SEC);
        v.clear();
        
        f = clock();
        RadixSort(init);
        f = clock() - f;
        t5.push_back((double)(f)/CLOCKS_PER_SEC);
        init.clear();
    }

    std::vector< std::vector<double> > res;

    res.push_back(t1);
    res.push_back(t2);
    res.push_back(t3);
    res.push_back(t4);
    res.push_back(t5);

    return res;
}


std::vector< std::vector<double> > test_LL_INT() {
    std::vector<double> t1;
    std::vector<double> t2;
    std::vector<double> t3;
    std::vector<double> t4;
    for (int z = 1; z < 6; z++) {
        std::vector<int> init;
        for (int i = 0; i < 1000; i++) {
            int elem = abs(rand() % (int)pow(10, z));
            init.push_back(elem);
        }

        LinkedList<int>* L = new LinkedList<int>;
        for (int i = 0; i < 1000; i++) {
            L->createNode(init[i]);
        }
        clock_t f = clock();
        InsertionSort_LL(L);
        f = clock() - f;
        t1.push_back((double)(f)/CLOCKS_PER_SEC);

        L = new LinkedList<int>;
        for (int i = 0; i < 1000; i++) {
            L->createNode(init[i]);
        }
        f = clock();
        MergeSort_LL(L, 1, 1000);
        f = clock() - f;
        t2.push_back((double)(f)/CLOCKS_PER_SEC);

        L = new LinkedList<int>;
        for (int i = 0; i < 1000; i++) {
            L->createNode(init[i]);
        }
        f = clock();
        QuickSort_LL(L, 1, 1000);
        f = clock() - f;
        t3.push_back((double)(f)/CLOCKS_PER_SEC);

        L = new LinkedList<int>;
        for (int i = 0; i < 1000; i++) {
            L->createNode(init[i]);
        }
        f = clock();
        CountingSort_LL(L);
        f = clock() - f;
        t4.push_back((double)(f)/CLOCKS_PER_SEC);
    }

    std::vector< std::vector<double> > res;
    res.push_back(t1);
    res.push_back(t2);
    res.push_back(t3);
    res.push_back(t4);

    return res;
}

std::vector< std::vector<double> > test_VEC_STR() {
    std::vector<double> t1;
    std::vector<double> t2;
    std::vector<double> t3;
    std::vector<double> t4;
    for (int z = 6; z < 11; z++) {
        std::vector<string> init;
        for (int i = 0; i < 1000; i++) {
            init.push_back(my_rnd(z));
        }

        std::vector<string> v;
        for (int i = 0; i < 1000; i++) {
            v.push_back(init[i]);
        }
        clock_t f = clock();
        InsertionSort(v);
        f = clock() - f;
        t1.push_back((double)(f)/CLOCKS_PER_SEC);
        v.clear();


        for (int i = 0; i < 1000; i++) {
            v.push_back(init[i]);
        }
        f = clock();
        MergeSort(v, 0, v.size());
        f = clock() - f;
        t2.push_back((double)(f)/CLOCKS_PER_SEC);
        v.clear();

        for (int i = 0; i < 1000; i++) {
            v.push_back(init[i]);
        }
        f = clock();
        QuickSort(v, 0, v.size());
        f = clock() - f;
        t3.push_back((double)(f)/CLOCKS_PER_SEC);
        v.clear();
        
        for (int i = 0; i < 1000; i++) {
            v.push_back(my_rnd_bin(z));
        }
        f = clock();
        RadixSortStr(v);
        f = clock() - f;
        t4.push_back((double)(f)/CLOCKS_PER_SEC);
        init.clear();
        v.clear();
    }

    std::vector< std::vector<double> > res;
    res.push_back(t1);
    res.push_back(t2);
    res.push_back(t3);
    res.push_back(t4);

    return res; 
}


std::vector< std::vector<double> > test_LL_STR() {
    std::vector<double> t1;
    std::vector<double> t2;
    std::vector<double> t3;
    for (int z = 1; z < 6; z++) {
        std::vector<string> init;
        for (int i = 0; i < 1000; i++) {
            init.push_back(my_rnd(z));
        }

        LinkedList<string>* L = new LinkedList<string>;
        for (int i = 0; i < 1000; i++) {
            L->createNode(init[i]);
        }
        clock_t f = clock();
        InsertionSort_LL(L);
        f = clock() - f;
        t1.push_back((double)(f)/CLOCKS_PER_SEC);

        L = new LinkedList<string>;
        for (int i = 0; i < 1000; i++) {
            L->createNode(init[i]);
        }
        f = clock();
        MergeSort_LL(L, 1, 1000);
        f = clock() - f;
        t2.push_back((double)(f)/CLOCKS_PER_SEC);

        L = new LinkedList<string>;
        for (int i = 0; i < 1000; i++) {
            L->createNode(init[i]);
        }
        f = clock();
        QuickSort_LL(L, 1, 1000);
        f = clock() - f;
        t3.push_back((double)(f)/CLOCKS_PER_SEC);
    }

    std::vector< std::vector<double> > res;
    res.push_back(t1);
    res.push_back(t2);
    res.push_back(t3);

    return res;
}

void writeCSV() {
    ofstream file;
    std::vector< std::vector<double> > res;
    int i, j;

    // file.open ("vec_int.csv");
    // res = test_VEC_INT();
    // for (i = 0; i < 5; i++) {
    //     file << i + 1;
    //     for (j = 0; j < 5; j++) {
    //         file << "," << res[j][i];
    //     }
    //     file << endl;
    // }
    // res.clear();

    ofstream file2;
    file2.open ("vec_str.csv");
    res = test_VEC_STR();
    for (i = 0; i < 5; i++) {
        file2 << i + 1;
        for (j = 0; j < 4; j++) {
            file2 << "," << res[j][i];
        }
        file2 << endl;
    }
    res.clear();

    ofstream file3;
    file3.open ("list_int.csv");
    res = test_LL_INT();
    for (i = 0; i < 5; i++) {
        file3 << i + 1;
        for (j = 0; j < 4; j++) {
            file3 << "," << res[j][i];
        }
        file3 << endl;
    }
    res.clear();

    ofstream file4;
    file4.open ("list_str.csv");
    res = test_LL_STR();
    for (i = 0; i < 5; i++) {
        file4 << i + 1;
        for (j = 0; j < 3; j++) {
            file4 << "," << res[j][i];
        }
        file4 << endl;
    }
    res.clear();
}

int main() {
    writeCSV();
}









