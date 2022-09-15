## 해당 폴더는 노마드 코더의 그림판 만들기 코드를 실습하는 폴더이다.

## css 적인 문제

- textbox 안의 placeholder를 좀 더 예쁘게 배치하고 싶다.
- all: unset 이 이해가 안된다..
- transition: opacity linear 는 어떻게 설정하지?

## js 적인 문제

- save 가 안된다.
- 이건 문제는 아니고, 추가적으로 구현하고 싶은 기능인데, 텍스트를 submit 하면 그림판에 뜨게하고 싶다.
- ctx.lineWidth = lineWidth.value; 를 작성할 때
  자동 완성으로
  ctx.lineWidth=lineWidth.ariaValueMax;
  가 입력되는 문제

## 문제&해결

- js 기능이 전혀 적용되지 않는 문제.
  => script 태그를 사용 안했다..
- label 안의 텍스트가 제대로 정렬 되지 않는다. => isFilling 을 모두 false 값을 줘서 동작이 제대로 안 됐던 거다.

function onModeClick() {
if (isFilling) {
isFilling = false;
btnMode.innerText = "Fill";
} else {
isFilling = true; //isFilling = false;
btnMode.innerText = "Draw";
}
}
