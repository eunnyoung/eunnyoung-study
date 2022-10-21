let isDrawing = false;
let isFilling = false;
const colors = Array.from(document.getElementsByClassName("color"));
const color = document.getElementsByClassName("color");
const colorRange = document.getElementsByClassName("colorRange");
const lineWidth = document.getElementById("lineWidth");
const text = document.getElementById("text");
const file = document.getElementById("file");
const btnMode = document.getElementById("btnMode");
const btnDestroy = document.getElementById("btnDestroy");
const btnErase = document.getElementById("btnErase");
const btnSave = document.getElementById("btnSave");
const canvas = document.querySelector("canvas");
const CANVAS_WIDTH = 800;
const CANVAS_HEIGHT = 800;
ctx.width = CANVAS_WIDTH;
ctx.height = CANVAS_HEIGHT;
// 못 쓴 변수
const ctx = canvas.getContext("2d");
ctx.lineCap = "round";
// 함수
function onMove(event) {
  if (isPainting) {
    ctx.lineTo(event.offsetX, event.offsetY);
    ctx.stroke();
    return;
  }
  ctx.moveTo(event.offsetX, event.offsetY);
}
function clickCanvas() {
  if (isFilling) {
    ctx.fillRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
  }
}
function clickDouble(event) {
  const text = text.value;
  if (text !== "") {
    ctx.save();
    ctx.lineWidth = 1;
    ctx.font = "68px sans-serif";
    ctx.fillText(text, event.offsetX, event.offsetY);
    ctx.restore();
  }
}
function clickColor(event) {
  const colorValue = event.target.dataset.color;
  ctx.strokeStyle = colorValue;
  ctx.fillStyle = colorValue;
  color.value = colorValue;
}
function clickDestory() {
  ctx.fillStyle = "white";
  ctx.fillRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
}
function clickErase() {
  ctx.strokeStyle = "white";
  isFilling = false;
  btnMode.innerText = "Fill";
}
function clickSave() {
  const url = canvas.toDataURL();
  const a = document.createElement("a");
  a.href = url;
  a.download = "myDrawing.png";
  a.click();
}
function clickMode() {
  if (isFilling) {
    isFilling = false;
    btnMode.innerText = "Fill";
  } else {
    isFilling = true;
    btnMode.innerText = "Draw";
  }
}
function changeColor(event) {
  ctx.strokeStyle = event.target.value;
  ctx.fillStyle = event.target.value;
}
function changeLineWidth(event) {
  ctx.lineWidth = event.target.value;
}
function changeFile(event) {
  const file = event.target.files[0];
  const url = URL.createObjectURL(file);
  const image = new Image();
  image.src = url;
  image.onload = function () {
    ctx.drawImage(image, 0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
    file.value = null;
  };
}
function startDrawing() {
  isDrawing = true;
}
function cancelDrawing() {
  isDrawing = false;
  ctx.beginPath();
}
// 이벤트리스너에 함수 연결하기
canvas.addEventListener("dbclick", clickDouble);
canvas.addEventListener("mousemove", onMove);
canvas.addEventListener("mousedown", startDrawing);
canvas.addEventListener("mouseup", cancelDrawing);
canvas.addEventListener("mouseleave", cancelDrawing);
canvas.addEventListener("click", clickCanvas);
lineWidth.addEventListener("change", changeLineWidth);
color.addEventListener("change", changeColor);
colors.addEventListener((color) => color.addEventListener("click", clickColor));
btnMode.addEventListener("click", clickMode);
btnDestroy.addEventListener("click", clickDestory);
btnErase.addEventListener("click", clickErase);
btnSave.addEventListener("click", clickSave);
file.addEventListener("change", changeFile);
