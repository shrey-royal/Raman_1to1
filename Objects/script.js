// let v = true
// let v = new Boolean(true)
// console.log(typeof v, v);
// let _int = new Number(23)
// console.log(typeof _int, _int.toPrecision(4));

// var person = {
//     firstname: "Raman",
//     lastname: "Chaudhary",
//     age: 19,
//     eyeColor: "brown"
// };

// console.log(person.firstname + " is " + person.age + " years old.")

// var gorment = new Object(); //create object

// gorment.state = "Gujarat"
// gorment.department = "Water"
// gorment.minister = "A_Name"

// console.log("State:", gorment.state, "\nDepartment:", gorment.department, "\nMinister:", gorment.minister);

// function Car(name, model, company, manufacturing_year) {
//     this.name = name;
//     this.model = model;
//     this.company = company;
//     this.manufacturing_year = manufacturing_year;
// }

// let car = new Car("911", " Turbo S", "Porsche", 911)

// console.log("Name:", car.name, "\nModel:", car.model, "\nCompany: ", car.company, "\nManufacturing Year:", car.manufacturing_year);

// function employee(id, name, salary) {
//     this.id = id;
//     this.name = name;
//     this.salary = salary

//     this.changeSalary = changeSalary;

//     function changeSalary(otherSalary) {
//         this.salary = otherSalary;
//     }
// }

// var emp = new employee(1, "Raman", 10000);
// console.log(emp.id + " " + emp.name + " " + emp.salary);

// emp.changeSalary(20000)

// console.log(emp.id + " " + emp.name + " " + emp.salary);

// ------------------------------------------------------------------------------------------------------------------------


// const person = {
//     name: 'Mosh',
//     age: 30,
//     city: 'Toronto'
// };


// //Accessing object properties
// console.log(person.name, person['name']);

// //Adding properties
// person['newProp'] = "new_value"
// console.log(person.newProp);

// const selectedColors = ['red', 'blue'];
// person.favoriteColor = selectedColors;
// console.log("Favorite Colors: " + person.favoriteColor);

const car = {
    make: 'Honda',
    model: 'Civic',
    year: 2018,
    color: 'black',
    price: 20000,
    isAvailable: true,

    drive: function() {
        console.log("Vroom Vroom");
    },

    start: function() {
        console.log('starting the car');
    },

    stop: function() {
        console.log('stopping the car');
    }
};

car.start();
car.drive();
console.log(car.make, car.model, car.year, car.color, car.price, car.isAvailable);
car.stop();

function Cakes(name, price, flavor, layers, occasion) {
    this.name = name;
    this.price = price;
    this.flavor = flavor;
    this.layers = layers;
    this.occasion = occasion;
}

const orderCake = new Cakes('Chocolate Cake', 100, 'Chocolate', 3,  'Birthday');
console.log(orderCake);

//Destructuring Objects
const { name, price, flavor, layers, occasion } = orderCake;
console.log(name, price, flavor, layers, occasion);
console.log('------------------------------------');


// JSON.stringify() - converts an object to a JSON string

const carJSON = JSON.stringify(car);
console.log(carJSON);

//JSON.parse() - converts a JSON string into an object

const modified_car = JSON.parse(carJSON);
console.log(modified_car);

