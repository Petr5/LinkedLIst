
#include "LinkedList.h"

namespace LinkedList{

    template <typename T> NodeList<T>::NodeList(): prev(nullptr), next(nullptr), val(){};
    template <typename T> NodeList<T>::NodeList(NodeList* prev, NodeList* next, T val): prev(prev), next(next), val(val){};

    template <typename T> NodeList<T>::NodeList(const NodeList& other): prev(other.prev), next(other.next), val(other.val){};

    /*template <typename T> T& NodeList<T>::operator*(){
        return this->val;
    }
    template <typename T> NodeList<T>& NodeList<T>::operator =(const T value){
        this->val = value;
        return *this;
    }

    template <typename T> bool NodeList<T>::operator> (const NodeList<T>& other) const{
        return this->val > other.val;
    }
    template <typename T> bool NodeList<T>::operator< (const NodeList<T>& other) const{
        return this->val < other.val;
    }
    template <typename T> bool NodeList<T>::operator>= (const NodeList<T>& other) const{
        return !*this < other;
    }
    template <typename T> bool NodeList<T>::operator<= (const NodeList<T>& other) const{
        return !*this > other;
    }
    template <typename T> bool NodeList<T>::operator ==(const NodeList<T>& other) const{
        return this->val == other.val;
    }
    template <typename T> bool NodeList<T>::operator !=(const NodeList<T>& other) const{
        return !*this = other;
    }
    template <typename T> bool NodeList<T>::operator ==(const T& other) const{
        return this->val == other;
    }
    template <typename T> bool NodeList<T>::operator !=(const T& other) const{
        return !*this == other;
    }
    template <typename T> NodeList<T>::operator T(){
        return this->val;
    }
    template <typename T> bool NodeList<T>::operator >(const T& other) const{
        return this->val > other;
    }
    template <typename T> bool NodeList<T>::operator >=(const T& other) const{
        return (*this > other) || (*this == other);
    }
    template <typename T> bool NodeList<T>::operator <=(const T& other) const{
        return (*this < other) || (*this == other);
    }
    template <typename T> bool NodeList<T>::operator <(const T& other) const{
        return this->val < other;
    }*/

    template <typename T> LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr), count(){};
    template <typename T> LinkedList<T>::LinkedList(const LinkedList<T>& other){
        this->copy(other);
    }
    template <typename T> void LinkedList<T>::push_back(const value_type& value){
        if(!count){
            this->tail = this->head = new NodeList<T>(nullptr, nullptr, value);
            head->next = new NodeList<T>(head, nullptr, 0);
            tail->prev = new NodeList<T>(nullptr, tail, 0);
            ++count;
        }
        else{
            head->next = new NodeList<T>(head, nullptr, value);
            head = head->next;
            head->next = new NodeList<T>(head, nullptr, 0);
            ++count;

        }
    }
    template <typename T> void LinkedList<T>::push_front(const value_type& value){
        if(!count){
            this->tail = this->head = new NodeList<T>(nullptr, nullptr, value);
            ++count;
            tail->prev = new NodeList<T>(nullptr, tail, 0);
            head->next = new NodeList<T>(head, nullptr, 0);
        }
        else{
            tail->prev = new NodeList<T>(nullptr, tail, value);

            tail = tail->prev;
            tail->prev = new NodeList<T>(nullptr, tail, 0);
            ++count;
        }
    }
    template <typename T> void LinkedList<T>::pop_front(){
        if (count == 1){
            delete head;
           head = tail = nullptr; --count;
        }
        else{
            auto temp = tail;
            tail = tail->next;
            tail->prev = new NodeList<T>(nullptr, tail, 0);
            --count;
            delete temp;
        }

    }
    template <typename T> void LinkedList<T>::pop_back(){
        if (count == 1) {delete head; head = tail = nullptr; count = 0;}
        else{
            auto temp = head;
            head = head->prev;
            head->next = new NodeList<T>(head, nullptr, 0);
            --count;
            delete temp;
        }
    }
    template <typename T> void LinkedList<T>::insert(T val, int nmb){
        for (int i = 0; i < nmb; ++i)
            push_back(val);
    }
    template <typename T> void LinkedList<T>::assign(T val, int nmb){
        for (int i = 0; i < nmb; ++i)
            push_back(val);
    }
    template <typename T> void LinkedList<T>::erase(iterator pos){
        if (pos == end()) ;
        else if (pos == begin() - 1) ;
        else if (pos.my_pointer == head){
            auto prev = pos->prev;
            auto next = pos->next;
            prev->next = next;
            next->prev = prev;
            head = prev;
        }
        else if (pos.my_pointer == tail){
            auto prev = pos->prev;
            auto next = pos->next;
            prev->next = next;
            next->prev = prev;
            tail = next;
        }
        else{
            auto prev = pos->prev;
            auto next = pos->next;
            prev->next = next;
            next->prev = prev;
        }
    }
    template <typename T> void LinkedList<T>::erase(iterator first, iterator second){
        for (auto it = first; it != second; ++it) erase(it);
    }
    template <typename T> T& LinkedList<T>::front() const{
        return tail->val;
    }
    template <typename T> T& LinkedList<T>::back() const{
        return head->val;
    }
    template <typename T> bool LinkedList<T>::empty() const{
        return count;
    }
    template <typename T> typename LinkedList<T>::size_type LinkedList<T>::size() const{
        return count;
    }
    template <typename T> void LinkedList<T>::clear(){
        while (count) pop_front();
        head = tail = nullptr;
    }

    template <typename T> int LinkedList<T>::operator [](int ind) const{
        auto temp = tail;
        for (int i = 0; i < ind; ++i)
            temp = temp->next;
        return temp->val;
    }
    template <typename T>
    void LinkedList<T>::resize(size_type size, value_type value) {
        NodeList<T>* cur;
        /*if (!count && size > 0){
            head = new NodeList<T>(nullptr, nullptr, value);
            count = 1;
            cur = head;
            for (size_type i = count; i < size; ++i){
                cur->next = new NodeList<T>(cur, nullptr, value);
                cur = cur->next;
            }
            tail = cur;
        }
        else*/ if (size <= count){
            while (size != count) pop_back();
        }
        else{
            while (size != count) push_back(value);
        }
    }

    template <typename T> std::ostream& operator<< (std::ostream& os, const LinkedList<T>& other){
            if (!other.count) std::cout << "container is empty" << std::endl;
            else{
                auto temp = other.tail;
                for(; temp != other.head; temp = temp->next){
                    os << temp->val << "\t";
                }
                os << temp->val;
            }
            return os;
    }


    template <typename T> LinkedList<T>::Iterator::Iterator() : my_pointer(nullptr){};
    template <typename T> LinkedList<T>::Iterator::Iterator(NodeList<T>* pointer): my_pointer(pointer) {};
    template <typename T> typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++(){
//        LinkedList::Iterator a(my_pointer);

        //if (my_pointer->next == nullptr) {std::cout << my_pointer << std::endl;std::cout <<"value" << my_pointer->val<<std::endl;std::cout <<"prev" << my_pointer->prev<<std::endl;}
        /*if (my_pointer->next != nullptr)*/
        my_pointer = my_pointer->next;
        return *this;

    }
    template <typename T> typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++(int) &{

        Iterator tmp = *this; ++(*this); return tmp;
    }
    template <typename T> typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--(){
//        LinkedList::Iterator a(my_pointer);
        my_pointer = my_pointer->prev;
        return *this;
    }
    template <typename T> typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator-(int cnt){
        iterator it(*this);
        for (int i = 0; i < cnt; ++i) --it;
        return it;
    }
    template <typename T> typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator+ (int cnt){
        iterator it(*this);
        for (int i = 0; i < cnt; ++i) ++it;

        return it;
    }

    template <typename T> size_t LinkedList<T>::Iterator::operator-(const Iterator& other){
        auto it = other;
        auto it2 = *this; size_t cnt = 0;
        if (*this == other){
            return 0;
        }
        else if (*this > other){
            while (*this != it) {++it; ++cnt;}
        }
        else if (*this < other){
            while (it2 != other) {++it2; ++cnt;}
        }
        return cnt;
    }

    template <typename T> typename LinkedList<T>::Iterator::value_type& LinkedList<T>::Iterator::operator*(){
        return this->my_pointer->val;
    }
    template <typename T>  NodeList<T>* LinkedList<T>::Iterator::operator-> (){ //#TODO
        return this->my_pointer;
    }
    template <typename T>  void LinkedList<T>::Iterator::operator= (const value_type value){
        *this->my_pointer = value;
    }
    template <typename T> LinkedList<T>::Iterator::Iterator (Iterator& other){
        my_pointer = other.my_pointer;
    };
    template<typename T> LinkedList<T>::Iterator::Iterator(const Iterator& other): my_pointer(other.my_pointer){};
    template<typename T> LinkedList<T>::Iterator::Iterator(const ReverseIterator& other): my_pointer(other.my_pointer){};

    template <typename T> bool LinkedList<T>::Iterator::operator ==(const Iterator& other) const{
        return my_pointer == other.my_pointer;
    }
    template <typename T> bool LinkedList<T>::Iterator::operator !=(const Iterator& other) const{
        return my_pointer != other.my_pointer;
    }
    template <typename T> bool LinkedList<T>::Iterator::operator >(const Iterator& other) const{
        auto it = *this;
        while (it.my_pointer != nullptr && it != other){
            ++it;
        }
        if (it.my_pointer == nullptr) return true;
        else return false;
    }
    template <typename T> bool LinkedList<T>::Iterator::operator <(const Iterator& other) const{
        if (*this <= other && *this != other) return true;
        else return false;
    }
    template <typename T> bool LinkedList<T>::Iterator::operator >=(const Iterator& other) const{
        return !(*this < other);
    }
    template <typename T> bool LinkedList<T>::Iterator::operator <=(const Iterator& other) const{
        return !(*this > other);
    }
    template <typename T> typename LinkedList<T>::reference LinkedList<T>::Iterator::operator[](int diff) const{
        iterator it(my_pointer);

        return (it + diff).my_pointer->val;
    }

    template <typename T> void LinkedList<T>::copy(const LinkedList<T>& other){
        count = other.count;
        auto temp = other.tail;
        head = tail = new NodeList<T>(nullptr, nullptr, temp->val);
        for (int i = 0; i < other.count - 1; ++i){
            temp = temp -> next;
            head->next = new NodeList<T>(head, nullptr, temp->val);

            head = head -> next;
        }
        tail->prev = new NodeList<T>(nullptr, tail, 0);
        head->next = new NodeList<T>(head, nullptr, 0);

    }
    template <typename T> void LinkedList<T>::swap(LinkedList<T>& other){
        LinkedList<T> list(*this);
        copy(other);
        other.copy(list);
    }
    template <typename T> void LinkedList<T>::reverse(){
        auto local_head = head; auto local_tail = tail;

            while (local_tail < local_head){
                T temp = local_head->val;
                local_head->val = local_tail->val;
                local_tail->val = temp;
                local_head = local_head->prev;
                local_tail = local_tail->next;
            }


    }
    template <typename T> typename LinkedList<T>::Iterator LinkedList<T>::begin() {
        return LinkedList::Iterator(tail);
    }
    template <typename T> typename LinkedList<T>::Iterator LinkedList<T>::end(){
        return LinkedList::Iterator( head->next);
    }
    template <typename T> typename LinkedList<T>::ReverseIterator LinkedList<T>::rbegin(){
        return LinkedList::ReverseIterator( head->next);
    }
    template <typename T> typename LinkedList<T>::ReverseIterator LinkedList<T>::rend(){
        return LinkedList::ReverseIterator( tail);
    }

    template <typename T> LinkedList<T>::ReverseIterator::ReverseIterator() : my_pointer(nullptr){};
    template <typename T> LinkedList<T>::ReverseIterator::ReverseIterator(NodeList<T>* pointer): my_pointer(pointer) {};
    template <typename T> LinkedList<T>::ReverseIterator::ReverseIterator(const ReverseIterator& other): my_pointer(other.my_pointer) {};
    template <typename T> LinkedList<T>::ReverseIterator::ReverseIterator(const Iterator& other): my_pointer(other.my_pointer) {};
    template <typename T> typename LinkedList<T>::ReverseIterator& LinkedList<T>::ReverseIterator::operator++(){
        my_pointer = my_pointer->prev;
        return *this;

    }
    template <typename T> typename LinkedList<T>::ReverseIterator& LinkedList<T>::ReverseIterator::operator++(int) &{

        Iterator tmp = *this; ++(*this); return tmp;
    }
    template <typename T> typename LinkedList<T>::ReverseIterator& LinkedList<T>::ReverseIterator::operator--(){
//        LinkedList::ReverseIterator a(my_pointer);
        my_pointer = my_pointer->next;
        return *this;
    }
    template <typename T> typename LinkedList<T>::ReverseIterator LinkedList<T>::ReverseIterator::operator-(int cnt){
        iterator it(*this);
        for (int i = 0; i < cnt; ++i) ++it;
        return it;
    }
    template <typename T> typename LinkedList<T>::ReverseIterator LinkedList<T>::ReverseIterator::operator+ (int cnt){
        iterator it(*this);
        for (int i = 0; i < cnt; ++i) --it;

        return it;
    }

    template <typename T> size_t LinkedList<T>::ReverseIterator::operator-(const ReverseIterator& other){
        auto it = other;
        auto it2 = *this; size_t cnt = 0;
        if (*this == other){
            return 0;
        }
        else if (*this > other){
            while (*this != it) {++it; ++cnt;}
        }
        else if (*this < other){
            while (it2 != other) {++it2; ++cnt;}
        }
        return cnt;
    }

    template <typename T> typename LinkedList<T>::ReverseIterator::value_type& LinkedList<T>::ReverseIterator::operator*(){
        return this->my_pointer->val;
    }
    template <typename T>  NodeList<T>* LinkedList<T>::ReverseIterator::operator-> (){ //#TODO
        return this->my_pointer;
    }
    template <typename T>  void LinkedList<T>::ReverseIterator::operator= (const value_type value){
        *this->my_pointer = value;
    }
    template <typename T> bool LinkedList<T>::ReverseIterator::operator ==(const ReverseIterator& other) const{
        return my_pointer == other.my_pointer;
    }
    template <typename T> bool LinkedList<T>::ReverseIterator::operator !=(const ReverseIterator& other) const{
        return my_pointer != other.my_pointer;
    }
    template <typename T> bool LinkedList<T>::ReverseIterator::operator >(const ReverseIterator& other) const{
        auto it = *this;
        while (it.my_pointer != nullptr && it != other){
            ++it;
        }
        if (it.my_pointer == nullptr) return true;
        else return false;
    }
    template <typename T> bool LinkedList<T>::ReverseIterator::operator <(const ReverseIterator& other) const{
        if (*this <= other && *this != other) return true;
        else return false;
    }
    template <typename T> bool LinkedList<T>::ReverseIterator::operator >=(const ReverseIterator& other) const{
        return !(*this < other);
    }
    template <typename T> bool LinkedList<T>::ReverseIterator::operator <=(const ReverseIterator& other) const{
        return !(*this > other);
    }
    template <typename T> typename LinkedList<T>::reference LinkedList<T>::ReverseIterator::operator[](int diff) const{
        iterator it(my_pointer);

        return (it + diff).my_pointer->val;
    }


};


