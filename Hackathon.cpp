#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Book
{
private:
    int id;
    string title;
    string author;
    string subject;
    string isbn;
    float price;

public:
    Book(int id) : id(id) {}
    Book() : id(0), title(""), author(""), subject(""), isbn(""), price(0.00) {}
    Book(int id, string title, string author, string isbn, float price) : id(id), title(title), author(author), subject(subject), isbn(isbn), price(price) {}

    // function for accepting the book record
    void setBook()
    {
        cout << "\nEnter the id: ";
        cin >> id;
        cout << "\nEnter the title: ";
        cin >> title;
        cout << "\nEnter the author: ";
        cin >> author;
        cout << "\nEnter the subject: ";
        cin >> subject;
        cout << "\nEnter the isbn: ";
        cin >> isbn;
        cout << "\nEnter the price: ";
        cin >> price;
    }

    // function for getting the book record

    void getBook()
    {
        cout << "\nId: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nSubject: " << subject;
        cout << "\nIsbn: " << isbn;
        cout << "\nPrice: " << price;
    }

    // getters for all the data members

    int getId()
    {
        return this->id;
    }
    string getTitle()
    {
        return this->title;
    }
    string getAuthor()
    {
        return this->author;
    }
    string getSubject()
    {
        return this->subject;
    }
    string getIsbn()
    {
        return this->isbn;
    }
    float getPrice()
    {
        return this->price;
    }

    // setters for the all the data members

    void setId(int id)
    {
        this->id = id;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setAuthor(string author)
    {
        this->author = author;
    }
    void setSubject(string subject)
    {
        this->subject = subject;
    }
    void setIsbn(string isbn)
    {
        this->isbn = isbn;
    }
    void setPrice(float price)
    {
        this->price = price;
    }
};

class Copy : public Book
{
private:
    int copyId;
    string rack;
    string status;

public:
    Copy() : copyId(0), rack(""), status("") {}
    Copy(int id, int copyId, string rack, string status) : Book(id), copyId(copyId), rack(rack), status(status) {}

    void setCopy()
    {
        cout << "\nEnter the copy id: ";
        cin >> copyId;
        cout << "\nEnter the rack: ";
        cin >> rack;
        status = "UnAssigned";
    }
};

class Members
{
private:
    int id;
    string name;
    string email;
    string phone;
    string nextPayement_dueDate;
    string paymentStatus;

public:
    // Setters

    void accept_record()
    {
        cout << "Enter Member Id:";
        cin >> id;
        cout << "Enter Member Name:";
        cin >> name;
        cout << "Enter Member email:";
        cin >> email;
        cout << "Enter Member phone:";
        cin >> phone;
        cout << "Enter Member nextPayement_dueDate:";
        cin >> nextPayement_dueDate;
        cout << "Enter Member paymentStatus:" << endl;

        int ch;
        cout << "1.Paid" << endl;
        cout << "2.Unpaid" << endl;
        cin >> ch;

        if (ch == 1)
            paymentStatus = "Paid";
        else
            paymentStatus = "Unpaid";
    }

    int getId()
    {
        return id;
    }
    bool getPayementStatus()
    {
        bool ans = 0;
        if (paymentStatus == "Paid")
            ans = 1;
        return ans;
    }
    void display_record()
    {
        cout << "id:" << id << endl;
        cout << "name: " << name << endl;
        cout << "email: " << email << endl;
        cout << "phone: " << phone << endl;
        cout << "nextPayement_dueDate: " << nextPayement_dueDate << endl;
        cout << "paymentStatus: " << paymentStatus << endl;
    }
};

// Members Funcn
void addMembers(vector<Members *> &members)
{
    Members *ptr = new Members();
    ptr->accept_record();
    members.push_back(ptr);
}

void displayMembers(vector<Members *> &members)
{
    for (int i = 0; i < members.size(); i++)
    {
        members[i]->display_record();
    }
}

// Books Funcn

void addBooks(vector<Book *> &books)
{
    Book *ptr = new Book();
    ptr->setBook();
    books.push_back(ptr);
}

void displayBooks(vector<Book *> &books)
{
    for (int i = 0; i < books.size(); i++)
    {
        books[i]->getBook();
    }
}

// Assign Copy To Books

void assignCopyToMember(vector<Members *> &members, vector<Book *> &books, vector<Copy *> &bookCopys)
{
    // 1. Check If member Exist and is a Member

    int id;
    cout << "Enter Member Id:";
    cin >> id;

    bool MemberFound = 0;
    bool MemberPaid = 1;

    int i;
    for (i = 0; i < members.size(); i++)
    {
        if (members[i]->getId() == id)
        {
            MemberFound = 1;
            if (!members[i]->getPayementStatus())
            {
                cout << "Member has Not Paid Fees" << endl;
                MemberPaid = 0;
            }
            break;
        }
    }
    if (MemberFound == 0 || MemberPaid == 0)
    {
        cout << "Member Does No Exist or has Not Paid Membership" << endl;
        return;
    }
    // Member found and has paid fees

    // Display Books
    cout << "Member Exist" << endl;
    cout << "Choose Book" << endl;

    for (int i = 0; i < books.size(); i++)
    {
        cout << i + 1 << "." << books[i]->getTitle() << endl;
        cout << " Book Id--> " << books[i]->getId() << endl;
    }
    return;
}

int MenuDrive()

{
    int ch;

    cout << "1.Add Members" << endl;
    cout << "2.Display Members" << endl;
    cout << "3.Add Book" << endl;
    cout << "4. Assign Copy To Member" << endl;
    cin >> ch;
    return ch;
}

int main()
{
    int ch;
    vector<Members *> members;
    vector<Book *> books;
    vector<Copy *> bookCopys;

    while ((ch = MenuDrive()) != 0)
    {
        switch (ch)
        {
        case 1:
        {
            addMembers(members);
            break;
        }
        case 2:
        {
            displayMembers(members);
            break;
        }
        case 3:
        {
            addBooks(books);
            break;
        }
        case 4:
        {
            assignCopyToMember(members, books, bookCopys);
        }
        default:
            break;
        }
    }
}