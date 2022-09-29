### 토큰 token 이란?

- 클라이언트의 유니크한 정보가 담긴 암호화 데이터다.
- 토큰을 이용해 서버가 각각의 클라이언트를 구별할 수 있다.

### 최근 자주 쓰이는 토큰: JWT (JSON WEB Token)

- JWT 는 JSON 형식의 토큰을 만들 수 있는 Node.js 패키지다.
- JWT 는 stateless 방식이다.
- JWT 는 iat(생성 시각), exp(expire, 유효 기간) 정보 등이 담겨 있다.

### stateless, stateful 방식

- stateless 는 서버에서 http 같은 client 의 이전 상태를 기록하지 않는 접속이고,
  stateful 은 서버에서 client 의 이전 상태를 기록하는 접속이다.
- 출처: https://russwest.tistory.com/40

### 세션

- 토큰을 안 쓰면 세션에 저장하게 되는데
  세션 저장은 유저가 로그인 상태일 때 인증 정보를 세션에 모두 저장하고 있는 방식이다.

- 관련 링크: https://velog.io/@dnjscksdn98/JWT-JSON-Web-Token-%EC%86%8C%EA%B0%9C-%EB%B0%8F-%EA%B5%AC%EC%A1%B0
