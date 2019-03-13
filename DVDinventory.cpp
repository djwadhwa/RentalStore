#include "DVDinventory.h"

//read in var, create correct object based on genre, fill using setters
void DVDinventory::fillInventory( ftsream infile ) {
  //Loop
  /*          PART 1: read in variables           */

  //use getline with , as delimieter
  //read in genre, stock, director, title

  /*          if F or D                           */
  //e.g. F, 10, Nora Ephron, You've Got Mail, 1998

  //read in year released
  //  if F
      //create Comedy object
      //use setters
  //  if D
      //create Drama object
      //use setters

  /*          if C                                */
  //C, 10, George Cukor, Holiday, Katherine Hepburn 9 1938
  //sometimes classics have same movie but dif major actor how to handle? add stock or seperate movie object?

  //read in major actor month and year realeas


}

bool DVDinventory::borrowItem( char genre, string attr1, string attr2 ) {}

bool DVDinventory::returnItem( char genre, string attr1, string attr2 ) {}
