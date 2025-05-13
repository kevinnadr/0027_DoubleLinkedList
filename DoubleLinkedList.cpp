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