#include <iostream>
#include <vector>

int main() {
  
  int n, m;

  std::cin >> n >> m;
  
  std::vector<std::vector<int>> dp(10, std::vector<int>(m+1, 0));

  for (int i=0;i<=9 && i<=m;++i) {
    dp[i][i] = 1;
  }

  while (--n) {    
    
    std::vector<std::vector<int>> temp(10, std::vector<int>(m+1, 0));

    for (int y=0;y<=9;++y) for (int z=0;z<=m;++z) {
     
      if (y==0) {if (y+z+1<=m) temp[1][z+1] += dp[y][z];}
      else if (y==9) {
        if (z+8<=m) temp[8][z+8] += dp[y][z];
        if (z+9<=m) temp[9][z+9] += dp[y][z];
      }
      else {
        if (z+y-1<=m) temp[y-1][z+y-1] += dp[y][z];
        if (z+y<=m) temp[y][z+y] += dp[y][z];
        if (z+y+1<=m) temp[y+1][z+y+1] += dp[y][z];
      }
    }
    dp = temp;
  }
  int result = 0;
  for (int i=0;i<=9;++i) for (int j=0;j<=m;++j) result += dp[i][j];
  std::cout << result << std::endl;
}
