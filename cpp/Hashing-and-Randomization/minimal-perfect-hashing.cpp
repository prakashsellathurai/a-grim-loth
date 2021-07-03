#include <iostream>
#include <string>
#include <vector>

class Minimal_perfect_hash {
private:
  int MAX;           // upper bound on number of elements in our set
  const int ver = 2; // number of hash tables
  std::vector<std::vector<int>> hashtable;
  std::vector<int> pos; // Array to store possible positions for a key

public:
  Minimal_perfect_hash(std::vector<int> keys) {
    int n = keys.size();
    MAX = n+1;
    initTable();

    for (int i = 0, cnt = 0; i < n; i++, cnt = 0) {
      insert(keys[i], 0, cnt, n);
    }
  }

  bool lookup(int num) {
    for (int i = 0; i < ver; i++) {
      pos[i] = hash(i + 1, num);
      if (hashtable[i][pos[i]] == num)
        return true;
    }
    return false;
  }
  /* function to print hash table contents */
  void printTable() {
    std::cout << "Final hash tables:" << std::endl;

    for (int i = 0; i < ver; i++) {
      std::cout << std::endl;
      for (int j = 0; j < MAX; j++) {
        if (hashtable[i][j] == INT_MIN) {
          std::cout << "- ";
        } else {
          std::cout << hashtable[i][j];
        }
        std::cout << " ";
      }
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }

protected:
  /* function to fill hash table with dummy value
   * dummy value: INT_MIN
   * number of hashtables: ver */
  void initTable() {
    hashtable.resize(ver);
    for (size_t i = 0; i < ver; i++) {
      hashtable[i].resize(MAX);
    }
    pos.resize(ver);
    for (int j = 0; j < MAX; j++)
      for (int i = 0; i < ver; i++)
        hashtable[i][j] = INT_MIN;
  }

  /* return hashed value for a key
  * function: ID of hash function according to which
          key has to hashed
  * key: item to be hashed */
  int hash(int function, int key) {
    switch (function) {
    case 1:
      return key % MAX;
    case 2:
      return (key / MAX) % MAX;
    }
    return 0;
  }

  /* function to insert a key in one of its possible positions
  * tableID: table in which key has to be insertd, also equal
  to function according to which key must be hashed
  * cnt: number of times function has already been called
  in order to insert the first input key
  * n: maximum number of times function can be recursively
  called before stopping and declaring presence of cycle */
  void insert(int key, int tableID, int cnt, int n) {
    /* if function has been recursively called max number
    of times, stop and declare cycle. Rehash. */
    if (cnt == n) {
      std::cout << key << " unpositioned" << std::endl;
      std::cout << "Cycle present. REHASH." << std::endl;
      return;
    }

    /* calculate and store possible positions for the key.
    * check if key already present at any of the positions.
    If YES, return. */
    for (int i = 0; i < ver; i++) {
      pos[i] = hash(i + 1, key);
      if (hashtable[i][pos[i]] == key)
        return;
    }

    /* check if another key is already present at the
    position for the new key in the table
    * If YES: insert the new key in its position
    * and insert the older key in an alternate position
    for it in the next table */
    if (hashtable[tableID][pos[tableID]] != INT_MIN) {
      int dis = hashtable[tableID][pos[tableID]];
      hashtable[tableID][pos[tableID]] = key;
      insert(dis, (tableID + 1) % ver, cnt + 1, n);
    } else // else: insert the new key in its position
      hashtable[tableID][pos[tableID]] = key;
  }
};

int main() {
  std::vector<int> keys_1 = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};

  Minimal_perfect_hash mph(keys_1);

  mph.printTable();

  std::cout << "lookup 100 : " << (mph.lookup(100) ? "YES" : "NO") << std::endl;
  std::cout << "lookup 300 : " << (mph.lookup(300) ? "YES" : "NO") << std::endl;

  return 0;
}
