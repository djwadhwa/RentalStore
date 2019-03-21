This is the work of team c = c + 1

Team members:
- DJ Wadhwa
- Tina Fedorov
- Tarcisius Daniel

In order to compile our code, access <the driver file> and here's the line needed in the terminal to test our file:
g++ -std=c++14 Driver.cpp RentalStore.cpp Customer.cpp DVDinventory.cpp Comedy.cpp Classic.cpp Drama.cpp Movie.cpp

Here is the output that we have from compiling it through the terminal:
Incorrect code: Z
Incorrect code: Z
INVENTORY BEFORE:
Comedies: 
Annie Hall 10 1977
Fargo 10 1996
National Lampoon's Animal House 10 1978
Pirates of the Caribbean 10 2003
Sleepless in Seattle 10 1993
When Harry Met Sally 10 1989
You've Got Mail 10 1998

Dramas: 
Good Morning Vietnam 10 1988
Unforgiven 10 1992
Good Will Hunting 10 2000
Silence of the Lambs 10 1991
Dogfight 10 1991
King of Hearts 10 1967
Schindler's List 10 1993

Classics: 
Holiday 10 9 1938 Cary Grant
Holiday 10 9 1938 Katherine Hepburn
Gone With the Wind 10 2 1939 Clark Gable
Gone With the Wind 10 2 1939 Vivien Leigh
The Wizard of Oz 10 7 1939 Judy Garland
The Philadelphia Story 10 5 1940 Cary Grant
The Philadelphia Story 10 5 1940 Katherine Hepburn
The Maltese Falcon 10 10 1941 Humphrey Bogart
Casablanca 10 8 1942 Humphrey Bogart
It's a Wonderful Life 10 11 1946 Donna Reed
It's a Wonderful Life 10 11 1946 James Steward
A Clockwork Orange 10 2 1971 Malcolm McDowell
Harold and Maude 10 3 1971 Ruth Gordon
print Inventory
Comedies: 
Annie Hall 10 1977
Fargo 10 1996
National Lampoon's Animal House 10 1978
Pirates of the Caribbean 10 2003
Sleepless in Seattle 10 1993
When Harry Met Sally 10 1989
You've Got Mail 10 1998

Dramas: 
Good Morning Vietnam 10 1988
Unforgiven 10 1992
Good Will Hunting 10 2000
Silence of the Lambs 10 1991
Dogfight 10 1991
King of Hearts 10 1967
Schindler's List 10 1993

Classics: 
Holiday 10 9 1938 Cary Grant
Holiday 10 9 1938 Katherine Hepburn
Gone With the Wind 10 2 1939 Clark Gable
Gone With the Wind 10 2 1939 Vivien Leigh
The Wizard of Oz 10 7 1939 Judy Garland
The Philadelphia Story 10 5 1940 Cary Grant
The Philadelphia Story 10 5 1940 Katherine Hepburn
The Maltese Falcon 10 10 1941 Humphrey Bogart
Casablanca 10 8 1942 Humphrey Bogart
It's a Wonderful Life 10 11 1946 Donna Reed
It's a Wonderful Life 10 11 1946 James Steward
A Clockwork Orange 10 2 1971 Malcolm McDowell
Harold and Maude 10 3 1971 Ruth Gordon
print History
customer: 1000
Mouse's current transactions history:
customer has no history
print History
customer: 5000
Frog's current transactions history:
customer has no history
print History
customer: 8000
Wacky's current transactions history:
customer has no history
borrow item
customer: 8000
borrow item
customer: 1000
borrow item
5 1940
Katherine Hepburn
customer: 1000
borrow item
customer: 2000
borrow item
2 1971
Malcolm McDowell
customer: 4444
borrow item
3 1971
Ruth Gordon
customer: 5000
return item
3 1971
Ruth Gordon
customer: 5000
borrow item
customer: 8888
borrow item
2 1971
Malcolm McDowell
customer: 1111
borrow item
error: genre doesnt exist
borrow item
3 1971
Ruth Gordon
customer: 5000
return item
3 1971
Ruth Gordon
customer: 5000
borrow item
customer: 1000
borrow item
customer: 2000
return item
2 1971
Malcolm McDowell
customer: 4444
borrow item
5 1940
Cary Grant
customer: 1000
borrow item
3 1971
Ruth Gordon
customer: 1111
borrow item
3 1971
Ruth Gordon
customer: 1000
borrow item
customer: 8888
borrow item
customer: 8888
return item
customer: 8000
borrow item
customer: 9999
borrow item
3 1971
Ruth Gordon
customer: 8000
borrow item
10 1941
Humphrey Bogart
customer: 1111
borrow item
3 1971
Ruth Gordon
customer: 8000
error: invalid action
borrow item
9 1938
Cary Grant
customer: 1111
borrow item
3 1971
Ruth Gordon
customer: 5000
borrow item
customer: 8888
borrow item
customer: 7777
return item
3 1971
Ruth Gordon
customer: 5000
error: invalid action
borrow item
3 1971
Ruth Gordon
customer: 5000
borrow item
customer: 8000
borrow item
3 1971
Ruth Gordon
customer: 8888
borrow item
3 1971
Ruth Gordon
customer: 7777
borrow item
3 1971
Ruth Gordon
customer: 2000
borrow item
customer: 2000
borrow item
customer: 9000
borrow item
customer: 9000
borrow item
2 1971
Malcolm McDowell
error: customer not found
borrow item
customer: 1000
error: movie not found or out of stock
borrow item
error: item type doesnt exist
borrow item
3 1971
Ruth Gordon
customer: 2000
borrow item
3 1971
Ruth Gordon
customer: 9000
borrow item
3 1971
Ruth Gordon
customer: 9000
error: movie not found or out of stock
borrow item
3 1971
Ruth Gordon
customer: 3333
error: movie not found or out of stock
borrow item
3 1971
Ruth Gordon
customer: 7777
error: movie not found or out of stock
borrow item
customer: 1000
error: movie not found or out of stock
print Inventory
Comedies: 
Annie Hall 9 1977
Fargo 9 1996
National Lampoon's Animal House 9 1978
Pirates of the Caribbean 10 2003
Sleepless in Seattle 9 1993
When Harry Met Sally 9 1989
You've Got Mail 9 1998

Dramas: 
Good Morning Vietnam 9 1988
Unforgiven 9 1992
Good Will Hunting 9 2000
Silence of the Lambs 9 1991
Dogfight 8 1991
King of Hearts 9 1967
Schindler's List 9 1993

Classics: 
Holiday 9 9 1938 Cary Grant
Holiday 10 9 1938 Katherine Hepburn
Gone With the Wind 10 2 1939 Clark Gable
Gone With the Wind 10 2 1939 Vivien Leigh
The Wizard of Oz 10 7 1939 Judy Garland
The Philadelphia Story 9 5 1940 Cary Grant
The Philadelphia Story 9 5 1940 Katherine Hepburn
The Maltese Falcon 9 10 1941 Humphrey Bogart
Casablanca 10 8 1942 Humphrey Bogart
It's a Wonderful Life 10 11 1946 Donna Reed
It's a Wonderful Life 10 11 1946 James Steward
A Clockwork Orange 9 2 1971 Malcolm McDowell
Harold and Maude 0 3 1971 Ruth Gordon
print History
customer: 1000
Mouse's current transactions history:
B D D Barry Levinson Good Morning Vietnam
B D C 5 1940 Katherine Hepburn
B D D Gus Van Sant Good Will Hunting
B D C 5 1940 Cary Grant
B D C 3 1971 Ruth Gordon
print History
customer: 1111
Mouse's current transactions history:
B D C 2 1971 Malcolm McDowell
B D C 3 1971 Ruth Gordon
B D C 10 1941 Humphrey Bogart
B D C 9 1938 Cary Grant
print History
customer: 5000
Frog's current transactions history:
B D C 3 1971 Ruth Gordon
R D C 3 1971 Ruth Gordon
B D C 3 1971 Ruth Gordon
R D C 3 1971 Ruth Gordon
B D C 3 1971 Ruth Gordon
R D C 3 1971 Ruth Gordon
B D C 3 1971 Ruth Gordon
print History
customer: 8000
Wacky's current transactions history:
B D F You've Got Mail 1998
R D F You've Got Mail 1998
B D C 3 1971 Ruth Gordon
B D C 3 1971 Ruth Gordon
B D F National Lampoon's Animal House 1978
print History
customer: 8888
Pig's current transactions history:
B D F Annie Hall 1977
B D F When Harry Met Sally 1989
B D D Jonathan Demme Silence of the Lambs
B D D Nancy Savoca Dogfight
B D C 3 1971 Ruth Gordon
INVENTORY AFTER:
Comedies: 
Annie Hall 9 1977
Fargo 9 1996
National Lampoon's Animal House 9 1978
Pirates of the Caribbean 10 2003
Sleepless in Seattle 9 1993
When Harry Met Sally 9 1989
You've Got Mail 9 1998

Dramas: 
Good Morning Vietnam 9 1988
Unforgiven 9 1992
Good Will Hunting 9 2000
Silence of the Lambs 9 1991
Dogfight 8 1991
King of Hearts 9 1967
Schindler's List 9 1993

Classics: 
Holiday 9 9 1938 Cary Grant
Holiday 10 9 1938 Katherine Hepburn
Gone With the Wind 10 2 1939 Clark Gable
Gone With the Wind 10 2 1939 Vivien Leigh
The Wizard of Oz 10 7 1939 Judy Garland
The Philadelphia Story 9 5 1940 Cary Grant
The Philadelphia Story 9 5 1940 Katherine Hepburn
The Maltese Falcon 9 10 1941 Humphrey Bogart
Casablanca 10 8 1942 Humphrey Bogart
It's a Wonderful Life 10 11 1946 Donna Reed
It's a Wonderful Life 10 11 1946 James Steward
A Clockwork Orange 9 2 1971 Malcolm McDowell
Harold and Maude 0 3 1971 Ruth Gordon
