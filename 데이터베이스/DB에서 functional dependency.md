
# functional dependency
- 한 테이블에 있는 두 개의 attribute(s) 집합(set)사이의 제약(constraint)



![](https://velog.velcdn.com/images/gon109/post/e33b4bea-47b7-4537-a4b5-3c2846c19b53/image.png)
- X-> Y 
- 집합 X가 집합 Y를 결정한다


### FD 파악하기
- 테이블의 스키마를 보고 의미적으로 파악해야 함.
- 테이블의 state를 보고 FD를 파악해서는 안된다.
![](https://velog.velcdn.com/images/gon109/post/ff7aae1d-3ffe-4e9b-8d63-78920802edad/image.png)


### FD 예시

![](https://velog.velcdn.com/images/gon109/post/58f5f363-0940-4ad6-8cc3-788f6d84c4d6/image.png)

- {X}->{Y} 라고 {Y}->{X}를 의미하지는 않는다.
- {}->Y : 공집합이 Y집합을 결정한다?-> Y값은 언제나 하나의 값만을 가진다는 의미
![](https://velog.velcdn.com/images/gon109/post/7d0d1ecd-3fad-4415-bbcc-2d8ba684405b/image.png)

### Trivial functional dependency

- X->Y가 유효할 떄, 만약 Y가 X의 부분 집합이라면 **trivial FD**
- {a,b,c} -> { c } is trivial FD
- {a,b,c} -> { a,c } is trivial FD
- {a,b,c} -> { a,b,c } is trivial FD

### Non-trivial fd
- X->Y일 때 Y가 X의 부분집합이 아닐때 **non-trivial**
- {a,b,c} -> {b,c,d} is non-trivial FD
- {a,b,c} -> {d,e} is non-trivial FD -> 이 두 집합은 공통된 attribute가 없음(completely no-trival FD)

### partial FD
- X->Y 일 때, X집합에 대해서 X의 그 **어떤** 부분집합도 Y를 결정지을 수 있으면 **partial FD**

X의 부분집합(proper subset)은 {a,b,c}에서
- {a,c}, {a}, {} 는 모두 proper subset
- {a,b,c}는 X의 proper subset이 아님.

예시)
- {empl_id,empl_name} -> {birth_date}일 때, 
- {empl_id} -> {birth_date} 가능 (partial FD로 볼 수 있다)

### Full functional dependency
- X->Y일 때, X의 **모든** 부분집합이 Y를 결정지을 수 없다면, **full FD**

예시)
- {stu_id, class_id} -> {grade}
- {stu_id}, {class_id} ,{} 는 grade를 결정짓지 못함

### 참고 사항
- Armstrong's axioms, Closure, minimal cover와 같은 추가내용도 존재(too much?)






ref https://www.youtube.com/watch?v=fw8hvolebLw&t=13s
