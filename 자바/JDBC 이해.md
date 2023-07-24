## JDBC 이해
### JDBC 등장 이유
- 애플리케이션을 개발할 때 중요한 데이터는 대부분 DB에 보관

![](https://velog.velcdn.com/images/gon109/post/9cbd751c-03d6-4e3b-9ada-abefe24d8ee4/image.png)


- 클라이언트가 애플리케이션 서버를 통해 데이터를 저장하거나 조회하면, 애플리케이션 서버는 다음 과정을 통해 DB를 사용한다.

![](https://velog.velcdn.com/images/gon109/post/ad5809a4-8fbc-4086-b3b2-cd3fb24bc491/image.png)

1. 커넥션 연결: 주로 TCP/IP를 사용해서 커넥션을 연결
2. SQL 전달: 애플리케이션 서버는 DB가 이해할 수 있는 SQL을 연결된 커넥션을 통해 DB에 전달
3. 결과 응답: DB는 전달된 SQL을 수행하고 그 결과를 응답한다. 애플리케이션 서버는 응답 결과 활용

### 문제점

- 각각의 DB마다 커넥션을 연결하는 방법, SQL을 전달하는 방법 결과를 응답 받는 방법이 모두 다름.

1. DB를 다른 종류의 DB로 변경하면 DB사용 코드도 함께 변경해야함
2. 각각의 DB마다 커넥션 연결, SQL 전달, 결과 응답 받는 방법 새로 학습해야 함.

**JDBC라는 자바 표준이 등장**


### JDBC 표준 인터페이스

- JDBC는 자바에서 DB에 접속할 수 있도록 하는 자바 API

![](https://velog.velcdn.com/images/gon109/post/8dcf1226-3cd9-426e-86c4-5a3025f3e70e/image.png)


대표적으로 다음 3가지 기능을 표준 인터페이스로 정의해서 제공

- java.sql.Connection: 연결
- java.sql.Statement: SQL을 담은 내용
- java.sql.ResultSet: SQL요청 응답

**JDBC 드라이버**
- JDBC인터페이스를 각각의 DB 벤더(회사)에서 자신의 DB에 맞도록 구현해서 라이브러리로 제공

![](https://velog.velcdn.com/images/gon109/post/ca2fd3e2-39eb-4daf-9515-eb2e82aa9355/image.png)


### 정리

1. DB를 다른 종류의 DB로 변경하면서 서버의 DB 사용 코드를 변경하지 않게 됨.
2. 개발자는 JDBC 표준 인터페이스 사용법만 학습하면 됨.

## JDBC와 최신 데이터 접근 기술

- SQL Mapper
- ORM

### SQL Mapper

![](https://velog.velcdn.com/images/gon109/post/98a49a8c-36c6-4418-a1f2-98ed9f8b0a10/image.png)


장점
- JDBC를 편리하게 사용하도록 도와줌
- JDBC의 반복 코드 제거
단점
- 개발자가 SQL을 직접 작성
대표 기술
- JdbcTemplate,MyBatis

### ORM

![](https://velog.velcdn.com/images/gon109/post/f9046279-7389-4917-89e1-1c08dabc1233/image.png)


- 객체를 관계형 DB 테이블과 매핑해주는 기술
- 반복적인 SQL을 직접 작성하지 않게 해줌
대표 기술
- JPA,Hibernate
- JPA는 자바 진영의 ORM 표준 인터페이스이고, 구현체는 Hibernate



