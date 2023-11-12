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

    // void pop(cartNode* cart, int id){
    //     if(cart == NULL){
    //         cout<<"\nNo Items to Delete, Cart is Empty!!!"<<endl;
    //     }
    //     else if((cart->product_id == id && cart->link == NULL){
    //         cartNode *curr = cart->link;
    //             cart->link = curr->link;
    //             free(curr);
    //     }
    //     else{
    //         cartNode *curr = cart;
    //         cartNode *prev = NULL;
    //         while(curr->product_id != id){
    //             prev = curr;
    //             curr = curr->link;
    //         }
    //         prev->link = curr->link;
    //         free(curr);
    //         cout<<"\nItem Successfully Removed!!!"<<endl;
    //     }
    // }

    // cartNode* pop(cartNode* head, int id) {
    // if(head == NULL) {
    //     cout<<"\nCart Is Empty, No Items to Delete!"<<endl<<endl;
    //     return head;
    // }
    // else if(head->link == NULL && head->product_id == id) {
    //     cout<<"\nProduct with id "<<id<<" has been successfully deleted from the cart"<<endl<<endl;
    //     free(head);
    //     return NULL;
    // }
    // cartNode *first = NULL, *second = head, *third = head->link;
    // while(second != NULL) {
    //     if(second->product_id == id) {
    //         break;
    //     }
    //     first = second;
    //     second = third;
    //     if(third != NULL)
    //         third = third->link;
    // }
    // if(second == NULL) {
    //     cout<<"\nProduct not found!"<<endl<<endl;
    //     return head;
    // }
    // first->link = third;
    // cout<<"\nProduct with id "<<id<<" has been successfully deleted from the cart"<<endl<<endl;
    // free(second);
    // return head;
    // }

void pop(cartNode*& head, int id) {
    cartNode* temp = head;
    cartNode* prev = NULL;

    if(temp == NULL){
        cout<<"\nCart Is Empty, No Items to Delete!"<<endl<<endl;
    }

    if (temp != NULL && temp->product_id == id) {
        head = temp->link;
        free(temp);
        cout<<"\nProduct with id "<<id<<" has been successfully deleted from the cart"<<endl<<endl;
        return;
    }
    while (temp != NULL && temp->product_id != id) {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL) {
        cout << "Item with product_id " << id << " not found." << endl;
        return;
    }
    prev->link = temp->link;
    free(temp);
    cout<<"\nProduct with id "<<id<<" has been successfully deleted from the cart"<<endl<<endl;
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