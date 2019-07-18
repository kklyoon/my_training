
### trie
문자열 검색에 적합한 자료구조, K진 트리구조, O(m) 의 시간 복잡도 (m = 문자열 길이)
```
triesize = 0
node = 0
for i in 0..p.length
    if trie[node][p[i]-'a'] == 0
        trie[node][p[i]-'a'] = ++triesize
        node = triesize
    else
        node = trie[node][p[i]-'a'];
check[node] = true; // 해당 노드에 문자열이 존재함을 알림
```

### What is typical cache line size?
프로세서 문서을 봐야한다. 내가 아는한 프로그래밍으로 알아내는 방법은 없다. 그러나 좋은면은 대부분의 캐시는 인텔기준을 따르는 표준 크기이다. x86 구조에서 캐시는 64바이트, 그러나 타겟프로세서의 가이드라인을 따라야 한다. 

### What is a Binary Search Tree?
비교가능한 키값을 가진 노드로 된 이진트리 부모키 값보다 작은건 왼쪽 큰건 오른쪽 서브트리로 들어간다.

### What is an AVL tree?
BST 에 균형을 맞춰놓은 것 모든 형제노드의 height 차가 1보다 크기 않음, O(logn)의 시간복잡도로 검색, 삽입, 삭제를 할 수 있음

### What is a red-black tree?

BST 트리, 각 노드는 검/빨 속성을 가진다. root 는 검은색, leaf 노드는 null이고 검은색, 레드노드의 자식노드는 항상 블랙이다. (레드는 연달아 나타날 수 없다.) 어떤 노드로부터 리프 노드에 도달하는 모든 경로에는 리프 노드를 제외하면 모든 같은 갯수의 블랙노드가 있다. 루트 노드부터 가장 먼 경로까지의 거리가, 가장 가까운 경로까지의 거리의 두배보다 항상 작다. 따라서 러프하게 균형잡혀있다. 

### What is a splay tree?
최근에 사용한 노드를 root 로 올려주는 BST

### What is a treap?
Tree + Heap 의 자료구조, 각노드에 우선순위가 있는 BST  
두가지 속성을 가짐  
BST의 속성 ( 왼쪽은 작고, 오른쪽은 크고)  
Max-Heap 속성을 가지는 priority 가 랜덤 할당됨, priority 가 높은 노드가 부모노드가 됨
worst case 일 때 O(N)




