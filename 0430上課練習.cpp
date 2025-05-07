#include <iostream>
using namespace std;

// 基底類別 Animal
class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }

    void sleep() {
        cout << "I can sleep!" << endl;
    }
};

// 派生類別 Dog 繼承自 Animal
class Dog : public  Animal {
public:
    void bark() {
        cout << "Woof! I can bark!" << endl;
    }
};

// 派生類別 Cat 繼承自 Animal
class Cat : public Animal {
public:
    void meow() {
        cout << "Meow~ I can meow!" << endl;
    }
};

int main() {
    Dog myDog;
    Cat myCat;

    cout << "Dog:" << endl;
    myDog.eat();     // 繼承自 Animal
    myDog.sleep();   // 繼承自 Animal
    myDog.bark();    // 自己的功能

    cout << "\nCat:" << endl;
    myCat.eat();     // 繼承自 Animal
    myCat.sleep();   // 繼承自 Animal
    myCat.meow();    // 自己的功能

    return 0;
}

