## 해당 폴더는 노마드 코더의 그림판 만들기 코드를 실습하는 폴더이다.

## css 적인 문제

- display: hidden 과 display: none 의 차이는 무엇인가?
- textbox 안의 placeholder를 좀 더 예쁘게 배치하고 싶다.
- all: unset 이 이해가 안된다..

## js 적인 문제

- lineWidth 조절 기능 외에는 정상 작동이 안된다.
- 이건 문제는 아니고, 추가적으로 구현하고 싶은 기능인데, 텍스트를 submit 하면 그림판에 뜨게하고 싶다.

## 문제&해결

- js 기능이 전혀 적용되지 않는다.
  <br/>=> script 태그를 사용 안했다.
- ctx.lineWidth = lineWidth.value; 를 작성할 때
  <br/>자동 완성으로
  <br/>ctx.lineWidth=lineWidth.ariaValueMax;
  <br/>가 입력된다.
  <br/>=> value 타이핑 후에 esc 키를 치고 ; 을 붙인다.
- getContext() 메서드는 무엇인가?
  <pre><canvas></pre>요소는 getContext() 메서드를 이용해서
  <br/>렌더링 컨텍스트와 (렌더링 컨텍스트의) 그리기 함수들을 사용할 수 있다.

## 공부 내용

- HTMLCanvasElement.getContext() 메소드는 캔버스의 드로잉 컨텍스트를 반환합니다.
