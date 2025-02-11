/**
 * @file common_words.cpp
 * Implementation of the CommonWords class.
 *
 * @author Zach Widder
 * @date Fall 2014
 */

#include "common_words.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

string remove_punct(const string& str)
{
    string ret;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(ret),
                        std::ptr_fun<int, int>(&std::ispunct));
    return ret;
}

CommonWords::CommonWords(const vector<string>& filenames)
{
    // initialize all member variables
    init_file_word_maps(filenames);
    init_common();
}

void CommonWords::init_file_word_maps(const vector<string>& filenames)
{
    // make the length of file_word_maps the same as the length of filenames
    file_word_maps.resize(filenames.size());

    // go through all files
    for (size_t i = 0; i < filenames.size(); i++) {
        // get the corresponding vector of words that represents the current
        // file
        vector<string> words = file_to_vector(filenames[i]);
        /* Your code goes here! */
        map<string, unsigned int> word_map;
        for (unsigned i = 0; i < words.size(); i++) {
          map<string, unsigned int>::iterator it = word_map.find(words[i]);
          if (it == word_map.end()) {
            word_map[words[i]] = 1;
          } else {
            word_map[words[i]]++;
          }
        }
        file_word_maps[i] = word_map;
    }
}

void CommonWords::init_common()
{
    /* Your code goes here! */
    for (unsigned i = 0; i < file_word_maps.size(); i++) {
      for (auto k = file_word_maps[i].begin(); k != file_word_maps[i].end(); ++k) {
        map<string, unsigned int>::iterator it = common.find(k->first);
        if (it == common.end()) {
          common[k->first] = 0;
        }
      }
    }
    for (auto kv = common.begin(); kv != common.end(); ++kv) {
      for (unsigned i = 0; i < file_word_maps.size(); i++) {
        map<string, unsigned int>::iterator it = file_word_maps[i].find(kv->first);
        if (it != file_word_maps[i].end()) {
          common[kv->first]++;
        }
      }
    }
}

/**
 * @param n The number of times to word has to apmap<unsigned long, unsigned long>::iterator lookup = memo.find(n);
pear.
 * @return A vector of strings. The vector contains all words that appear
 * in each file >= n times.
 */
vector<string> CommonWords::get_common_words(unsigned int n) const
{
    vector<string> out;
    /* Your code goes here! */
    for (auto it = common.begin(); it != common.end(); ++it) {
      if (it->second < file_word_maps.size()) {
        continue;
      }
      for (unsigned i = 0; i < file_word_maps.size(); i++) {
        auto word = file_word_maps[i].find(it->first);
        if (word->second < n) {
          break;
        }
        if (word->second >= n && i == file_word_maps.size() - 1) {
          out.push_back(it->first);
        }
      }
    }
    return out;
}

/**
 * Takes a filename and transforms it to a vector of all words in that file.
 * @param filename The name of the file that will fill the vector
 */
vector<string> CommonWords::file_to_vector(const string& filename) const
{
    ifstream words(filename);
    vector<string> out;

    if (words.is_open()) {
        std::istream_iterator<string> word_iter(words);
        while (!words.eof()) {
            out.push_back(remove_punct(*word_iter));
            ++word_iter;
        }
    }
    return out;
}
