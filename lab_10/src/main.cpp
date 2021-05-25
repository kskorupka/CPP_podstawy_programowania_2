#include <array>
#include <iostream>
#include <string>
using namespace std;
static const int N = 10;
class VectoredList {
    int size;
    int capacity = N;
public:
    class Bucket {
    public:
        Bucket* prev;
        Bucket* next;
        std::array <std::string, N> elements;
        int CurrentSize;
        Bucket() :CurrentSize(0) {
            for (int i = 0; i < N; i++) elements[i] = "";
        }
        ~Bucket() {};
    };
    class VectoredListIterator {
    public:
        Bucket* bucket;
        int cursor;
        VectoredListIterator() :bucket(0), cursor(0) {}
        VectoredListIterator(const VectoredList& vectoredlist, double n) :bucket(vectoredlist.get_head()), cursor(0) {
            int i = 0;
            while (i < n && bucket) {
                i++;
                cursor++;
                if (i % vectoredlist.get_capacity() == 0) {
                    bucket = bucket->next;
                    cursor = 0;
                }
            }
        }
        VectoredListIterator& operator--() {
            if (cursor > 0) cursor--;
            else {
                if (bucket) bucket = bucket->prev;
                cursor = N - 1;
            }
            return *this;
        }
        VectoredListIterator& operator++() {
            if (cursor < N - 1) cursor++;
            else {
                if (bucket) bucket = bucket->next;
                cursor = 0;
            }
            return *this;
        }
        std::string operator*() {
            return bucket->elements[cursor];
        }
        bool good()const { return bucket != 0; }
        std::string get()const { return bucket->elements[cursor]; }
    };
private:
    Bucket* head;
    Bucket* tail;
public:
    VectoredList() {
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
    Bucket* get_head()const { return head; }
    Bucket* get_tail()const { return tail; }
    int get_size()const { return size; }
    int get_capacity()const { return capacity; }
    void change_tail(Bucket* bucket) {
        tail = bucket;
    }
    VectoredListIterator begin() const { return VectoredListIterator(*this, 0); }
    VectoredListIterator end() {
        VectoredListIterator i;
        if (this->get_tail()->CurrentSize == N) {
            Bucket* bucket = new Bucket();
            this->get_tail()->next = bucket;
            bucket->next = 0;
            bucket->prev = this->get_tail();
            this->change_tail(bucket);
        }
        i.bucket = this->get_tail();
        i.cursor = this->get_tail()->CurrentSize;
        return i;
    }
    VectoredListIterator last_element() {
        VectoredListIterator end = this->end();
        --end;
        return end;
    }
    void pop_back() {
        Bucket* end = this->get_tail();
        if (end->CurrentSize == 0) {
            end->prev->elements[end->prev->CurrentSize - 1] = "";
            end->prev->CurrentSize--;
            end->prev->next = 0;
            change_tail(end->prev);
            delete end;
        }
        else {
            end->elements[end->CurrentSize - 1] = "";
            end->CurrentSize--;
        }
    }
    int VectoredListSize() {
        int i = 0;
        VectoredListIterator start = this->begin();
        VectoredListIterator end = this->end();
        do {
            ++i;
            ++start;
        } while (start.bucket->elements[start.cursor] != end.bucket->elements[end.cursor]);
        return i;
    }
    void erase(VectoredListIterator it);
    void erase(VectoredListIterator it1, VectoredListIterator it2);
    VectoredList& operator=(const VectoredList& v);
    std::string operator[](int i) {
        VectoredListIterator it(*this, i);
        return it.bucket->elements[it.cursor];
    }
};
bool operator!=(VectoredList::VectoredListIterator& it1, VectoredList::VectoredListIterator& it2) {
    return (it1.bucket->elements[it1.cursor] != it2.bucket->elements[it2.cursor]);
}
void VectoredList::erase(VectoredList::VectoredListIterator it) {
    VectoredListIterator ptr = VectoredListIterator(*this, 0);
    VectoredListIterator end = this->end();
    while (ptr != it) { ++ptr; }
    VectoredListIterator pom = ptr;
    ++pom;
    while (pom != end) {
        ptr.bucket->elements[ptr.cursor] = pom.bucket->elements[pom.cursor];
        ++pom;
        ++ptr;
    }
    (*this).pop_back();
}
void VectoredList::erase(VectoredList::VectoredListIterator it1, VectoredList::VectoredListIterator it2) {
    VectoredListIterator ptr = VectoredListIterator(*this, 0);
    while (ptr != it1) { ++ptr; }
    VectoredListIterator pom = ptr;
    while (pom != it2) { ++pom; }
    ++pom;
    std::string tmp;
    VectoredListIterator end = this->end();
    while (pom != end) {
        tmp = pom.bucket->elements[pom.cursor];
        ptr.bucket->elements[ptr.cursor] = tmp;
        ++pom;
        ++ptr;
    }
    do {
        (*this).pop_back();
        end = this->end();
    } while (ptr != end);
}
VectoredList& VectoredList:: operator=(const VectoredList& v) {
    if (&v == this) return *this;
    VectoredList::VectoredListIterator it = v.begin();
    VectoredList::VectoredListIterator end;
    end.bucket = v.get_tail();
    end.cursor = v.get_tail()->CurrentSize;
    while (it != end) {
        this->push_back(it.bucket->elements[it.cursor]);
        ++it;
    }
    return *this;
}
int main() {
    cout << endl << "---------- 1,2 ----------" << endl;
     VectoredList v;
     for (int i = 0; i < 101; ++i)
         v.push_back("s" + to_string(i));

     for (VectoredList::VectoredListIterator ita(v, 101); ita.good(); --ita)
     {
         cout << ita.get() << " ";
         if (ita.cursor % 10 == 0)
             cout << endl;
     }

    cout << endl << "---------- 3 ----------" << endl;;
     for (const auto &element : v)
         cout << element << "AAA" << endl;

    cout << endl << "---------- 4 ----------" << endl;
     VectoredList::VectoredListIterator it3(v, 3);
     VectoredList::VectoredListIterator it33(v, 33);
     VectoredList::VectoredListIterator it45(v, 45);

     v.erase(it3);
     v.pop_back();
     v.pop_back();
     v.erase(it33, it45);
     for (int i = 0; i < v.VectoredListSize(); ++i)
     {
         cout << v[i] << " ";
         if (i % 10 == 0)
             cout << endl;
     }
     cout << endl << "---------- 5 ----------" << endl;
     //VectoredList v2=v; //this doesn't work, but the next one works
     VectoredList v2;
     v2 = v;
      for (int i = 0; i < v2.VectoredListSize(); ++i)
      {
          cout << v2[i] << " ";
          if (i % 10 == 0)
              cout << endl;
      }
}