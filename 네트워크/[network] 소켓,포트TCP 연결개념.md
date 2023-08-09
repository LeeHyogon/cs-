## 개요

#### OSI 7layer
- 네트워크 시스템 구성을 위한 범용적이고 개념적인 모델
- ISO/IEC에서 OSI 모델 관리
#### TCP/IP stack
- 인터넷이 발명되면서 함께 개발된 프로토콜 스택
- IEFT에서 인터넷 표준을 관리(RFC)

두 개념은 혼용
IP는 network layer
TCP,UDP는 transport layer
라고도 할 수 있다.

## TCP/IP stack

![image](https://github.com/LeeHyogon/cs-/assets/45483116/aca3a715-1cbc-495f-8751-86d675d62aa0)

- 아래 3 계층은 하드웨어/펌웨어, OS레벨에서 구현/관리
- 네트워크 기능을 **지원**하는데 목적
- application layer는 네트워크 기능을 **사용**하는데 목적
- 소켓과 포트는 app과 transport 사이에 있는 개념

![image](https://github.com/LeeHyogon/cs-/assets/45483116/4ff03642-5175-49a3-929a-e021fab9ac74)
- 아래 3계층을 단순화해서 다음과 같이 표현할 수 있다.


## port
![image](https://github.com/LeeHyogon/cs-/assets/45483116/897e5bda-fdd3-49ae-912c-98a5055d072f)

- process와 연결된 data path 혹은 data channel
- 인터넷 프로토콜인 TCP/IP를 사용할 때에는 클라이언트 프로그램이 네트워크 상의 특정 서버 프로그램을 지정하는 방법으로 사용
- port name을 통해 식별 (port에 name을 부여하는 방법은 system마다 다름)

![image](https://github.com/LeeHyogon/cs-/assets/45483116/e44672fe-fb05-4e51-b874-93c4f6b58df1)

- 인터넷 프로토콜은 unreliable 하다. 데이터가 손실될수도 순서가 보장되지 않음.
- 프로세스와 프로세스 사이에 통신할 때, 정확하게 데이터를 받는게 중요하므로, 프로세스 간의 통신에서 데이터를 reliable로 주고 받을 수 있는 프로토콜이 필요. -> TCP의 탄생

#### TCP
- 데이터를 reliable하게 주고 받을 수 있는 프로토콜

#### Connection
- TCP에서의 Connection은 프로세스 간의 안정적이고 논리적인 통신 통로를 의미
- 두 프로세스의 통신은 connection을 열고 3-way handshake. connection 종료 시 4-way handshake. 
- connection-oriented: 커넥션 기반 통신

#### 포트 식별
- 프로세스 간 통신에서 port는 어떻게 찾아가지? 인터넷상에서 port를 어떻게 unique하게 식별할 것인가?-> port(number)정의
- port(number) 정의: 16bits로 이루어진 숫자(0~65535)
- internet address(ip address) 로 각 host를 유니크하게 식별할 수 있다.
**Socket** :internet address + port number . 인터넷 상에 존재하는 각 port를 유니크하게 식별하기 위한 주소. **각 socket은 인터넷 상에서 유니크하다**

## Connection & Socket
- 각 connection을 유니크하게 식별할 수 있어야 한다
- 한 쌍의 socket은 connection을 유니크하게 식별한다
- 결론: A클라이언트의 소켓, B클라이언트의 소켓의 쌍으로 커넥션을 유니크하게 식별할 수 있음.
- <src internet addr, src port, dest internet addr, dest port>
- 하나의 socket은 동시에 여러 connection들에게 사용될 수 있다.

### UDP
- connectionless protocol: 연결을 맺지 않고 바로 데이터를 주고 받는다
- unreliable: internet protocol을 거의 그대로 사용. 간단한 에러 체크.
- UDP 표준을 보면 socket 단어가 등장하지 않는다. 개념이 생긴 뒤 자연스럽게 사용?
- <protocol, ip address, port number>로 유니크하게 식별


### 주의 사항
- 실제로 네트워크 프로그래밍 할 때는 소켓의 개념과 의미가 미묘하게 다름
- 특히 소켓을 식별하는 방법에 큰 차이가 있다.







ref https://www.youtube.com/watch?v=X73Jl2nsqiE&t=428s
