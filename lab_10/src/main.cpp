#include <array>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
static const int N = 10;
class VectoredList {
    int size;
    int capacity;
public:
    class Bucket {
    public:
        Bucket* prev;
        Bucket* next;
        std::array <std::string, N> elements;
        int CurrentSize;
        Bucket() :CurrentSize(0), prev(0), next(0) {
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
    VectoredList() : size(0), capacity(N), head(0), tail(0) {};
    VectoredList(const VectoredList& v) :head(0), tail(0), size(0), capacity(N) {
        VectoredList::VectoredListIterator it = v.begin();
        VectoredList::VectoredListIterator end;
        end.bucket = v.get_tail();
        end.cursor = v.get_tail()->CurrentSize;
        while (it.bucket->elements[it.cursor] != end.bucket->elements[end.cursor]) {
            this->push_back(it.bucket->elements[it.cursor]);
            ++it;
        }
    }
    ~VectoredList() {
        Bucket* tmp = head;
        Bucket* tmp2;
        while (tmp) {
            tmp2 = tmp;
            tmp = tmp->next;
            delete(tmp2);
            size--;
        }
        delete(tmp);
    }
    Bucket* get_head()const { return head; }
    Bucket* get_tail()const { return tail; }
    int get_size()const { return size; }
    int get_capacity()const { return capacity; }
    void change_tail(Bucket* bucket) {
        tail = bucket;
    }
    void change_head(Bucket* bucket) {
        head = bucket;
    }
    void change_size(int n) {
        size = n;
    }
    void push_back(std::string s) {
        if (size == 0) {
            Bucket* bucket = new Bucket();
            change_head(bucket);
            change_tail(bucket);
            get_head()->prev = 0;
            get_head()->next = 0;
            get_tail()->prev = 0;
            get_tail()->next = 0;
            size++;
        }
        Bucket* bucket = get_tail();
        if (bucket->CurrentSize < capacity) {
            bucket->elements[bucket->CurrentSize] = s;
            bucket->CurrentSize++;
        }
        else {
            Bucket* next= new Bucket();
            size++;
            bucket->next = next;
            next->prev = bucket;
            next->next = 0;
            change_tail(next);
            next->elements[0] = s;
            next->CurrentSize++;
        }
    }
    VectoredListIterator begin() const { return VectoredListIterator(*this, 0); }
    VectoredListIterator end() {
        VectoredListIterator i;
        if (get_tail()->CurrentSize == N) {
            Bucket* bucket = new Bucket();
            get_tail()->next = bucket;
            bucket->next = 0;
            bucket->prev = get_tail();
            change_tail(bucket);
            size++;
        }
        i.bucket = get_tail();
        i.cursor = get_tail()->CurrentSize;
        return i;
    }
    VectoredListIterator last_element() {
        VectoredListIterator end = this->end();
        --end;
        return end;
    }
    void pop_back() {
        Bucket* end = get_tail();
        if (end->CurrentSize == 0) {
            end->prev->elements[end->prev->CurrentSize - 1] = "";
            end->prev->CurrentSize--;
            end->prev->next = 0;
            change_tail(end->prev);
            delete end;
            size--;
        }
        else {
            end->elements[end->CurrentSize - 1] = "";
            end->CurrentSize--;
        }
    }
    int VectoredListSize() {
        int i = 0;
        if (get_size() == 0) return 0;
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
    Bucket* bucket = head;
    Bucket* tmp;
    while (bucket) {
        tmp = bucket;
        bucket = bucket->next;
        delete(tmp);
        size--;
    }
    delete(bucket);
    VectoredList::VectoredListIterator it = v.begin();
    VectoredList::VectoredListIterator end;
    end.bucket = v.get_tail();
    end.cursor = v.get_tail()->CurrentSize;
    while (it != end) {
        this->push_back(it.bucket->elements[it.cursor]);
        ++it;
    }
    cout << "(operator= [lvalue]) Ctor move (head):" << this->get_head() << endl;
    cout << "(operator= [lvalue]) Ctor move (tail):" << this->get_tail() << endl;
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
     VectoredList v2 = v; //deep_copy
      for (int i = 0; i < v2.VectoredListSize(); ++i)
      {
          cout << v2[i] << " ";
          if (i % 10 == 0)
              cout << endl;
      }

      // i've created operator=() overload too, but in this case we're using deep_copy constructor
      //this also works:
      /*
      VectoredList v3;
      v3 = v;
      cout<<endl<<endl;
      for (int i = 0; i < v3.VectoredListSize(); ++i)
      {
          cout << v3[i] << " ";
          if (i % 10 == 0)
              cout << endl;
      }*/
}