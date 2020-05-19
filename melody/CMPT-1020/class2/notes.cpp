

// first file
#include <iostream>
using namespace std;

class Book {
    private:
    string title;
    string author;
    int edition;
    double price;

    public:
    string getTitle() const;
    string getAuthor() const;
    int getEdition() const;
    double getPrice() const;
    void setTitle(string);
    void setAuthor(string);
    void setEdition(int);
    void setPrice(double);
    Book();
    Book(string);
    Book(string, string, int, double);
    void output();
    void input();
};

void Book::output()
{
    cout << title << " by " << author << " " << edition << "th edition is worth $" << price << endl;
}

void Book::input()
{
    cout << "Title?";
    getline(cin, title);
    cout << "Author?";
    getline(cin, author);
    cout << "Edition?";
    cin >> edition;
    cout << "Price?";
    cin >> price;
}

Book::Book()
{
    title = "Python Programming";
    author = "Gaddis";
    edition = 5;
    price = 79.99;
    cout << "Hello" << endl;
}
Book::Book(string x)
{
    title = x;
    author = "Liang";
    edition = 8;
    price = 19.99;
    cout << "Hi" << endl;
}
Book::Book(string x, string y, int a, double b)
{
    title = x;
    author = y;
    edition = a;
    price = b;
    cout << "Hola" << endl;
}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

int Book::getEdition() const
{
    return edition;
}

double Book::getPrice() const
{
    return price;
}

void Book::setTitle(string x)
{
    title = x;
}
void Book::setAuthor(string x)
{
    author = x;
}
void Book::setEdition(int x)
{
    edition = x;
}
void Book::setPrice(double x)
{
    price = x;
}

int main()
{
    Book a;
    Book b;
    Book c("Intro to programming");
    Book d("Anatomy", "Robinson", 2, 99.99);
    Book e[10]; // makes 10 Books; runs the default constructor for each one.
    e[0].setTitle("Crime And Punishment");
    e[0].setAuthor("Fyodor Dostoevsky");
    //... other indexes
    e[9].setTitle("Anna Kerenina");
    e[9].setAuthor("Leo Tolstoy");
    e[9].setPrice(24.99);
/*    a.setTitle("Harry Potter");
    a.setEdition(4);
    a.setPrice(9.99);
    a.setAuthor("Rowling");*/
    a.input();
    a.output();
    b.output();
    c.output();
    d.output();
}

