#include<bits/stdc++.h>


using namespace std;

class SegmentTree {
  int * arr;
  int * tree;
  int n;
  public:
    SegmentTree(int * ar, int m) {
      n = m;
      arr = new int[n];
      arr = ar;
      tree = new int[4 * n + 1];
      build(1, 0, n - 1);
    }
  void build(int node, int start, int end) {
    if (start == end) {
      tree[node] = arr[start];
      return;
    }
    int mid = start + (end - start) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
  void update(int pos, int val) {
    update(1, 0, n - 1, pos, val);
  }
  void update(int node, int start, int end, int pos, int val) {
    if (start == end) {
      tree[node] = val;
      arr[start] = val;
      return;
    }
    int mid = start + (end - start) / 2;
    if (start <= pos && pos <= mid) {
      update(2 * node, start, mid, pos, val);
    } else {
      update(2 * node + 1, mid + 1, end, pos, val);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }

  int query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
  int query(int node, int start, int end, int left, int right) {
    if (right < start || left > end) return 0;
    if (start == end) {
      return tree[node];
    }
    if (start >= left && end <= right) {
      return tree[node];
    }
    int mid = start + (end - start) / 2;
    int leftSum = query(2 * node, start, mid, left, right);
    int rightSum = query(2 * node + 1, mid + 1, end, left, right);
    return leftSum + rightSum;
  }

};

int main() {

  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
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

}