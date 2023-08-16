# JVM이란

- Java Virtual Machine, 자바 가상 머신
- 자바와 운영체제 사이에엇 중개자 역할을 수행하며 자바가 운영체제에 구애 받지 않고 프로그램을 실행할 수 있도록 도와줌. 
- 또한 가비지 컬렉터를 사용한 메모리 관리도 자동으로 수행하며, 다른 하드웨어와 다르게 레지스터 기반이 아닌 스택 기반으로 동작



## JVM 메모리 구조
![](https://velog.velcdn.com/images/gon109/post/1db37dfa-3659-4692-ae29-52be94689e57/image.png)

- JVM의 구조는 크게 보면 Garbage Collector, Exceution Engine, Class Loader, Runtime Data Area로 크게 4가지

### 1. Class Loader
- Java 파일을 작성한 후 javac 명령어를 통해 컴파일하면 .class파일이 생성된다.
- 이 .class파일은 java 코드를 바이트 코드로 변환한 파일. 
- Class Loader는 이렇게 변환된 class 파일들을 엮어 JVM이 운영체제로부터 할당받은 메모리 영역인 Runtime Data Area에 적재하는 역할을 한다

### 2. Execution Engine
- Class Loader에 의해 메모리에 적재된 바이트 코트들을 기계어로 변경하여 실행하는 역할을 한다.
- Interpreter 방식과 JIT 컴파일러를 이용하는 방식이 있다.
#### 컴파일러
- 정적 컴파일 방식을 사용하는 언어 번역 프로그램
- 실행하시 전에 프로그램 코드를 기계어와 같은 목적 코드(실행 가능한 코드, 실행 속도가 매우 빠름)로 번역

#### 인터프리터
- 실행 중 프로그래밍 언어를 한줄 씩 읽어가면서 해당 기능에 대응하는 기계어 코드를 실행


![](https://velog.velcdn.com/images/gon109/post/2b67500d-f8be-43c2-872c-31af53ab4ceb/image.png)
#### JIT 컴파일
> JIT 컴파일 또는 동적 번역은 프로그램을 실제 실행하는 시점에 기계어로 번역하는 컴파일 기법

* JIT 컴파일러는 정적 컴파일 방식과 인터프리트 방식을 혼합한 방식으로 생각할 수 있다.
  * 실행 시점에는 인터프리트 방식으로 기계어 코드를 생성함과 동시에 그 코드를 캐싱
  * 같은 함수가 여러 번 불릴때 매번 기계어 코드 생성하는 것 방지
* 자바의 경우 다음 순서를 거친다
  1. 자바 컴파일러가 자바 소스 코드를 바이트 코드로 변환하며 최적화
  2. 바이트 코드가 실행되는 과정에서 실시간으로 JIT 컴파일러가 바이트 코드를 기계어로 변환
  	* 실행되는, 즉 필요한 부분만 변환된다.
    * 변환된 기계어 코드는 캐싱되어 다시 컴파일할 필요가 없다.
#### JIT의 장점
* 실행과정에서 필요한만큼만 컴파일한다.
  * 인터프리트 방식은 소스코드를 최적화 과정 없이 번역하므로 성능이 낮음
  * 정적 컴파일언어는 실행 전 무조건 컴파일하므로, 컴파일하기 위해 많은 시간 소요
  * 인터프리터에 비해 빠른 수준이며, 경우에 따라 정적 컴파일러보다 빠름
### 3. Garbage Collector
- Heap 메모리 영역에서 생성된 객체들 중 참조되지 않는 객체들을 탐색 후 제거
- GC가 수행되는 동안 GC를 수행하는 쓰레드외의 모든 쓰레드가 일시정지될 수 있다.(stop the world)

### 4. Runtime Data Area
- JVM의 메모리 영역으로 자바를 실행할 때 사용되는 데이터들을 적재하는 역할

![](https://velog.velcdn.com/images/gon109/post/61ae821b-f2c7-4482-8c22-16c889670b36/image.png)

#### 4.1 PC Register
- Thread가 시작될 때마다 생성되며 Thread마다 하나씩 존재. 현재 Thread가 실행되는 부분의 주소와 명령을 저장하고 있어 어떤 부분을 무슨 명령으로 실행해야 할 지에 대한 기록을 하는 부분
- 현재 수행중인 JVM명령의 주소를 갖는다

#### 4.2 JVM Stack 
- 메서드 호출 시 마다 각각의 스택 프레임(메서드 공간)을 생성.
- 그리고 메서드 안에서 사용되는 값들을 저장하고 호출된 메서드의 매개변수, 지역변수, 리턴 값 및 연산 시 일어나는 값들을 임시로 저장. 
- 메서드 수행이 끝나면 프레임별로 삭제한다.

#### 4.3 Native Method Stack
- JAVA 언어가 아닌 다른 언어로 작성된 코드를 위한 공간. C/C++ 코드를 실행시켜 kernel에 접근할 수 있다.


#### 4.4 Heap
- 모든 Thread가 공유하며, new 키워드로 생성된 객체와 배열이 생성되는 영역. GC가 참조되지 않는 메모리를 확인하고 제거하는 영역에 해당된다.

다음과 같이 세 부분으로 나누어진다.
![](https://velog.velcdn.com/images/gon109/post/3c699d01-fed6-4fd2-af26-f5685b511358/image.png)

* New/Young
  * 객체들이 최초로 생성되는 공간인 Eden과 Eden에서 참조되는 객체들이 저장되는 공간인 Survivor 0/1이 해당 영역에 해당. Minor GC가 발생
  
* Old
  * New 영역에서 일정 시간 참조되고 살아남은 객체들이 저장되는 공간. Major GC가 발생

* Permanent
  * 생성된 객체들의 Meta 정보가 저장되는 영역이고 JVM에 의해 사용된다. Major GC 발생
  * Java 7까지 Heap영역에 존재했지만, Java 8 버전부터 Metaspace가 이를 대체
  


### 5. Method Area
* 메서드 영역은 JVM이 시작될 때 생성되는 공간으로 바이트 코드(.class)를 처음 메모리 공간에 올릴 때 초기화되는 대상을 저장하기 위한 메모리 공간.
* JVM이 동작하고 클래스가 로드될 때 적재되서 프로그램이 종료될 떄까지 저장

모든 쓰레드가 공유하는 영역이라 다음과 같이 초기화 코드 정보들이 저장되게 된다.
1. Field Info: 멤버 변수의 이름, 데이터 타입, 접근 제어자의 정보
2. Method Info: 메서드 이름, return 타입, 함수 매개변수, 접근 제어자의 정보
3. Type Info: Class 인지 Inteface인지 여부, Type의 속성 Super Class의 이름

![](https://velog.velcdn.com/images/gon109/post/dba50c7c-8ebc-48b5-b0e5-0a498673947c/image.png)

간단히 말하면 메서드 영역은 **정적 필드**와 **클래스 구조**를 가진다.



ref https://velog.io/@guswlsapdlf/Java%EC%9D%98-JVM-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EA%B5%AC%EC%A1%B0

ref https://steady-coding.tistory.com/305

ref https://velog.io/@bcj0114/%EC%BB%B4%ED%8C%8C%EC%9D%BC%EB%9F%AC%EC%99%80-%EC%9D%B8%ED%84%B0%ED%94%84%EB%A6%AC%ED%84%B0-%EA%B7%B8%EB%A6%AC%EA%B3%A0-JIT-%EC%BB%B4%ED%8C%8C%EC%9D%BC

ref https://inpa.tistory.com/entry/JAVA-%E2%98%95-JVM-%EB%82%B4%EB%B6%80-%EA%B5%AC%EC%A1%B0-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EC%98%81%EC%97%AD-%EC%8B%AC%ED%99%94%ED%8E%B8#%EB%A9%94%EC%84%9C%EB%93%9C_%EC%98%81%EC%97%AD_method_area
