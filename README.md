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
