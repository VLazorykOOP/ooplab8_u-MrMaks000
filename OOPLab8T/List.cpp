#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data; //��� ���������� ����
        Node* prev; //��������� �������
        Node* next; //��������� �������
        Node(const T& d = T{}, Node* p = nullptr, Node* n = nullptr)    //����������� ���� �� ����, ��������� ������� �� ��������� �������
            : data{ d }, prev{ p }, next{ n } {}
    };
    Node* head; //������ �������
    Node* tail; //������ �������
    int size;   //�����
public:
    //���������� ���� ��������, �� �������� ��������� ������.
    class Iterator {
    public:
        Iterator(Node* n = nullptr) : curr{ n } {} //�� ����������� �����, ���� ������ �������� �� �������� ������� n � �������� ���� ��������� �����.
        T& operator*() { return curr->data; }      //�� �������������� �������� "������������", ���� ������� ��������� �� ��� ��������� ��������, �� ����������� � ��� data.
        Iterator& operator++() { curr = curr->next; return *this; } //�� ������������ ��������� "�������������" � "�������������", �� ���������� ������������� �� ��������� ������. 
        Iterator& operator--() { curr = curr->prev; return *this; }
        bool operator==(const Iterator& other) const { return curr == other.curr; } //�� ������������ ��������� ���������, �� ���������� ���������� ��� ���������. �������� == ������� true,
        bool operator!=(const Iterator& other) const { return !(*this == other); }  //� �������� != ������� false 
        //���� �� ���������� �� ������ �������� ������ �� ������, �� ������� �������� ����� curr, ��� ��������� �� �������� �������.
    private:
        Node* curr;
    };

    DoublyLinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 } {} //����������� �� ������������ � ����� �� �������� �����������
    //����������
    ~DoublyLinkedList() {
        Node* p;
        while (head != nullptr) {
            p = head;
            head = head->next;
            delete p;
        }
        tail = nullptr;
        size = 0;
    }
    //����� ��� ������
    int getSize() const { return size; }
    //��������� ���� ������ �� ������, �� ������� �������� True ��� False 
    bool isEmpty() const { return size == 0; }
    //���������� ������ ��������
    void pushFront(const T& val) {
        head = new Node(val, nullptr, head);
        if (tail == nullptr) {
            tail = head;
        }
        else {
            head->next->prev = head;
        }
        size++;
    }
    //���������� ������ � ���� 
    void pushBack(const T& val) {
        tail = new Node(val, tail, nullptr);
        if (head == nullptr) {
            head = tail;
        }
        else {
            tail->prev->next = tail;
        }
        size++;
    }
    //��������� ������ ��������
    void popFront() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        Node* p = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        else {
            head->prev = nullptr;
        }
        delete p;
        size--;
    }
    //��������� ������ � ����
    void popBack() {
        if (isEmpty()) {
            throw std::out_of_range("List is empty");
        }
        Node* p = tail;
        tail = tail->prev;
        if (tail == nullptr) {
            head = nullptr;
        }
        else {
            tail->next = nullptr;
        }
        delete p;
        size--;
    }

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }
};
