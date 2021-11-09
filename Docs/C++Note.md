## C++

#### 입출력 빠르게 하는 법
``` c++
cin.tie(NULL);
ios::sync_with_stdio(false);
```

#### Vector 자주 쓰는 함수
1. push_back(‘ ‘): 맨뒤에 원소 추가
2. pop_back() : 맨뒤에 원소 삭제(void)
3. clear() : 배열 비우기
4. size() : 사이즈 return

#### vector를 2차원 배열과 같이 사용하는 법

``` C++
#include<vector>
#include<algorithm>

vector <pair<int, int>> vec;              // 자료형으로 pair를 넘겨줌

cin >> n;
vec.resize(n);                            // resize 안하면 index에 접근할 수 없다고 나오면서 에러

for (int i = 0; i < n; i++)
  cin >> vec[i].first >> vec[i].second;   // resize를 써줬기 때문에 index로 접근 가능

sort(vec.begin(), vec.end());	          // 첫번째 기준 : vec[i].first, 두번째 기준 : vec[i].second
```
