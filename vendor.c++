#include"categories.c++"
#include"cart.c++"
#include<iostream>
#include<fstream>

using namespace std;

Category *sections[15];
CartNode cart;

int main();
void addItems();
void customer();
void viewcart();
int checkCategory();
void vendor();
void askForTheItem(Node);
void removeItemsFromCart();
void showProducts(int);
void viewCart();
void generateBill(cartNode);
void customer();


void init() {
    sections[0] = new Category("Fruits");
    sections[0]->head = sections[0]->push(sections[0]->head, 101, const_cast<char*>("Apple"), 32.5, 22);
    sections[0]->head = sections[0]->push(sections[0]->head, 102, const_cast<char*>("Banana"), 5, 48);
    sections[0]->head = sections[0]->push(sections[0]->head, 103, const_cast<char*>("Kiwi"), 40, 2);
    sections[0]->head = sections[0]->push(sections[0]->head, 104, const_cast<char*>("Orange"), 7, 35);
    sections[1] = new Category("Vegetables");
    sections[1]->head = sections[1]->push(sections[1]->head, 201, const_cast<char*>("Potato"), 4, 120);
    sections[1]->head = sections[1]->push(sections[1]->head, 202, const_cast<char*>("Tomato"), 9, 35);
    sections[1]->head = sections[1]->push(sections[1]->head, 203, const_cast<char*>("Chilies"), 10, 40);
    sections[1]->head = sections[1]->push(sections[1]->head, 204, const_cast<char*>("Cucumber"), 15, 30);
    sections[2] = new Category("Dairy");
    sections[2]->head = sections[2]->push(sections[2]->head, 301, const_cast<char*>("Milk"), 25, 100);
    sections[2]->head = sections[2]->push(sections[2]->head, 302, const_cast<char*>("Cheese"), 130, 20);
    sections[2]->head = sections[2]->push(sections[2]->head, 303, const_cast<char*>("Butter"), 49, 45);
    sections[3] = new Category("Snacks");
    sections[3]->head = sections[3]->push(sections[3]->head, 401, const_cast<char*>("Kurkure"), 10, 2);
    sections[3]->head = sections[3]->push(sections[3]->head, 402, const_cast<char*>("Lays"), 20, 1);
    sections[3]->head = sections[3]->push(sections[3]->head, 403, const_cast<char*>("Bingo"), 15, 25);
    sections[3]->head = sections[3]->push(sections[3]->head, 404, const_cast<char*>("Bourbon"), 30, 29);
}
int checkCategory() {
    int index;
    string catName;
    cout<<"Enter category name: ";
    cin>>catName;
    for(index = 0; index < 15; index++) {
        if(sections[index]->category_name == catName)
            break;
    }
    if(index == 15)
        cout<<endl<<"Incorrect category name!"<<endl<<endl;
    return index;
}
void vendor() {
    int catcount = 4;
    int choice = 0;
    int index, id;
    string catName;
    do{
        for(index = 0; index < 100; index++)
            cout<<".";
        cout<<endl;
        cout<<"1.Create New Category\t2.Add New Item\t3.View Category\t 4.Delete Product\n5.Update Price\t\t6.Update Stock\t0.Exit"<<endl;
        for(index = 0; index < 100; index++)
            cout<<".";
        cout<<endl;
        cout<<"Choice: ";
        cin>>choice;
        switch(choice) {
            case 1: cout<<"Enter category name: ";
                    cin>>catName;
                    sections[catcount] = new Category(catName);
                    catcount++;
                    break;
            case 2: index = checkCategory();
                    if(index == 15)
                        break;
                    sections[index]->head = sections[index]->push(sections[index]->head);
                    break;
            case 3: index = checkCategory();
                    if(index == 15)
                        break;
                    sections[index]->listAll(sections[index]->head);
                    break;
            case 4: index = checkCategory();
                    if(index == 15)
                        break;
                    cout<<"Enter product id: ";
                    cin>>id;
                    sections[index]->head = sections[index]->pop(sections[index]->head, id);
                    break;
            case 5: index = checkCategory();
                    if(index == 15)
                        break;
                    cout<<"Enter product id: ";
                    cin>>id;
                    sections[index]->updatePrice(sections[index]->head, id);
                    break;
            case 6: index = checkCategory();
                    if(index == 15)
                        break;
                    cout<<"Enter product id: ";
                    cin>>id;
                    sections[index]->updateStock(sections[index]->head, id);
                    break;
            case 0: break;
            default: cout<<"Enter a valid choice!"<<endl;
        }
    }while(choice!=0);
}
void askForTheItem(Node *sect){
    int id, qty, take;
    cout<<"Enter the product ID: ";
    cin>>id;
    while(sect->product_id != id){
        sect = sect->link;
    }
    cout<<"Enter the quantity: ";
    cin>>qty;
    if(qty > sect->stock){
        cout<<"The Available stock is only "<<sect->stock<<" Shall I add all the Items?(1 - yes, 0 - no, 999 - cancel the item)"<<endl; cin>>take;
        if(take == 1){
            qty = sect->stock;
        }
        else if(take == 0){
            cout<<"Then Enter the Quantity less than  the stock: "; cin>>qty;
        }
        else if(take == 999){
            return;
        }
        else{
            cout<<"Invalid Choice"<<endl;
        }
    }
    cart.head = cart.createNode(cart.head, id, sect->product_name, qty, sect->price);
    sect->stock = sect->stock - qty;
    cout<<"\n*Item Added to the Cart!!!"<<endl;
}
void removeItemsFromCart(){
    int id;
    cout<<"Enter the id of the product Item: "; cin>>id;
    cart.pop(cart.head, id);
    return;
}
void showProducts(int index){

    int showProductChoice = 0;
    sections[index]->listAll(sections[index]->head);
    do{
        for(int index = 0; index < 100; index++)
            cout<<".";
        cout<<"\n1. Add Items to the cart\n2. Remove Items form the Cart\n3. View Cart\n4. Go Back to the Categories List\n5. Go Back to the main menu\n6. Exit"<<endl; 
        for(int index = 0; index < 100; index++)
            cout<<".";    
        cout<<"\nEnter Your Choice: ";
        cin>>showProductChoice;
        switch(showProductChoice){
            case 1: askForTheItem(sections[index]->head);
                break;
            case 2: removeItemsFromCart();
                break;
            case 3: viewCart();
                break;
            case 4: addItems();
                break;
            case 5: customer();
                break;
            case 6: exit(1);
                break;
            default: cout<<"\nEnter a Valid Choice!!! "<<endl;
        }
    }while(showProductChoice != 0);
    
}
void addItems(){
    int index;
    string catName;
    for(int index = 0; index < 15; index++){
        if(sections[index] != NULL){
            cout<<index + 1<<". "<<sections[index]->category_name<<endl;
        }
    }
    cout<<"\nEnter category name: ";
    cin>>catName;
    for(index = 0; index < 15; index++) {
        if(sections[index]->category_name == catName)
            showProducts(index);
    }
    if(index == 15)
        cout<<endl<<"\nIncorrect category name!"<<endl;
}
void viewCart(){
    cart.listAllCartNode(cart.head);
}
void generateBill(cartNode *head)
{
    ofstream billFile;
    billFile.open("bill.txt");
    double total = 0.0;
    cartNode *current = head;
    billFile<<"                C++  MART                "<<endl;
    for(int i = 0; i < 41; i++)
            billFile<<"-";
    billFile<<endl;
    billFile <<"ID\t\t"<<"Product Name\t\t"<<"Qty\t\t"<<"Price"<<endl;
    for(int i = 0; i < 41; i++)
            billFile<<"-";
    billFile<<endl;
    while (current != NULL)
    {
        billFile<< current->product_id << "\t\t" << current->product_name << "\t\t\t\t" << current->quantity << "\t\t" <<current->sum<<endl;
        total += current->sum;
        current = current->link;
    }
    billFile<<endl;
    for(int i = 0; i < 41; i++)
        billFile<<"-";
    double tax = total*0.18;
    billFile << "\nTax:\t\t\t\t\t\t\t\t" <<tax<< endl;  
    for(int i = 0; i < 41; i++)
        billFile<<"-";      
    billFile << "\nGrand Total:\t\t\t\t\t\t" << total+tax << endl;
    for(int i = 0; i < 41; i++)
        billFile<<"-";
    billFile<<endl;
    billFile.close();
}
void customer(){
    int cchoice = 0;
    do{
        for(int index = 0; index < 100; index++)
            cout<<".";        
        cout<<"\n1. View and Add Items to the cart\n2. Remove Items form the Cart\n3. View Cart\n4. Chectout and Generate Bill\n5. Exit"<<endl;
        for(int index = 0; index < 100; index++)
            cout<<".";        
        cout<<"\nEnter Your Choice: ";        
         cin>>cchoice;
        switch(cchoice){
            case 1: addItems();
                    break;
            case 2: removeItemsFromCart();
                    break;
            case 3: viewCart();
                    break;
            case 4: generateBill(cart.head);
                    for(int index = 0; index < 100; index++)
                        cout<<".";
                        cout<<"\n--------------------------------------------------"<<endl;
                        cout<<"|                                                |"<<endl;
                        cout<<"|            THANK  YOU, VISIT AGAIN             |"<<endl;
                        cout<<"|                                                |"<<endl;
                        cout<<"--------------------------------------------------"<<endl;
                    exit(1);
                    break;
            case 5: exit(1);
                break;
            default: cout<<"\nEnter a Valid Choice!!!"<<endl;
                break;
        }
    }while(cchoice != 0);

}
int main() {
    init();
    int choice = 0;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"|                                                |"<<endl;
    cout<<"|                     C++ MART                   |"<<endl;
    cout<<"|                                                |"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    do {
        for(int index = 0; index < 100; index++)
            cout<<".";
        cout<<"\n1. I am a Vendor\n2. I am a Customer\n3. Exit"<<endl;
        for(int index = 0; index < 100; index++)
            cout<<".";
        cout<<"\nEnter your Choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1: vendor();
            break;
        case 2: customer();
            break;
        default:cout<<"\nEnter a Valid Choice!!!"<<endl;
            break;
        }
    }while(choice != 0);
    return 0;
}