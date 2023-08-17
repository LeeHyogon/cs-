
# HTTP란?
- 인터넷에서 데이터를 주고받을 수 있는 프로토콜
- 초기에는 웹브라우저와 웹 서버 간의 커뮤니케이션을 위해 디자인되었지만, 최근에는 모바일 app 및 IoT등과의 커뮤니케이션과 같이 다른 목적으로도 사용
- HTTP 클라이언트가 요청을 생성하기 위한 연결을 연 다음 응답을 받을 때까지 대기하는 클라이언트-서버 모델을 따른다.
- HTTP는 stateless protocol이며, 이는 서버가 두 요청 간에 어떠한 상태나 데이터를 유지하지 않음을 읨. 

## 1. HTTP 1.0
- 브라우저 친화적인 프로토콜
- 요청 및 응답에 대한 메타 데이터를 포함하는 헤더 필드 제공(Status code,Content-Type 등)
- Reponse: Content-Type에 Http 파일 외에도 script,스타일 시트, 미디어 등을 전송 가능
- Method: GET, HEAD, POST
- Connection 특성: 응답 직후 종료
![](https://velog.velcdn.com/images/gon109/post/3eb27dc9-dce5-4deb-ae60-d76a3bb76692/image.png)

#### 단점
- 각 모든 요청에 따라 새로운 커넥션, 응답이 전송된 후 즉시 닫으므로 새로운 커넥션이 설정될 때마다 TCP 3-way handshake가 발생


## 2. HTTP 1.1 (default keep-alive)
- 가장 많이 사용되는 버전
- Method: GET, HEAD, POST, PUT, DELETE, TRACE, OPTIONS

### HTTP 1.1 Keep Alive와 Pipeline
![](https://velog.velcdn.com/images/gon109/post/cdb6a971-3771-4be5-89d9-93067230743d/image.png)

### HTTP 1.0 "Closed" vs HTTP 1.1 "Keep-Alive"
- HTTP 1.0: TCP Connection은 HTTP 요청마다 3-way Handshake와 TearDown을 반복
- HTTP 1.1: 하나의 TCP Connection이 열려있으면 (Established 상태), 그 연결을 통해 여러 Request에 대한 Reponse를 받을 수 있다.

### HTTP Pipelining

![](https://velog.velcdn.com/images/gon109/post/1f9cee6a-44ff-4151-81e8-234e57360908/image.png)

- HTTP 1.1로 스펙이 업그레이드 되면서 클라이언트-서버 간 요청과 응답의 효율성을 개선하기 위해 만들어진 개념
- Reuqest들은 연속적으로 발생하며, 순차적으로 동작한다.
-   HTTP/1.1 에서는 다수의 HTTP Request들이 각각의 서버 소켓에 Write된 후, Browser는 각 Request들에 대한 Response들을 순차적으로 기다리는 문제를 해결하기 위해 여러 요청들에 대한 응답 처리를 뒤로 미루는 방법을 사요
- 즉, 클라이언트는 각 요청에 대한 응답을 기다리지 않고, 여러 개의 HTTP Request를 하나의 TCP/IP Packet으로 연속적으로 Packing해서 요청을 보낸다.
- 파이프 라이닝이 적용되면, **하나의 커넥션으로 다수의 Request와 Response를 처리할 수 있게끔 Network Latency를 줄일 수 있다**

#### 단점: Head Of Line Blocking (HOL 블로킹)
![](https://velog.velcdn.com/images/gon109/post/941b2227-bf53-4012-8dc3-81533b1dc713/image.png)
- 다음과 같이 응답처리를 미루는 방식이므로, 각 응답의 처리는 순차적으로 처리되며 결국 후순위의 응답은 지연된다.
- HTTP/2가 등작하면서 멀티플렉싱 알고리즘으로 대체되며 파이프라이닝은 사용 x.



## 3. HTTP 2.0

### Frame & Stream & Messages
- 기존에 Plain Text(평문)를 사용하고, 개행으로 구별되던 HTTP/1.x 와 달리, 바이너리 포맷으로 인코딩된 Message, Frame으로 구성된다.
![](https://velog.velcdn.com/images/gon109/post/d0cc44c8-a84d-490d-b81b-e883ad7cf289/image.png)

![](https://velog.velcdn.com/images/gon109/post/8a40ad36-cffb-4cbf-a0e2-e2526cfe1a14/image.png)

- Stream: 구성된 연결 내에서 전달되는 바이트의 양방향 흐름, 하나 이상의 메시지가 전달 가능
- Message: Message: 논리적 요청 또는 응답 메시지에 매핑되는 프레임의 전체 시퀀스
- Frame: HTTP/2에서는 통신의 최소 단위, 각 최소 단위에는 하나의 프레임 헤더가 포함된다.
이 프레임 헤더는 최소한으로 프레임이 속하는 스트림을 식별함. HEADERS Type Frame, DATA Type Frame이 존재.


### HTTP Header Data Compression(HTTP 헤더 데이터 압축)
- 이전 Header의 내용과 중복되는 필드를 재전송 하지 않도록 하여, 데이터를 절약함.
- 또한, 기존에 HTTP Header가 Plain Text(평문)이었지만, HTTP/2에서는 Huffman Coding을 사용하는 HPACK이라는 Header 압축방식을 이용하여 데이터 전송 효율을 높힘


![](https://velog.velcdn.com/images/gon109/post/4d48cca4-f30e-4371-b59b-1167e93850eb/image.png)
#### Server Push 
- 클라이언트가 요청하지 않은 JavaScript, CSS, Font, 이미지 파일 등과 같이 필요하게 될 특정 파일들을 서버에서 단일 HTTP 요청 응답 시 함께 전송 가능

### Multiplexing: HTTP 1.x의 HOL(Head-of-Line) Blocking 문제 해결
- HTTP/1.1 까지는 한번에 하나의 파일만 전송이 가능했다. 이로인해 여러 파일을 전송할 경우, 선행하는 파일의 전송이 늦어지면, 전체 파일 전송의 시간이 늘어나는 문제가 발생
- HTTP/2에서는 여러 파일을 한번에 병렬 전송하여, 문제 해결 
- 동시에 여러 개의 컨텐츠를 받는 것은 동일하지만, queue와 같은 기술을 통해서 하나의 connection만으로 컨텐츠를 동시에 받을 수 있도록 함.

#### Stream 우선순위
* HTTP 메시지가 많은 개별 프레임으로 분할될 수 있고, 여러 스트림의 프레임을 Multiplexing할 수 있게되면서, 스트림들의 우선순위를 지정할 필요가 생겼다.
  * 클라이언트는 우선순위 지정 트리를 사용하여 서버의 스트림 처리 우선순위를 지정할 수 있다.

ref https://hirlawldo.tistory.com/106
ref https://jins-dev.tistory.com/entry/HTTP11-%EC%9D%98-HTTP-Pipelining-%EA%B3%BC-Persistent-Connection-%EC%97%90-%EB%8C%80%ED%95%98%EC%97%AC
ref https://velog.io/@taesunny/HTTP2HTTP-2.0-%EC%A0%95%EB%A6%AC
