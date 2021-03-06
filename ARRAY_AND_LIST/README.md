#  📋 배열과 리스트
배열과 리스트에서 나올 만한 면접 질문들을 모아 보았습니다.

### ⭐ 배열과 동적 배열이 무엇인가요?
* 먼저 배열은 원소들이 메모리에 연속적으로 저장되어 있는 특징을 가지고 있습니다. 크기가 변할 수 있다면 **동적 배열**, 그렇지 않다면 **정적 배열** 입니다.
* 동적 배열은 _size_ 와 _capacity_ 라는 개념이 있습니다. _size_ 는 동적 배열에 들어가 있는 원소의 수, _capacity_ 는 동적 배열에 들어갈 수 있는 원소의 수를 의미합니다.
* 배열과 동적 배열은
  * _Random Access_ 에 특화된 자료구조입니다. O(1)
  * 중간에 원소를 넣거나 삭제하는 연산은 최악의 경우에 O(n) 만큼 걸립니다.


### ⭐ 왜 동적 배열에서 뒤에 추가하는 연산이  효율적으로 동작하나요?
동적 배열의 _capacity_ 를 증가시킬 때, 하나씩 증가시키는 게 아니라 **n배율로 확장**시키기 때문입니다.
* 이 n의 값을 _grow rate_ 라고 합니다.
예를 들어 n = 2라고 하고 초기 capacity를 1이라 해 보겠습니다. 1025 번의 뒤에 추가하는 add 쿼리가 들어왔을 때
* _capacity_ 가 1, 2, 4, 8, ... , 1024, 2048인 동적 배열이 새로 생성됩니다.
* _expand_ 연산이 일어날 때, 기존 배열에 있었던 값들을 새롭게 생성된 배열에 **복사** 합니다.
* 오래된 배열인 _capacity_ 가 1, 2, 4, 8, ... , 1024인 동적 배열이 메모리에서 해제됩니다.

이 일련의 과정을 add 쿼리의 횟수 1025로 나눴을 때 비용이 **상수** 로 떨어지게 됩니다.

### ⭐ amortized 분석이 무엇인가요?
모든 경우에 대해서 평균적인 연산 횟수를 구한다면 _average_ 분석입니다. **기댓값** 과 관련이 있다고 생각하시면 좋습니다. 
크기가 n인 배열의 임의의 위치에 원소를 추가해 봅시다.
* 0번째에 추가하는 경우, n개의 원소를 뒤로 밀어야 합니다.
* 1번째에 추가하는 경우, n-1개의 원소를 뒤로 밀어야 합니다.
* 이를 일반화 시키면, i번째에 추가하는 경우, n-i개의 원소를 뒤로 밀어야 합니다.
* 0번째, 1번째, ... , n번째에 추가하는 **event가 고르게 온다 가정** 하면 평균적으로 n/2개의 원소를 뒤로 밀어야 합니다.
* 따라서 배열에 원소를 추가하는 평균 복잡도는 O(n)이 됩니다.

동적 배열의 맨 뒤에 원소를 추가하는 add 연산을 분석해 봅시다.
* 이 연산은 배열이 꽉 찬 경우에 _expand_ 를 하는 복잡도가 들어갑니다.
* 그렇지 않은 경우에는 바로 뒤에 추가하면 되므로 O(1)의 복잡도를 가집니다.
* 그런데 동적 배열의 맨 뒤에 연산을 추가하는 _add_ 연산은 _amortized_ O(1)이라 합니다. 왜 그럴까요?
  * _size_ 가 n이고 _capacity_ 가 n일 때 부터, _size_ 가 2n이고 _capacity_ 가 2n인 상황까지 봅시다. _grow rate_ = 2라고 하겠습니다.
  * 다음에 크기가 x인 배열을 삭제, 생성, 복사하는 비용과 원소를 배열에 x번 대입하는 비용이 1로 같다고 하겠습니다.
  * 먼저 _size_ 가 n이고 _capacity_ 가 n인 상황에서 원소가 추가된다면, _capacity_ 는 2n이 됩니다. 이 과정에서 크기가 2n 인 배열을 만들고 n 개의 원소를 복사하고 크기가 n인 배열이 삭제됩니다. 총 비용은 4n입니다.
  * 다음에 n번 원소를 추가하면 됩니다. 이 때에는 대입 연산만 일어나므로, 총 비용은 n이 됩니다.
  * add 연산 n번 일어날 동안 총 비용이 5n이므로 add의 평균 비용은 5n/n = 5가 됩니다.

연산에 대한 average 비용을 구한 건 비슷합니다. 단지 다른 것은 **n회의 연산** 을 했을 때의 전체 비용을 연산 횟수로 나눠서 **상수로 떨어진 것**을 보였을 뿐입니다.

### ⭐⭐⭐ 언제 Linked List를 쓰나요?
* 삽입, 삭제가 빈번히 일어나고, **해당 연산이 일어나는 위치**를 빠르게 알 수 있다면 Linked List를 씁니다.