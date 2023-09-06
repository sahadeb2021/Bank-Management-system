// admin is alomost working
#ifndef ADMIN_H
#define ADMIN_H

#include "staff.h"

class admin : public staff
{
    public:
        admin(BST* &bst) : staff(bst)
        {
            
        }
        BST* function();
        void CreateAccount(int,string,string,int);
        void DeleteAccount(int);
        void changeDetail(int,string,string);
};




BST* admin :: function()
{
    while(true)
    {
        cout<<"choose the following "<<endl;
        cout<<"1. Get customer detail"<<endl;
        cout<<"2. Deposit"<<endl;
        cout<<"3. transfer"<<endl;
        cout<<"4. Withdraw"<<endl;
        cout<<"5. change Detail"<<endl;
        cout<<"6. Create Account"<<endl;
        cout<<"7. Delete account"<<endl;
        cout<<"8. exit"<<endl;
        int condition;
        cin>>condition;
        if(condition == 1)
        {
            cout<<"Enter the account number : ";
            int acc;
            cin>>acc;
            showCustomerDetail(acc);
        }
        else if(condition == 2)
        {
            int acc,am;
            cout<<"Enter account number : ";
            cin>>acc;
            cout<<"Enter amount : ";
            cin>>am;
            deposit(acc,am);
        }
        else if(condition == 3)
        {
            int send_acc,rec_acc,am;
            cout<<"Enter sender account number : ";
            cin>>send_acc;
            cout<<"Enter receiver account number : ";
            cin>>rec_acc;
            cout<<"amount : ";
            cin>>am;
            transfer(send_acc,rec_acc,am);
        }
        else if(condition == 4)
        {
            int acc,am;
            cout<<"Enter account number : ";
            cin>>acc;
            cout<<"Enter amount : ";
            cin>>am;
            withdraw(acc,am);
        }
        else if(condition == 5)
        {
            int acc;
            string n,a;
            cout<<"Enter account number : ";
            cin>>acc;
            cout<<"Enter new name : ";
            cin>>n;
            cout<<"Enter address : ";
            cin>>a;
            changeDetail(acc,n,a);
        }
        else if(condition == 6)
        {
            int acc,am;
            string n,a;
            cout<<"Enter account number : ";
            cin>>acc;
            cout<<"Enter name : ";
            cin>>n;
            cout<<"Address : ";
            cin>>a;
            cout<<"Enter amount : ";
            cin>>am;
            CreateAccount(acc,n,a,am);
        }
        else if(condition == 7)
        {
            int acc;
            cout<<"Enter account number : ";
            cin>>acc;
            DeleteAccount(acc);
        }
        else
        {
            return bst;
        }
    }
}


void admin :: CreateAccount(int acc,string n,string a,int am)
{
    Node new_node(n,acc,am,a);
    bst = Add(bst,new_node);
    showCustomerDetail(acc);
}

void admin :: DeleteAccount(int a)
{
    bst = Delete(bst,a);
}
void admin :: changeDetail(int acc,string n,string a)
{
    BST* x= getBST_node(bst,acc);
    x->v.name = n;
    x->v.address = a;
}

#endif