#include <iostream>
using namespace std;

// membuat struktur untuk objek double linked list
struct Node 
{
    //deskripsi noMhs dan name untuk menampung data 
    int noMhs;
    string name;
    // deskripsi pointer next dan prev untuk menunjuk ke node berikutnya dan sebelumnya
    Node *next;
    Node *prev;
};

//deklarasi pointer start dan pemberian nilai 
Node *start = NULL;
void addNode()
{
    //pembuatan node dan pemberian value untuk data noMhs dan name
	Node* newNode = new Node(); // step 1: create a new node
	cout << "\nEnter the roll number of the student: ";
	cin >> newNode->noMhs; // assign value to the data field of the new node
	cout << "\nEnter the name of the student: ";
	cin >> newNode->name; // assign value to the data field of the new node

	
    //insert the new node in the list
    //kondisi jika start == NULL atau noMhs dari node baru <= noMhs start
	if (START == NULL || newNode->noMhs <= START->noMhs)
	{// step 2: insert the new node at the beginning
     // kondisi jika star == NULL atau noMhs dari node baru <= noMhs start
		if (START != NULL && newNode->noMhs == START->noMhs)
		{
			cout << "\033[31mDuplicate roll number not allowed\033[0m" << endl;
			return;
		}
		// if the list is emty, make the new node the START
        // jika list kosong, maka node next nya adalah start
		newNode->next = START; // step 3: make the new node point to the first node
        //kondisi jika start tidak memiliki nilai atau tidak kosong
		if (START != NULL)
		{
			START->prev = newNode; // step 4: make the first node to the new node
		}

        // memberi nilai prev = null dan start = node baru
		newNode->prev = NULL; // step 5: make the new node point to NULL
		START = newNode; // step 6: make the new node the first node
	}

    // kondisi jika semua kondisi if tidak terpenuhi
	else
	{
		// insert the new node in the middle or at the end
		Node* current = START; // step 1.a: start from the first node
		Node* previous = NULL; // step 1.b: previous node is NULL initially

		while (current != NULL && current->noMhs < newNode->noMhs)
		{                             // step 1.c: traverse the list to find the correct position
			previous = current;       // step 1.d: move the previous to the current node
			current = current->next;  // step 1.e: move the current to the next node
		}

		newNode->next = current;   // step 4: make the next field of the new node point to current
		newNode->prev = previous;  // step 5: mkae the previous field of the node point the previous

		if (current != NULL)
		{
			current->prev = newNode; // step 6; Make the previous field of the current node point to the new node
		}
		if (previous != NULL)
		{
			previous->next = newNode; // step 7: Make the next field of the previous node point to the new node
		}
		else
		{
			// if previous is still NULL, it means newNode is now the first node
			START = newNode;
		}
	}
}

//pembuatan function search untuk mencari data
bool search(int rollNo, Node** previous, Node** current)
{
	*previous = NULL;
	*current = START;
	while (*current != NULL && (*current)->noMhs != rollNo)
	{
		*previous = NULL;
		*current = START;
	}
	return (*current != NULL);
}

// pembuatan procedur deleteNode untuk menghapus node
void deleteNode()
{
	Node* previous, * current;
	int rollNo;

	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	cin >> rollNo;

	if (START == NULL)
	{
		cout << "List is emty" << endl;
		return;
	}

	current = START;
	previous = NULL;

	while (current != NULL && current->noMhs != rollNo)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
	{
		cout << "\033[31mThe record with roll number " << rollNo << " not found\033[0m" << endl;
		return;
	}

	if (current == START)
	{
		START = START->next;
		if (START != NULL)
		{
			START->prev = NULL;
		}
	}

	else
	{
		previous->next = current->next;
		if (current->next != NULL)
		{
			current->next->prev = previous;
		}
	}

	delete current;
	cout << "\x1b[32mRecord with roll number " << rollNo << " deleted\x1b[0m" << endl;

}

//Mengecek apakah linked list kosong
bool listEmty()
    {
        return (START == NULL);
    }

	//untuk menampilkan data dari awal sampai akhir
    void traverse()
    {
        if (listEmty())
            cout << "\nList is emty" << endl;
        else
        {
            cout << "\nRecord in accending order of roll number are:" << endl;
            Node* currentNode = START;
            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << " " << currentNode->name << endl;
                currentNode = currentNode->next;
            }
        }
    }
