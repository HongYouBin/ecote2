# ecote2

## https://github.com/ndb796/python-for-coding-test

## https://github.com/HongYouBin/ecote

### 6번 무지의 먹방 라이브 316p

https://programmers.co.kr/learn/courses/30/lessons/42891

https://github.com/HongYouBin/ecote2/blob/main/6.cpp

- 작은 시간부터 처리한다는 아이디어는 금방 떠올렸다. 구현이 어려웠다.
- 작은 시간부터 처리되었다고 가정하자. 다음 시간을 처리할 때 이미 처리된 시간과 현재 처리해야 하는 시간의 총 합이 k보다 작은지 따져봐야 한다.(25행) k시간 후에 몇 번 음식을 처리해야 하는지 알아야 하기 때문에 처리된 총 합의 시간이 k보다 작거나 같은지 따져봐야 한다.
- 21행) k 시간이 지난 후에 처리해야 하는 음식이 없다면 -1을 출력해야하는 조건이 있다. 총 합이 k시간 보다 작으면 k 시간이 지난 후에 처리해야 하는 음식이 없다. 처음 문제를 풀 때 해당 조건을 빼먹어서 오답이 나왔다. 처음 문제를 읽을 때 정확하게 읽는 습관을 길러야 한다.
- 38행) 남은 시간에서 남은 음식의 크기를 나눈 나머지가 정답이 된다. 복잡하게 구현하지 말고 비슷한 유형이 나오면 사용해야 한다.
- 시간이 작은 수부터 처리해야 하기 때문에 우선순위 큐를 사용했다. 작은 수가 root에 있어야 해서 greater<>를 사용했는데, 시간초과가 발생했다. 답을 보니 내 방식을 사용하지 않고, 입력할 때 음수를 붙여 큰 수가 자식 노드로 가게 하고, 출력할 때 다시 음수를 붙여 원래 상태로 복귀시켰다. 우선순위 큐를 사용하고 작을수록 부모노드에 있어야하는 경우 음수처리해서 입력해야 시간이 절약된다.
- 다른 사람의 풀이를 보니 우선순위 큐를 사용하지 않고 map을 사용했다. map이 key를 기준으로 자동 정렬하는 성질을 이용했다.
  - https://hyuckang.tistory.com/40

### 9번 문자열 압축 323p

https://programmers.co.kr/learn/courses/30/lessons/60057

https://github.com/HongYouBin/ecote2/blob/main/9.cpp

- 1개부터 문자열의 절반까지로 압축의 범위를 설정했다. 설정한 압축의 범위에 맞게 문자열을 자른 후 비교하는 과정을 거쳤다.
- 14행에서 문자열을 자를 때 직접 구현해줬는데 그럴 필요 없이 substr함수를 이용하면 됐다.
- prev를 처음으로 잘려진 문자열로 설정하면 더 간단하게 구현 가능했다.
- 다른 문자열이 나올 때 compressed에 압축된 내용을 추가하면 된다. 추가되지 못한 나머지 부분들은 32행부터 처리해줬다.
- compressed를 처리할 때 조건문을 많이 사용했는데, 그럴 필요 없이 삼항 연산자를 쓰면 간단하게 처리 가능하다.
- 정수를 문자열(string)으로 바꾸기 위해서 to_string() 함수를 이용해야 한다.
- 9행에서 string s의 길이가 1인 경우 s.size()/2 + 1의 값으로 1이 나온다. 따라서 괄호 표시를 '<=' 크거나 같다로 해줘야 정상적으로 작동한다. 또는 answer의 값을 초기화할때 1e9이 아니라 s의 크기로 해주면 된다.

### 10번 자물쇠와 열쇠 325p

https://programmers.co.kr/learn/courses/30/lessons/60059

https://github.com/HongYouBin/ecote2/blob/main/10.cpp

- 배열 90도 회전 -> 11행)tmp[j][arr.size()-1-i] = arr[i]
- 2차원 vector 초기화 방법 -> 32행) vector<vector<int>> newLock(lockS _ 3, vector<int>(lockS _ 3));

### 11번 뱀 327p

https://www.acmicpc.net/problem/3190

https://github.com/HongYouBin/ecote2/blob/main/11.cpp

### 12번 기둥과 보 설치 329p

https://school.programmers.co.kr/learn/courses/30/lessons/60061

https://github.com/HongYouBin/ecote2/blob/main/12.cpp

- 17행) 보의 양쪽 끝부분이 다른 보와 동시에 연결되어 있어야 한다는 조건을 실수했다. 한쪽 보의 끝부분이 다른 보와 연결되어 있는 경우도 참이 되도록 했다. 문제를 꼼꼼하게 읽고 구현해야 한다. 조건이 까다로운 경우 주석처리로 처리해야 하는 조건을 명시하는 방법을 사용할 예정이다.
- 2차원 vector를 정렬할 때 따로 정렬 조건을 넣지 않으면 vector의 순서를 기준으로 (첫 번째 기준:vt[0], 두 번재 기준:vt[1], 세 번재 기준:vt[2] ... ) 정렬된다.
- https://leeeegun.tistory.com/5
- https://twinkite.tistory.com/entry/C-2%EC%B0%A8%EC%9B%90-%EB%B2%A1%ED%84%B0-%EC%A0%95%EB%A0%ACsort
- https://learncom1234.tistory.com/6

### 13번 치킨 배달 332p

https://www.acmicpc.net/problem/15686

https://github.com/HongYouBin/ecote2/blob/main/13.cpp

### 14번 외벽 점검 335p

https://school.programmers.co.kr/learn/courses/30/lessons/60062

https://github.com/HongYouBin/ecote2/blob/main/14.cpp

- 처음 문제와 비슷하게 완전탐색이 아닌 그리디한 방법을 이용하려 했다. dist 배열이 큰 수부터 청소를 시작하게 만들면 된다고 생각했다. 그리디한 방법으로 구현하면 오류가 나는데 왜 그런지 이유와 케이스를 아직 찾지 못했다.
- next_permutation()은 순열을 만들 때 오름차순에서 점점 내림차순으로 만든다.
  - https://hanil0623.tistory.com/2

### 17번 경쟁적 전염 344p

https://www.acmicpc.net/problem/18405

https://github.com/HongYouBin/ecote2/blob/main/17.cpp

- bfs를 사용해야하는 구현문제이다.

### 18번 괄호 변환 346p

https://school.programmers.co.kr/learn/courses/30/lessons/60058

https://github.com/HongYouBin/ecote2/blob/main/18.cpp

### 19번 연산자 끼워 넣기 349p

https://www.acmicpc.net/problem/14888

https://github.com/HongYouBin/ecote2/blob/main/19.cpp

### 20번 감시 피하기 351p

https://www.acmicpc.net/problem/18248

https://github.com/HongYouBin/ecote2/blob/main/20.cpp

### 21번 인구 이동 353p

https://www.acmicpc.net/problem/16234

https://github.com/HongYouBin/ecote2/blob/main/21.cpp

- bfs로 구현했다.
- 처음 설계 과정에서 종료조건을 설정하지 않아 애먹었다. 초기 설계를 정확하게 해야 한다.
- 답은 bfs를 몇번 했는지를 센 값이 map의 크기과 같으면 종료하도록 했다. 나의 풀이보다 간단하고 빠르다.

### 22번 블록 이동하기 355p

https://school.programmers.co.kr/learn/courses/30/lessons/60063

https://github.com/HongYouBin/ecote2/blob/main/22.cpp

- 24행 turn 함수 구현이 가장 까다로웠다. 정확하게 설계한 후, 실수 없도록 구현해야 한다.
- 54행) 이동해야 하는 두 번째 블록의 좌표를 구할 때 실수를 했다.
- 24행 turn 함수와 13행 move 함수 모두 2차원 vector를 인수로 받을 때 시간 절약을 위해 참조로 받았다. 복사의 시간 비용이 큰 경우 참조로 받아야 한다.

### 24번 안테나 360p

https://www.acmicpc.net/problem/18310

https://github.com/HongYouBin/ecote2/blob/main/24.cpp

### 25번 실패율 361p

https://school.programmers.co.kr/learn/courses/30/lessons/42889

https://github.com/HongYouBin/ecote2/blob/main/25.cpp

- 실패율 계산할 때 int가 아닌 double로 실수 형태로 받아야 한다. 형 변환이 필요하다.
  - https://ju3un.github.io/c++-type-casting/
- 스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다는 조건을 빼먹었다. 문제를 정확하게 읽고 구현해야 한다.

### 26번 카드 정렬하기 363p

https://school.programmers.co.kr/learn/courses/30/lessons/1715

https://github.com/HongYouBin/ecote2/blob/main/26.cpp

### 27번 정렬된 배열에서 특정 수의 개수 구하기 367p

https://github.com/HongYouBin/ecote2/blob/main/27.cpp

- lower_bound(), upper_bound() 사용

### 29번 공유기 설치 369p

https://www.acmicpc.net/problem/2110

https://github.com/HongYouBin/ecote2/blob/main/28.cpp

- 설치된 공유기 수와 설정한 공유기 사이의 거리는 반비례한다. 공유기 수가 c보다 크면 거리를 늘려 공유기 수를 줄여야 하고, 반대로 공유기 수가 c보다 작으면 거리를 줄여 공유기 수를 늘려야 한다.

### 30번 가사 검색 370p

https://school.programmers.co.kr/learn/courses/30/lessons/60060

https://github.com/HongYouBin/ecote2/blob/main/30.cpp

### 33번 퇴사 377p

https://www.acmicpc.net/problem/14501

https://github.com/HongYouBin/ecote2/blob/main/33_1.cpp
https://github.com/HongYouBin/ecote2/blob/main/33_2.cpp

- dp[i]를 i일까지 얻을 수 있는 최대 수익이라고 설정했고 n일부터 1일까지 순서대로 dp 테이블을 채웠다. 설정에 맞게 세운 점화식은 dp[i] = dp[i + t[i]] + p[i]이다. 이때 점화식이 완벽한 것은 아닌데 i일에 상담하지 않은 경우의 수를 따져줘야 한다. 따라서 i일 이후의 최대값과 dp[i] = dp[i + t[i]] + p[i] 값 중 큰 값으로 dp 테이블을 채워야 한다.
- t[i] + i > n + 1 인 경우에 무시하고 지나갔는데, dp[i] = 0이 된다. 그 말은 i일까지 얻을 수 있는 최대 수익이 0이라는 뜻으로 나중에 dp[i]를 참고할 수 있으므로 오답이 된다. 따라서 i일 이후의 최대값으로 해야 정답이 된다.
- 33_2는 완전탐색으로 구현했다.

### 34번 병사 배치하기 380p

https://www.acmicpc.net/problem/18353

https://github.com/HongYouBin/ecote2/blob/main/34_1.cpp
https://github.com/HongYouBin/ecote2/blob/main/34_2.cpp

- 34_1) dp중 가장 긴 증가하는 수열을 응용하면 풀었다. 시간복잡도는 O(N\*N)이 걸렸다.
- binary search로도 해당 문제를 풀 수 있다. 원래는 가장 긴 증가하는 수열로 이분탐색을 하는데 문제는 감소하는 조건이 있기 때문에 처음 입력을 할 때 음수로 넣고, 가장 긴 증가하는 수열로 풀었다.
  - https://st-lab.tistory.com/285

### 36번 편집 거리 382p

https://github.com/HongYouBin/ecote2/blob/main/36.cpp

- 19행) s1[i-1] != s2[j-1]인 경우 arr[i][j-1] (추가), arr[i-1][j] (삭제), arr[i-1][j-1] (교체) 중 가장 작은 수에 1을 더한 값으로 테이블을 채운다.

### 37번 플로이드 385p

https://github.com/HongYouBin/ecote2/blob/main/37.cpp

https://www.acmicpc.net/problem/11404

- 플로이드 워셜 알고리즘 사용하면 된다.
  - 23행부터 30행까지 플로이드 워셜 알고리즘을 구현했다. 처음 알고리즘을 구현할 때 실수를 했다. 플로이드 워셜 알고리즘안에 for문이 총 3가지가 있다. 그 중 k로 시작하는 for문이 첫 번째 for문이어야 하는데, 세 번째 for문으로 돌도록 구현했다.
    - k가 거쳐가는 노드인데 첫 번째 노드부터 마지막 노드 모두 거쳐가는 노드를 돌기 위해서 바깥에 존재해야 한다.

### 38번 정확한 순위 387p

https://github.com/HongYouBin/ecote2/blob/main/38.cpp

- 플로이드 워셜 알고리즘 사용했다. 성적을 오름차순으로 받는 배열, 내림차순으로 받는 배열을 만들었다. 두 배열 중 i행 j열이 0이 아니면 i와 j간의 순위가 결정할 수 있다.
- 배열 1개로 만들어 배열을 아낄 수 있는데, 하나의 배열로 플로이드 워셜 알고리즘을 진행한 후 arr[i][j]와 arr[j][i] 두 개의 수를 비교하여 i와 j의 순위를 비교할 수 있다.

### 39번 화성 탐사 388p

https://github.com/HongYouBin/ecote2/blob/main/39.cpp

- 다익스트라 알고리즘 이용했다. 에너지 소모량이 적힌 2차원 배열을 참조하여 i행 j열에 방문한다면, 기존 사용한 에너지 소모량에 i행 j열에 적힌 에너지 소모량을 더해 최단 경로 알고리즘을 구현했다.

### 40번 숨바꼭질 390p

https://github.com/HongYouBin/ecote2/blob/main/40.cpp

- 다익스트라 알고리즘 이용했다. vector 배열을 이용하여 그래프를 구현했다.

### 41번 여행 계획 393p

https://github.com/HongYouBin/ecote2/blob/main/41.cpp

- 서로소 집합 이용했다.
- https://www.acmicpc.net/problem/1976 백준에서 비슷한 문제를 찾아 풀었다.

### 42번 탑승구 395p

https://github.com/HongYouBin/ecote2/blob/main/42.cpp

- https://www.acmicpc.net/problem/10775 백준에서 비슷한 문제를 찾아 풀었다.
- 그리디하게 접근할 수 있는 문제이다. 비행기가 도착했을 때 도킹할 수 있는 가장 낮은 탑승구에 도킹하면 된다. 문제는 그리디를 구현할 때 시간초과가 발생한다. 따라서 서로소 집합 알고리즘을 사용해야 한다. parent[i]는 i번째 탑승구까지 도킹할 수 있는 비행기가 도착했을 때 도킹할 수 있는 가장 낮은 탑승구라고 설정하면 parent[i]가 0이면 도킹에 실패한다. i번째 비행기가 도킹하면 parent[i]를 갱신해줘야 하는데, 똑같이 i 비행기가 도착하면 도킹할 수 있는 가장 낮은 탐승구는 parent[i]-1이 된다. 따라서 parent[i]와 parent[i]-1을 merge 해줘야 한다.

### 43 어두운 길 397p

https://github.com/HongYouBin/ecote2/blob/main/43.cpp

- https://www.acmicpc.net/problem/6497
- 크루스칼 알고리즘 이용했다.

### 44 행성 터널 398p

https://github.com/HongYouBin/ecote2/blob/main/44.cpp

https://www.acmicpc.net/problem/2887

- 크루스칼 알고리즘 사용
- 참고해야하는 edge를 모든 경우의 수를 따지면 시간초과가 발생한다. edge 수를 줄여야 한다. x, y, z를 각각 배열로 받은 후 정렬하여 배열에서 가까운 요소끼리 절대값을 씌우고 빼준 edge만 참고하면 된다.

### 45 최종 순위 399p

https://github.com/HongYouBin/ecote2/blob/main/45.cpp

https://www.acmicpc.net/problem/3665

- 위상정렬 사용
- 위상정렬의 결과값으로 3가지가 나올 수 있다. 첫 번째는 경우의 수가 1개밖에 없는 결과이다. indgree가 0인 index를 받기 위해 만든 queue가 항상 1을 유지하면 가능하다. 두 번째는 경우의 수가 2개 이상인 경우이다. queue의 크기가 2이상이 되면 위상정렬의 결과가 다양해진다. 세 번째는 순환을 돌아 결과값을 만들지 못하는 경우이다. queue 크기가 0이면 순환이 발생한다.

### 46 아기상어 402p

https://github.com/HongYouBin/ecote2/blob/main/46_1.cpp

https://www.acmicpc.net/problem/16236

- bfs를 활용한 구현문제이다.
- bfs를 활용하여 크기가 상어보다 작고 가까운 물고기를 찾는 코드를 구현하는 것은 어렵지 않았다. '거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다'라는 조건이 까다로웠다. 따로 상어보다 작은 물고기가 있는 테이블을 따로 만들어서 현재 상어의 위치에서 가장 가까운 것이 1순위, 1순위가 여러개라면 가장 위에 있는 물고기가 2순위, 2순위가 여러개라면 가장 왼쪽에 있는 물고기가 3순위로 조건을 설정해주면서 조건에 맞는지 테이블을 조회 하는데 은근 까다로웠다.
- 문제를 거의 다 풀어놓고 test case를 통과하지 못했는데, 처음 상어의 위치 9를 갱신하지 않아서였다. 사소한 디테일이 정답을 가를 수 있기 때문에 꼼꼼하게 신경써야 한다.
- 시간 단축을 위해 조건 테이블을 생성하지 않고 구현하는 방법이 없나 고민해 봤다. bfs로 배열을 도는 순서를 설정하면 된다고 생각했다. 1순위로 북, 2순위로 서, 3순위로 동, 4순위로 남 순서로 조회하려 했다. 하지만 4번 test case에서 막혔는데, 물고기의 거리가 1일 때는 성립하나 거리가 2 이상일 때부터 성립하지 않는다. 아래에 반례를 적어놨다. 5번 순서와 6번의 순서가 바뀌어야 정답이 인정된다. 따라서 '거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다'라는 조건이 붙으면 해당 조건 확인용 테이블을 생성해야 한다.
  - 2 1 3 6
    5 4 7 8
  - https://github.com/HongYouBin/ecote2/blob/main/46_2.cpp
