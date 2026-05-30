struct node {
    node() {}
    node(int c) {v = c;}
    int l = INT_MAX;
    int r = INT_MIN;
    int v = 0;

    bool valid() { return v >= 0; }
};

struct tree {

    unordered_map<int, int> pos;
    int n;
    vector<node> arr;
    void init(int n1) {
        n = n1;
        arr = vector<node>(n * 4 + 2);
    }

    void merge(const node& ln, const node& rn, node& cur, int l, int r)
    {
        cur.l = min(ln.l, rn.l);
        cur.r = max(ln.r, rn.r);
        cur.v = max(ln.v, rn.v);
        if (cur.l > cur.r)
        {
            cur.v = r - l + 1;
        }
        else if (ln.r != INT_MIN && rn.l != INT_MAX)
        {

            cur.v = max(cur.v, rn.l - ln.r);
        } else if (ln.r == INT_MIN)
        {
            cur.v = max(cur.v, rn.l - l);
        } else {
            cur.v = max(cur.v, r - ln.r);
        }
    }
    // l, r, range of current node cur, 
    // p the target point
    node& update(int l, int r, int cur, int p) {
        if (p < l || p > r)  return arr[cur];
        if (r - l <= 1) {
            arr[cur].l = min(arr[cur].l, p);
            arr[cur].r = max(arr[cur].r, p);
            arr[cur].v = r - l;
            return arr[cur];
        }
        int m = (l + r) / 2;
        auto& ln = update(l, m,  cur * 2, p);
        auto& rn = update(m, r, cur * 2 + 1, p);

        merge(ln, rn, arr[cur], l, r);
        return arr[cur];
    }

    node search(int l, int r, int cur, int x, int y)
    {
        if (y < l || x > r)  return node(-1);
        if (x <= l && r <= y) {
            return arr[cur];
        }
        if (r - l <= 1)
        {
            return node(-1);
        }
        int m = (l + r) / 2;
        auto ln = search(l, m,  cur * 2, x, y);
        auto rn = search(m, r, cur * 2 + 1, x, y);
        
        if (ln.valid() && rn.valid()) 
        {
            node cn;
            merge(ln, rn, cn, max(l, x), min(r, y));
            return cn;
        }
        else if (ln.valid())
        {
            return ln;
        } else {
            return rn;
        }
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& qs) {
         int n = 0;
         tree t;
         for (auto& q : qs) 
         {
            n = max(n, q[1] + 1);
         }
         t.init(n);
         vector<bool> ans;
         for (auto& q : qs) 
         {
            if (q[0] == 1)
            {
                t.update(0, n - 1, 1, q[1]);
            } else {
                auto cur = t.search(0, n - 1, 1, 0, q[1]);
                if (cur.l == INT_MAX)
                {
                    cur.v = q[1];
                }
                
                if (cur.v >= q[2])
                {
                    ans.push_back(true);
                } else {
                    ans.push_back(false);
                }
            }
         }
         return ans;
    }
};