const map = []
let boardWidth = 3
let boardHeight = 3
const gameBoard = document.getElementById('game-board');
let playerTurn = 1
let maxBoxes = (boardHeight-1) * (boardWidth-1);
let playerScore = [0, 0];
let lastMove = [];

function BuildBoard(){
    const actualWidth = boardWidth * 2 - 1; 
    const actualHeight = boardHeight * 2 - 1;
    gameBoard.style.gridTemplateColumns = `repeat(${actualWidth}, 60px)`;
    gameBoard.style.gridTemplateRows = `repeat(${actualHeight}, 60px)`;
    for (let i = 0; i < actualHeight; i++) {
        map.push([]);
        for (let j = 0; j < actualWidth; j++) {
            if (i % 2 === 0 && j % 2 === 0) {
                map[i][j] = '*'; // Dots
            } 
            else if (i % 2 === 1 && j % 2 === 1) {
                map[i][j] = '0P'; // Player's name spot
            } 
            else {
                // Determine if it's a horizontal or vertical line
                if (i % 2 === 0) {
                    map[i][j] = '0H'; // Horizontal line
                } 
                else {
                    map[i][j] = '0V'; // Vertical line
                }
            }
        }
    }
    PrintBoard();
}

function PrintBoard(){
    gameBoard.innerHTML = ''; // Clear the game board
    // Base size calculations
    const baseSize = 60; // Keep base size in pixels
    const cellSize = baseSize - (Math.max(boardWidth, boardHeight) * 2);
    for (let i = 0; i < map.length; i++) {
        for (let j = 0; j < map[i].length; j++) {
            const cell = document.createElement('div');
            cell.classList.add('cell');
            cell.style.width = `${cellSize}px`;
            cell.style.height = `${cellSize}px`;

            if (map[i][j] == '*') {
                cell.classList.add('dot');
                cell.style.width = '40%';  // 40% of cell size
                cell.style.height = '40%';
                cell.style.left = '50%';
                cell.style.top = '50%';
                cell.style.transform = 'translate(-50%, -50%)';
            } 
            else if (map[i][j][1] == 'H') {
                cell.classList.add('horizontal-line');
                cell.style.width = '160%';  // Extend beyond cell
                cell.style.height = '15%';  // Line thickness
                cell.style.left = '50%';    // Offset from left
                cell.style.top = '42.5%';   // Center vertically (50% - height/2)
            } 
            else if (map[i][j][1] == 'V') {
                cell.classList.add('vertical-line');
                cell.style.width = '15%';   // Line thickness
                cell.style.height = '160%';  // Extend beyond cell
                cell.style.left = '42.5%';  // Center horizontally (50% - width/2)
                cell.style.top = '50%';     // Offset from top
            }
            else if (map[i][j][1] == 'P') {
                cell.classList.add('player');
                cell.style.width = '80%';   // Player size
                cell.style.height = '80%';
                cell.style.left = '50%';
                cell.style.top = '50%';
                cell.style.transform = 'translate(-50%, -50%)';
                if (map[i][j][0] != '0') {
                    cell.textContent = 'Player' + map[i][j][0];
                    cell.style.color = (map[i][j][0] == '1') ? 'red' : 'blue';
                    cell.style.backgroundColor ='transparent';

                }
            }
            if (map[i][j][0] == '1') {
                cell.classList.add('player1');
            } 
            else if (map[i][j][0] == '2') {
                cell.classList.add('player2');
            }
            else if (map[i][j][0] == '0') {
                cell.classList.add('empty');
                if (map[i][j][1] == 'H' || map[i][j][1] == 'V') {
                    cell.classList.add('hover');
                }
            }
            gameBoard.appendChild(cell);
            if (map[i][j][1] == 'H' || map[i][j][1] == 'V') {
                cell.addEventListener('click', () => {
                    UpdateBoard(i, j);
                    cell.classList.add('line-visible');
                    cell.classList.remove('empty');
                    cell.removeEventListener('click', arguments.callee);
                });
            }
        }
    }
}

function UpdateBoard(i, j){
    side_check = ['up', 'down', 'left', 'right'];
    cell_type = map[i][j][1];
    player_flag = false;
    if (map[i][j][1] != 'P' && map[i][j][0] == 0) {
        map[i][j] = playerTurn + map[i][j][1];
        if (i == 0){
            side_check = side_check.filter(side => side !== 'up');
        }
        else if (i == (boardHeight * 2 - 2)){
            side_check = side_check.filter(side => side !== 'down');
        }
        if (j == 0){
            side_check = side_check.filter(side => side !== 'left');
        }
        else if (j == map[i].length - 1){
            side_check = side_check.filter(side => side !== 'right');
        }
        if (cell_type == 'V'){ // vertical line
            side_check = side_check.filter(side => side !== 'up');
            side_check = side_check.filter(side => side !== 'down');
        }
        else if (cell_type == 'H'){ // horizontal line
            side_check = side_check.filter(side => side !== 'left');
            side_check = side_check.filter(side => side !== 'right');
        }
        
        console.log(side_check);
        if (side_check.includes('up')){
            if (map[i-2][j][0] != '0' && map[i-1][j-1][0] != '0' && map[i-1][j+1][0] != '0'){
                map[i-1][j] = playerTurn + map[i-1][j][1];
                playerScore[playerTurn-1] += 1;
                player_flag = true;
                lastMove = [i, j, true, i-1, j];
            }
        }
        if (side_check.includes('left')){
            if (map[i][j-2][0] != '0' && map[i+1][j-1][0] != '0' && map[i-1][j-1][0] != '0'){
                map[i][j-1] = playerTurn + map[i][j-1][1];
                playerScore[playerTurn-1] += 1;
                player_flag = true;
                lastMove = [i, j, true, i, j-1];
            }
        }
        if (side_check.includes('right')){
            if (map[i][j+2][0] != '0' && map[i+1][j+1][0] != '0' && map[i-1][j+1][0] != '0'){
                map[i][j+1] = playerTurn + map[i][j+1][1];
                playerScore[playerTurn-1] += 1;
                player_flag = true;
                lastMove = [i, j, true, i, j+1];
            }
        }
        if (side_check.includes('down')){
            if (map[i+2][j][0] != '0' && map[i+1][j-1][0] != '0' && map[i+1][j+1][0] != '0'){
                map[i+1][j] = playerTurn + map[i+1][j][1];
                playerScore[playerTurn-1] += 1;
                player_flag = true;
                lastMove = [i, j, true, i+1, j];
            }
        }
    }
    console.log(map);
    if (!player_flag){
        if (playerTurn == 1) playerTurn = 2;
        else playerTurn = 1;
        lastMove = [i, j, false];
    }
    PrintBoard();
    gameOver();
}

function gameOver(){
    if (playerScore[0] + playerScore[1] == maxBoxes){
        if (playerScore[0] > playerScore[1]){
            alert('Player 1 wins!');
        }
        else if (playerScore[0] < playerScore[1]){
            alert('Player 2 wins!');
        }
        else{
            alert('It\'s a tie!');
        }
    }
}

function ResetBoard(){
    map.length = 0;
    playerTurn = 1;
    playerScore = [0, 0];
    BuildBoard();
}

function UndoMove(){
    map[lastMove[0]][lastMove[1]] = '0' + map[lastMove[0]][lastMove[1]][1];
    if (lastMove[2]){
        map[lastMove[3]][lastMove[4]] = '0' + map[lastMove[3]][lastMove[4]][1];
        playerScore[playerTurn-1] -= 1;
        if (playerTurn == 1) playerTurn = 2;
        else playerTurn = 1;
    }
    PrintBoard();
}

function Settings() {
    boardWidth = parseInt(document.getElementById('boardWidth').value);
    boardHeight = parseInt(document.getElementById('boardHeight').value);
    maxBoxes = (boardHeight - 1) * (boardWidth - 1);
    ResetBoard();
}

BuildBoard();