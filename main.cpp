#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct info{
    char name[50];
    char author[30];
    int cost;
    int retail;
    char publisher[30];
    int edition;
};

info add(info b)
{
    system("cls");

    cin.ignore();
    cout << "Enter book name: ";
    cin.getline(b.name, 50);
    cout << "Enter author: ";
    cin.getline(b.author, 50);
    cout << "Enter cost price: ";
    cin >> b.cost;
    cout << "Enter retail price: ";
    cin >> b.retail;
    cin.ignore();
    cout << "Enter publisher: ";
    cin.getline(b.publisher, 50);
    cout << "Enter edition: ";
    cin >> b.edition;

    system("cls");

    fstream file;
    file.open("books.txt", ios::in | ios::app);
    if(file.is_open()) {
        file << b.name << " " << b.author << " " << b.cost << " " << b.retail << " " << b.publisher << " " << b.edition << endl;
    }
    else {
        cout << "File couldn't be opened";
    }
    file.close();
}

void display(info b[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << "*******************************************************************" << endl;

        cout << "Book Name: " << b[i].name << endl;
        cout << "Author: " << b[i].author << endl;
        cout << "Cost Price: " << b[i].cost << endl;
        cout << "Retail Price: " << b[i].retail << endl;
        cout << "Publisher: " << b[i].publisher << endl;
        cout << "Edition: " << b[i].edition << endl;

        cout << "********************************************************************" << endl;
    }
    system("pause");
}

int main()
{
    info books[10];
    info book;

    int choice;

    do {

        system("cls");
        cout << "\t\tMenu" << endl;
        cout << "1. Add Book(s)" << endl;
        cout << "2. Display Book(s)" << endl;
        cout << "3. Edit  Book" << endl;
        cout << "4. Exit" << endl;

        cin >> choice;

        switch(choice)
        {
            case 1:
                int n;
                system("cls");
                cout << "How many books will you add: ";
                cin >> n;
                for(int i = 0; i < n; i++)
                {
                    book = add(book);
                    books[i] = book;
                }
                break;
            case 2:
                display(books,n);
                break;
            case 3:
                break;
            case 4:
                system("cls");
                cout << "Thanks for visiting us!" << endl;
                return 0;
                break;
        }
    } while (choice != 4);
}
