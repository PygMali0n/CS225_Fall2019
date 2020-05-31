// your code here
#include "q5.h"

void increase_quantity(Food * f) {
  int newquantity = f->get_quantity() + 1;
  f->set_quantity(newquantity);
}
