#include <iostream>
using namespace std;
#include <cstring>
#include <conio.h>
const int maxBooks= 10;
const int maxStudent = 10;

struct book {
    string code ;
    string name ;
    string category ;
    string authorName ;
    string edition ;
    bool available = true;
};

struct library {
    book books[maxBooks];
    short numBooks = 0;
};

struct student {
    string ID;
    string name;
    string email;
    string passoword;
    book arr[maxBooks];
};
// Function for student login
// Returns the index of the logged-in student or -1 if login fails
int StudentLog(student arr[]) {
    //search
    // return index
    string s,s1;
    int x;
    cout<<"Please Enter your student number" << endl;
    cin>>x;
    cin.ignore();
    int y=x-55;
    cout<<"Please Enter your username" << endl;
    getline(cin,s);
    cout<<"Please Enter your password" << endl;
    getline(cin,s1);
    for(int i=0;i<=y;i++)
    {
        if(i==y)
        {
            if(arr[i].name==s)
            {
                if(arr[i].passoword==s1)
                    return y;
            }
        }
    }
    return -1;
}
// Function for students to create a new account
// Returns the index of the new student
int StudentSign(student arr[]) {
    // arrary of student logged pointer -> = give the student index in the array
    // return index
    static int  index=-1;
    string s;
    cout<<"Please Enter your Username" << endl;
    getline(cin,s);
    cin.ignore();
    arr[index+1].name=s;
  cin.ignore();
    cout<<"Please Enter your Email:\n" << endl;
    getline(cin,s);
    arr[index+1].email=s;
    cin.ignore();
   // cout<<"PLease Enter your ID:\n ";
    //cin>>s;
  //  cin.ignore();
   // arr[index+1].ID=s;
    cout<<"Please Enter your Password:\n" << endl;
    getline(cin,s);
    cin.ignore();
    arr[index+1].passoword=s;
    index++;
    cout<<"Your student number in library is:\n"<<index+55<<endl<<" \n You will log in again with it" << endl;

    return index ;

}
// Function to allow students to edit their account information
void editInfo(student arr[], int z)
{
    int x;
    string s1;
    cout<<"what do you want to change?\n"<<" 1-User name\n"<<"2-ID\n"<<"3-gmail\n"<<"4-password \n";
    cout<<"Please Enter number you choose";
    cin>>x;
    switch(x)
    {
        case 1:
        {
            cout<<"Please Enter Your new username" << endl;
            getline(cin,s1);
            cin.ignore();
            arr[z].name=s1;
        }
            break ;
        case 2:
        {
            cout<<"Please Enter your new id" << endl;
            getline(cin,s1);
            cin.ignore();
            arr[z].ID=s1;
        }
            break ;
        case 3:
        {
            cout<<"Please Enter your new email" << endl;
            getline(cin,s1);
           cin.ignore();
            arr[z].email=s1;
        }
            break;
        case 4:
        {
            cout<<"Please Enter your new password" << endl;
            getline(cin,s1);
            cin.ignore();
            arr[z].passoword=s1;
        }
    }
}
// Function to display options for library operations
void displayOptions() {
    cout << "\nThese are the availabe options for you:\n ";
    cout << "1. View The Book Names\n";
    cout << "2. View Book Information\n";
    cout << "3. Borrow a Book\n";
    cout << "4. View my Borrowed Books\n";
    cout << "5. Modify my Borrowed Books\n";
}
// Function to view the names of books in the library
void viewBookNames(library mylibrary) {
    cout << "\nList of Book Names:\n";
    for (int i = 0; i < mylibrary.numBooks; i++) {
        cout << i + 1 << ". " << mylibrary.books[i].name << endl;
    }
    cout << endl;
}
// Function to view detailed information about a specific book
void viewBookInfo(book& b) {
    cout << "\nBook Name: " << b.name << endl;
    cout << "Book Code: " << b.code << endl;
    cout << "Category: " << b.category << endl;
    cout << "Author Name: " << b.authorName << endl;
    cout << "Edition: " << b.edition << endl;
    cout << "Availability for borrowing: " << (b.available ? "Availiable" : "Not Availibale") << endl;
}
// Function for a student to borrow a book from the library
void borrowBook(library& mylibrary) {
    int bookIndex;
    cout << "Enter the index of book you want to borrow: ";
    cin >> bookIndex;
    if (bookIndex < 0 || bookIndex > mylibrary.numBooks) {
        cout << "Invalid index. Please try again.\n";
    }
    else if (!mylibrary.books[bookIndex-1].available) {
        cout << "This book is not available for borrwoing.\n";
    }
    else {
        mylibrary.books[bookIndex-1].available = false;
        cout << "Book borrowed successfully.\n";
    }
}
// Function to view the list of books borrowed by a student
void viewBorrowedBooks(library mylibrary) {
    cout << "\nBorrowed Books:\n";
    for (int i = 0; i < mylibrary.numBooks; i++) {
        if (!mylibrary.books[i].available) {
            cout << "- " << mylibrary.books[i].name << endl;
        }
    }
}
// Function to modify the list of books borrowed by a student
void modifyBorrowedBooks(library& mylibrary) {
    int bookIndex;
    char returnBook;
    cout << "Enter the index of the book you want to modify: ";
    cin >> bookIndex;
    cout << "Do you want to return the book? (enter y or n): ";
    cin >> returnBook;
    if (!mylibrary.books[bookIndex - 1].available) {

        if (bookIndex >= 0 && bookIndex < mylibrary.numBooks) {
            if (returnBook == 'y') {
                mylibrary.books[bookIndex - 1].available = true;
                cout << "Book returned successfully.\n";
            }
            else {
                cout << "The book is still in your list\n";
            }
        }
        else {
            cout << "Invalid Selection.\n";
        }

    } else {
        cout << "This book is not in your borrowed list";
    }
}

// Function to check if the administrator's password is correct

bool adminlog( const int adminsPassword) {
    int password = 123;

    if (adminsPassword == password) {
        return 1;
    }
    else {
        return 0;
    }
}
// Function for an administrator to add a new book to the library
void newBook(library& mylibrary, int numBooks) {  // Corrected the function d
    char available;

  //  AddNewBook:
    cout << "Please enter the new book's code" << endl;
    cin >> mylibrary.books[numBooks].code;

    cout << "Please enter the new book's name" << endl;
    cin >> mylibrary.books[numBooks].name;

    cout << "Please enter the new book's category" << endl;
    cin >> mylibrary.books[numBooks].category;

    cout << "Please enter the new book's author name" << endl;
    cin >> mylibrary.books[numBooks].authorName;

    cout << "Please enter the new book's edition" << endl;
    cin >>mylibrary.books[numBooks].edition;

    cout << "Please enter y if the book is available and n if not" << endl;
    cin >> available;
    if (available == 'y') {
        mylibrary.books[numBooks].available = true;
        cout << "This Book is added successfully!" << endl;
    } else if(available == 'n'){
        mylibrary.books[numBooks].available = false;
        cout << "This Book is added successfully!" << endl;
    } else{
        cout <<"This is invalid input";
    }
    mylibrary.numBooks++;
}
// Function for an administrator to delete a book from the library
void deleteBook(library mylibrary ,library library2) {
    string x;
    int index = 0;

    cout << " enter the code of the book you want to delete\n";
    cin >> x;

    for (int i=0 ; i < mylibrary.numBooks;i++) {
        if (mylibrary.books[i].code == x) {
            index = i;

        }

    }
    for (int j = 0;j < index ;j++) {
        library2.books[j].code = mylibrary.books[j].code;
        library2.books[j].name = mylibrary.books[j].name;
        library2.books[j].category = mylibrary.books[j].category;
        library2.books[j].authorName  = mylibrary.books[j].authorName;
        library2.books[j].edition = mylibrary.books[j].edition;
        library2.books[j].available = mylibrary.books[j].available;
    }
    for (int j = index+1 ;j < maxBooks; j++) {
        library2.books[j -1].code = mylibrary.books[j -1].code;
        library2.books[j -1].name = mylibrary.books[j -1].name;
        library2.books[j -1].category = mylibrary.books[j -1].category;
        library2.books[j -1].authorName  = mylibrary.books[j -1].authorName;
        library2.books[j -1].edition = mylibrary.books[j -1].edition;
        library2.books[j -1].available = mylibrary.books[j -1].available;


    }


    for(int k=0;k<maxBooks;k++)
    {
        mylibrary.books[k].code = library2.books[k].code ;
        mylibrary.books[k].name = library2.books[k].name ;
        mylibrary.books[k].category = library2.books[k].category ;
        mylibrary.books[k].authorName = library2.books[k].authorName ;
        mylibrary.books[k].edition = library2.books[k].edition ;
        mylibrary.books[k].available = library2.books[k].available ;
    }
}
// Function for an administrator to edit the information of a book in the library
void editBook(library& mylibrary) {
    string editinfo;
    cout << "\n Enter the code of book you want to edit" << endl;
    cin >> editinfo;

    for (int i = 0; i < mylibrary.numBooks ; i++) {
        // Check if the code of the current book matches the user input
        if (mylibrary.books[i].code == editinfo) {
            cout << "\nThe book is found in the library" << endl;

            cout << "Code: " << mylibrary.books[i].code << endl;
            cout << "Name: " << mylibrary.books[i].name << endl;
            cout << " authorName: " << mylibrary.books[i].authorName << endl;
            cout << "Edition: " << mylibrary.books[i].edition << endl;
            cout << "Category " << mylibrary.books[i].category << endl;

            // set the new info

            cout << "\nEnter new information for the book:" << endl;

            cout << "New Code: ";
            getline(cin, mylibrary.books[i].code);
            cout << "New Name: ";
            getline(cin, mylibrary.books[i].name);
            cout << "New Author: ";
            getline(cin, mylibrary.books[i].authorName);
            cout << "New Edition: ";
            getline(cin, mylibrary.books[i].edition);
            cout << "New Category: ";
            getline(cin, mylibrary.books[i].category);

            cout << "\nThe book is edited successfully" << endl;
        }
    }

    cout << "The book is not found" << endl;

}
// Main function where the program execution starts
int main() {


    student studentLogged[maxStudent];
    library mylibrary;

    mylibrary.numBooks = 4;
    mylibrary.books[0] = { "3K02" ,"Atomic Habits", "Self Help", "James Clear", "2nd edition", true };
    mylibrary.books[1] = { "3K03", "The Kite Runner", "Literature", "Khaled Hosseini", "1st edition", true };
    mylibrary.books[2] = { "3K04", "Hamlet", "Play", "William Shakespear", "10th edition", true };
    mylibrary.books[3] = { "3K05", "Harry Potter and the Chamber of Secrets", "Young Adult", "J.K. Rolling", "14th edition", true };

    int adminsPassword;
    int Checklog;
    char loginType , acc , options ;
    bool checklog = 0;
    short index = 0;
    short bookIndex;
    short choice = 0;
    char modify = ' ';
    back:
    start:
    cout << "For student login enter s \n For admin login enter a";
    cin >> loginType;
    //Student Login
    if (loginType == 's' || loginType == 'S') {
        cout << "Do you have an Account? \n"; //answer shoud be y or n
        cin >> acc;


        if (acc == 'y' || acc == 'Y') {
            index = StudentLog(studentLogged);
        } else if (acc == 'n' || acc == 'N') {
            index = StudentSign(studentLogged);

        } else {
            cout << "This is an invalid answer \n";
        }


        //Check if login is successful
        // We can do extra functionality
        //checklog = Checklog(studentLogged);
        while (index == -1) {
            cout << "This is invalid Login \n Try to login again \n";
            index = StudentSign(studentLogged);
        }

        if (index != -1) {
            cout << "You have logged in Successfully! \n Here are the options you have: ";
            index:
            cout << "Edit information (enter e)" << endl << "View my library (enter l)" << endl << "Log out (enter o)"
                 << endl;
            cin >> options;
            cin.ignore();
            switch (options) {
                case 'e':
                    editInfo(studentLogged, index);
                    goto index;
                    break;

                case 'l':
                    do {
                        displayOptions();
                        cout << "Enter your choice: ";
                        cin >> choice;


                        switch (choice) {
                            case 1:
                                viewBookNames(mylibrary);
                                break;

                            case 2:
                                cout << "Enter the index of the book you want to view: ";
                                cin >> bookIndex;

                                if (bookIndex >= 1 && bookIndex <= mylibrary.numBooks) {
                                    viewBookInfo(mylibrary.books[bookIndex - 1]);
                                }
                                else {
                                    cout << "This is invalid index";
                                }
                                   break;

                            case 3:
                                borrowBook(mylibrary);
                                break;


                            case 4:
                                viewBorrowedBooks(mylibrary);
                                break;

                            case 5:
                                modifyBorrowedBooks(mylibrary);
                                break;

                            default:
                                cout << "This is invalid Choice." << endl;
                                cout << "Please try again." << endl;
                                break;
                        }
                    } while (true);
                        break;

                case 'o':
                goto start;

                break;

                default:
                   // cout << "This is invalid option\n";
                    break;
            }
            goto index;
        }

    }

    else if (loginType =='a') {
        adminlogin:
        cout << "Please enter admin's password" << endl;
        cin >> adminsPassword;
        //checck whether the login is valid or not
        Checklog = adminlog(adminsPassword);
        int choices;
        if (Checklog) {
            cout << "you have logged in successfully!!" << endl << "Please select the option you want to get access on:\n";
            choices:
            cout << "1- Add a new book" << endl;
            cout << "2- Modify books information" << endl;
            cout << "3- Delete a book from the library" << endl;
            cin>>choices;
            switch(choices)
            {
                case 1:
                    newBook(mylibrary, mylibrary.numBooks);
                    goto choices ;
                    break;

                case 2:
                    editBook(mylibrary);
                    goto choices ;
                    break;
                case 3 :
                    library library2;
                    deleteBook(mylibrary, library2);
                    cout<<"you have deleted this book successfully" << endl;
                    goto choices ;
                break;


            }
        }
        else {
            cout << "This is an invalid login" << endl << "Please try to login again" << endl;
            goto adminlogin;
        }


    }


    else
    {
        cout <<"This is an invalid type\nplease enter the required letters" << endl;

        goto back;
    }

    return 0;
}


