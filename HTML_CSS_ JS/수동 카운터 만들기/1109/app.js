const counter = document.getElementById("cjounter");
const increase = document.getElementById("increase");
const decrease = document.getElementById("decrease");
let num = 0;
const render = function () {
  counter.innerHTML = num;
};
increase.onclick = function () {
  num++;
  console.log("increase 버튼 클릭", num);
  render();
};
decrease.onclick = function () {
  num--;
  console.log("decrease", num);
  render();
};
