let secretNumber = generateRandomNumber().split('');
let round = 1;
let possibleNumbers = generateAllPossibleNumbers();
let gameOver = false;

function generateRandomNumber() {
    let digits = '0123456789';
    let num = '';
    while (num.length < 4) {
        let randomDigit = digits[Math.floor(Math.random() * digits.length)];
        if (!num.includes(randomDigit)) {
            num += randomDigit;
        }
    }
    return num;
}

function checkInput() {
    if (document.getElementById('bot-guessing').checked) {
        console.log('bot-guessing');
        botGuess();
        return;
    } else {
        var input = document.getElementById('guess-input').value;
        if (input.length !== 4 || new Set(input).size !== 4) {
            alert('Please enter a 4-digit number with unique digits.');
            return;
        } else {
            checkGuess(input);
            return;
        }
    }
}

function checkGuess(input) {
    var guess = input.split('');
    var b_c = [];
    for (let i = 0; i < 4; i++) {
        if (guess[i] === secretNumber[i]) {
            b_c.push('B');
        } else if (secretNumber.includes(guess[i]) && !(guess[i] === secretNumber[i])) {
            b_c.push('C');
        } else {
            b_c.push('X');
        }
    }
    let table = document.getElementById('table');
    let newRow = table.insertRow();
    newRow.innerHTML = "<td>" + round + "</td>" + "<td>" + guess.join('') + "</td>" + "<td>" + b_c.join('') + "</td>";
    round++;
}

function generateAllPossibleNumbers() {
    let numbers = [];
    for (let i = 1000; i <= 9999; i++) {
        let numStr = i.toString();
        if (new Set(numStr).size === 4) {
            numbers.push(numStr);
        }
    }
    return numbers;
}

function botGuess() {
    if (possibleNumbers.length === 0) {
        alert('No possible numbers left!');
        resetGame();
        return;
    }
    let botGuess = possibleNumbers[Math.floor(Math.random() * possibleNumbers.length)];
    checkBotGuess(botGuess);
}

function checkBotGuess(guess) {
    var guessArray = guess.split('');
    var b_c = [];
    for (let i = 0; i < 4; i++) {
        if (guessArray[i] === secretNumber[i]) {
            b_c.push('B');
        } else if (secretNumber.includes(guessArray[i]) && !(guessArray[i] === secretNumber[i])) {
            b_c.push('C');
        } else {
            b_c.push('X');
        }
    }
    let table = document.getElementById('table');
    let newRow = table.insertRow();
    newRow.innerHTML = "<td>" + round + "</td>" + "<td>" + guessArray.join('') + "</td>" + "<td>" + b_c.join('') + "</td>";
    round++;
    if (b_c.filter(x => x == 'B').length == 4) {
        alert('Bot guessed the number correctly!');
        resetGame();
    } else {
        refinePossibleNumbers(guessArray, b_c);
        setTimeout(botGuess, 1000); 
    }
}

function refinePossibleNumbers(guessArray, b_c) {
    possibleNumbers = possibleNumbers.filter(num => {
        let numArray = num.split('');
        for (let i = 0; i < 4; i++) {
            if (b_c[i] == 'B' && numArray[i] != guessArray[i]) {
                return false;
            }
            if (b_c[i] == 'C' && (numArray[i] == guessArray[i] || !numArray.includes(guessArray[i]))) {
                return false;
            }
            if (b_c[i] == 'X' && numArray.includes(guessArray[i])) {
                return false;
            }
        }
        return true;
    });
}

function resetGame() {
    secretNumber = generateRandomNumber().split('');
    round = 1;
    possibleNumbers = generateAllPossibleNumbers();
    gameOver = false;
    document.getElementById('table').innerHTML = "<tr><th>Round</th><th>Guess</th><th>Result</th></tr>";
}