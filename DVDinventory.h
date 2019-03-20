#ifndef DVDINVENTORY_H
#define DVDINVENTORY_H

class DVDinventory: public Inventory {

public:
  void fillInventory( fstream );
  bool borrowItem(char genre, string attr1, string attr2);
  bool returnItem(char genre, string attr1, string attr2);

private:
  BST<F> comedyDVDList;
  BST<D> dramaDVDList;
  BST<C> classicDVDList;

};
#endif
