# Event Sourcing
- 데이터의 마지막 상태만 저장하는 것이 아닌, 해당 데이터에 수행된 전체 이력을 기록
- 데이터 구조 단순(insert만 존재)
- 데이터의 일관성과 트랜잭션 처리 가능
- 데이터 저장소의 개체를 직접 업데이트 하지 않기 때문에 동시성에 대한 충돌 문제 해결
![image](https://github.com/LeeHyogon/cs-/assets/45483116/de58ecd2-18ac-43d2-b3a8-836b4e4a6275)


#### 도메인 주도 설계
- Aggregate
- Projection
#### 메시지 중심의 비동기 작업 처리
#### 단점
- 모든 이벤트에 대한 복원 -> 스냅샷 (1000개의 이벤트중 100개 200개 이런식으로 자름) 
- 다양한 데이터 조회 -> CQRS

![image](https://github.com/LeeHyogon/cs-/assets/45483116/98c826ef-ec04-4ddc-9d82-01866c125cd4)

# CQRS (Command and Query Responsibility Segregation)
- 명령과 조회의 책임 분리
- 상태를 변경하는 Command
- 조회를 담당하는 Query

![image](https://github.com/LeeHyogon/cs-/assets/45483116/fe41cc45-2bc4-4574-9350-0cb0d4caec96)
- 모든 이벤트를 Event Store에 저장
- Event Handler(kafka)가 이벤트를 캐치하고 DB에 그 값을 반영 시킴
- 이렇게 반영된 상태값만 가져간다면, 상태변경하는 부분과 조회하는 부분이 분리가 됨

![image](https://github.com/LeeHyogon/cs-/assets/45483116/45839c8a-f283-4c6a-98cc-5fda46b49600)

# Saga pattern 
- Application 에서 Transcation 처리
- Application이 분리된 경우에 각각의 Local transaction만 처리
- 각 App에 대한 연속적인 Transaction에서 실패할 경우 Rollback 처리 구현 -> **보상 Transaction**
- 데이터의 원자성을 보장하지 않지만, 일관성을 보장


![image](https://github.com/LeeHyogon/cs-/assets/45483116/7d663c84-88cc-449e-99cf-ed5f7448964d)


### Choreography-based saga(개별 서비스 처리형)

![image](https://github.com/LeeHyogon/cs-/assets/45483116/68ef0bf8-b0f7-4bba-8bb7-bed15820d22f)

1) 주문 서비스에서 주문 요청(POST)을 수신하고 PENDING 상태의 주문 생성
2) 주문 생성 이벤트 전달
3) 고객 서비스의 Event handler가 Credit 예약 시도
4) 결과 이벤트 전달
5) 주문 서비스의 Event handler를 통해 주문 승인 or 거부

### Orchestration-based saga(중앙 집중형)
![image](https://github.com/LeeHyogon/cs-/assets/45483116/337b5796-d375-41ec-a7d4-07e0435411bf)

1) 주문 서비스 주문 요청(POST)을 수신하고 Create Order saga orchestrator 생성
2) Order saga orchestrator가 PENDING 상태의 주문 생성
3) Credit 예약 명령을 고객 서비스에 전달
4) 고객 서비스가 Credit 예약 처리
5) 결과 메시지 전달
6) Order saga orchestrator에서 주문의 승인 or 거부





ref https://www.inflearn.com/course/lecture?courseSlug=%EC%8A%A4%ED%94%84%EB%A7%81-%ED%81%B4%EB%9D%BC%EC%9A%B0%EB%93%9C-%EB%A7%88%EC%9D%B4%ED%81%AC%EB%A1%9C%EC%84%9C%EB%B9%84%EC%8A%A4&unitId=72521
