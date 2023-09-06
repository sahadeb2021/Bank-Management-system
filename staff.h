#pragma once
#ifndef STAFF_H
#define STAFF_H


#include "BST.h"

class staff
{
    protected:
        BST* bst;
    public:
        staff(BST* &b)
        {
            bst = b;
        }
        
        BST* function();
        void showCustomerDetail(int);
        void deposit(int ,int);
        void transfer(int ,int,int);
        void withdraw(int ,int);
};


BST* staff :: function()
{
    while(true)
    {
        cout<<"choose the following "<<endl;
        cout<<"1. Get customer detail"<<endl;
        cout<<"2. Deposit"<<endl;
        cout<<"3. transfer"<<endl;
        cout<<"4. Withdraw"<<endl;
        cout<<"5. exit"<<endl;
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
        else
        {
            return bst;
        }
    }
    
}


void staff :: deposit(int acc,int am)
{
    BST* Account_node = getBST_node(bst,acc);
    if(Account_node)
    {
        Account_node->v.account += am;
    }
    else
        return;
}

void staff :: withdraw(int acc,int am)
{
    BST* Account_node = getBST_node(bst,acc);
    if(Account_node)
        Account_node->v.account -= am;
    else 
        return;
}


void staff :: transfer(int send_acc,int rec_acc,int am)
{
    BST* send_node = getBST_node(bst,send_acc);
    if(!send_node)
    {
        cout<<"sender account number not found";
        return;
    }
    BST* rec_node = getBST_node(bst,rec_acc);
    if(!rec_node)
    {
        cout<<"receiver account number not found";
        return;
    }
    send_node->v.amount -= am;
    rec_node->v.amount += am;
}

void staff :: showCustomerDetail(int acc)
{
    Node Account_node = getInfo(bst,acc);
    Account_node.Print();
}




#endif