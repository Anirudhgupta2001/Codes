//Crossword Problem

//Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
//For example, The following is an example for the input crossword grid and the word list.
//+-++++++++
//+-++-+++++
//+-------++
//+-++-+++++
//+-++-+++++
//+-++-+++++
//++++-+++++
//++++-+++++
//++++++++++
//----------
//CALIFORNIA;NIGERIA;CANADA;TELAVIV
//Output for the given input should be:
//+C++++++++
//+A++T+++++
//+NIGERIA++
//+A++L+++++
//+D++A+++++
//+A++V+++++
//++++I+++++
//++++V+++++
//++++++++++
//CALIFORNIA
//Note: We have provided such test cases that there is only one solution for the given input.
//Input format:
//The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
//The next line of input contains the word list, in which each word is separated by ';'. 
//Output format:
//Print the crossword grid, after placing the words of word list in '-' cells.  
//Constraints
//The number of words in the word list lie in the range of: [1,6]
//The length of words in the word list lie in the range: [1, 10]
//Time Limit: 1 second
//Sample Input 1:
//+-++++++++
//+-++-+++++
//+-------++
//+-++-+++++
//+-++-+++++
//+-++-+++++
//++++-+++++
//++++-+++++
//++++++++++
//----------
//CALIFORNIA;NIGERIA;CANADA;TELAVIV
//Sample Output 1:
//+C++++++++
//+A++T+++++
//+NIGERIA++
//+A++L+++++
//+D++A+++++
//+A++V+++++
//++++I+++++
//++++V+++++
//++++++++++
//CALIFORNIA




#include<bits/stdc++.h>
using namespace std;
#define IOS                            ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll                             long long
#define int                            long long
#define pb                             push_back
#define pii                            pair <int, int>
#define vi                             vector <int>
#define ff                             first
#define ss                             second
#define sz(x)                          (int)x.size()
#define vpii                           vector <pair <int, int>>
#define vvi                            vector <vector <int> >
#define all(x)                         (x).begin(), (x).end()
#define rall(x)                        (x).rbegin(), (x).rend()
#define endl                           "\n"
#define MAX                            1e18
#define MIN                            INT_MIN
#define mod                            1000000007
#define TEST                           int T;cin>>T;for(i=1;i<=T;i++)


template <typename T> T myPow(T x, int n) { if (x == 0)return 0; if (n == 0)return 1; T res = myPow(x, n / 2); if (n & 1)return x * res * res; else return res * res;}


bool canPlacedVertically(vector<string>&board, string word, int r, int c) {
  if (r - 1 >= 0 && board[r - 1][c] != '+')return false;
  if (r + word.size() < 10 && board[r + word.size()][c] != '+')return false;
  if (r + word.size() > 10)return false;
  for (int i = 0; i < word.size(); i++) {
    if (board[i + r][c] == '-' || board[i + r][c] == word[i])continue;
    else return false;
  }
  return true;
}
bool canPlacedHorizontally(vector<string>&board, string word, int r, int c) {
  if (c - 1 >= 0 && board[r][c - 1] != '+')return false;
  if (c + word.size() < 10 && board[r][c + word.size()] != '+')return false;
  if (c + word.size() > 10)return false;
  for (int i = 0; i < word.size(); i++) {
    if (board[r][c + i] == '-' || board[r][c + i] == word[i])continue;
    else return false;
  }
  return true;
}
void placeVertically(vector<string>&board, string word, int r, int c) {
  for (int i = 0; i < word.size(); i++) {
    board[r + i][c] = word[i];
  }
}
void placeHorizontally(vector<string>&board, string word, int r, int c) {
  for (int i = 0; i < word.size(); i++) {
    board[r][c + i] = word[i];
  }
}
void getAns(vector<string>&board, vector<string>&words, int x) {
  if (x == words.size()) {
    for (auto p : board)cout << p << endl;
    return;
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (board[i][j] == '-' || board[i][j] == words[x][0]) {
        if (canPlacedHorizontally(board, words[x], i, j)) {
          string temp = board[i].substr(j, words[x].size());
          placeHorizontally(board, words[x], i, j);
          getAns(board, words, x + 1);
          int k = j;
          for (auto p : temp)board[i][k++] = p;
        }
        if (canPlacedVertically(board, words[x], i, j)) {
          string temp = "";
          for (int k = i; k < i + words[x].size(); k++)temp += board[k][j];
          placeVertically(board, words[x], i, j);
          getAns(board, words, x + 1);
          int k = i;
          for (auto p : temp)board[k++][j] = p;
        }
      }
    }
  }
}
void solve(int test) {

  string s;
  vector<string>board(10);
  for (int i = 0; i < 10; i++) {
    cin >> board[i];
  }
  // for (auto p : board)cout << p << endl;
  cin >> s;
  vector<string>words;
  string cur = "";
  for (auto p : s) {
    if (p == ';')words.push_back(cur), cur = "";
    else
      cur += p;
  }
  words.push_back(cur);
  //for (auto p : words)cout << p << " "; cout << endl;
  getAns(board, words, 0);

}


signed main()
{
  IOS
// #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif

  int i = 1;
  //TEST
  solve(i);

  return 0;

}

