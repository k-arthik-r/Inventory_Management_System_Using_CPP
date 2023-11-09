#include<iostream>
#include<algorithm>
using namespace std;

typedef struct cartNode
{
    int product_id;
    char product_name[32];
    int quantity;
    double sum;
    cartNode* link;
}cartNode;

class CartNode{

    public:
    cartNode* head = NULL;

    cartNode* createNode(cartNode* cart ,int id, char name[32], int quantity, int price) {
        cartNode* newNode = (cartNode*)malloc(sizeof(cartNode));
        newNode->link = NULL;
        newNode->product_id = id;
        copy_n(name, 32, newNode->product_name);
        newNode->quantity = quantity;
        newNode->sum = quantity * price;
        if (cart == NULL){
            cart =  newNode;
        }
        else{
            cartNode* temp = cart;
            while(temp->link != NULL){
                temp = temp->link;
            }
            temp->link = newNode;
        }
        return cart;
    }

    void listAllCartNode(cartNode* cart){
        cartNode *cartt = cart;
        cout<<endl<<"Cart"<<endl;
        for(int index = 0; index < 100; index++)
            cout<<".";
        cout<<endl;
        if(cartt == NULL) {
            cout<<"Cart is Empty"<<endl<<endl;
            return;
        }
        cout<<"Product ID\tProduct name\tQuantity\tPrice"<<endl;
        while(cartt != NULL) {
            cout<<cartt->product_id<<"\t\t"<<cartt->product_name<<"\t\t"<<cartt->quantity<<"\t\t"<<cartt->sum<<endl;
            cartt = cartt->link;
        }
        cout<<endl;
        return;
    }
    
};