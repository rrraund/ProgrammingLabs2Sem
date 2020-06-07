#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


template<typename T>
class CircularBuffer
{
private:
    int bufSize = 0;
    int curPos;
    T *arr;

public:
    class iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
    private:
        T *ptr;

    public:
        iterator() : ptr(nullptr) {}
        explicit iterator(T *ptr) : ptr(ptr) {}
        iterator(const iterator &itr) : ptr(itr.ptr) {}

        iterator &operator+=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type diff)
        {
            ptr += diff;
            return *this;
        }

        iterator &operator-=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type diff)
        {
            ptr -= diff;
            return *this;
        }

        T &operator*() const
        {
            return *ptr;
        }

        T *operator->() const
        {
            return ptr;
        }

        T &operator[](typename std::iterator<std::random_access_iterator_tag, T>::difference_type diff) const
        {
            return ptr[diff];
        }

        iterator &operator++()
        {
            ptr++;
            return *this;
        }

        iterator &operator--()
        {
            ptr--;
            return *this;
        }

        iterator operator++(T)
        {
            iterator tmp(*this);
            ++ptr;
            return tmp;
        }

        iterator operator--(T)
        {
            iterator tmp(*this);
            --ptr;
            return tmp;
        }

        bool operator==(const iterator &itr) const
        {
            return ptr == itr.ptr;
        }

        bool operator!=(const iterator &itr) const
        {
            return ptr != itr.ptr;
        }

        bool operator>(const iterator &itr) const
        {
            return ptr > itr.ptr;
        }

        bool operator<(const iterator &itr) const
        {
            return ptr < itr.ptr;
        }

        bool operator>=(const iterator &itr) const
        {
            return ptr >= itr.ptr;
        }

        bool operator<=(const iterator &itr) const
        {
            return ptr <= itr.ptr;
        }

        iterator operator+(typename std::iterator<std::random_access_iterator_tag, T>::difference_type diff) const
        {
            return iterator(ptr + diff);
        }

        iterator operator-(typename std::iterator<std::random_access_iterator_tag, T>::difference_type diff) const
        {
            return iterator(ptr - diff);
        }

        typename std::iterator<std::random_access_iterator_tag, T>::difference_type operator-(const iterator &itr) const
        {
            return ptr - itr.ptr;
        }
    };

public:
    CircularBuffer(int size_)
    {
        bufSize = size_;
        arr = new T[bufSize];
        curPos = 0;
        for (int i = 0; i < bufSize; i++)
        {
            arr[i] = 0;
        }
    }

    CircularBuffer(int size_, T value) : bufSize(size_)
    {
        arr = new T[bufSize];
        curPos = 0;
        for (int i = 0; i < bufSize; i++)
        {
            arr[i] = value;
        }
    }

    ~CircularBuffer()
    {
        delete[] arr;
    }

    void pushBack(T v)
    {
        arr[curPos] = v;
        if (curPos == (bufSize - 1))
        {
            curPos = 0;
        }
        else
        {
            curPos++;
        }
    }

    int size()
    {
        return bufSize;
    }

    void popBack()
    {
        arr[bufSize - 1] = 0;
        curPos--;
        bufSize--;
    }

    void pushFront(T v)
    {
        T *tempArr = new T[bufSize];
        tempArr[0] = v;
        for (int i = 1; i < bufSize; i++)
        {
            tempArr[i] = arr[i - 1];
        }
        for (int i = 0; i < bufSize; i++)
        {
            arr[i] = tempArr[i];
        }
    }

    void pushAt(const iterator it, T value)
    {
        T *tempArr = new T[bufSize];
        int i;
        for (i = 0; i < bufSize; i++)
        {
            if (it == &(arr[i]))
            {
                tempArr[i] = value;
                break;
            }
            else
            {
                tempArr[i] = arr[i];
            }
        }
        i++;
        for (int j = i - 1; j < bufSize; j++)
        {
            if (i == bufSize)
            {
                i = 0;
            }
            tempArr[i] = arr[j];
            i++;
        }
        for (int i = 0; i < bufSize; i++)
        {
            arr[i] = tempArr[i];
        }

    }

    void popAt(const iterator it)
    {
        if (it >= end())
        {
            throw invalid_argument("Circular buffer out of range");
        }
        T *tempArr = new T[bufSize];
        int j = 0;
        for (int i = 0; i < bufSize; i++)
        {
            if (it == &(arr[j]))
            {
                j++;
                i--;
            }
            else
            {
                tempArr[i] = arr[j];
                j++;
            }
        }
        for (int i = 0; i < bufSize; i++)
        {
            arr[i] = tempArr[i];
        }
        bufSize--;
    }

    void popFront()
    {
        for (int i = 0; i < bufSize - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        bufSize--;
    }

    T getFirst()
    {
        return arr[0];
    }

    T getLast()
    {
        return arr[bufSize - 1];
    }

    iterator begin()
    {
        return iterator(arr);
    }

    iterator end()
    {
        return iterator(&(arr[bufSize]));
    }

    const T operator[](int ind)
    {
        if (ind >= bufSize)
        {
            throw invalid_argument("Circular buffer out of range");
        }
        else
        {
            return arr[ind];
        }
    }

    void print()
    {
        for (int i = 0; i < this->bufSize; i++)
        {
            cout << this->arr[i] << " ";
        }
        cout << endl;
    }

    void resize(const size_t& newSize)
    {
        T* NewBuffer;
        if (newSize < bufSize)
        {
            NewBuffer = new T[newSize];
            for (int i = 0; i < newSize; i++)
            {
                NewBuffer[i] = arr[i % bufSize];
            }
            delete[] arr;
            arr = NewBuffer;
            bufSize = newSize;
        }
        else
        {
            NewBuffer = new T[newSize];
            for (int i = 0; i < bufSize; i++)
            {
                NewBuffer[i] = arr[i % bufSize];
            }
            delete[] arr;
            arr = NewBuffer;
            bufSize = newSize;
        }
    }
};



int main()
{
    CircularBuffer<int> buffer(5);
    for (int i = 0; i < 5; i++)
    {
        buffer.pushBack(i * -100);
    }
    buffer.print();
    sort(buffer.begin(), buffer.end());
    buffer.print();

    buffer.resize(10);
    buffer.print();

    buffer.resize(20);
    for (int i = 0; i < 20; i++)
    {
        buffer.pushBack(i * -100);
    }
    sort(buffer.begin(), buffer.end());
    buffer.print();
    reverse(buffer.begin(), buffer.end());
    buffer.pushBack(777);
    buffer.print();

    cout << buffer.getFirst() << endl;
    cout << buffer.getLast() << endl;

    return 0;
}