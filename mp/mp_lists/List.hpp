/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() {
  // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;
    length_ = 0;
}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(tail_->next);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  ListNode* cur = head_;
  while (cur != NULL) {
    ListNode* next = cur->next;
    delete cur;
    cur = next;
  }
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  newNode -> prev = NULL;
  if (head_ != NULL) {
    head_ -> prev = newNode;
    newNode ->next = head_;
  }
  if (tail_ == NULL) {
    tail_ = newNode;
    tail_->next = NULL;
  }
  head_ = newNode;
  length_++;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  newNode ->next = NULL;
  if (tail_ != NULL) {
    tail_->next = newNode;
    newNode->prev = tail_;
  }
  if (head_ == NULL) {
    head_ = newNode;
    head_ ->prev = NULL;
  }
  tail_ = newNode;
  length_++;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  if (splitPoint == 0) {
    return start;
  }
  ListNode * prev = start->prev;
  ListNode * curr = start;
  for (int i = 0; i < splitPoint && curr != NULL; i++) {
    prev = curr;
    curr = curr->next;
  }

  if (curr != NULL) {
    curr ->prev = NULL;
    prev ->next = NULL;
    return curr;
  }

  return curr;
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
  if (head_ == NULL || head_->next == NULL) {
    return;
  }
  ListNode * remove = head_->next;
  int i = 1;
  while (remove != NULL && &(remove->data) != &(tail_->data)) {
    if (i%2 == 0) {
      remove = remove->next;
      i++;
      continue;
    } else {
      ListNode* tmp = remove->next;
      ListNode* prev = remove->prev;
      prev->next = tmp;
      tmp->prev = prev;
      tail_->next = remove;
      remove->prev = tail_;
      remove->next = NULL;
      tail_ = remove;
      remove = tmp;
      i++;
    }
  }
  return;
}

/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */


template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
  if (startPoint == NULL || endPoint == NULL) {
    return;
  }
  if (startPoint == endPoint) {
    return;
  }
  ListNode * tmp;
  ListNode * start = startPoint->prev;
  ListNode * end = endPoint->next;
  ListNode * current = startPoint;
  while (current != end) {
    tmp = current->prev;
    current->prev = current->next;
    current->next = tmp;
    current = current->prev;
  }
  tmp = startPoint;
  startPoint = endPoint;
  endPoint = tmp;
  endPoint->next = end;
  startPoint->prev = start;
  if (start != NULL) {
    start->next = startPoint;
  } else {
    head_ = startPoint;
  }
  if (end != NULL) {
    end->prev = endPoint;
  } else {
    tail_ = endPoint;
  }
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */


template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
  if (n == 1) {
    return;
  }
  if (n >= length_) {
    reverse(head_, tail_);
  } else {
    ListNode* current = head_;
    ListNode* prev = head_;
    for (int i = 1; i <= length_; i++) {
      if (i % n == 0) {
        reverse(prev, current);
        prev = current->next;
      } else if (i == length_) {
        reverse(prev, tail_);
        break;
      }
      current = current->next;
    }
  }
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  /// @todo Graded in MP3.2
  if (first == NULL && second == NULL)
  {
    return NULL;
  }
  if (first == NULL)
  {
    return second;
  }

  if (second == NULL)
  {
    return first;
  }
  ListNode * result = first;
  ListNode * f1 = first;
  ListNode * s1 = second;
  if (first->data < second->data) {
    f1 = f1->next;
  } else {
    result = second;
    s1 = s1->next;
  }
  ListNode * r1 = result;
  while (f1 != NULL && s1 != NULL) {
    if (f1->data < s1->data) {
      r1->next = f1;
      f1->prev = r1;
      r1 = f1;
      f1 = f1->next;
    } else {
      r1->next = s1;
      s1->prev = r1;
      r1 = s1;
      s1 = s1->next;
    }
  }
  if (f1 == NULL) {
    r1->next = s1;
    s1->prev = r1;
  } else {
    r1->next = f1;
    f1->prev = r1;
  }
  return result;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  if (chainLength == 0 || start == NULL) {
    return NULL;
  }
  if (chainLength == 1) {
    start->next = NULL;
    start->prev = NULL;
    return start;
  }
  ListNode * prev = NULL;
  ListNode * curr = start;
  int x = chainLength/2;
  while (x > 0) {
    prev = curr;
    curr = curr->next;
    x--;
  }
  prev->next = NULL;
  curr->prev = NULL;
  ListNode * second = mergesort(curr, chainLength - chainLength/2);
  ListNode * first = mergesort(start, chainLength/2);
  return merge(first, second);
}
