let isPainting = false;
let isFilling = false;
const btnSave = document.getElementById("btnSave");
const btnDestroy = document.getElementById("btnDestroy");
const btnMode = document.getElementById("btnMode");
const btnErase = document.getElementById("btnErase");
const colorRange = document.getElementById("colorRange");
const color = document.getElementsByClassName("color");
const colors = Array.from(document.getElementsByClassName("color"));
const text = document.getElementById("text");
const file = document.getElementById("file");
const CANVAS_HEIGHT = 800;
const CANVAS_WIDTH = 800;
const canvas = document.querySelector("canvas");
canvas.height = CANVAS_HEIGHT;
canvas.width = CANVAS_WIDTH;
// 못 쓴 변수
const lineWidth = document.getElementById("lineWidth");
const ctx = canvas.getContext("2d");
ctx.lineWidth = lineWidth.value;
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
function clickMode() {
  if (isFilling) {
    isFilling = false;
    btnMode.innerText = "Fill";
  } else {
    isFilling = true;
    btnMode.innerText = "Draw";
  }
}
function clickDestroy() {
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
function changeLineWidth(event) {
  ctx.lineWidth = event.target.value;
}
function changeColor(event) {
  ctx.strokeStyle = event.target.value;
  ctx.fillStyle = event.target.value;
}
function startPainting() {
  isPainting = true;
}
function cancelPainting() {
  isPainting = false;
  ctx.beginPath();
}
// 함수와 이벤트리스너 연결
canvas.addEventListener("dbclick", clickDouble);
canvas.addEventListener("mousemove", onMove);
canvas.addEventListener("mousedown", startPainting);
canvas.addEventListener("mouseup", cancelPainting);
canvas.addEventListener("mouseleave", cancelPainting);
canvas.addEventListener("click", clickCanvas);
lineWidth.addEventListener("change", changeLineWidth);
color.addEventListener("change", changeColor);
colors.addEventListener((color) => color.addEventListener("clcik", clickColor));
btnMode.addEventListener("click", clickMode);
btnDestroy.addEventListener("click", clickDestroy);
btnErase.addEventListener("click", clickErase);
btnSave.addEventListener("click", clickSave);
file.addEventListener("change", changeFile);
