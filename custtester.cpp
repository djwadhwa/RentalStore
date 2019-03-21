#include "Customer.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
Customer c1(1, "Tarcisius", "Daniel"), c2(2, "DJ", "Wadhwa"), c3(1, "Tarcisius", "Daniel");
c1.addHistory ('B', 'D', "Pirates of Caribbean" );
c1.addHistory ('B', 'D', "Kungfu Panda");
c1.addHistory ('R', 'D', "Pirates of Caribbean");
c1.printHistory();

}
