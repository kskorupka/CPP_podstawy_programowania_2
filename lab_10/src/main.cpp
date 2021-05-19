#include <array>
#include <iostream>
#include <string>
using namespace std;
static const int N = 10;
class VectoredList {
    int size;
    int capacity = N;
public:
    class Bucket{
    public:
        Bucket* prev;
        Bucket* next;
        std::array <std::string, N> elements;
        int CurrentSize;
        Bucket() {}
        ~Bucket() {}
    };
    /*class VectoredListIterator {
        //VectoredList vectoredlist;
        Bucket* cursor;
    public:
        VectoredListIterator(VectoredList &_vectoredlist){
        }
    };*/
private:
    Bucket* head;
    Bucket* tail;
public:
    VectoredList(){
        Bucket* bucket = new Bucket();
        head = bucket;
        tail = bucket;
        bucket->prev = 0;
        bucket->next = 0;
        size = 1;
    }
    ~VectoredList() {
        Bucket* tmp = head;
        Bucket* tmp2;
        while (tmp) {
            tmp2 = tmp;
            tmp = tmp->next;
            delete(tmp2);
        }
    }
    void push_back(std::string s) {
        Bucket* ptr = this->head;
        while (ptr->next) { ptr = ptr->next; }
        if (ptr->CurrentSize < this->capacity) {
            ptr->elements[ptr->CurrentSize] = s;
            ptr->CurrentSize++;
        }
        else {
            Bucket* bucket = new Bucket();
            Bucket* ptr = this->head;
            while (ptr->next) { ptr = ptr->next; }
            bucket->prev = ptr;
            bucket->next = 0;
            ptr->next = bucket;
            this->tail = bucket;
            bucket->elements[0] = s;
        }
    }
    Bucket* get_head() { return head; }
    Bucket* get_tail() { return tail; }
    int get_size() { return size; }
    int get_capacity() { return capacity; }
};
/*
VectoredList::Bucket::Bucket() {
    Bucket* ptr = head;
    while (ptr) {
        ptr = ptr->next;
    }
    prev = ptr;
    next = 0;
}*/
int main()
{
    cout << endl << "---------- 1,2 ----------" << endl;
     VectoredList v;
     for (int i = 0; i < 101; ++i)
         v.push_back("s" + to_string(i));

     //done
     VectoredList::Bucket* start = v.get_head();
     /*
     while (start) {
         for (int i = 0; i < v.get_capacity(); i++) std::cout << start->elements[i] << " ";
         std::cout << std::endl;
         start = start->next;
     }*/


    // for (VectoredList::VectoredListIterator ita(v, 101); ita.good(); --ita)
    // {
    //     cout << ita.get() << " ";
    //     if (ita.cursor % 10 == 0)
    //         cout << endl;
    // }

    cout << endl << "---------- 3 ----------" << endl;;
    // for (const auto &element : v)
    //     cout << element << "AAA" << endl;

    cout << endl << "---------- 4 ----------" << endl;
    // VectoredList::VectoredListIterator it3(v, 3);
    // VectoredList::VectoredListIterator it33(v, 33);
    // VectoredList::VectoredListIterator it45(v, 45);

    // v.erase(it3);
    // v.pop_back();
    // v.pop_back();
    // v.erase(it33, it45);
    // for (int i = 0; i < v.VectoredListSize(); ++i)
    // {
    //     cout << v[i] << " ";
    //     if (i % 10 == 0)
    //         cout << endl;
    // }

    cout << endl << "---------- 5 ----------" << endl;
    // VectoredList v2 = v;
    // for (int i = 0; i < v2.VectoredListSize(); ++i)
    // {
    //     cout << v2[i] << " ";
    //     if (i % 10 == 0)
    //         cout << endl;
    // }
}