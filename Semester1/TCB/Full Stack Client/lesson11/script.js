let arr = [1, 1, 1, 0, 2, 2, 2];

function moveFrog(buttonID) {
    buttonID = parseInt(buttonID);
    if (arr[buttonID] == 1 && arr[buttonID + 1] == 0) {
        arr[buttonID] = 0;
        arr[buttonID + 1] = 1;
    } else if (arr[buttonID] == 1 && arr[buttonID + 1] == 2 && arr[buttonID + 2] == 0) {
        arr[buttonID] = 0;
        arr[buttonID + 2] = 1;
    } else if (arr[buttonID] == 2 && arr[buttonID - 1] == 0) {
        arr[buttonID] = 0;
        arr[buttonID - 1] = 2;
    } else if (arr[buttonID] == 2 && arr[buttonID - 1] == 1 && arr[buttonID - 2] == 0) {
        arr[buttonID] = 0;
        arr[buttonID - 2] = 2;
    }
    start();
    gameOver();
}

function start() {
    for (let i = 0; i < arr.length; i++) {
        const button = document.getElementById(i.toString());
        if (button) {
            if (arr[i] == 1) {
                button.classList.add('frog', 'team1');
                button.classList.remove('empty', 'team2');
                button.textContent = '1';
            } else if (arr[i] == 2) {
                button.classList.add('frog', 'team2');
                button.classList.remove('empty', 'team1');
                button.textContent = '2';
            } else {
                button.classList.add('empty');
                button.classList.remove('frog', 'team1', 'team2');
                button.textContent = '';
            }
        }
    }
}

function gameOver() {
    if (arr[0] == 2 && arr[1] == 2 && arr[2] == 2 && arr[4] == 1 && arr[5] == 1 && arr[6] == 1) {
        alert('Congratulations! You won!');
        gameReset();
    }
}

function gameReset() {
    arr = [1, 1, 1, 0, 2, 2, 2];
    start();
}

// Initialize the game board
start();