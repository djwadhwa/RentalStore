#include <string>
#include <iostream>
#include "Customer.h"

int main()
{
    Customer c1(1, "Tarcisius", "Daniel"), c2(2, "DJ", "Wadhwa");
    c1.addHistory('B', 'D', "Pirates of Caribbeans");
    c1.addHistory('B', 'D', "Kungfu Panda");
    c1.addHistory('R', 'D', "Pirates of Caribbeans");
    c1.addHistory('R', 'D', "Kungfu Panda");
    c1.printHistory();
    return 0;
}