### 1030

- 문제: todo list 기능이 잘 되지 않는다.
  <br/>preventDefault 가 제대로 타이핑이 안 된 건가 싶어서 todo.js 파일을 다시 훑어봤다.
  <pre>
    // const newTodo = toDoInput.ariaValueMax;
  const newTodo = toDoInput.value;
  </pre>
  위와 같이 코드를 수정해도 여전히 투두리스트 input 박스 enter 시 페이지 새로고침 되는 문제가 발생하고 있다.

### 공부 내용

- padStart
- innerText
- 템플릿 리터럴
- localStorage
