#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Books
{
private:
    int book_id;
    string title;
    string author;
    string subject;
    string isbn;
    float price;

public:
    Books() : book_id(0), title(""), author(""), subject(""), isbn(""), price(0.00) {}

    Books(int id, string title, string author, string isbn, float price)
    {
        book_id = id;
        this->title = title;
        this->author = author;
        this->subject = subject;
        this->isbn = isbn;
        this->price = price;
    }

    Books(int id)
    {
        book_id = id;
    }
    // function for accepting the book record
    void setBook()
    {
        cout << "\nEnter the Book_id: ";
        cin >> book_id;
        cout << "Enter the title: ";
        cin >> title;
        cout << "Enter the author: ";
        cin >> author;
        cout << "Enter the subject: ";
        cin >> subject;
        cout << "Enter the isbn: ";
        cin >> isbn;
        cout << "Enter the price: ";
        cin >> price;
        cout << endl;
    }

    // function for getting the book record

    void getBook()
    {
        cout << "\nBook_Id: " << book_id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Subject: " << subject << endl;
        cout << "Isbn: " << isbn << endl;
        cout << "Price: " << price;
        cout << endl;
    }

    // getters for all the data members

    int getId()
    {
        return this->book_id;
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
        this->book_id = id;
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

class Copys : public Books
{
private:
    int copyId;
    string rack;
    string status;

public:
    Copys() : copyId(0), rack(""), status("") {}
    Copys(int Book_id, string title, string author, string isbn, float price, int copy_id, string rack)
        : Books(Book_id, title, author, isbn, price)
    {
        this->copyId = copy_id;
        this->rack = rack;
        this->status = "UnAssigned";
    }

    void getCopys()
    {
        Books::getBook();
        cout << "copyId: " << copyId << endl;
        cout << "rack: " << rack << endl;
        cout << "status :" << status << endl;
    }

    void setCopy()
    {
        Books::setBook();
        cout << "\nEnter the copy id: ";
        cin >> copyId;
        cout << "\nEnter the rack: ";
        cin >> rack;
        status = "UnAssigned";
    }

    bool isAvailable()
    {
        if (status == "UnAssigned")
            return true;
        return false;
    }

    void setCopyasAssigned()
    {
        status = "Assigned";
    }
    int getCopy_id()
    {
        return copyId;
    }
};

class Members
{
private:
    int id;
    string name;
    string email;
    string phone;
    time_t nextPayement_dueDate;
    string paymentStatus;

public:
    // Setters
    void accept_record()
    {
        cout << endl;
        cout << "Enter Member member_Id:";
        cin >> id;
        cout << "Enter Member Name:";
        cin >> name;
        cout << "Enter Member email:";
        cin >> email;
        cout << "Enter Member phone:";
        cin >> phone;
        cout << "Enter Member nextPayement_dueDate";

        int date;
        int month;
        int year;

        cout << "\nEnter Date: ";
        cin >> date;
        cout << "Enter Month: ";
        cin >> month;
        cout << "Enter Year: ";
        cin >> year;

        tm t = {};
        t.tm_mday = date;
        t.tm_mon = month - 1;
        t.tm_year = year - 1900;

        nextPayement_dueDate = mktime(&t);

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

    void display_record()
    {
        cout << "Member_id:" << id << endl;
        cout << "name: " << name << endl;
        cout << "email: " << email << endl;
        cout << "phone: " << phone << endl;

        tm *t = localtime(&nextPayement_dueDate);

        cout << "nextPayement_dueDate: " << t->tm_mday << "/" << t->tm_mon + 1 << "/" << t->tm_year + 1900 << endl;
        cout << "paymentStatus: " << paymentStatus << endl;
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
};

namespace booksFuncn
{
    // Add Books
    void addBooks(vector<Books *> &books)
    {
        Books *ptr = new Books();
        ptr->setBook();
        books.push_back(ptr);
    }
    // Display Books
    void displayBooks(vector<Books *> books)
    {
        for (int i = 0; i < books.size(); i++)
        {
            books[i]->getBook();
        }
        return;
    }
    // Display Book Title and its id;
    void displayBooksTitleandId(vector<Books *> books)
    {
        for (int i = 0; i < books.size(); i++)
        {
            cout << books[i]->getId() << ". " << books[i]->getTitle();
            cout << endl;
        }
        return;
    }
}

namespace MemberFuncn
{
    // Add Members
    void addMember(vector<Members *> &members)
    {
        Members *ptr = new Members();
        ptr->accept_record();
        members.push_back(ptr);
    }
    // Display Members
    void displayMembers(vector<Members *> members)
    {
        cout << endl;
        for (int i = 0; i < members.size(); i++)
        {
            members[i]->display_record();
            cout << endl;
        }
        return;
    }

    bool checkMemberisPresent(vector<Members *> members, int member_id)
    {
        bool ans = 0;
        for (int i = 0; i < members.size(); i++)
        {
            if (members[i]->getId() == member_id)
            {
                ans = 1;
                break;
            }
        }
        return ans;
    }
}

namespace CopyFuncn
{
    // Add Books
    void addCopy(vector<Books *> books, vector<Copys *> &booksCopy)
    {
        // Display Books Title with Book id
        cout << endl;
        for (int i = 0; i < books.size(); i++)
        {
            cout << books[i]->getId() << ". " << books[i]->getTitle();
            cout << endl;
        }

        int book_id;
        cout << "\nEnter Book_id Which You want to make Copy: ";
        cin >> book_id;

        int i;
        bool bookFound = 0;

        for (i = 0; i < books.size(); i++)
        {
            if (book_id == books[i]->getId())
            {
                bookFound = 1;
                break;
            }
        }
        if (!bookFound)
        {
            cout << "Book Not Found!!!" << endl;
            return;
        }

        string rack;
        cout << "Enter Rack:";
        cin >> rack;

        int count = 0;
        for (int i = 0; i < booksCopy.size(); i++)
        {
            if (booksCopy[i]->getId() == book_id)
            {
                count++;
            }
        }

        static int copy_id = 1;

        // int Book_id, string title, string author, string isbn, float price, int copy_id, string rack
        Copys *ptr = new Copys(books[i]->getId(), books[i]->getTitle(), books[i]->getAuthor(), books[i]->getIsbn(), books[i]->getPrice(), copy_id, rack);
        copy_id++;

        booksCopy.push_back(ptr);

        return;
    }

    // Display Books
    void displayCopyBooks(vector<Copys *> copys)
    {
        for (int i = 0; i < copys.size(); i++)
        {
            copys[i]->getCopys();
        }
        return;
    }
}

namespace AssignCopiesFuncn
{
    void assignCopyToMember(vector<Copys *> &bookCopys, vector<Members *> &members, vector<Books *> &books)
    {
        cout << endl;
        int member_id;
        cout << "Enter Member_Id :";
        cin >> member_id;

        if (!MemberFuncn::checkMemberisPresent(members, member_id))
        {
            cout << endl;
            cout << "Member Not Present" << endl;
            return;
        }

        int i;
        for (i = 0; i < members.size(); i++)
        {
            if (members[i]->getId() == member_id)
            {
                cout << endl;
                cout << "Member Exist in System.." << endl;
                break;
            }
        }

        if (!members[i]->getPayementStatus())
        {
            cout << "Member Has Not Taken Membership!!" << endl;
            return;
        }

        // Assign Copy to Member

        // Display Unique Books
        booksFuncn::displayBooksTitleandId(books);

        int book_id;
        cout << "Enter Book id: ";
        cin >> book_id;

        bool book_assigned = 0;

        for (int i = 0; i < bookCopys.size(); i++)
        {
            if (bookCopys[i]->getId() == book_id && bookCopys[i]->isAvailable())
            {
                bookCopys[i]->setCopyasAssigned();
                book_assigned = 1;
                break;
            }
        }
        if (!book_assigned)
        {
            cout << "Book cannot be Assigned!!!" << endl;
            return;
        }
        cout << "Book Assigned!!!" << endl;

        return;
    }
}
int MenuDrive()

{
    int ch;

    cout << "1.Add Members" << endl;
    cout << "2.Display Members" << endl;
    cout << "3.Add Book" << endl;
    cout << "4.Display Books" << endl;
    cout << "5.Make Copyies of Book " << endl;
    cout << "6.Display Copy Records" << endl;
    cout << "7.Assign Copies To Member" << endl;
    cout << endl;
    cout << "Enter Choice: ";
    cin >> ch;
    return ch;
}

int main()
{
    int ch;

    vector<Books *> books;
    vector<Copys *> bookCopys;
    vector<Members *> members;

    // vector<issueRecords *> issueRecordsv;

    // dummyData(bookCopys);

    while ((ch = MenuDrive()) != 0)
    {
        switch (ch)
        {
        case 1:
        {
            MemberFuncn::addMember(members);
            break;
        }
        case 2:
        {
            MemberFuncn::displayMembers(members);
            break;
        }
        case 3:
        {
            booksFuncn::addBooks(books);
            break;
        }
        case 4:
        {
            booksFuncn::displayBooks(books);
            break;
        }
        case 5:
        {
            CopyFuncn::addCopy(books, bookCopys);
            break;
        }
        case 6:
        {
            CopyFuncn::displayCopyBooks(bookCopys);
            break;
        }
        case 7:
        {
            AssignCopiesFuncn::assignCopyToMember(bookCopys, members, books);
            break;
        }
        default:
            break;
        }
        cout << endl;
        // }
    }
}