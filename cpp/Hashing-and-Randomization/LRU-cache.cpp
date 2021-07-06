#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
class LRUCache {
private:
  int capacity;
  list<int> recent;
  unordered_map<int, int> cache;
  unordered_map<int, list<int>::iterator> pos;
  
  void use(int key) {
    if (pos.find(key) != pos.end()) {
      recent.erase(pos[key]);
    } else if (recent.size() >= capacity) {
      int old = recent.back();
      recent.pop_back();
      cache.erase(old);
      pos.erase(old);
    }
    recent.push_front(key);
    pos[key] = recent.begin();
  }

public:
  LRUCache(int capacity) : capacity(capacity) {}
  int get(int key) {
    if (cache.find(key) != cache.end()) {
      use(key);
      return cache[key];
    }
    return -1;
  }
  void set(int key, int value) {
    use(key);
    cache[key] = value;
  }
};

int main(int argc, const char **argv) {
  LRUCache *obj = new LRUCache(5);

  for (int i = 0; i < 5; i++) {
    obj->set(i, i );
  }
  for (int i = 0; i < 7; i++) {
    std::cout << obj->get(i) << std::endl;
  }
  return 0;
}