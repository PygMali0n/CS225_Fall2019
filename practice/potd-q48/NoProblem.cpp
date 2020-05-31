
vector<string> NoProblem(int start, vector<int> created, vector<int> needed) {

    // your code here
    int save = start;
    vector<string> str;
    for (unsigned i = 0; i<created.size(); i++) {
      if (save>=needed[i]) {
        str.push_back("No problem! :D");
        save-=needed[i];
      } else {
        str.push_back("No problem. :(");
      }
      save+=created[i];
    }
    return str;
}
