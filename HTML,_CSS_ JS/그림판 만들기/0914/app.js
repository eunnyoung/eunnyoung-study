// canvas 관련 상수 지정
const CANVAS_HEIGTH = 800;
const CANVAS_WIDTH = 800;
const lineWidth = document.getElementById("lineWidth");
const canvas = document.querySelector("canvas");
const ctx = canvas.getContext("2d");
// btn 상수 설정
const btnMode = document.getElementById("btnMode");
const btnDestroy = document.getElementById("btnDestroy");
const btnErase = document.getElementById("btnErase");
const btnSave = document.getElementById("btnSave");
// input 상수 설정
const inputFile = document.getElementById("file");
const inputText = document.getElementById("text");
// let 변수 설정
let isDrawing = false;
let isFilling = false;
// color 관련 상수 지정
const colors = Array.from(document.getElementsByClassName("color"));
const color = document.getElementById("color");
//
canvas.width = CANVAS_WIDTH;
canvas.height = CANVAS_HEIGHT;
ctx.lineWidth = lineWidth.value;
