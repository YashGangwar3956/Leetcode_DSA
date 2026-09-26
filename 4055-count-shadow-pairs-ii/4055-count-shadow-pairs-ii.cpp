/**
 * Time Complexity: O(n * log(n) * log(n))
 * Space Complexity: O(n)
 * where `n` is the length of the vector `nums`
 */
class Solution {
 public:
  int shadowPairs(const vector<int> &nums) {
    using task_t = tuple<vector<int>, int, int>;
    const int n = static_cast<int>(nums.size());
    vector<int> values(nums);
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    const int m = static_cast<int>(values.size());
    vector<task_t> tasks;
    tasks.emplace_back(vector<int>(n), 0, m - 1);
    for (int i = 0; i < n; ++i) {
      get<0>(tasks.front())[i] = static_cast<int>(lower_bound(values.begin(), values.end(), nums[i]) - values.begin());
    }

    int ret = 0;
    while (!tasks.empty()) {
      task_t task = move(tasks.back());
      tasks.pop_back();
      if (get<1>(task) == get<2>(task)) {
        continue;
      }
      const int mid = get<1>(task) + ((get<2>(task) - get<1>(task)) >> 1);
      vector<int> left;
      vector<int> right;
      vector<int> st;
      vector<int> caps;
      vector<int> starts;
      for (const int x : get<0>(task)) {
        if (x < mid + 1) {
          left.emplace_back(x);

          while (!st.empty() && st.back() < x) {
            st.pop_back();
          }

          const int size = static_cast<int>(st.size());

          while (!starts.empty() && starts.back() > size - 1) {
            starts.pop_back();
            caps.pop_back();
          }

          st.emplace_back(x);

          if (caps.empty() || caps.back() != m) {
            caps.emplace_back(m);
            starts.emplace_back(size);
          }
        } else {
          right.emplace_back(x);
          const int p = static_cast<int>(lower_bound(caps.begin(), caps.end(), x) - caps.begin());
          if (p == static_cast<int>(caps.size())) {
            continue;
          }

          const int start = starts[p];
          ret += static_cast<int>(st.size()) - start;

          caps.resize(p);
          starts.resize(p);
          caps.emplace_back(x);
          starts.emplace_back(start);
        }
      }

      if (!left.empty()) {
        tasks.emplace_back(move(left), get<1>(task), mid);
      }
      if (!right.empty()) {
        tasks.emplace_back(move(right), mid + 1, get<2>(task));
      }
    }
    return ret;
  }
};