//
// Created by petrm on 05.03.2022.
//

#ifndef FAST_LINKEDLIST_H
#define FAST_LINKEDLIST_H


#include <iostream>
#include <algorithm>

namespace LinkedList{

    template <typename T> class LinkedList;
    template <typename T> class NodeList;

    template<typename T> std::ostream& operator<< (std::ostream& os, const LinkedList<T>& other);
    template <typename T>
    class NodeList{
    public:
        T val; // :((((
        NodeList* next;
        NodeList* prev;

    public:
        friend class LinkedList<T>;
        friend class Iterator;
        NodeList();
        NodeList(NodeList* prev, NodeList* next, T val);
        NodeList(const NodeList& other);
        /*NodeList<T>& operator =(const T value);
        bool operator> (const NodeList<T>& other) const;
        bool operator< (const NodeList<T>& other) const;
        bool operator>= (const NodeList<T>& other) const;
        bool operator<= (const NodeList<T>& other) const;
        bool operator ==(const NodeList<T>& other) const;
        bool operator !=(const NodeList<T>& other) const;
        bool operator ==(const T& other) const;
        bool operator !=(const T& other) const;
        bool operator >(const T& other) const;
        bool operator >=(const T& other) const;
        bool operator <=(const T& other) const;
        bool operator <(const T& other) const;
        T& operator*();*/
    };

    template <typename T>
    class LinkedList{
    public:
        class Iterator;
        class ReverseIterator;
        typedef  T value_type;
        typedef size_t size_type;
        typedef  value_type& reference;
        typedef const value_type & const_reference;
        typedef LinkedList::Iterator iterator;
        typedef LinkedList::ReverseIterator reverse_iterator;
        typedef const LinkedList::Iterator const_iterator;
    private:

        NodeList<T>* tail;
        size_type count;


    public:
//        friend std::ostream& operator<<<T>(std::ostream& os, const LinkedList<T>& other);
        NodeList<T>* head;
        LinkedList();
//        ~LinkedList();
        LinkedList(const LinkedList&);
        void push_back(const value_type& val);
        void push_front(const value_type& value);
        void pop_front();
        void pop_back();
        void insert(T val, int nmb);
        bool empty() const;
        size_type size() const;
        T& front() const;
        T& back() const;
        void assign(T val, int nmb);
        void resize(size_type size, value_type value = 0);
        void clear();
        void swap(LinkedList<T>& other);
        void copy (const LinkedList& other);
        int operator [](int ind) const;
        void reverse();
        void erase(iterator pos);
        void erase(iterator first, iterator second);
        Iterator begin();
        Iterator end();
        ReverseIterator rbegin();
        ReverseIterator rend();
        friend std::ostream& operator<< <> (std::ostream& os, const LinkedList<T>& other);

    };

    template <typename T>
    class LinkedList<T>::Iterator{
    public:

        typedef std::ptrdiff_t difference_type;
        using value_type = value_type;
        typedef value_type* pointer;  // or also value_type*
        typedef value_type& reference;
        typedef std::random_access_iterator_tag iterator_category;
        friend class ReverseIterator;
    private:
        NodeList<T>* my_pointer;
        friend class LinkedList;
    public:
        Iterator();
        explicit Iterator(NodeList<T>* pointer);
        Iterator ( Iterator& other);
        Iterator (const Iterator& other);
        Iterator (const ReverseIterator& other);
        Iterator& operator++ ();
        Iterator& operator++ (int)&;
        Iterator& operator--();
        size_t operator-(const Iterator& other);
        Iterator operator-(int cnt);
        Iterator operator+ (int cnt);
        void operator =(const value_type value);
        bool operator ==(const Iterator& other) const;
        bool operator !=(const Iterator& other) const;
        bool operator >(const Iterator& other) const;
        bool operator <(const Iterator& other) const;
        bool operator >=(const Iterator& other) const;
        bool operator <=(const Iterator& other) const;
        reference operator[](int diff) const;
        NodeList<T>* operator-> ();

        value_type& operator*();
    };


    template <typename T>
    class LinkedList<T>::ReverseIterator{
    public:

        typedef std::ptrdiff_t difference_type;
        using value_type = value_type;
        typedef value_type* pointer;  // or also value_type*
        typedef value_type& reference;
        typedef std::random_access_iterator_tag iterator_category;
        friend class Iterator;
    private:
        NodeList<T>* my_pointer;

    public:
        ReverseIterator();
        explicit ReverseIterator(NodeList<T>* pointer);
        ReverseIterator (const ReverseIterator& other);
        ReverseIterator(const Iterator& other);


        ReverseIterator& operator++ ();
        ReverseIterator& operator++ (int)&;
        ReverseIterator& operator--();
        size_t operator-(const ReverseIterator& other);
        ReverseIterator operator-(int cnt);
        ReverseIterator operator+ (int cnt);
        void operator =(const value_type value);
        bool operator ==(const ReverseIterator& other) const;
        bool operator !=(const ReverseIterator& other) const;
        bool operator >(const ReverseIterator& other) const;
        bool operator <(const ReverseIterator& other) const;
        bool operator >=(const ReverseIterator& other) const;
        bool operator <=(const ReverseIterator& other) const;
        reference operator[](int diff) const;
        NodeList<T>* operator-> ();

        value_type& operator*();
    };

}



#endif //FAST_LINKEDLIST_H
