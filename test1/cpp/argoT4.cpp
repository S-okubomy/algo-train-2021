#include <iostream>
#include <vector>
using namespace std;

bool func(int i, int w, const vector<int> &a) {

  cout << "確認m: " << i << endl;
  // ベースケース
  if (i == 0) {
    if (w == 0) {
      cout << "確認true?: " << i << endl;
      return true;
    } else {
      cout << "確認false?: " << i << endl;
      return false;
    }
  }

  cout << "確認0: " << i << endl;

  // a[i - 1] を選ばない場合
  if (func(i - 1, w, a)) return true;

  cout << "確認1: " << i << endl;

  // a[i - 1] をぶ場合
  if (func(i - 1, w - a[i - 1], a)) return true;
  cout << "確認2: " << i << endl;

  // どちらも false の場合は false
  return false;
}

int main() {
  // 入力
  int N, W;
  cin >> N >> W;
  vector<int> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  // 再帰的に解く
  if (func(N, W, a))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}