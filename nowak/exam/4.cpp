#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class DynamicList {
private:
    std::unique_ptr<T[]> list;
    int size;
public:
    DynamicList() : size(0), list(nullptr) {}

    void add(T value) {
        std::unique_ptr<T[]> temp(new T[size + 1]);
        for (int i = 0; i < size; i++) {
            temp[i] = std::move(list[i]);
        }
        temp[size] = std::move(value);
        list = std::move(temp);
        size++;
    }

    T pop() {
        if (size == 0) {
            std::cout << "List is empty" << std::endl;
            return T();
        }
        T value = std::move(list[0]);
        std::unique_ptr<T[]> temp(new T[size - 1]);
        for (int i = 1; i < size; i++) {
            temp[i - 1] = std::move(list[i]);
        }
        list = std::move(temp);
        size--;
        return std::move(value);
    }

    void push(T value) {
        std::unique_ptr<T[]> temp(new T[size + 1]);
        temp[0] = std::move(value);
        for (int i = 0; i < size; i++) {
            temp[i + 1] = std::move(list[i]);
        }
        list = std::move(temp);
        size++;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        std::unique_ptr<T[]> temp(new T[size - 1]);
        for (int i = 0; i < size - 1; i++) {
            if (i < index) {
                temp[i] = std::move(list[i]);
            } else {
                temp[i] = std::move(list[i + 1]);
            }
        }
        list = std::move(temp);
        size--;
    }

    void insertAt(int index, T value) {
        if (index < 0 || index >= size) {
            std::cout << "Index out of range" << std::endl;
            return;
        }
        std::unique_ptr<T[]> temp(new T[size + 1]);
        for (int i = 0; i < size + 1; i++) {
            if (i < index) {
                temp[i] = std::move(list[i]);
            } else if (i == index) {
                temp[i] = std::move(value);
            } else {
                temp[i] = std::move(list[i - 1]);
            }
        }
        list = std::move(temp);
        size++;
    }

    void show() {
        std::cout << "[";
        for (int i = 0; i < size; i++) {
            std::cout << list[i];
            if (i < size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }
};



int main() {
    DynamicList<int> list;
    int option, value, index;
    while (true) {
        cout << "Select an option:" << endl;
        cout << "1. add" << endl;
        cout << "2. pop" << endl;
        cout << "3. push" << endl;
        cout << "4. remove at" << endl;
        cout << "5. insert at" << endl;
        cout << "6. show" << endl;
        cout << "7. isEmpty()" << endl;
	cout << "8. exit" << endl;
        cin >> option;
        switch (option) {
        case 1:
            cout << "Enter a value: ";
            cin >> value;
            list.add(value);
            break;
        case 2:
            value = list.pop();
            cout << "Popped value: " << value << endl;
            break;
        case 3:
            cout << "Enter a value: ";
            cin >> value;
            list.push(value);
            break;
        case 4:
            cout << "Enter an index: ";
            cin >> index;
            list.removeAt(index);
            break;
        case 5:
            cout << "Enter an index: ";
            cin >> index;
            cout << "Enter a value: ";
            cin >> value;
            list.insertAt(index, value);
            break;
        case 6:
            list.show();
            break;
	case 7: 
	    if (list.isEmpty())
                cout << "List is empty" << endl;
            else
                cout << "List is not empty" << endl;
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }
}

