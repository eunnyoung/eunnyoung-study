let isDrawing = false;
let isFilling = false;
const lineWidth = document.getElementById("lineWidth");
const colors = Array.from(document.getElementsByClassName("color"));
const colorRange = document.getElementById("colorRange");
const btnMode = document.getElementById("btnMode");
const btnDestory = document.getElementById("btnDestroy");
const btnErase = document.getElementById("btnErase");
const btnSave = document.getElementById("btnErase");
const file = document.getElementById("file");
const text = document.getElementById("text");
const CANVAS_WIDTH = 800;
const CANVAS_HEIGHT = 800;
const canvas = document.querySelector("canvas");
const ctx = canvas.getContext("2d");
canvas.width = CANVAS_WIDTH;
canvas.height = CANVAS_HEIGHT;
ctx.lineCap = "round";
ctx.lineWidth = lineWidth.value;
// 함수
function startDrawing() {
  isDrawing = true;
}
function cancelDrawing() {
  isDrawing = false;
  ctx.beginPath();
}
function onMove(event) {
  if (isDrawing) {
    ctx.lineTo(event.offsetX, event.offsetY);
    ctx.stroke();
    return;
  }
  ctx.moveTo(event.offsetX.event.offsetY);
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
function clickCanvas() {
  if (isFilling) {
    ctx.fillRect(0, 0, CANVAS_WIDTH, CANVAS_HEIGHT);
  }
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
function clickColor(event) {
  const colorValue = event.target.dataset.color;
  ctx.strokeStyle = colorValue;
  ctx.fillStyle = colorValue;
  color.value = colorValue;
  console.log(
    `${event.target.id},${evnet.target.dataset.color},${event.target.value}`
  );
}
function clickSave() {
  const url = canvs.toDataURL();
  const a = document.createElement("a");
  a.href = url;
  a.download = "myDrawing.png";
  a.click();
}
function changeColor(event) {
  ctx.strokeStyle = event.target.value;
  ctx.fillStyle = event.target.value;
  console.log(`${event.target.value}`);
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
canvas.addEventListener("mouseup", cancelDrawing);
canvas.addEventListener("mouserdown", startDrawing);
canvas.addEventListener("mouseleave", cancelDrawing);
canvas.addEventListener("dblclick", clickDouble);
canvas.addEventListener("click", clickCanvas);
canvas.addEventListener("mousemove", onMove);
lineWidth.addEventListener("change", changeLineWidth);
file.addEventListener("change", changeFile);
colors.addEventListener((colorRange) =>
  colorRange.addEventListener("change", clickColor)
);
colorRange.addEventListener("change", changeColor);
btnMode.addEventListener("click", clickMode);
btnDestory.addEventListener("click", clickDestroy);
btnErase.addEventListener("click", clickErase);
btnSave.addEventListener("click", clickSave);
