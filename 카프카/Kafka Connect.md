# Kafka Connect
- 특별한 프로그래밍없이 Configuration으로 데이터를 이동
- Standalone mode, Distribution mode 지원
	
    - RESTful API 통해 지원(Postman, 웹브라우저uri값으로 커넥트관련 작업가능)   
    - Stream 또는 Batch 형태로 데이터 전송 가능
    - 커스텀 Connector를 통해 다양한 Plugin 제공(File,S3,Hive,Mysql,etc...)
    
 
![](https://velog.velcdn.com/images/gon109/post/2a307ecd-21b2-49cf-ae80-2e74bc584654/image.png)

- KafkaConnect Source: 데이터를 가져옴
- KafkaConnect Sink: 데이터를 보냄
- SourceSystem: 데이터를 가져와서 카프카 커넥트에 저장할때 관여함 
- Target System: 카프카 커넥터에 저장되어 있던 이 값을 다른 곳으로 Export할때 Target





ref https://www.inflearn.com/course/%EC%8A%A4%ED%94%84%EB%A7%81-%ED%81%B4%EB%9D%BC%EC%9A%B0%EB%93%9C-%EB%A7%88%EC%9D%B4%ED%81%AC%EB%A1%9C%EC%84%9C%EB%B9%84%EC%8A%A4/dashboard
