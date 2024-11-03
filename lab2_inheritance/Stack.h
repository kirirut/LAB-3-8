#pragma once
#include <iostream>
#include <stdexcept>


template <typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& data) : data(data), next(nullptr) {}
};
template <typename T>
class Stack {
private:
    Node<T>* topNode; // Указатель на вершину стека
    size_t stackSize; // Текущий размер стека

public:
    Stack() : topNode(nullptr), stackSize(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push( T& element) {
        Node<T>* newNode = new Node<T>(element);
        newNode->next = topNode;
        topNode = newNode;
        ++stackSize;
    }

    void pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        Node<T>* tempNode = topNode;
        topNode = topNode->next;
        delete tempNode;
        --stackSize;
    }

    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty. No top element.");
        }
        return topNode->data;
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    size_t size() const {
        return stackSize;
    }
    T find(double CPUcapacity) {
        Node<T>* currentNode = topNode;
        while (currentNode != nullptr) {
            if (currentNode->data.GetCPUcapacity() == CPUcapacity) {
                return currentNode->data;
            }
            currentNode = currentNode->next;
        } 
        throw std::runtime_error("Element with specified CPU capacity not found.");
    }


};
void TestStack();
