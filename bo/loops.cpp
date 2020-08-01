#include <vector>
#include <array>
#include <iostream>

// allows access to a "Generic Type"
template <typename T>
class Node 
{
    T value;
    Node *next;
    public:

    // default constructor
    Node()
    {
        next = NULL;
        value = 0;
    }
    Node(T val)
    {
        if (typeof(val) == bool)
        {
            throw "Boolean not allowed";
        }
        value = val;
        next = NULL;
    }
    // used in main
    Node(T val, Node *next_ptr)
    {
        value = val;
        next = next_ptr;
    }

    friend std::ostream& operator<<(std::ostream& os, Node& n)
    {
        os << n.value << " -> " << n.next;
        return os;
    }
};

// + - / * ++ -- << >>

// inherit fro Node
template <typename T>
class BetterNode : public Node<T>
{
    // runs this default constructor first, then it runs the parent's default constructor
    BetterNode()
    {
        this::Node(NULL, NULL); // similar to this; manually invoke the parent constructor
    }
    BetterNode(int);
};

int fact(int f);

int main()
{
    // C notation
    int biglist[22] = {1,5,22,532,11,235,92};
    // fixed-memory C++
    std::array<int, 10> betterlist = {1,2,3,4,5,6,7,8,9,9};
    // dynamic memory allocation C++
    std::vector<int> bestlist = {10, 20, 30};
    std::vector<std::string> string_vec = {"One", "Two", "Three"};

    for (int i =0; i<5; i++)
    {
        std::cout<<biglist[i];
    }

    Node<int> n(20, NULL);
    std::cout << n << std::endl;

}

int fact(int f)
{
    if (f <= 1)
        return f;
    else
        return fact(f-1) + fact(f-2);
}
