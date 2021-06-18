// Note that by default C++ creates a max-heap
// for priority queue
#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue<int> gq) {
  priority_queue<int> g = gq;
  while (!g.empty()) {
    cout << '\t' << g.top();
    g.pop();
  }
  cout << '\n';
}

void showpq(priority_queue<int, vector<int>, greater<int>> gq) {
  priority_queue<int, vector<int>, greater<int>> g = gq;
  while (!g.empty()) {
    cout << '\t' << g.top();
    g.pop();
  }
  cout << '\n';
}
int main() {

  std::cout << "MAX HEAP" << std::endl;
  priority_queue<int> gquiz;
  gquiz.push(10);
  gquiz.push(30);
  gquiz.push(20);
  gquiz.push(5);
  gquiz.push(1);

  cout << "The priority queue gquiz is : ";
  showpq(gquiz);

  cout << "\ngquiz.size() : " << gquiz.size();
  cout << "\ngquiz.top() : " << gquiz.top();

  cout << "\ngquiz.pop() : ";
  gquiz.pop();
  showpq(gquiz);
  std::cout << "==============================================================="
               "========"
            << std::endl;

            // Syntax to create a min heap for priority queue 
// priority_queue <int, vector<int>, greater<int>> g = gq;  
  std::cout << "Min Heap" << std::endl;
  priority_queue<int, vector<int>, greater<int>> minHEap;
  minHEap.push(10);
  minHEap.push(30);
  minHEap.push(20);
  minHEap.push(5);
  minHEap.push(1);

  cout << "The priority queue minHEap is : ";
  showpq(minHEap);

  cout << "\nminHEap.size() : " << minHEap.size();
  cout << "\nminHEap.top() : " << minHEap.top();

  cout << "\nminHEap.pop() : ";
  minHEap.pop();
  showpq(minHEap);
  return 0;
}
