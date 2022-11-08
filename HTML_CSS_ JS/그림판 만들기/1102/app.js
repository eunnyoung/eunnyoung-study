let isDrawing = false;
let isFilling = false;
const colorRange = document.getElementById("colorRange");
const colors = Array.from(document.getElementsByClassName("color"));
const canvas = document.querySelector("canvas");
const file = document.getElementById("file");
const text = document.getElementById("text");
const btnMode = document.getElementById("btnMode");
const btnDestroy = document.getElementById("btnDestroy");
const btnErase = document.getElementById("btnErase");
const btnSave = document.getElementById("btnSave");
const lineWidth = document.getElementById("lineWidth");
const CANVAS_WIDTH = 800;
const CANVAS_HEIGHT = 800;
canvas.width = CANVAS_WIDTH;
canvas.height = CANVAS_HEIGHT;
const ctx = canvas.getContext("2d");
ctx.lineWidth = lineWidth.value;
ctx.lineCap = "round";

function onMove(event) {
  if (isDrawing) {
    ctx.lineTo(event.offsetX, event.offsetY);
    ctx.stroke();
    return;
  }
  ctx.moveTo(event.offsetX, event.offsetY);
}
function startDrawing() {
  isDrawing = true;
}
function cancelDrawing() {
  isDrawing = false;
  ctx.beginPath();
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
function clickDouble(event) {
  const text = text.value;
  if (text !== "") {
    ctx.save();
    ctx.lineWidth = 1;
    ctx.font = "68px sans-serif";
    ctx.fillRect(text, event.offsetX, event.offsetY);
    ctx.restore();
  }
}
function clickCanvas() {
  if (isFilling) {
    ctx.fillRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
  }
}
function clickColor(event) {
  // const clickedColor = event.target.style.backgroundColor;
  const clickedColor = event.target.dataset.color;
  ctx.strokeStyle = clickedColor;
  ctx.fillStyle = clickedColor;
  colorRange.value = clickedColor;
  console.log(`test: ${event.target.dataset.color}`);
}
// input color 변경
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
// 이벤트 리스너 연결
canvas.addEventListener("dblclick", clickDouble);
canvas.addEventListener("mousemove", onMove);
canvas.addEventListener("mousedown", startDrawing);
canvas.addEventListener("mouseup", cancelDrawing);
canvas.addEventListener("mouseleave", cancelDrawing);
canvas.addEventListener("click", clickCanvas);
lineWidth.addEventListener("change", changeLineWidth);
colorRange.addEventListener("change", changeColor);
colors.forEach((colorRange) =>
  colorRange.addEventListener("click", clickColor)
);
btnMode.addEventListener("click", clickMode);
btnDestroy.addEventListener("click", clickDestroy);
btnErase.addEventListener("click", clickErase);
file.addEventListener("change", changeFile);
btnSave.addEventListener("click", clickSave);
