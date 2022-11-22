let isDrawing = false;
let isFilling = false;
const colors = Array.from(document.getElementsByClassName("color"));
const colorRange = document.getElementById("colorRange");
const lineWidth = document.getElementById("lineWidth");
const canvas = document.querySelector("canvas");
const ctx = canvas.getContext("2d");
const CANVAS_WIDTH = 800;
const CANVAS_HEIGHT = 800;
canvas.width = CANVAS_WIDTH;
canvas.height = CANVAS_HEIGHT;
ctx.lineCap = "round";
ctx.lineWidth = lineWidth.value;

const file = document.getElementById("file");
const text = document.getElementById("text");
const btnMode = document.getElementById("btnMode");
const btnDestroy = document.getElementById("btnDestroy");
const btnErase = document.getElementById("btnErase");
const btnSave = document.getElementById("btnSave");
// functions
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
function clickDouble(event) {
  const textCanvas = text.value;
  if (textCanvas !== "") {
    ctx.save();
    // 이 부분을 통해서 폰트 사이즈를 조절할 수 있다. 뒤에 폰트 스타일까지 지정해줘야 한다.
    ctx.font = "100px serif";
    ctx.fillText(textCanvas, event.offsetX, event.offsetY);
    ctx.restore();
  }
}
function clickCanvas() {
  if (isFilling) {
    ctx.fillRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
  }
}
function clickColor(event) {
  const clickedColor = event.target.dataset.color;
  ctx.strokeStyle = clickedColor;
  ctx.fillStyle = clickedColor;
  colorRange.value = clickedColor;
}
function clickMode() {
  if (isFilling) {
    isFilling = false;
    btnMode.innerText = "Draw";
  } else {
    isFilling = true;
    btnMode.innerText = "Fill";
  }
}
function clickDestroy() {
  ctx.fillStyle = "white";
  ctx.fillRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
}
function clickErase() {
  ctx.strokeStyle = "white";
  isFilling = false;
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
function changeColor(event) {
  ctx.strokeStyle = event.target.value;
  ctx.fillStyle = event.target.value;
}
function changeLineWidth(event) {
  ctx.lineWidth = event.target.value;
}
// eventListener
canvas.addEventListener("click", clickCanvas);
canvas.addEventListener("dblclick", clickDouble);
canvas.addEventListener("mousemove", onMove);
canvas.addEventListener("mousedown", startDrawing);
canvas.addEventListener("mouseup", cancelDrawing);
canvas.addEventListener("mouseleave", cancelDrawing);
lineWidth.addEventListener("change", changeLineWidth);
file.addEventListener("change", changeFile);
colors.forEach((colorRange) =>
  colorRange.addEventListener("click", clickColor)
);
colorRange.addEventListener("change", changeColor);
btnMode.addEventListener("click", clickMode);
btnErase.addEventListener("click", clickErase);
btnDestroy.addEventListener("click", clickDestroy);
btnSave.addEventListener("click", clickSave);
