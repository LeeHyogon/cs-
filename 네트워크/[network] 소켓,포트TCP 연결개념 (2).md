# 개요
- 네트워크 프로그래밍 관점에서 분석

## 소켓
- 애플리케이션이 시스템의 기능을 함부로 쓸 수 없다.
- 대신 시스템은 애플리케이션이 네트워크 기능을 사용할 수 있도록 프로그래밍 인터페이스를 제공
- 애플리케이션은 socket을 통해 데이터를 주고 받는다
- 개발자는 socket programming을 통해 네트워크 상의 다른 프로세스와 데이터를 주고 받을 수 있도록 구현한다
- 대부분의 시스템은 socket 형태로 네트워크 기능 제공

### 실제 구현/동작 관점
- prot(number)는 socket을 식별하기 위해 부여되는 숫자
- 실제구현에서 socket은 <protocol, IP address, port number>로 정의된다.

<protocol, IP address, port number>는 유니크하게 식별되는가?
- 프로토콜 스펙을 시스템 레벨에서 구현하면서 조금 달라짐. UDP는 Ip address와 port number로 유니크하게 식별이 가능하나, TCP는 안됨.


### TCP socket 동작 방식

![image](https://github.com/LeeHyogon/cs-/assets/45483116/dbe9ee8b-79df-46b4-b91d-35b240e78c12)

- connection 연결 요청 : listening socket으로
- connectino이 성립된 이후: <src IP, src port, dest IP, dest port>
- 새로운 port number를 할당해서 connection을 연결하지만 모든 포트 넘버를 가지고 있는 경우, 서로 다른 socket이 동일한 IP와 port를 가지는 것이 가능!

TCP socket은 <IP,port>만으로는 유니크하게 식별할 수 없다
하지만 TCP 표준에서는 TCP socket은 <IP,port>가 유니크해야 한다고 이야기함. 개념과 구현의 불일치.
### UDP socket 동작 방식

- UDP socket에서 데이터를 보낼 때 어느 UDP socket으로 보낼지 지정할 수 있다.
- UDP socket에서 데이터를 읽을 때 어느 UDP socket으로부터 왔는지 알 수 있다.

### Port number
- 16 bits로 이루어진 숫자 (0~65535)
- 0~1023: well-known ports, system ports ex) http(80), https(443), dns(53)
- 1024~49151: registered ports (IANA에 등록된 번호) ex) mysql DB(3306), apache tomcat server(8080)
- 나머지. 등록안된.등등






