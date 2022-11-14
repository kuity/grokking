using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskScheduler {
 public:
  struct valueCompare {
    char operator()(const pair<char, int> &x, const pair<char, int> &y) {
      return x.second < y.second;
    }
  };

  static int scheduleTasks(vector<char> &tasks, int k) {
    int intervalCount = 0;

    unordered_map<char, int> m;
    // max heap
    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> q;
    for (auto c: tasks) {
      m[c]++;
    }

    for (auto it=m.begin(); it!=m.end(); it++) {
      q.push(make_pair(it->first, it->second));
    }

    queue<pair<char, int>> buf; // buffer containing tasks; put some dummy tasks inside
    int buf_task_count = 0; // keep track of the number of real tasks in buffer
    auto dummy_task = make_pair('x', 0);
    for (auto i=0; i<k; i++) {
        buf.push(dummy_task);
    }

    string task_exec = "";
    // if no task no q and no task in buffer, done
    while(q.size() > 0 || buf_task_count > 0) {
      // if there's a task, perform it and add task to buffer. if not, add a dummy task to buffer
      if (q.size() > 0) {
        auto s1 = q.top();
        q.pop();
        if (s1.second > 1) {
            s1.second--;
            buf.push(s1);
            buf_task_count++;
        } else {
            buf.push(dummy_task);
        }
        task_exec.push_back(s1.first);
      } else {
        buf.push(dummy_task);
        task_exec.push_back('x');
      }

      // every cycle, can pop 1 task off the buffer and add back to q if it's not a dummy task
      auto t = buf.front();
      buf.pop();
      if (t.second > 0) {
          q.push(t);
          buf_task_count--;
      }

      intervalCount++;
    }

    cout << task_exec << endl;
    return intervalCount;
  }
};

int main(int argc, char *argv[]) {
  vector<char> tasks = {'a', 'a', 'a', 'b', 'c', 'c'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 2) << endl;

  tasks = vector<char>{'a', 'b', 'a'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 3) << endl;
}
