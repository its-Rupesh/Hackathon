#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int increment_id = 0;

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
        Book::setBook();
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

class issueRecords
{
private:
    int issueRecordId;
    int copy_id;
    int member_id;
    string issue_date;
    string return_dueDate;
    string return_date;
    float fine_amount;

public:
    issueRecords(int id, int copy_id, int member_id, string issue_date, string return_dueDate, string return_date, float fine_amount)
    {
        this->issueRecordId = id;
        this->copy_id = copy_id;
        this->member_id = member_id;
        this->issue_date = issue_date;
        this->return_dueDate = return_dueDate;
        this->fine_amount = fine_amount;
    }
    void acceptIssueRecords()
    {
        cout << "\nEnter the issue record id: ";
        cin >> issueRecordId;
        cout << "\nEnter the issue_date: ";
        cin >> issue_date;
        cout << "\nEnter the return due date: ";
        cin >> return_dueDate;
        cout << "\nEnter the return date: ";
        cin >> return_date;
        cout << "\nEnter the fine_amount: ";
        cin >> fine_amount;
    }
    void displayIssueRecords()
    {
        cout << "issueRecordId:" << issueRecordId << endl;
        cout << "copy_id:" << copy_id << endl;
        cout << "member_id:" << member_id << endl;
        cout << "issue_date" << issue_date << endl;
        cout << "return_date:" << return_date << endl;
        cout << "fine_amount" << fine_amount << endl;
    }
    // Setter
    void setReturnDate(string return_date)
    {
        this->return_date = return_date;
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

// checkCopyAvailablity

bool checkCopyAvailablity(int BookId, vector<Copy *> &bookCopys, vector<issueRecords *> &issueRecordsv, int member_id)
{
    cout << "W" << endl;
    int i;
    bool copyFound = 0;

    for (i = 0; i < bookCopys.size(); i++)
    {
        if (BookId == bookCopys[i]->getId())
        {
            if (bookCopys[i]->isAvailable())
            {
                copyFound = 1;
                bookCopys[i]->setCopyasAssigned();
                break;
            }
        }
    }
    if (copyFound == 0)
        return false;
    cout << "W" << endl;

    issueRecords *ptr = new issueRecords(increment_id, bookCopys[i]->getCopy_id(), member_id, "30/6/25", "30/6/25", "30/6/25", 65.25);
    issueRecordsv.push_back(ptr);

    cout << "Book Assigned" << endl;

    return true;
}

// Assign Copy To Books

void assignCopyToMember(vector<Members *> &members, vector<Book *> &books, vector<Copy *> &bookCopys, vector<issueRecords *> &issueRecordsv)
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

    int bookid;
    cin >> bookid;

    bool isBookAvailableandAssigned = checkCopyAvailablity(bookid, bookCopys, issueRecordsv, id);

    if (!isBookAvailableandAssigned)
        cout << "Book Cannot be Assigned" << endl;

    return;
}

void displayRecords(vector<issueRecords *> issueRecordsv)
{
    for (int i = 0; i < issueRecordsv.size(); i++)
    {
        issueRecordsv[i]->displayIssueRecords();
    }
    return;
}

void dummyData(vector<Copy *> &bookCopys)
{
    int i = 2;
    while (i)
    {
        Copy *ptr = new Copy();
        ptr->setCopy();
        bookCopys.push_back(ptr);
        i--;
    }
}

int MenuDrive()

{
    int ch;

    cout << "1.Add Members" << endl;
    cout << "2.Display Members" << endl;
    cout << "3.Add Book" << endl;
    cout << "4. Assign Copy To Member" << endl;
    cout << "5.Display Records" << endl;
    cin >> ch;
    return ch;
}

int main()
{
    int ch;
    vector<Members *> members;
    vector<Book *> books;
    vector<Copy *> bookCopys;
    vector<issueRecords *> issueRecordsv;

    dummyData(bookCopys);

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
            // dummyData(bookCopys);
            assignCopyToMember(members, books, bookCopys, issueRecordsv);

            break;
        }
        case 5:
        {
            displayRecords(issueRecordsv);
            break;
        }
        default:
            break;
        }
    }
}