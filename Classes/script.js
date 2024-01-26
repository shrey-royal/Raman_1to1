class Calculator {
    constructor(a, b) {
        console.log("Default Constructor");
        this.a = a;
        this.b = b;
    }

    add() {
        return this.a + this.b;
    }

    subtract() {
        return this.a - this.b;
    }

    multiply() {
        return this.a * this.b;
    }

    divide() {
        return this.a / this.b;
    }

    remainder() {
        return this.a % this.b;
    }

    power() {
        return this.a ** this.b;
    }

    squareRoot() {
        return Math.sqrt(this.a);
    }

    cubeRoot() {
        return Math.cbrt(this.a);
    }
}

// const Calc = new Calculator(2, 3);

// console.log("a: " + Calc.a);
// console.log("b: " + Calc.b);
// console.log("Add: " + Calc.add());
// console.log("Subtract: " + Calc.subtract());
// console.log("Multiply: " + Calc.multiply());
// console.log("Divide: " + Calc.divide());
// console.log("Remainder: " + Calc.remainder());
// console.log("Power: " + Calc.power());
// console.log("Square Root: " + Calc.squareRoot());
// console.log("Cube Root: " + Calc.cubeRoot());

class Test_Class extends Calculator {
    a = prompt("Enter a number: ")
    b = prompt("Enter another number: ")

    constructor(a, b) {
        super(a, b);
    }

    add() {
        return super.add();
    }

    subtract() {
        return super.subtract();
    }
}

// const Calc = new Test_Class(2, 3);

// console.log("a: " + Calc.a);
// console.log("b: " + Calc.b);
// console.log("Add: " + Calc.add());
// console.log("Subtract: " + Calc.subtract());
// console.log("Multiply: " + Calc.multiply());
// console.log("Divide: " + Calc.divide());
// console.log("Remainder: " + Calc.remainder());
// console.log("Power: " + Calc.power());
// console.log("Square Root: " + Calc.squareRoot());
// console.log("Cube Root: " + Calc.cubeRoot());

//hoisting - using a variable or function before it is declared

//means function declaration can be called befoer it is declared but function expression cannot be called before it is declared

//function declaration is hoisted
// fun();

// function fun() {
//     console.log("FUN");
// }

//function expression is not hoisted
// fun1();
// var fun1 = function() {
//     console.log("Hello from fun1");
// }

// carName = "Volvo"
// console.log(carName);
// var carName

//static keyword
// class MathUtils {
//     static multiply(a, b) {
//         return a * b;
//     }
// }

// console.log(MathUtils.multiply(2,3));

//getter and setter
class Circle {
    constructor(radius) {
        this.radius = radius;
    }

    get diameter() {
        return 2 * this.radius;
    }

    set diameter(value) {
        this.radius = value / 2;
    }
}

const c = new Circle(5)

console.log("c.radius: ", c.radius);        //getter
console.log("c.diameter: ", c.diameter);    //getter

c.diameter = 100;   //setter


console.log("c.radius: ", c.radius);        //getter
console.log("c.diameter: ", c.diameter);    //getter

// in javascript getter and setter methods can be resued as properties
// js engine will automatically call the getter and setter methods when we try to access the properties

// scope of let variable is within the block({}) - act as private variable
// scope of var variable is within the function - act as public variable
// scope of const variable is within the block({}) - act as private variable

// let _a;  //private property - convention