let matrix = [];
const initialArray = [...Array(15).keys()].map(n => n + 1).concat(''); // [1, 2, ..., 15, '']

function generateRandomBoard(arr) {
    if (!Array.isArray(arr)) {
        console.error('Invalid array');
        return;
    }
    arr = arr.sort(() => Math.random() - 0.5);
    matrix = [];
    while (arr.length) matrix.push(arr.splice(0, 4));
    matrix.forEach((row, rowIndex) => {
        row.forEach((number, colIndex) => {
            const cell = document.getElementById(`${rowIndex},${colIndex}`);
            if (number === '') {
                cell.classList.add('empty');
                cell.textContent = '';
            } else {
                cell.classList.remove('empty');
                cell.textContent = number;
            }
        });
    });
}

function moveCell(buttonID) {
    const [row, col] = buttonID.split(',').map(Number);
    let check = ["up", "down", "left", "right"];
    if (row == 3 || col == 3 || row == 0 || col == 0) {
        if (row == 0) {
            check = check.filter(item => item !== "up");
        }
        if (row == 3) {
            check = check.filter(item => item !== "down");
        }
        if (col == 0) {
            check = check.filter(item => item !== "left");
        }
        if (col == 3) {
            check = check.filter(item => item !== "right");
        }
    }
    if (check.includes("up") && row > 0 && matrix[row - 1][col] === '') {
        matrix[row - 1][col] = matrix[row][col];
        matrix[row][col] = '';
    }
    if (check.includes("down") && row < 3 && matrix[row + 1][col] === '') {
        matrix[row + 1][col] = matrix[row][col];
        matrix[row][col] = '';
    }
    if (check.includes("left") && col > 0 && matrix[row][col - 1] === '') {
        matrix[row][col - 1] = matrix[row][col];
        matrix[row][col] = '';
    }
    if (check.includes("right") && col < 3 && matrix[row][col + 1] === '') {
        matrix[row][col + 1] = matrix[row][col];
        matrix[row][col] = '';
    }
    updateBoard();
    gameOver();
}

function updateBoard() {
    matrix.forEach((row, rowIndex) => {
        row.forEach((number, colIndex) => {
            const cell = document.getElementById(`${rowIndex},${colIndex}`);
            if (number === '') {
                cell.classList.add('empty');
                cell.textContent = '';
            } else {
                cell.classList.remove('empty');
                cell.textContent = number;
            }
        });
    });
}

function resetGame() {
    generateRandomBoard([...Array(15).keys()].map(n => n + 1).concat(''));
}

function gameOver(){
    let count = 1;
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            if (matrix[i][j] != count) {
                return false;
            }
            count++;
        }
    }
    if (count == 16) alert('You win!');
}

resetGame();