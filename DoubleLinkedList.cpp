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