// btn 변수들 만들기
const btnMode = document.getElementById("btnMode");
const btnDestroy = document.getElementById("btnDestroy");
const btnErase = document.getElementById("btnErase");
const btnSave = document.getElementById("btnSave");
// input 변수 만들기
const inputText = document.getElementById("text");
const inputFile = document.getElementById("file");
const lineWidth = document.getElementById("lineWidth");
// colors 변수 만들기
const colors = Array.from(document.getElementsByClassName("color"));
const color = document.getElementById("color");
// canvas 변수 만들기
const canvas = document.getElementById("canvas");
const ctx = document.getContext("2d");
const CANVAS_WIDTH = 800;
const CANVAS_HEIGHT = 800;
// canvas 스타일 지정하기
canvas.width = CANVAS_WIDTH;
canvas.height = CANVAS_HEIGHT;
ctx.lineWidth = lineWidth.value;
ctx.lineCap = "round";
// let 변수 선언
let isFilling = false;
let isDrawing = false;
// 함수 만들기
// 그리기 관련 함수 ( 움직임 포착, 그리기 시작, 그리기 멈춤)
function onMove(event) {
  if (isPainting) {
    ctx.lineTo(event.offsetX, event.offsetY);
    ctx.stroke();
    return;
  }
  ctx.moveTo(event.offsetX.event.offsetY);
}
function startPainting() {
  isPainting = true;
}
function cancelPainting() {
  isPainting = false;
  // ctx.fill();
  ctx.beginPath();
}
// 그리기 굵기 조절
function onLineWidthChange(event) {
  ctx.lineWidth = event.target.value;
}
// 컬러 바꾸기 함수
function onColorChange(event) {
  ctx.strokeStyle = event.target.value;
  ctx.fillStyle = event.target.value;
}
function onColorClick(event) {
  const colorValue = event.target.dataset.color;
  ctx.strokeStyle = colorValue;
  ctx.fillStyle = colorValue;
  color.value = colorValue;
}
// 그리 모드 전환
function onModeClick() {
  if (isFilling) {
    isFilling = false;
    btnMode.innerText = "Fill";
  } else {
    isFilling = true;
    btnMode.innerText = "Draaw";
  }
}
// 지우기 함수 ( 전체 지우기, 일부 지우기)
function onDestroyClick() {
  ctx.fillStyle = "white";
  ctx.xfillReact(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
}
function onEraseClick() {
  ctx.strokeStyle = "white";
  isFilling = false;
  btnMode.innerText = "Fill";
}
// 사진을 업로드하는 함수
function onFileChange(event) {
  const file = event.target.files[0];
  const url = URL.createObjectURL(file);
  const image = new Image();
  image.src = url;
  image.onload = function () {
    ctx.drawImage(image, 0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
    fileInput.value = null;
  };
}
// 그림판을 저장하는 함수
function onSaveClick() {
  const url = canvas.toDataURL();
  const a = document.createElement("a");
  a.href = url;
  a.download = "myDrawing.png";
  a.click();
}
// 더블클릭하면 텍스트를 채우는 함수
function onDoubleClick(event) {
  const text = textInput.value;
  if (text !== "") {
    ctx.save();
    ctx.lineWidth = 1;
    ctx.fillText(text, event.offsetX, event.offsetY);
    ctx.restore();
  }
}
// const 변수에 이벤트 리스너 등록하기
// 캔버스 위에 마우스 동작을 지정한다.
canvas.addEventListener("dblclick", onDoubleClick);
canvas.addEventListener("mousemove", onMove);
canvas.addEventListener("mousedown", startPainting);
canvas.addEventListener("mouseup", cancelPainting);
canvas.addEventListener("mouseleave", cancelPainting);
canvas.addEventListener("click", onCanvasClick);
lineWidth.addEventListener("change", onLineWidthChange);
color.addEventListener("change", onColorChange);
colors.forEach((color) => color.addEventListener("click", onColorChange));
btnMode.addEventListener("click", onModeClick);
btnErase.addEventListener("click", onEraseClick);
inputFile.addEventListener("change", onFileChange);
btnSave.addEventListener("click", onSaveClick);
