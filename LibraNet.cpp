#include <iostream>
#include <string>
using namespace std;

// Base class
class LibraryItem {
protected:
    string title;
    string author;
    bool available;

public:
    LibraryItem(string t, string a) : title(t), author(a), available(true) {}

    void borrowItem() {
        if (available) {
            available = false;
            cout << title << " has been borrowed." << endl;
        } else {
            cout << title << " is not available." << endl;
        }
    }

    void returnItem() {
        available = true;
        cout << title << " has been returned." << endl;
    }

    virtual void displayInfo() {
        cout << title << " by " << author << endl;
    }
};

// Book class
class Book : public LibraryItem {
    int pages;
public:
    Book(string t, string a, int p) : LibraryItem(t, a), pages(p) {}

    void displayInfo() override {
        cout << "Book: " << title << " by " << author
             << " (" << pages << " pages)" << endl;
    }
};

// Audiobook class
class Audiobook : public LibraryItem {
    int duration; // in minutes
public:
    Audiobook(string t, string a, int d) : LibraryItem(t, a), duration(d) {}

    void displayInfo() override {
        cout << "Audiobook: " << title << " by " << author
             << " (" << duration << " mins)" << endl;
    }

    void play() {
        cout << "Now playing audiobook: " << title << endl;
    }
};

// Magazine class
class Magazine : public LibraryItem {
    int issue;
public:
    Magazine(string t, string a, int i) : LibraryItem(t, a), issue(i) {}

    void displayInfo() override {
        cout << "Magazine: " << title << " (Issue " << issue
             << ") by " << author << endl;
    }
};

int main() {
    cout<< "LibraNet is working" <<endl;
     Book b1("Attack on Titan", "Hajime Isayama", 200);
    Book b2("The Kite Runner", "Khaled Hosseini", 371);
    Audiobook a1("Demon Slayer (Manga Adaptation)", "Koyoharu Gotouge", 150);
    Magazine m1("National Geographic", "Editorial Team", 202);
    Magazine m2("Time Magazine", "Editorial Team", 310);

    b1.displayInfo();
    b2.displayInfo();
    a1.displayInfo();
    m1.displayInfo();
    m2.displayInfo();

    cout << "\n--- Borrowing and Returning ---" << endl;

    b1.borrowItem();
    b1.returnItem();

    a1.borrowItem();
    a1.play();
    a1.returnItem();

    m2.borrowItem();
    m2.returnItem();

    return 0;
}