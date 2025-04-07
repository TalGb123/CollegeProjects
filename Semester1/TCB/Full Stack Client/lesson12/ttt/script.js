const arr = [[0, 0, 0]
            ,[0, 0, 0]
            ,[0, 0, 0]];
var player = 1;

printBoard();

function playGame(buttonID) {
    let row = buttonID.split(",")[0];
    let col = buttonID.split(",")[1];
    console.log(row, col);
    if (player == 1) {
        arr[row][col] = 1;
        player = 2;
    } 
    else {
        arr[row][col] = 2;
        player = 1;
    }
    printBoard();
}

function printBoard() {
    for (let i = 0; i < arr.length; i++) {
        const button = document.getElementById(i.toString());
        if (button) {
            if (arr[i] == 1) {
                button.classList.add('X');
                button.classList.remove('empty');
                button.textContent = 'X';
            } else if (arr[i] == 2) {
                button.classList.add('O');
                button.classList.remove('empty');
                button.textContent = 'O';
            } else {
                button.classList.add('empty');
                button.classList.remove('X', 'O');
                button.textContent = '';
            }
        }
    }
}