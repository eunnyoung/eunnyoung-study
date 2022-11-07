const counter = document.getElementById("counter");
const increase = document.getElementById("increase");
const decrease = document.getElementById("decrease");
let num = 0;
const render = function () {
  counter.innerHTML = num;
};
increase.onlick = function () {
  num++;
  console.log("increase 버튼 클릭", num);
  render();
};
decrease.onclick = function () {
  num--;
  console.log("decrease", num);
  render();
};
