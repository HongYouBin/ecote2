# ecote2## https://github.com/ndb796/python-for-coding-test

## 어려운 문제일수록 설계 필수!!

### 6번 무지의 먹방 라이브 316p

https://programmers.co.kr/learn/courses/30/lessons/42891

https://github.com/HongYouBin/ecote/blob/main/6.cpp

- 작은 시간부터 처리한다는 아이디어는 금방 떠올렸다. 구현이 어려웠다.
- 작은 시간부터 처리되었다고 가정하자. 다음 시간을 처리할 때 이미 처리된 시간과 현재 처리해야 하는 시간의 총 합이 k보다 작은지 따져봐야 한다.(25행) k시간 후에 몇 번 음식을 처리해야 하는지 알아야 하기 때문에 처리된 총 합의 시간이 k보다 작거나 같은지 따져봐야 한다.
- 21행) k 시간이 지난 후에 처리해야 하는 음식이 없다면 -1을 출력해야하는 조건이 있다. 총 합이 k시간 보다 작으면 k 시간이 지난 후에 처리해야 하는 음식이 없다. 처음 문제를 풀 때 해당 조건을 빼먹어서 오답이 나왔다. 처음 문제를 읽을 때 정확하게 읽는 습관을 길러야 한다.
- 38행) 남은 시간에서 남은 음식의 크기를 나눈 나머지가 정답이 된다. 복잡하게 구현하지 말고 비슷한 유형이 나오면 사용해야 한다.
- 시간이 작은 수부터 처리해야 하기 때문에 우선순위 큐를 사용했다. 작은 수가 root에 있어야 해서 greater<>를 사용했는데, 시간초과가 발생했다. 답을 보니 내 방식을 사용하지 않고, 입력할 때 음수를 붙여 큰 수가 자식 노드로 가게 하고, 출력할 때 다시 음수를 붙여 원래 상태로 복귀시켰다. 우선순위 큐를 사용하고 작을수록 부모노드에 있어야하는 경우 음수처리해서 입력해야 시간이 절약된다.
- 다른 사람의 풀이를 보니 우선순위 큐를 사용하지 않고 map을 사용했다. map이 key를 기준으로 자동 정렬하는 성질을 이용했다.
  - https://hyuckang.tistory.com/40
