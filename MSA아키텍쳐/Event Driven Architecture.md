
## Monolithic vs Microservice

#### Monolithic
- 단일 DB
- 트랜잭션 처리 ACID

#### Microservice
- 각 서비스마다 독립적인 언어,DB 선택 가능
- API를 통해 접근

![](https://velog.velcdn.com/images/gon109/post/51246c5b-1a7e-424e-ab97-ca11ed32cac2/image.png)
- JDBC와 같이 다이렉트 접근은 원칙적으로 x



# Event Driven Architecture
**Event Driven Architecture란?**
- 이벤트의 생산, 감지, 소비 및 반응 또는 시스템 상태의 중대한 변화를 지원하는 sw모델 또는 아키텍쳐 패러다임.
- 특정 서비스에서 다른 서비스가 관심을 가질 수 있는 일부 작업을 수행할 때 해당 서비스는 이벤트를 생성. 다른 서비스는 이벤트들을 전달받고 필요 시 자체 작업을 수행할 수 있다. REST와는 달리 이벤트를 통해 느슨한 구조로 요청을 생성하므로, 요청을 소비하는 서비스의 세부 정보를 알 필요가 없음

## Event Driven Microservice를 적용하는 이유

### 1) Database Per Service
 기존의 Shared Database 구성, 그 중 관계형 DB를 사용하는 경우 ACID 원칙에 따른 트랜잭션 처리, 데이터 무결성, 모든 테이블에 접근해 Join을 통한 통합 뷰 제공, 관계를 활용한 효율적인 데이터 저장,조회 등 DBMS 레벨에서 여러 유용한 기능을 제공

MSA에서 Database Per Service를 적용하면 DBMS레벨에서 제공하던 기능을 애플리케이션 레벨에서 해결해야 함. 

EDM은 애플리케이션 레벨에서 최종 일관성을 지원해 트랜잭션 처리를 수행하는 것에 적합하며 서비스의 목적에 최적화된 DB를 선택하는 것에 도움을 준다.

> Data Per Service 패턴이란 
![](https://velog.velcdn.com/images/gon109/post/917b4659-f86d-4bfc-b504-7ce0eeceb3c2/image.png)
다음과 같이 개벌 데이터 스토어는 다른 서비스에 직접 Access 불가능. 영구 데이터는 API로만 엑세스 할 수 있음.


### 2) 트랜잭션 처리

 기존 Monolithic 시스템에서 문제 발생 시 일관된 commit 또는 롤백 처리나 이전에 발생한 상태 변경에 직접 접근해서 데이터 수정이 가능. 하지만 MSA가 적용된 시스템에서는 서로 다른 서비스에 걸쳐진 기능을 수행하는 도중 일관된 commit 또는 롤백을 수행할 수 없다. 이때 EDM을 적용해 롤백 또는 재시도하여 처리가 가능. 

### 3) 반정규화 데이터의 동기 처리

MSA가 적용된 시스템에서는 비즈니스 로직과 이를 수행하는 필요 데이터가 서로 다른 서비스에 나누어져 있을 수 있다. 이때 EDM을 적용해 서비스 간 데이터 동기 처리 수행 가능

### 4) 최종 일관성(Eventually Consistency)

기존 DMBS를 활용한 ACID 트랜잭션에 따른 데이터 무결성 보장은 MSA에서 서비스, DB가 나누어 가짐으로써 더는 달성할 수 없다. 대신 EDM을 사용해 데이터의 최종적인 일관성 유지로 변경됨.



## MSA에서 kafka를 활용한 트랜잭션


### Commit 트랜잭션
- Atomicity, Consistency -> Commit Transaction


![](https://velog.velcdn.com/images/gon109/post/9be3a052-c00a-4091-bc30-9adcc15df7d0/image.png)

- 주문을 했을 때, 발생했었던 주문 데이터를 바로 DB에 반영하는게 아니라 일단 PENDING(대기)상태로 만듬

![](https://velog.velcdn.com/images/gon109/post/3cd94784-4b4a-47b4-a564-0b31a9c14680/image.png)

- 수량을 체크하고 주문이 가능한 재고가 남아있다면 데이터를 업데이트.

![](https://velog.velcdn.com/images/gon109/post/148fd5a4-6bc6-40e7-a48a-da2628ea510f/image.png)

- 업데이트한 이벤트를 kafka에 전달

![](https://velog.velcdn.com/images/gon109/post/edbb2fc1-8f76-47ab-92c0-2ecc9c38401e/image.png)

- 이렇게 전달된 메세지를 확인 후 PENDING상태를 CONFIRMED로 변경.

### Rollback Transaction


![](https://velog.velcdn.com/images/gon109/post/0aa19f1d-d859-40a7-aa23-a30bdd8d00c4/image.png)
- 재고를 확인한 경우, 주문이 불가능한 것을 확인. UPDATE하지 않음.
![](https://velog.velcdn.com/images/gon109/post/2b80cd5c-ce65-4c82-a381-d9fe2a3391b8/image.png)
- kafka에 거절했다는 메세지를 전송

![](https://velog.velcdn.com/images/gon109/post/a35e321b-1f14-4ca3-a426-fa33ad22b512/image.png)
- 자신이 갖고있었던 PENDING상태를 CANCELED상태로 변경하면서, MSA라더라도 롤백을 구현 가능




ref https://bsssss.tistory.com/1053 <br>

ref https://www.samsungsds.com/kr/insights/msa_architecture_edm.html <br>
ref https://www.inflearn.com/course/%EC%8A%A4%ED%94%84%EB%A7%81-%ED%81%B4%EB%9D%BC%EC%9A%B0%EB%93%9C-%EB%A7%88%EC%9D%B4%ED%81%AC%EB%A1%9C%EC%84%9C%EB%B9%84%EC%8A%A4/dashboard
