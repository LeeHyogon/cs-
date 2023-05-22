### 프로그램	

- 어떤 작업을 하기 위해 실행할 수 있는 파일	

- 파일이 저장 장치에 있지만 메모리에는 올라가 있지 않은 정적인 상태	


### 프로세스 

- 실행되어 작업중인 컴퓨터 프로그램

- 메모리에 적재되고 CPU 자원을 할당받아 프로그램이 실행되고 있는 상태

### 스레드의 개념
- 하나의 프로세스 내에서 동시에 진행되는 작업 갈래, 흐름의 단위 

#### 스레드의 자원 공유

프로세스의 4가지 메모리 영역
- Code
- Data
- Heap
- Stack

스레드는 Stack만 할당받아 복사하고 Code, Data, Heap은 프로세스내의 다른 스레드들과 공유된다.

 stack은 함수 호출 시 전달되는 인자, 되돌아갈 주소값, 함수 내에서 선언하는 변수 등을 저장하는 메모리 공간이기 때문에, </br>
 
- 독립적인 stack -> 독립적인 함수 호출 가능 -> 독립적인 실행 흐름 추가 
 
**즉, stack을 가짐으로써 스레드는 독립적인 실행 흐름을 가질 수 있게 되는 것이다.** 

### 프로세스 & 스레드의 동시 실행 원리

#### 멀티 코어와 스레드

- 4코어가 물리적 코어 갯수면, 8쓰레드는 논리적 코어 갯수를 말한다. 이 경우 물리적 코어 하나가 스레드 두 개 이상을 동시에 실행 가능하다는 의미
 

### CPU의 작업 처리 방식
 
 
#### 1.병렬성 (Parallelism)

- 여러개의 프로세스, 스레드를 돌려 병렬로 작업들을 동시 수행하는 것을 말한다. </br>
  (멀티코어 프로세서가 달린 컴퓨터에서 할 수 있는 방식)
 

#### 2.동시성 (Concurrency)

- 작업을 동시에 실행하는 것처럼 보이게 하는 것

- 프로세스들을 번갈아가면서 매우 빠르게 처리하기 때문에 마치 동시에 돌아가는 것처럼 보이게 된다.
 
- 진행 중인 작업들을 번갈아 바꾸는 것을 **Context Switching 이라고 부른다.**
 

### 동시성이 필요한 이유

#### 1.하드웨어적 한계
- 코어 탑재 갯수의 제한

#### 2.논리적인 효율
 - 짧은 작업 기간을 가진 프로세스가 긴 작업 기간을 가진 프로세스를 기다리지 않고, 병렬적으로 처리할 수 있음.


 출처: https://inpa.tistory.com/entry/%F0%9F%91%A9%E2%80%8D%F0%9F%92%BB-%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4-%E2%9A%94%EF%B8%8F-%EC%93%B0%EB%A0%88%EB%93%9C-%EC%B0%A8%EC%9D%B4
 
 ### CPU 스케줄링
 - 운영체제에서 CPU를 사용할 수 있는 프로세스스를 선택하고, CPU를 할당하는 작업을 말한다. 


