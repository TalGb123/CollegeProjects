function factorial(num) {
    let result = 1;
    for (let i=1; i<=num; i++) {
        result *= i;
    }
    return result;
}

function displayFactorial(num){
    let result = factorial(num);
    document.getElementById(`result`).innerHTML = `!${num} = ${result}`;
}

function factorialAll(){
    let num = parseInt(prompt("Enter a number: "));
    let str = "";
    for (let i=1; i<=num; i++) {
        str += `!${i} = ` + factorial(i) + "<br>";
        document.getElementById(`result`).innerHTML = str;
    }
}

function twoPowerFour(){
    let result = 2;
    for (let i=1; i<4; i++) {
        result *= 2;
    }
    document.getElementById(`result`).innerHTML = `2<sup>4</sup> = ${result}`;
}

function factorialExplanation() {
    let num = parseInt(prompt("Enter a number: "));
    let str = "";
    for (let i = 1; i <= num; i++) {
        str += `${i} * `;
    }
    str = str.slice(0, -3);
    document.getElementById('result').innerHTML = `${str} = ${factorial(num)}`;
}

function Grade() {
    let grade = document.getElementById('grade').value;
    document.getElementById('result').innerHTML = `Your grade is ${grade}`;
}