const clock = document.getElementById("clock");
function getClock() {
  const date = new Date();
  // String.prototype.padStart()
  // padStart() 메서드는 현재 문자열의 시작을 다른 문자열로 채워,
  // 주어진 길이를 만족하는 새로운 문자열을 반환합니다.
  const hours = String(date.getHours()).padStart(2, "0");
  const minutes = String(date.getMinutes()).padStart(2, "0");
  const seconds = String(date.getSeconds()).padStart(2, "0");
  clock.innerText = `${hours}:${minutes}:${seconds}`;
}
getClock();
setInterval(getClock, 1000);
