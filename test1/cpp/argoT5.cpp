#include <iostream>
#include <vector>
using namespace std;

template <class T> void chmax(T &a, T b) {
  cout << "比較a: " << a << " 確認b: " << b << endl;
  if (a < b) { a = b; }
}

int main() {
  // 入力
  int N;
  long long W;
  cin >> N >> W;
  vector<long long> weight(N), value(N);
  for (int i = 0; i < N; ++i)
    cin >> weight[i] >> value[i];

  // DP テーブル定義
  vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));

  // DPループ
  for (int i = 0; i < N; ++i) {
    for (int w = 0; w <= W; ++w) {
      cout << "1-確認i: " << i << " 確認w: " << w << " dp: " << dp[i][w] << endl;

      // i 番目の品物を選ぶ場合
      // if (w - weight[i] >= 0) { chmax(dp[i + 1][w], dp[i][w - weight[i]] + value[i]); }
      if (w - weight[i] >= 0) { dp[i + 1][w] = dp[i][w - weight[i]] + value[i]; }

      cout << "2-確認i: " << i << " 確認w: " << w << " dp: " << dp[i][w] << endl;
      // i 番目の品物を選ばない場合
      chmax(dp[i + 1][w], dp[i][w]);
      // dp[i + 1][w] = dp[i][w];
    }
  }

  // 最適値の出力
  cout << dp[N][W] << endl;
}