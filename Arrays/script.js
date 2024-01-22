// let arr = [1, 2, 3, 4]

// console.log(arr);
// console.log(arr.length);
// let a1 = arr.slice(0)
// console.log(a1);
// console.log(a1.fill(4, 0, 2));
// console.log(a1.reverse());
// console.log(a1.concat(a1, arr));

// arr.push(10)
// console.log(arr)

// let seas = ['Black Sea', 'Caribbean Sea', 'North Sea', 'Baltic Sea', 'Red Sea', 2]
// seas.push('Red Sea')
// seas.unshift('Red Sea')
// console.log(seas.pop());
// console.log(seas.shift());
// console.log(seas.indexOf('North Sea'));
// console.log(Array.isArray(seas));   //true

// console.log(seas);

//2D Array
let board = [1, 2, 3, 4, 5, 6, 7, 8, 9];

let s = '';
for (let i = 0, j = 1; i < board.length; i++, j++) {
  s += board[i] + ' ';
  if (j % 3 == 0) {
    console.log(s);
    s = '';
  }
}