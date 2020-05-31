/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    if (t == NULL) {
      return;
    }
    Node* pivot = t->right;
    if (pivot == NULL) {
      return;
    }
    t->right = pivot->left;
    pivot->left = t;
    t->height = std::max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    pivot->height = std::max(heightOrNeg1(pivot->left), heightOrNeg1(pivot->right)) + 1;
    t = pivot;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
    if (t == NULL) {
      return;
    }
    Node* pivot = t->left;
    if (pivot == NULL) {
      return;
    }
    t->left = pivot->right;
    pivot->right = t;
    t->height = std::max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    pivot->height = std::max(heightOrNeg1(pivot->left), heightOrNeg1(pivot->right)) + 1;
    t = pivot;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if (subtree == NULL) {
      return;
    }
    if (heightOrNeg1(subtree->left) + 2 == heightOrNeg1(subtree->right)) {
      if (heightOrNeg1(subtree->right->left) < heightOrNeg1(subtree->right->right)) {
        rotateLeft(subtree);
      } else {
        rotateRightLeft(subtree);
      }
    } else if (heightOrNeg1(subtree->left) == 2 + heightOrNeg1(subtree->right)){
      if (heightOrNeg1(subtree->left->left) > heightOrNeg1(subtree->left->right)) {
        rotateRight(subtree);
      } else {
        rotateLeftRight(subtree);
      }
    }
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if (subtree == NULL) {
      Node* tmp = new Node(key, value);
      subtree = tmp;
    }
    if (key > subtree->key) {
      insert(subtree->right,key,value);
      rebalance(subtree);
      subtree->height = std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
    } else if (key < subtree->key) {
      insert(subtree->left,key,value);
      rebalance(subtree);
      subtree->height = std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right)) + 1;
    } else {
      subtree->value = value;
    }
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree->left,key);
        subtree->height = 1 + std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
        rebalance(subtree);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree->right,key);
        subtree->height = 1 + std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
        rebalance(subtree);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
            delete subtree;
            subtree = NULL;
            return;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
            Node* curr = subtree->left;
            while (curr->right != NULL) {
              curr = curr->right;
            }
            subtree->key = curr->key;
            subtree->value = curr->value;
            remove(subtree->left, curr->key);


        } else {
            /* one-child remove */
            // your code here
            if (subtree->left != NULL) {
              Node* tmp = subtree->left;
              *subtree = *tmp;
              delete tmp;
              tmp = NULL;
            } else if (subtree->right != NULL) {
              Node* tmp = subtree->right;
              *subtree = *tmp;
              delete tmp;
              tmp = NULL;
            }
        }
        // your code here
        subtree->height = 1 + std::max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right));
        rebalance(subtree);
    }
}
