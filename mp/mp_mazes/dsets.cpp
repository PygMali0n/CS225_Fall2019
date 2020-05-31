/* Your code here! */
#include "dsets.h"

void DisjointSets::addelements(int num) {
  for (int i = 0; i < num; i++) {
    sets.push_back(-1);
  }
}
int DisjointSets::find(int elem) {
  if (sets[elem] < 0) {
    return elem;
  } else {
    int root = find(sets[elem]);
    sets[elem] = root;
    return root;
  }
}
void DisjointSets::setunion(int a, int b) {
  int aroot = find(a);
  int broot = find(b);
  if (aroot == broot) return;
  if (sets[aroot] > sets[broot]) {
    sets[broot] = sets[aroot]+sets[broot];
    sets[aroot] = broot;
  } else {
    sets[aroot] = sets[aroot]+sets[broot];
    sets[broot] = aroot;
  }
}
int DisjointSets::size(int elem) {
  return -1*sets[find(elem)];
}
