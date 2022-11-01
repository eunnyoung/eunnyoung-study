let isDrawing=false;
let isFilling=false;
const CANVAS_WIDTH=800;
const CANVAS_HEIGHT=800;
const canvas=document.querySelector("canvas");
const ctx=canvas.getContext("2d");
canvas.width=CANVAS_WIDTH;
canvas.height=CANVAS_HEIGHT;
ctx.lineCap=lineWidth.value;
ctx.lineCap="round";
const file=document.getElementById("file");
const text=document.getElementById("text");
const colors=Array.from(
  document.getElementsByClassName("color")
);
const colorRange=document.getElementById("colorRange");
const btnMode=document.getElementById("btnMode");
const btnDestroy=document.getElementById("btnDestroy");
const btnErase=document.getElementById("btnErase");
const btnSave=document.getElementById("btnSave");
const lineWidth=document.getElementById("lineWidth");
// 함수
function onMove
function startDrawing(){
  isDrawing=true;
}
function cancelDrawing(){
  isDrawing=false;
  ctx.beginPath();
}
function clickCanvas
function clickDouble
function clickMode
function clickDestroy
function clickErase
function clickSave
function clickColor
function changeColor
function changeFile
function changeLineWidth