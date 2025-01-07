#include <iostream>

using namespace std;

int LongestSubseq(int arr[], int n)
{
  int max = 0;

  if (n == 1)
  {
    return 1;
  }

  for (int i = 0; i < n - 1; i++)
  {
    int count = 1;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] > arr[j])
      {
        if (max < count)
        {
          max = count;
        }
        i += (count - 1);
        break;
      }
      else
      {
        count++;
      }
    }
    // count가 증가하다가 끝나는경우
    if(max < count){
        max = count;
    }
  }
  return max;
}
int main()
{
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int testCase;

  cin >> testCase;

  while (testCase--)
  {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    cout << LongestSubseq(arr, n) << '\n';
  }

  return 0;
}