/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
     if (first[curDim] < second[curDim]) {
       return true;
     } else if (first[curDim] > second[curDim]) {
       return false;
     } else {
       return first < second;
     }

}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
     double current_square = 0.0;
     double potential_square = 0.0;
     for (int i = 0; i < Dim; i++) {
       current_square += (currentBest[i]-target[i])*(currentBest[i]-target[i]);
       potential_square += (potential[i]-target[i])*(potential[i]-target[i]);
     }
     if (potential_square < current_square) {
       return true;
     } else if (potential_square > current_square) {
       return false;
     } else {
       return potential < currentBest;
     }

}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
     if (newPoints.empty()) {
       root = NULL;
       size = 0;
     } else {
       size = 0;
       vector<Point<Dim>> points = newPoints;
       construct(points, 0, newPoints.size() - 1, 0, root);
     }
}

template <int Dim>
void KDTree<Dim>::construct(vector<Point<Dim>>& newPoints, int left, int right, int dimension, KDTreeNode*& node) {
  if (left > right) return;
  int median = (left+right) / 2;
  Point<Dim> middle = select(newPoints, left, right, median, dimension);
  node = new KDTreeNode(middle);
  size++;
  construct(newPoints, left, median-1, (dimension+1) %Dim, node->left);
  construct(newPoints, median+1, right, (dimension+1) %Dim, node->right);
}

template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>& list, int left, int right, int pivotIndex, int dim) {
  Point<Dim> pivotValue = list[pivotIndex];
  swap(list[pivotIndex], list[right]);
  int storeIndex = left;
  for (int i = left; i < right; i++) {
    if(smallerDimVal(list[i], pivotValue, dim)) {
      swap(list[i], list[storeIndex]);
      storeIndex++;
    }
  }
  swap(list[right], list[storeIndex]);
  return storeIndex;

}

template <int Dim>
Point<Dim> KDTree<Dim>::select(vector<Point<Dim>>& list, int left, int right, int k, int dim) {
  if (left == right) {
    return list[left];
  }
  int pivotIndex = (left + right) / 2;
  pivotIndex = partition(list, left, right, pivotIndex, dim);
  if (k == pivotIndex) {
    return list[k];
  } else if (k < pivotIndex) {
    return select(list, left, pivotIndex-1, k, dim);
  } else {
    return select(list, pivotIndex+1, right, k, dim);
  }
}



template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
   size = other.size;
   copy_(root, other.root);
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
  delete_(root);
  size = rhs.size;
  copy_(root, rhs.root);

  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
   delete_(root);
}

template <int Dim>
void KDTree<Dim>::delete_(KDTreeNode*& node) {
  if (node==NULL) return;
  delete_(node->left);
  delete_(node->right);
  delete node;
}

template <int Dim>
void KDTree<Dim>::copy_(KDTreeNode*& curr, KDTreeNode*& other) {
  if (other == NULL) return;
  curr = new KDTreeNode(other->point);
  copy_(curr->left, other->left);
  copy_(curr->right, other->right);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    Point<Dim> currentBest = root->point;
    Point<Dim> q = query;
    find(q, currentBest, root, 0);
    return currentBest;
}

template <int Dim>
void KDTree<Dim>::find(Point<Dim>& query, Point<Dim>& currentBest, KDTreeNode* node, int dimension) const{
  if (node == NULL) return;
  KDTreeNode* near;
  KDTreeNode* far;
  if (smallerDimVal(query, node->point, dimension)) {
    near = node->left;
    far = node->right;
  } else {
    near = node->right;
    far = node->left;
  }
  find(query, currentBest, near, (dimension+1) %Dim);

  if (shouldReplace(query, currentBest, node->point)) {
    currentBest = node->point;
  }
  double radius = 0.0;
  double distance_to_q = (node->point[dimension] - query[dimension]) * (node->point[dimension] - query[dimension]);
  for (int i = 0; i < Dim; i++) {
    radius += (currentBest[i] - query[i]) * (currentBest[i] - query[i]);
  }
  if (distance_to_q<=radius) {
    find(query, currentBest, far, (dimension+1)%Dim);
  }
}
