#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Node
{
    int product_id;
    char product_name[32];
    double price;
    int stock;
    Node *link;
} Node;

class Category
{
public:
    Node *head = NULL;
    string category_name;
    Category()
    {
    }
    Category(string obj_name)
    {
        category_name = obj_name;
    }

    Node *createNode()
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->link = NULL;
        cout << "Enter product id: ";
        cin >> newNode->product_id;
        cout << "Enter product name: ";
        cin >> newNode->product_name;
        cout << "Enter product price: ";
        cin >> newNode->price;
        cout << "Enter product stock: ";
        cin >> newNode->stock;
        return newNode;
    }

    Node *createNode(int id, char name[32], double price, int stock)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->link = NULL;
        newNode->product_id = id;
        copy_n(name, 32, newNode->product_name);
        newNode->price = price;
        newNode->stock = stock;
        return newNode;
    }

    Node *push(Node *head)
    {
        Node *newNode = createNode();
        Node *temp = head;
        if (head == NULL)
        {
            return newNode;
        }
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = NULL;
        return head;
    }
    Node *push(Node *head, int id, char name[32], double price, int stock)
    {
        Node *newNode = createNode(id, name, price, stock);
        Node *temp = head;
        if (head == NULL)
        {
            return newNode;
        }
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = NULL;
        return head;
    }

    Node *pop(Node *head, int id)
    {
        if (head == NULL)
        {
            cout << "Empty category!" << endl
                 << endl;
            return head;
        }
        if (head->product_id == id)
        {
            Node *temp = head;
            head = head->link;
            free(temp);
            cout << "Product with id " << id << " has been successfully deleted." << endl
                 << endl;
            return head;
        }

        Node *prev = head;
        Node *curr = head->link;

        while (curr != NULL)
        {
            if (curr->product_id == id)
            {
                prev->link = curr->link;
                free(curr);
                cout << "Product with id " << id << " has been successfully deleted." << endl
                     << endl;
                return head;
            }
            prev = curr;
            curr = curr->link;
        }

        cout << "Product with id " << id << " not found!" << endl
             << endl;
        return head;
    }

    void listAll(Node *head)
    {
        cout << endl
             << category_name << endl;
        for (int index = 0; index < 100; index++)
            cout << ".";
        cout << endl;
        if (head == NULL)
        {
            cout << "Empty category!" << endl
                 << endl;
            return;
        }
        cout << "Product ID\tProduct name\tPrice\t\tStock" << endl;
        while (head != NULL)
        {
            cout << head->product_id << "\t\t" << head->product_name << "\t\t" << head->price << "\t\t" << head->stock << endl;
            head = head->link;
        }
        cout << endl;
    }
    void updatePrice(Node *head, int id)
    {
        int price;
        if (head == NULL)
        {
            cout << "Empty category!" << endl
                 << endl;
            return;
        }
        else if (head->link == NULL && head->product_id == id)
        {
            cout << "Enter new price of " << head->product_name << ": ";
            cin >> price;
            head->price = price;
            cout << "Product with id " << id << " has been successfully updated." << endl
                 << endl;
            return;
        }
        Node *first = NULL, *second = head, *third = head->link;
        while (second != NULL)
        {
            if (second->product_id == id)
            {
                break;
            }
            first = second;
            second = third;
            if (third != NULL)
                third = third->link;
        }
        if (second == NULL)
        {
            cout << "Product not found!" << endl
                 << endl;
            return;
        }
        cout << "Enter new price of " << second->product_name << ": ";
        cin >> price;
        second->price = price;
        cout << "Product with id " << id << " has been successfully updated." << endl
             << endl;
        return;
    }
    void updateStock(Node *head, int id)
    {
        int stock;
        if (head == NULL)
        {
            cout << "Empty category!" << endl
                 << endl;
            return;
        }
        else if (head->link == NULL && head->product_id == id)
        {
            cout << "Enter new stock of " << head->product_name << ": ";
            cin >> stock;
            head->stock = stock;
            cout << "Product with id " << id << " has been successfully updated." << endl
                 << endl;
            return;
        }
        Node *first = NULL, *second = head, *third = head->link;
        while (second != NULL)
        {
            if (second->product_id == id)
            {
                break;
            }
            first = second;
            second = third;
            if (third != NULL)
                third = third->link;
        }
        if (second == NULL)
        {
            cout << "Product not found!" << endl
                 << endl;
            return;
        }
        cout << "Enter new stock of " << second->product_name << ": ";
        cin >> stock;
        second->stock = stock;
        cout << "Product with id " << id << " has been successfully updated." << endl
             << endl;
        return;
    }
};

class Cart : public Category
{
public:
    Node *createNode()
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->link = NULL;
        cout << "Enter product id: ";
        cin >> newNode->product_id;
        cout << "Enter product name: ";
        cin >> newNode->product_name;
        cout << "Enter product price: ";
        cin >> newNode->price;
        cout << "Enter product stock: ";
        cin >> newNode->stock;
        return newNode;
    }

    Node *push(Node *head)
    {
        Node *newNode = createNode();
        Node *temp = head;
        if (head == NULL)
        {
            return newNode;
        }
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newNode;
        newNode->link = NULL;
        return head;
    }
};