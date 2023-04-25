#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data; //тут зберігається обєкт
        Node* prev; //попередній елемент
        Node* next; //наступний елемент
        Node(const T& d = T{}, Node* p = nullptr, Node* n = nullptr)    //конструктор який має обєкт, попередній елемент та наступний елемент
            : data{ d }, prev{ p }, next{ n } {}
    };
    Node* head; //перший елемент
    Node* tail; //останій елемент
    int size;   //розмір
public:
    //Побудували клас ітератор, що дозволяє проходити список.
    class Iterator {
    public:
        Iterator(Node* n = nullptr) : curr{ n } {} //це конструктор класу, який приймає вказівник на поточний елемент n і ініціалізує його відповідним чином.
        T& operator*() { return curr->data; }      //це перевантажений оператор "розіменування", який повертає посилання на дані поточного елемента, що зберігаються в полі data.
        Iterator& operator++() { curr = curr->next; return *this; } //ці перевантажені оператори "інкрементації" і "декрементації", які дозволяють переміщуватися по елементах списку. 
        Iterator& operator--() { curr = curr->prev; return *this; }
        bool operator==(const Iterator& other) const { return curr == other.curr; } //ці перевантажені оператори порівняння, які дозволяють порівнювати два ітератори. Оператор == повертає true,
        bool operator!=(const Iterator& other) const { return !(*this == other); }  //а оператор != повертає false 
        //Коли ми переходимо від одного елемента списку до іншого, ми змінюємо значення змінної curr, щоб вказувати на поточний елемент.
    private:
        Node* curr;
    };

    DoublyLinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 } {} //конструктор по замовчуванню в якому всі значення зануляються
    //Деструктор
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
    //Гетер для розміру
    int getSize() const { return size; }
    //Порівняння якщо список не пустий, та повертає значення True або False 
    bool isEmpty() const { return size == 0; }
    //Заповнення списку спочатку
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
    //Заповнення списку з кінця 
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
    //Видалення списку спочатку
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
    //Видалення списку з кінця
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
