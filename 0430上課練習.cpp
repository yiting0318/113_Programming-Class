#include <iostream>
using namespace std;

// �����O Animal
class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }

    void sleep() {
        cout << "I can sleep!" << endl;
    }
};

// �������O Dog �~�Ӧ� Animal
class Dog : public  Animal {
public:
    void bark() {
        cout << "Woof! I can bark!" << endl;
    }
};

// �������O Cat �~�Ӧ� Animal
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
    myDog.eat();     // �~�Ӧ� Animal
    myDog.sleep();   // �~�Ӧ� Animal
    myDog.bark();    // �ۤv���\��

    cout << "\nCat:" << endl;
    myCat.eat();     // �~�Ӧ� Animal
    myCat.sleep();   // �~�Ӧ� Animal
    myCat.meow();    // �ۤv���\��

    return 0;
}

