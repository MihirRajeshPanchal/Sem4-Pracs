// Basic types

let id: number = 5;
let company: string = "Web dev";
let x: any = 'Hello';

let ids: number[] = [1, 2, 3, 4, 5];
let arr: any[] = [1, true, "Hello"];

// Tuple
let person: [number, string, boolean] = [1, 'mihir', true];

let employee: [number, string][];

employee = [
    [1, 'mihir'],
    [2, 'John']
];

// UNION

let pid: number | string;
pid = '22';

// Enum

enum Direction {
    up = 1, down, right, left
}

console.log(Direction.up);  // Output: 1

// Object

type User = {
    id: number,
    name: string
}

const user: User = {
    id: 1,
    name: "mihir"
}

// Type Assertion
let cid: any = 2;
let customerId = cid as number;

// Functions
function add(x: number, y: number): number {
    return x + y;
}

console.log(add(1, 2));  // Output: 3

function log(message: string | number): void {
    console.log(message);
}

// Interfaces
interface UserInterface {
    id: number,
    name: string,
    age?: number
}

const user1: UserInterface = {
    id: 2,
    name: "mihir"
}

user1.id = 5;  // This is valid since 'id' is not readonly

type Point = number | string;
const p1: Point = 1;

interface MathFunc {
    (x: number, y: number): number;
}

const addition: MathFunc = (x: number, y: number) => x + y;
const subtraction: MathFunc = (x: number, y: number) => x - y;

// Classes

class Person {
    id: number;  // By default, this is public
    name: string;

    constructor(id: number, name: string) {
        this.id = id;
        this.name = name;
    }
}

const mihir = new Person(1, 'mihir panchal');
console.log(mihir);  // Output: Person { id: 1, name: 'mihir panchal' }

mihir.id = 5;
console.log(mihir);  // Output: Person { id: 5, name: 'mihir panchal' }

// Extended class
class Employee extends Person {
    position: string;

    constructor(id: number, name: string, position: string) {
        super(id, name);
        this.position = position;
    }
}

const emp = new Employee(3, 'David', 'Webdev');
console.log(emp.name);  // Output: David
console.log(emp.position);  // Output: Webdev
