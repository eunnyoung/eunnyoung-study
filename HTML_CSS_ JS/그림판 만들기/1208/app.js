let isDrawing = false;
let isFilling = false;
const colors = Array.from(document.getElementsByClassName("colors"));
const colorRange = document.getElementById("colorRange");
const lineWidth = document.getElementById("lineWidth");
const btnMode = document.getElementById("btnMode");
const btnDestroy = document.getElementById("btnDestroy");
const btnErase = document.getElementById("btnErase");
const btnSave = document.getElementById("btnSave");
const text = document.getElementById("text");
const file = document.getElementById("file");
const canvas = document.querySelector("canvas");
const CANVAS_WIDTH = 800;
const CANVAS_HEIGHT = 800;
const ctx = canvas.getContext("2d");
canvas.width = CANVAS_WIDTH;
canvas.height = CANVAS_HEIGHT;
ctx.lineCap = "round";
ctx.lineWidth = lineWidth.value;
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
  const textValue = text.value;
  if (textValue !== "") {
    ctx.save();
    ctx.font = "100px serif";
    ctx.fillText(textValue, event.offsetX, event.offsetY);
    ctx.restore();
  }
}
function clickCanvas() {
  if (isFilling) {
    ctx.fillRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
  }
}
function clickMode() {
  if (isDrawing) {
    isDrawing = false;
    btnMode.innerText = "Draw";
  } else {
    isDrawing = true;
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
function clickSave(event) {
  const a = document.createElement("a");
  const url = canvas.toDataURL();
  a.href = url;
  a.download = "myDrawing.png";
  a.click();
}
function clickColor(event) {
  const clickedColor = event.target.dataset.color;
  ctx.fillStyle = clickedColor;
  ctx.strokeStyle = clickedColor;
  colorRange.value = clickedColor;
}
function changeColor(event) {
  ctx.fillStyle = event.target.value;
  ctx.strokeStyle = event.target.value;
}
function changeLineWidth(event) {
  // lineWidth.value = event.target.value;
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
// eventListner
canvas.addEventListener("click", clickCanvas);
canvas.addEventListener("dbclick", clickDouble);
canvas.addEventListener("mousemove", onMove);
canvas.addEventListener("mouseleave", cancelDrawing);
canvas.addEventListener("mousedown", startDrawing);
canvas.addEventListener("mouseup", cancelDrawing);
lineWidth.addEventListener("change", changeLineWidth);
file.addEventListener("change", changeFile);
colors.forEach((colorRange) =>
  colorRange.addEventListener("change", clickColor)
);
colorRange.addEventListener("change", changeColor);
btnMode.addEventListener("click", clickMode);
btnDestroy.addEventListener("click", clickDestroy);
btnErase.addEventListener("click", clickErase);
btnSave.addEventListener("click", clickSave);
