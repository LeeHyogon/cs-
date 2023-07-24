## CPU 스케줄링 (CPU Scheduling)

- CPU를 사용할 수 있는 프로세스를 선택하고, CPU를 할당하는 작업을 말한다. 
- CPU 이용률을 최대화하기 위해 항상 실행 중인 프로세스를 가지게 하는데 있다.

### 1. CPU 스케줄러 

- 실행 준비가 되어 있는 메모리 내의 프로세스 중에서 선택하여, 이들 중 하나에게 CPU를 할당한다.


기본적으로 프로세스는 CPU만 사용하는 단계(CPU burst)와 I/O 작업만 하는 단계(I/O burst)의 반복으로 구성된 사이클의 형태로 다음과 같이 수행된다.

![image](https://user-images.githubusercontent.com/45483116/233749530-e99e0015-167d-489d-bda8-d8997726e8eb.png)


-  I/O-bound Job : 짧고 많은 CPU burst가 존재하는 프로그램 
-  CPU-bound Job : 길고 적은 CPU burst가 존재하는 프로그램

이러한 여러 Job이 섞여있기 때문에 CPU 스케줄링이 필요하다.

### 2. 선점 및 비선점 스케줄링 (Preemptive and Nonpreemptive Scheduling)

CPU Scheduler는 메모리에서 Ready 상태의 프로세스 중 어떤 프로세스를 CPU에 할당해줄지 선택한다. CPU 스케줄링으로 인해 변경되는 프로세스의 상태는 다음과 같다. 
 
 1) Running → Waiting(Blocked) : I/O 요청이나 자식의 종료를 위해 wait( ) 함수 호출한 경우 (I/O 발생)

 2) Running → Ready : 인터럽트가 발생한 경우 (인터럽트 발생)

 3) Waiting → Ready : I/O 작업이 끝난 경우 (I/O 종료)

 4) Terminate

여기서 1)과 4)는 Non-preemptive (비선점) 방식이고, 그 외의 모든 과정은 preemptive(선점) 방식이다. 

- Preemptive(선점) : **운영체제가 강제로 프로세스의 사용권을 통제하는 방식**
- Non-preemptive(비선점) : **프로세스가 스스로 다음 프로세스에게 자리를 넘겨주는 방식**

