const ShoppingCart = {
    items: [],

    addItem: function(item) {
        this.items.push(item);
        console.log(`${item.name} added into the cart.`);
    },

    removeItem: function(itemName) {
        const index = this.items.findIndex(item => item.name === itemName);
        if(index !== -1) {
            const removedItem = this.items.splice(index, 1)[0];
            console.log(`${removedItem.name} removed from the cart.`);
        } else {
            console.log(`${itemName} not found in the cart.`);
        }
    },

    calculateTotalPrice: function() {
        let totalPrice = 0;
        this.items.forEach(item => {
            totalPrice += item.price;
        });
        return totalPrice.toFixed(2);
    }
};

const item1 = { name: 'T-Shirt', price: 20 };
const item2 = { name: 'Jeans', price: 50 };
const item3 = { name: 'Bushirt', price: 100 };

ShoppingCart.addItem(item1);
ShoppingCart.addItem(item2);
ShoppingCart.addItem(item3);

console.table(ShoppingCart.items)

console.log('Total Price:', ShoppingCart.calculateTotalPrice());
ShoppingCart.removeItem('Jeans');

console.table(ShoppingCart.items)
console.log('Total Price:', ShoppingCart.calculateTotalPrice());


// function Abcd(name) {
//     this.name = () => {
//        return (name+" hello")
//     };

//     this.new_naam = function() {
//         return (name + " by navu naam")
//     };
// }
 
// const a = new Abcd("undef");
// console.log(a.name("Haridas"));

// const b = new Abcd("undef");
// console.log(b.new_naam("Krishnadas"));