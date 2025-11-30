#include <iostream>
#include <vector>

struct Node {
    int val = 0;
    Node* next = nullptr;
};

struct UniLinkedList {
    UniLinkedList() = default;
    UniLinkedList(int* p, size_t n) : size_(n) {
        if (p == nullptr)
            throw std::invalid_argument("UniLinkedList: Cannot copy from nothing");
        Node** cur = &root_;
        for (size_t i = 0; i < n; ++i) {
            *cur = new Node(p[i]);
            cur = &((*cur)->next);
        }
    }
    UniLinkedList(const UniLinkedList& other) : size_(other.size_){
        Node** cur = &root_;
        for (Node* curOther = other.root_; curOther != nullptr; curOther = curOther->next) {
            *cur = new Node(curOther->val);
            cur = &((*cur)->next);
        }
    }
    UniLinkedList(std::initializer_list<int> lst) : size_(lst.size()) {
        Node** cur = &root_;
        for (auto it = lst.begin(); it != lst.end(); ++it) {
            *cur = new Node(*it);
            cur = &((*cur)->next);
        }
    }
    UniLinkedList(size_t n, int val_default=0) {
        Node** cur = &root_;
        while (n--) {
            *cur = new Node(val_default);
            cur = &((*cur)->next);
        }
    }
    UniLinkedList(UniLinkedList&& other) noexcept
        : root_(other.root_), size_(other.size_) {
        other.root_ = nullptr;
        other.size_ = 0;
    }

    UniLinkedList& operator=(const UniLinkedList& other) {
        if (&other == this)
            return *this;
        this->~UniLinkedList();
        new(this) UniLinkedList(other);
        return *this;
    }

    UniLinkedList& operator=(UniLinkedList&& other) noexcept {
        if (&other == this)
            return *this;
        this->~UniLinkedList();
        new(this) UniLinkedList(std::move(other));
        return *this;
    }

    size_t size() const {
        return size_;
    }

    int& operator[](size_t pos) const {
        return getNode(pos).val;
    }

    int& front() const {
        return (*this)[0];
    }

    int& back() const {
        return (*this)[size_ - 1];
    }

    void insert(size_t i, int val) {
        Node* newNode = new Node(val);
        if (i == 0) {
            newNode->next = root_;
            root_ = newNode;
        } else {
            Node& iNode = getNode(i - 1);
            if (iNode.next != nullptr) {
                newNode->next = iNode.next;
            }
            iNode.next = newNode;
        }
        ++size_;
    }

    void erase(size_t i) {
        if (i == 0) {
            Node* newRoot = root_->next;
            delete[] root_;
            root_ = newRoot;
        } else {
            Node& prev = getNode(i - 1);
            Node* cur = prev.next;
            if (prev.next->next != nullptr) {
                prev.next = prev.next->next;
            }
            delete[] cur;
        }
        --size_;
    }

    void print() const {
        Node* cur = root_;
        size_t i = size_;
        while (i--) {
            std::cout << cur->val << ' ';
            cur = cur->next;
        }
        std::cout << '\n';
    }

    ~UniLinkedList() {
        Node* cur = root_;
        while (cur != nullptr) {
            Node copy = *cur;
            delete cur;
            cur = copy.next;
        }
    }
private:
    Node* root_ = nullptr;
    size_t size_ = 0;

    Node& getNode(size_t pos) const {
        Node* cur = root_;
        while (pos--) {
            cur = cur->next;
        }
        return *cur;
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    UniLinkedList l(vec.data(), vec.size());
    l.print();
    l.erase(1);
    l.print();
    l.insert(2, 10);
    l.print();
    return 0;
}
