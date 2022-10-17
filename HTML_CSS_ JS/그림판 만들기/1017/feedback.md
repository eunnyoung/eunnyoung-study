### 문제

- function 들이 모두 작동을 안한다 ㅠㅠ 왜지..
  다른 사람한테 물어보기라도 해야한다..
- <pre>
  // color.addEventListener("change", changeColor);
  colorRange.addEventListener("change", changeColor);
  // colors.addEventListener((color) => color.addEventListener("click", clickColor));
  colors.forEach((color) => color.addEventListener("click", clickColor));
  </pre>
  원래 코드를 주석처리하고 그 아래의 코드로 바꿨더니,
  몇 함수들은 정상 동작한다.
  개발자 도구를 열어 어디에서 에러가 났는지 확인했다.
  Erase, Save, Destroy 기능은 작동하지만,
  선을 그리는 기능은 동작하지 않는다.
