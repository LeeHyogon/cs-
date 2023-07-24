Stateless와 Stateful을 뭉뚱그려서 이해하고 있어서, Jwt Token이 Stateless라는 정보를 보고 Jwt는 Stateless라고 잘못 이해를 했었다.

그런데 많은 검색결과 Stateless Stateful이라는 식으로, 뒤의 단어를 삭제하고 뭉뚱그려서 표현을 하면 안된다는 것을 알게 되었다.

### Stateless vs Stateful

이 두 개념을 나누는 명확한 기준이 무엇일까? 
답은 이전의 요청이 현재의 요청에 영향을 미치느냐이다. 

그렇다면 Jwt Token을 사용한 Login방식은 Stateless 일까? Stateful일까?

정답은 로그인이라는 요청이 존재하는 이상 Stateful (Protocol)이라고 하는 것이 정확하다.

그럼 왜 Jwt Token을 Stateless하다고 표현하는 걸까?

Google에 Jwt Stateless Authentication 라는 단어를 검색해본 후, 해답을 알 수 있게 되었다.

Login 요청을 포함하지 않고 Login 이후의 Authenticaion관점에서만 보면, 좁은 영역에서는 Stateless하다는 의미로 Stateless (Authentication)이라는 표현을 많이 사용하는 것으로 보이는데,

국내 웹사이트에서는 JWT를 Stateless (Authentication)하다.. 라는 식으로 표현을 하여,
개념에 혼동이 오는 것 같다. 

JWT는 Stateless하다.. 라고 표현하는 것은 명확하지 않고 헷갈릴 수 있는 표현이라고 결론을 내렸다. 

결론: JWT login 방식은 Stateless Authentication이라고 표현할 수 있으나, 거시적인 관점에선 Stateful Protocol이라고 봐야한다.

