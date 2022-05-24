#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
  int * arr;
  int * tree;
  int n;
  public:
    SegmentTree(int * ar, int m) {
      this -> n = m;
      arr = new int[n];
      arr = ar;
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

  int query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) return INT_MIN;
    if (start == end) {
      return tree[node];
    } else if (l <= start && r >= end) {
      return tree[node];
    }
    int mid = start + (end - start) / 2;
    int left = query(node * 2, start, mid, l, r);
    int right = query(node * 2 + 1, mid + 1, end, l, r);
    return max(left, right);
  }

  int query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }

};

int main(int argc, char
  const * argv[]) {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];

  int q;
  cin >> q;
  SegmentTree st(arr, n);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int ans = st.queryy(l, r);
    cout << ans << end_l;
  }
  return 0;
}