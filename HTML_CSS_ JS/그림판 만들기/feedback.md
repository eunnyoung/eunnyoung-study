### css

- display: none 과 visibility: hidden 의 차이는 무엇인가?
  <br/>=> display: none 은 아예 사라지게 하는 것으로, 보이지도 않고 렌더링도 되지 않는다.
  <br/>=> visibility: hidden 은 해당 요소가 시각화되지는 않지만, width, height 등으로 공간의 크기를 지정하였다면 그만큼 공백 렌더링한다.
- all: unset 이 이해가 안된다

### js

- 이건 문제는 아니고, 추가적으로 구현하고 싶은 기능인데, 텍스트를 submit 하면 그림판에 뜨게하고 싶다.
- js 기능이 전혀 적용되지 않는다.
  <br/>=> script 태그를 사용 안했다.
- ctx.lineWidth = lineWidth.value; 를 작성할 때
  <br/>자동 완성으로
  <br/>ctx.lineWidth=lineWidth.ariaValueMax;
  <br/>가 입력된다.
  <br/>=> value 타이핑 후에 esc 키를 치고 ; 을 붙인다.
- getContext() 메서드는 무엇인가?
  <canvas> 태그는 getContext() 메서드를 이용해서
  <br/>렌더링 컨텍스트와 (렌더링 컨텍스트의) 그리기 함수들을 사용할 수 있다.
- HTMLCanvasElement.getContext() 메소드는 캔버스의 드로잉 컨텍스트를 반환합니다.

### clickColor 함수가 계획했던 대로 기능하지 않는데 어떻게 해야 할까?

- 첫번째 시도,
  <pre>
  function clickColor(event) {
    const clickedColor = event.target.style.backgroundColor;
    ctx.strokeStyle = clickedColor;
    ctx.fillStyle = clickedColor;
    colorRange.value = clickedColor;
  }
  </pre>
  이렇게 작성했더니 컬러가 rgb 형태로 전달된다. 지정한 background-color 값을 가져오는 게 아니라 클릭된 div 의 컬러 값을 rgb 형태로 가져오는 것 같았다.
  그래서 input 인 colorRange 에 전달이 되지 않았다. hex 형태의 값만 받기 때문이다.
- 두번째 시도,(성공)
  <br/> 노마드 코더 원본 코드에 data-color 라는 속성이 있는데 나는 이 속성을 입력하지 않았다. 그래서 입력하고 dataset.color 값을 받아왔더니 제대로 기능한다.

### 1102_copy 폴더 파일은 제대로 실행되는데, 1105 폴더 파일의 js 기능은 왜 실행되지 않는가?

- 코드를 다음과 같이 수정했다.
<pre>
function onMove(event) {
  if (isDrawing) {
    // ctx.lineTo(event.offsetX, evnet.offsetY);
    ctx.lineTo(event.offsetX, event.offsetY);
    ctx.stroke();
    return;
  }
  ctx.moveTo(event.offsetX, event.offsetY);
}
// 에러가 난 코드
// colors.addEventListener((colorRange) =>
//   colorRange.addEventListener("click", clickColor)
// );
colors.forEach((colorRange) =>
  colorRange.addEventListener("click", clickColor)
);
</pre>
