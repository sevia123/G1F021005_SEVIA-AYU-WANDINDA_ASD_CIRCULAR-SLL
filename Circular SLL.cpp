#include <iostream>
using namespace std;

// Deklarasi struktur untuk Circular Single Linked List
struct SmartPhone{
  string merkbarang, tipebarang;
  int hargabarang;

  SmartPhone *next;
};

SmartPhone *head, *tail, *newNode, *cur, *del;

// create Circular Single Linked List
void createCircularSingleLinkedList(string  merkbarang, string tipebarang, int hargabarang ){

  head = new SmartPhone();
  head->merkbarang = merkbarang;
  head->tipebarang = tipebarang;
  head->hargabarang = hargabarang;
  tail =head;
  tail->next = head;

}

// add first
void addFirst (string  merkbarang, string tipebarang, int hargabarang ){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new SmartPhone();
    newNode->merkbarang = merkbarang;
    newNode->tipebarang = tipebarang;
    newNode->hargabarang = hargabarang;
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
  }
}

// add Last
void addLast (string  merkbarang, string tipebarang, int hargabarang ){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    newNode = new SmartPhone();
    newNode->merkbarang = merkbarang;
    newNode->tipebarang = tipebarang;
    newNode->hargabarang = hargabarang;
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }
}



// remove First
void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    delete del;
  }
}

// remove last
void removeLast()
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    del = tail;
    cur = head;
    while( cur->next != tail ){
      cur = cur->next;
    }
    tail = cur;
    tail->next = head;
    delete del;
  }
}



void printCircular()
{
  if( head == NULL ){
    cout << "Buat Linked List dulu!!" << endl;
  }else{
    cout << " SmartPhone " << endl;
    cout << "|__________________________________________________________|" << endl; 
    cout << "| MerkBarang\t| TipeBarang\t\t| HargaBarang\t\t|" << endl;
    cout << "|__________________________________________________________|" << endl; 
    cur = head;
    while (cur->next != head)
    {
      // print
      cout << "| " << cur->merkbarang << "\t| " << cur->tipebarang << "\t\t| " << cur->hargabarang << "\t\t\t|" << endl;
      cur = cur->next;
    }
    cout << "| " << cur->merkbarang << "\t| " << cur->tipebarang << "\t\t| " << cur->hargabarang << "\t\t\t|" << endl;
    cout << "|__________________________________________________________|" << endl;
  }
}


int main(){
  createCircularSingleLinkedList("Android","VIVO Y91", 2000000);
  
  printCircular();

  addFirst ("Android","OPPO A3S", 3000000);
  printCircular();

  addLast("Iphone","     XS    ", 7000000);
  printCircular();

  removeFirst();

  printCircular();

  removeLast();

  printCircular();
}
