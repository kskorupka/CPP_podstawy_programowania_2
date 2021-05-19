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
        Bucket() {};
        ~Bucket() {};
    };
    class VectoredListIterator {
    public:
        Bucket* bucket;
        int cursor;
        VectoredListIterator():bucket(0),cursor(0){}
        VectoredListIterator(VectoredList& vectoredlist, double n):bucket(vectoredlist.get_head()),cursor(0){
            int i = 0;
            while (i < (n-1) && bucket) {
                i++;
                cursor++;
                if (i % vectoredlist.get_capacity() == 0) {
                    bucket = bucket->next;
                    cursor = 0;
                }
            }
        }
        VectoredListIterator&operator--() {
            if (cursor > 0) cursor--;
            else {
                if (bucket) bucket = bucket->prev;
                cursor = N-1;
            }
            return *this;
        }
        VectoredListIterator&operator++() {
            if (cursor < N-1) cursor++;
            else {
                if (bucket) bucket = bucket->next;
                cursor = 0;
            }
            return *this;
        }
        std::string operator*(){
            return bucket->elements[cursor];
        }
        bool good()const{ return bucket != 0; }
        std::string get()const{ return bucket->elements[cursor]; }
    };
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
            bucket->CurrentSize++;
        }
    }
    Bucket* get_head()const{ return head; }
    Bucket* get_tail()const{ return tail; }
    int get_size()const{ return size; }
    int get_capacity()const{ return capacity; }
    VectoredListIterator begin() { return VectoredListIterator(*this, 0); }
    VectoredListIterator end() {
        VectoredListIterator i;
        i.bucket = this->get_tail();
        i.cursor = this->get_tail()->CurrentSize - 1;
        return i;
    }
};
bool operator!=(VectoredList::VectoredListIterator& it1, VectoredList::VectoredListIterator& it2) {
    return (it1.bucket->elements[it1.cursor] != it2.bucket->elements[it2.bucket->CurrentSize]);
}
int main()
{
    cout << endl << "---------- 1,2 ----------" << endl;
     VectoredList v;
     for (int i = 0; i < 101; ++i)
         v.push_back("s" + to_string(i));

     //done
     //VectoredList::Bucket* start = v.get_head();
    
     /*
     while (start) {
         for (int i = 0; i < v.get_capacity(); i++) std::cout << start->elements[i] << " ";
         std::cout << std::endl;
         start = start->next;
     }*/

     for (VectoredList::VectoredListIterator ita(v, 101); ita.good(); --ita)
     {
         cout << ita.get() << " ";
         if (ita.cursor % 10 == 0)
             cout << endl;
     }

     //done
     
    cout << endl << "---------- 3 ----------" << endl;;
     for (const auto &element : v)
         cout << element << "AAA" << endl;
         
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