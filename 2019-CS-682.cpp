
//IMPLEMENTATION OF SINGLY LINKED LISTS
//2019-CS-682
//Muhammad Bilal
//IMPLEMENTATION OF SINGLY LINKED LISTS
#include"iostream"
#include"conio.h"
#include <typeinfo>
using namespace  std;



class node //struct
{
public:
    node* nextptr=NULL;
    string ss;
    
    node()
    {
        nextptr = NULL;
    }
    
    node(string s)
    {
        ss = s;
        nextptr = NULL;
    }
    //TO Get the data
    string getstringData()
    {
        return ss;
    }
    void setstringData(string s)
    {
        ss = s;
    }
    node* getNextptr()
    {
        return nextptr;
    }
    void setnextptr(node* nptr)
    {
        nextptr = nptr;
    }
};


class linkedlist
{
    node* headptr;
    node* addnodeatspecificpoition;
    
public:
    linkedlist()
    {
        headptr = NULL;
    }
    void insertionAtTail(node* n)
    {
        if (headptr == NULL)
        {
            headptr = n;
        }
        else
        {
            node* rptr = headptr;
            while (rptr->getNextptr() != NULL)
            {
                rptr = rptr->getNextptr();
            }
            rptr->setnextptr(n);
        }
    }

    void insertionAtHead(node *n)
    {
        node* tmp = n;
        tmp->setnextptr(headptr);
        headptr = tmp;
    }

    int sizeOfLinkedList()
    {
        int i = 1;
        node* ptr = headptr;
        while (ptr->getNextptr() != NULL)
        {
            ++i;
            ptr = ptr->getNextptr();
        }
        return i;
    }

    bool isListEmpty() {
        if (sizeOfLinkedList() <= 1)
        {
            return true;
        }
        else 
        {
            false;
        }
    }


    void insertionAtAnyPoint(node* n, int position)
    {
        if (position > sizeOfLinkedList() || position < 1) {
            cout << "\n\nInvalid insertion at index :" << position<<" ,No such index exists.ERROR!\n";
            return;
        }

        addnodeatspecificpoition = new node;
        addnodeatspecificpoition = n;
        addnodeatspecificpoition->setnextptr(NULL);

        

        if (headptr == NULL)
        {
            headptr = addnodeatspecificpoition;
        }
        else if (position == 0)
        {
            addnodeatspecificpoition->setnextptr(headptr);
            headptr = addnodeatspecificpoition;
        }
        else
        {
            node* current = headptr;
            int i = 1;
            for (i = 1; current != NULL; i++)
            {
                if (i == position)
                {
                    addnodeatspecificpoition->setnextptr(current->getNextptr());
                    current->setnextptr(addnodeatspecificpoition);
                    break;
                }
                current = current->getNextptr();
            }
        }
    }

    void deleteNodeAtHead()
    {
            //temp to store head
            node* temp = headptr;
            cout << "\nDeleting the head node now i.e at position 0\n";
            headptr = temp->getNextptr();
            delete temp;
      
    }
    int searchNode(string d) 
    {
        node* ptr=headptr;
        static int i = 0;   
        bool flag = 0;

            while (ptr->getNextptr()!=NULL) 
            { 
                if (i <= sizeOfLinkedList())
                {
                    return -1;
                }
                if (ptr->getstringData() == d)
                {
                    flag = 1;
                    return i;
                }
                i++;
                ptr = ptr->getNextptr();
            }
            if (flag == 0) { cout << "\nNo element " << d << " exists in the linked list\n"; }
    }
    void numberOfNodesWithKey(string d)
    {
        node* ptr = headptr;
        static int i = 0;
        bool flag = 0;
        static int count = 0;
        while (ptr->getNextptr() != NULL)
        {
            
            if (ptr->getstringData() == d)
            {
                flag = 1;
                count++;
               
            }

            i++;
            ptr = ptr->getNextptr();
        }
        if (flag == 0) { cout << "\nNo element " << d << " exists in the linked list\n"; }
        if (ptr->getNextptr() == NULL)
        {
            cout << "\nNULL (There is no pointer left)\n";
        }
        cout << "\nThe value " << d << " is present " << count << " times is the linked list\n";
    }
    void deleteNodeAtAnyPoint(int position)
    {
        if (position > sizeOfLinkedList() || position < 1)
        {
            cout << "\nInvalid deletion index provided,There is no such node exists like:" << position<<endl;
            return;
        }
        if (headptr == NULL)
        {
            cout << "\nThe list is empty now\n";
            return;
        }
        //temp to store head
        node *temp=headptr;
        //Delete head node
        if (position == 0)
        {
            cout << "\nDeleting the head node now i.e at position 0\n";
            headptr = temp->getNextptr();
            delete temp;
            return;
        }
        //store previous of to be deleted node
        for (int i = 0; temp != NULL && i < position - 1; i++)
        {
            temp = temp->getNextptr();
        }
        if (temp == NULL || temp->getNextptr() == NULL)
        {
            return;
        }
        //delete node at pos (next of pos-1)
        node *next = temp->getNextptr()->getNextptr();
        delete temp->getNextptr();
        temp->setnextptr(next);
    }
    
    void deletionAtTail()
    {
        if (headptr == NULL)
        {
            cout << NULL;
            return;
        }
          

        if (headptr->getNextptr() == NULL) {
            delete headptr;
            cout << NULL;
            return;
        }

        cout << "\nNow removing the last node at position "<<sizeOfLinkedList()<<endl;
        // Find the second last node 
        node* secondLast = headptr;
        while (secondLast->getNextptr()->getNextptr() != NULL)
        {
            secondLast = secondLast->getNextptr();
        }
            
        // Delete last node 
        delete secondLast->getNextptr();
        secondLast->setnextptr(NULL);
    }
    void update(string old, string value)
    {
        node* current;
        int pos = 0;

        if (headptr == NULL) {
            cout<<("\nLinked List not initialized\n");
            return;
        }

        current = headptr;
        while (current->getNextptr() != NULL) {
            if (current->getstringData() == old) {
                current->setstringData(value);
                cout << "\n found at position, " << pos << " replaced with :" << value;
                return;
            }

            current = current->getNextptr();
            pos++;
        }

        cout<<("Data does not exist in the list\n", old);
    }
    friend ostream& operator<<(ostream& output,const linkedlist& L)
    {
      
        node* ptr = L.headptr;
        try
        {
            while (ptr->getNextptr() != NULL)
            {
                output << ptr->getstringData() << endl;
                ptr = ptr->getNextptr();
            }

            output << ptr->getstringData();
            if (ptr->getNextptr() == NULL)
            {
                throw(ptr->getNextptr());
            }
        }
        catch(node *ptr){
            output << "\nAccess denied at pointer:";
            output << ptr<<endl;
        }
      
        return output;
    }
   
    ~linkedlist() {
        cout << "\nIn the constructor deleting all the nodes and singly linked list\n";
        delete addnodeatspecificpoition;
        node* temp = headptr, * next;
        while (temp != NULL)
        {
            next = temp->getNextptr();
            delete temp;
            temp = next;
        }

        delete headptr;
        headptr = NULL;
    }
};



int main()
{

    linkedlist L1;

    //Insertion at tail
    L1.insertionAtTail(new node("bilal"));
    L1.insertionAtTail(new node("ammar"));
    L1.insertionAtTail(new node("Haris"));
    L1.insertionAtTail(new node("Taha"));
    L1.insertionAtTail(new node("Pakistan"));
    L1.insertionAtTail(new node("Hamza"));
    L1.insertionAtTail(new node("Pakistan"));
    L1.insertionAtTail(new node("Usama"));
    cout << L1;
    

    ///////////////////////////////////////////////////////////
    bool check = true;
    while (check == true)
    {

        char options;


        cout << "\n\nEnter what you want to do \n\n1) Press '1' For Displaying linked list data,\n2) Press '2' For insertionAttail in linked list"
            << "\n3) Press '3' For insertionAthead in singly linked list\n4) Press '4' For insertion At any given position \n5) Press '5' for getting the size of linked list\n"
            << "\n6) Press '6' For deletionAtHead(NODE) in singly linked list\n7) Press '7' For deletionAtTail(NODE) [deletion of the last node] \n8) Press '8' For deletionAtAnyPoint(NODE)"
            << "\n9) Press '9' For searchNode(key) [returns the index/position of the node with key value] \n"
            <<"10) Press 'v' For numberOfNodesWithKey(key) [returns the total number of nodes with similar key value] \n"

            <<"\n11) Press 'u' for updating the specific element with previous one.\n 12) Press 'e' To EXIT THE PROGRAM\n";


        cin >> options;


        switch (options)
        {
        case '1':
        {
            cout << "\nShowing the linked list data:- \n";
            cout << L1;
            break;
        }
        case '2':
        {
            string value;
            cout << "\nEnter a value(string) for inserting at Tail\n";
            cin >> value;
            L1.insertionAtTail(new node(value));
            break;
        }
        case '3':
        {
            string value;
            cout << "\nEnter a value for inserting at Head\n";
            cin >> value;
            L1.insertionAtHead(new node(value));
            break;
        }
        case '4':
        {
            int pos;
            string value;
            cout << "\nEnter the index(int) at which you want to insert value\n";
            cin >> pos;
            cout << "\nEnter the value(string) for inserting at index" << pos<<endl;
            cin >> value;
            L1.insertionAtAnyPoint(new node(value), pos);
            break;
        }
        case '5':
        {
            cout << "\nThe size of linked list is equal to\n";
            L1.sizeOfLinkedList();
            break;
        }
        case '6':
        {
            L1.deleteNodeAtHead();
            break;
        }
        case '7':
        {
            L1.deletionAtTail();
            break;
        }
        case '8':
        {
            cout << "\nEnter the index(int) at which you want to delete node:-\n";
            int i;
            cin >> i;
            L1.deleteNodeAtAnyPoint(i);
            break;
        }
        case '9':
        {
            cout << "\nEnter the value to return the index of provided node:-\n";
            string value;
            cin >> value;
            cout<<"\n(i+1 approach)The given value "<<value<<" is found at position:- "<<L1.searchNode(value);
        }
        case 'v':
        {
            cout << "\nEnter the value to check how many times it is present in the linked list";
            string value;
            cin >> value;
            L1.numberOfNodesWithKey(value);
        }
        case 'u':
        {
            string pre,nex;
            cout << "\nEnter the previous value for which you have to replace with new one: ";
            cin >> pre;
            cout << "\nEnter the next value to update in place of " << pre << endl;
            cin >> nex;
            L1.update(pre, nex);
        }
        case 'e':
        {
            cout << "The program is ending now: ";
            break;
        }
        default:
        {
            cout << "\n\nEnter right value please: \n";
        }

        }
    

        char option;

        cout << "Enter y for opening menu again and n for exiting\t";
        cin >> option;
        while (option != 'y' && option != 'n')
        {
            cout << "Enter right value Please! only y or n: ";
            char option1;
            cin >> option1;
            if (option1 == 'y' || option1 == 'n')
            {
                break;
            }
        }
        if (option == 'y')
        {
            check = true;
        }
        else if (option == 'n')
        {
            check = false;
            cout << "The program is ending now! ";
        }
    }
}

