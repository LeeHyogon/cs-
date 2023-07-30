# 컴퓨터 시스템 구성

![image](https://github.com/LeeHyogon/cs-/assets/45483116/a0c26e0e-5dd9-40c6-905b-8fa99f121ec3)


- 각 레벨별로 사용되는 스레들에 대해 알아보자.


## Hardware thread 
- 코어의 고민 : 메모리에서 데이터를 기다리는 시간이 꽤 오래 걸림
-> 메모리를 기다리는 동안 다른 스레드를 실행하는 것은 어떨까?

Core \ Compute \ memory \ Compute \ memory  
        \ memory  \ Compute\ memory  \ Compute 
- 코어는 하나지만 코어의 사용률을 극대화 시키기 위해 2개의 서로 다른 스레드를 실행시킴. 이 각각의 스레드를 하드웨어 스레드라고 한다.
- OS관점에서는 가상의(logical) 코어
- 만약에 싱글 코어 CPU에서 하드웨어 스레드가 2개라면 OS는 이 CPU를 듀얼 코어로 인식하고 듀얼 코어에 맞춰서 OS레벨의 스레드들을 스케줄링 한다.

#### 인텔 듀얼 코어 CPU에 hyper-threading이 적용됐다면 하드웨어 스레드는 총 몇개인지?
듀얼 코어면 코어 4개짜리인 CPU로 인식하게 됨.


## OS thread
- OS kernel 영역에서 사용하는 스레드. OS 커널 레벨에서 생성되고 관리됨.
- CPU에서 실제로 실행되는 단위. **CPU 스케줄링의 단위**
- OS스레드의 컨텍스트 스위칭은 커널이 개입. 모드 전환 비용 발생
- 사용자 코드와 커널 코드 모두 OS 스레드에서 실행된다.

#### 동의어: 네이티브(OS) 스레드, 커널 스레드*(맥락에 따라서는 다른 의미일 수 있음), 커널-레벨 스레드, OS-레벨 스레드

#### 커널
- 운영체제의 핵심
- 시스템의 전반을 관리/감독하는 역할
- 하드웨어와 관련된 작업을 직접 수행

#### OS 스레드가 8개일 때, 하이퍼 스레딩이 적용된 인텔 듀얼코어 위에서 동작한다면 OS스레드들을 어떻게 코어가 균등하게 할당할 수 있을까? 
- 코어 4개 (사실은 2개지만) 당 코어 하나에 OS스레드를 2개씩 할당한다.

## User thread
- 유저 레벨 쓰레드
- 스레드 개념을 프로그래밍 레벨에서 추상화한 것

``` java
Thread thread = new Thread();
thread.start();
```
- 여기서 Thread를 유저 스레드라고 볼 수 있다.
- Java에서 제공하는 Thread의 코드에서 start 메서드를 확인해보면 start는 JNI(java native interface)의 clone이라는 system call을 호출함. 그래서 OS레벨의 스레드를 1개 생성후 자바스레드 1개와 1:1로 연결된다.

- - 유저쓰레드가 CPU에서 실행되러면 OS스레드와 반드시 연결돼야 한다.
 
#### 유저 스레드와 OS스레드를 어떻게 연결시킬 것인가?

### 1. One-to-One model
![image](https://github.com/LeeHyogon/cs-/assets/45483116/5779f6f5-0bea-4635-a3e9-b4456dd0606c)

- 일대일 매핑인 경우, 스레드 관리를 OS에 위임한다.
- 스케줄링을 커널이 수행.
- CPU가 멀티코어를 가진다 하더라도 OS스레드가 멀티코어를 활용하므로, 유저 스레드도 멀티코어 잘 활용하게됨.
- 만약 유저 스레드가 Block I/O를 수행하면 일대일 매핑된 OS스레드는 block이 되지만, 다른 스레드는 잘 동작한다. but, race condition 가능성

### 2. Many-to-One model
![image](https://github.com/LeeHyogon/cs-/assets/45483116/4a760ff5-a2f7-46cc-94f6-9f912a8dbc9c)

- 컨텍스트 스위칭이 더 빠르다. why? 컨텍스트 스위칭이 User 레벨에서만 일어나고 커널이 개입하지 않기때문.(커널이 개입하지 않으므로 빨리 끝난다)
- 즉, 유저 스레드간의 스위칭이 빠름
- OS 쓰레드가 1개인 경우이므로, 커널레벨에서의 race condition 가능성이 거의 없고, 유저 레벨에서 유저 쓰레드들이 컨텍스트 스위칭하다 race condition이 일어날 가능성이 있다.
- OS 쓰레드가 1개이므로 멀티코어를 활용하지 못한다.
- 유저 쓰레드가 block이 되는 순간 OS 쓰레드가 1개이므로, 다른 모든 유저 쓰레드도 블락. -> 그래서 non block I/O 사용

### 3. Many-to-Many mdoel

![image](https://github.com/LeeHyogon/cs-/assets/45483116/eded04aa-772b-4680-84b4-61c0aaaceab2)

- 앞의 2가지 모델의 장점을 합친 모델
- 유저 쓰레드간의 스위칭이 빠르면서도 멀티 코어 활용이 가능하고, 한 유저스레드가 block되더라도 전체 block이 되지 않음.
- 구현이 복잡함


## 조금 다른 uSER 스레드
- OS와는 독립적으로 유저 레벨에서 스케줄링되는 스레드

## Green thread

- java의 초창기 버전은 Many-to-One 스레딩 모델을 사용. 이 때 이 유저 쓰레드들을 **그린 스레드**라고 호칭
- 혹은, 자바이외에도 Many-to-One 스레딩 모델을 의미할 수도
- 현대에 와서는 의미가 확장되어서 OS와는 독립적으로 유저레벨에서 스케줄링되는 스레드.(아까 봤던 다른의미의 user스레드 개념과 동일)

## 조금 다른 맥락에서 Kernel thread
- OS 커널의 역할을 수행하는 스레드
- 커널 코드를 실행하는 스레드(커널이 하는 일을 수행하는..)



### 현재 Java에서 threading model은 무엇일까?
- 과거에는 Many-To-One 스레딩 모델을 사용했다고 한다. 그렇다면 지금은?
- OS별로 JNI와 JVM의 소스 코드는 분리 구현되어 있고, 윈도우와 리눅스에 대해서는 one-to-one방식으로 동작하도록 구현 되어 있음.
- 즉, OS 마다 다르다!



ref https://www.youtube.com/watch?v=vorIqiLM7jc&list=WL&index=4&t=221s
