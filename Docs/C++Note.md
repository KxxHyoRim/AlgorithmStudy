## C++

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

#### DP (Dynamic Programming)

- 주로 반복 문제에서 사용 (앞전 계산 결과를 array 등에 저장해둠) 

  `fib (7) = fib(6) + fib(5) = (fib(5) + fib(4)) + fib(5)`

- Key 1 : 점화식 잘 세우기

- Key 2 : 초기조건 설정 (= 재귀 탈출 조건)

#### Tips

- Global scope에 변수를 선언하면 '0'으로 초기화. bool type은 'fasle'
- int = 32bit, long long = 64bit, unsigned long long = 64bit
- 입출력 빠르게 하는 법
    ``` c++
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    ```
