#include<bits/stdc++.h>

using namespace std;

class SegmentTree {
  int * arr;
  int * tree;
  int n;
  public:
    SegmentTree(int * ar, int m) {
      this -> n = m;
      arr = new int[n];
      arr=ar;
      tree = new int[4 * n + 1];
      build(1, 0, n - 1);
    }

  void build(int node, int start, int end) {
    if (start > end) return;
    if (start == end) {
      tree[node] = arr[start];
      return;
    }
    int mid = start + (end - start) / 2;
    int left = 2 * node;
    int right = 2 * node + 1;
    build(left, start, mid);
    build(right, mid + 1, end);
    tree[node] = max(tree[left], tree[right]);

  }

  int query(int start, int end, int node, int l, int r) {

    if (r < start || l > end) {
      return INT_MIN;
    }

    if (start == end) {
      return tree[node];
    } else if (l <= start && r >= end) {
      return tree[node];
    }

    int mid = start + (end - start) / 2;
    int left = query(start, mid, 2 * node, l, r);
    int right = query(mid + 1, end, 2 * node + 1, l, r);
    return max(left, right);

  }

  int query(int l, int r) {
    return query(0, n - 1, 1, l, r);
  }

  void update(int node, int start, int end, int pos, int val) {
    if (start == end) {
      arr[start] = val;
      tree[node] = val;
      return;
    }
    int mid = start + (end - start) / 2;

    if (start <= pos && pos <= mid) {
      update(2 * node, start, mid, pos, val);
    } else {
      update(2 * node + 1, mid + 1, end, pos, val);
    }

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
  }

  void update(int pos, int value) {
    update(1, 0, n - 1, pos, value);
  }
};

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  SegmentTree st(arr, n);

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int pos, val;
      cin >> pos >> val;
      st.update(pos, val);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r) << endl;
    }
  }

  return 0;
}