#include<bits/stdc++.h>
#include "BST.h"
#include "staff.h"
#include "customer.h"
#include "admin.h"
using namespace std;

BST* detail = nullptr;

int main()
{
    while(true)
    {
        cout<<"Choose the following "<<endl;
        cout<<"1. staff"<<endl;
        cout<<"2. customer"<<endl;
        cout<<"3. admin"<<endl;
        cout<<"4. exit"<<endl;
        int condition;
        cin>>condition;
        if(condition ==1){
            staff s(detail);
            detail = s.function();
        }
        else if(condition == 2){
            customer c(detail);
            detail = c.function();
        }
        else if(condition == 3){
            admin a(detail);
            detail = a.function();  
        }
        else
            break;
    }
    
    
}