// link list created using constructor
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destructor are used to delete memoery
    ~node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "delete the value is " << val << endl;
    }
};
void insertattail(node *&tail, int d)
{

    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
    tail = temp;
}
void insertathead(node *&head, int d) // stating
{                                     // {creted new node
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void print(node *&head) // print
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void deletenode(int position, node *&head) // delete
{
    if (position == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int b;
        cout << "Enter the element:";
        cin >> b;
        insertattail(tail, b);
        print(head);
    }
    for (int i = 1; i < 2; i++)
    {
        int k;
        cout << "plz enter the position we want to delete ";
        cin >> k;
        deletenode(k, head);
        print(head);
    }
}
