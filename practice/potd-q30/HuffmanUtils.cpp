#include "HuffmanNode.h"
#include "HuffmanUtils.h"
#include <string>

using std::string;

/**
 * binaryToString
 *
 * Write a function that takes in the root to a huffman tree
 * and a binary string.
 *
 * Remember 0s in the string mean left and 1s mean right.
 */
string binaryToString(string binaryString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string toreturn = "";
    HuffmanNode* curr = huffmanTree;
    for (char& c : binaryString) {
      if (curr->left_ == NULL && curr->right_ == NULL) {
        toreturn += curr->char_;
        curr = huffmanTree;
      }
      if (c == '0') {
        curr = curr->left_;
      } else if (c == '1') {
        curr = curr->right_;
      }
    }
    toreturn += curr->char_;
    return toreturn;
}

/**
 * stringToBinary
 *
 * Write a function that takes in the root to a huffman tree
 * and a character string. Return the binary representation of the string
 * using the huffman tree.
 *
 * Remember 0s in the binary string mean left and 1s mean right
 */
void getPath(char& c, HuffmanNode* huffmanTree, string path, string & finalpath) {
  if (huffmanTree == NULL) {
    return;
  }
  if (huffmanTree->char_ == c && huffmanTree->left_ == NULL && huffmanTree->right_ == NULL) {
    for (char& c : path) {
      finalpath+= c;
    }
    return;
  } else {
    string path_l = path + "0";
    string path_r = path + "1";
    getPath(c, huffmanTree->left_, path_l, finalpath);
    getPath(c, huffmanTree->right_, path_r, finalpath);
  }
}

string stringToBinary(string charString, HuffmanNode* huffmanTree) {
    /* TODO: Your code here */
    string toreturn = "";
    for (char& c : charString) {
      string finalpath = "";
      string path = "";
      getPath(c, huffmanTree, path, finalpath);
      toreturn += finalpath;
    }
    return toreturn;
}
