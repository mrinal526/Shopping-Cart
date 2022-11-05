#include<iostream>
#include"datamodel.h"
#include<vector>
using namespace std;

vector<Product>allProducts = {
    Product(1,"apple",26),   
    Product(2,"banana",16),
    Product(3,"mango",36),
    Product(4,"guava",246),
    Product(5,"strawberry",126),
    Product(6,"pineapple",66),
};

Product* chooseProduct(){
    
    string productList;
    cout<<" Available Products "<<endl;

    for(auto product : allProducts){
        productList.append(product.getDisplayName()); 
    }
    cout<< productList <<endl;

    cout<<"---------------------------"<<endl;
   
    string choice;
    cin>>choice;
    for(int i=0;i<allProducts.size();i++){
        if(allProducts[i].getShortName()==choice){
            return &allProducts[i];
        }
    }
    cout<<"Product not found!"<<endl;
    return NULL;
}

bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }

    int total = cart.getTotal();
    cout<<"Pay in Cash ";

    int paid;
    cin>>paid;

    if(paid>=total){
        cout<<"Change "<<paid-total<<endl;
        cout<<"Thank You for Shopping!";
        return true; 
    }
    else{
        cout<<"Not enough cash!";
        return false;
    }
}

int main()
{
    char action;
    Cart cart;
    while(true){
        cout<<"Select an action - (a)dd item, (v)iew cart, (c)heckout"<<endl;
        cin>>action;

        if(action=='a'){
           
            Product * product = chooseProduct(); 
            if(product!=NULL){
                cout<<"Added to the Cart "<<product->getDisplayName()<<endl;
                cart.addProduct(*product); 
            }
        }
        else if(action=='v'){
            
            cout<<"-------------------"<<endl;
            cout<< cart.viewCart();
            cout<<"--------------------"<<endl;
        }
        else{
            //checkout
            cart.viewCart();
            if(checkout(cart)){ 
                break;
            }
        }
    }
    
    return 0;
}