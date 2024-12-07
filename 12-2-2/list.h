#ifndef __LIST_H__
#define __LIST_H__
#include <iostream>

template<class T>
class Node {
public:
    T data;
    Node<T>* next;
};
template <class T>
class List {
private:
    Node<T>* head;

public:
    List() : head(nullptr) {}
    ~List() {
        while (head != nullptr) {
            pop_front();
        }
    }

    List(T* arr, int n_nodes) {
        head = nullptr;
        for (int i = 0; i < n_nodes; ++i) {
            push_back(arr[i]);
        }
    }

    void insert_at(int idx, const T& data) {
        if (idx == 0) {
            push_front(data);
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; temp != nullptr && i < idx - 1; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            return;
        }
        Node<T>* new_node = new Node<T>();
        new_node->data = data;
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void remove_at(int idx) {
        if (idx == 0) {
            pop_front();
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; temp != nullptr && i < idx - 1; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            return;
        }
        Node<T>* node_to_delete = temp->next;
        temp->next = temp->next->next;
        delete node_to_delete;
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void push_back(const T& val) {
        Node<T>* new_node = new Node<T>();
        new_node->data = val;
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void push_front(const T& val) {
        Node<T>* new_node = new Node<T>();
        new_node->data = val;
        new_node->next = head;
        head = new_node;
    }

    template <class U>
    friend std::ostream& operator<< (std::ostream& out, List<U>& rhs) {
        Node<U>* temp = rhs.head;
        while (temp != nullptr) {
            out << temp->data;
            if (temp->next != nullptr) {
                out << ",";
            }
            temp = temp->next;
        }
        return out;
    }
};

#endif
