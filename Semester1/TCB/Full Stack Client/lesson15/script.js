const gameBoard = document.getElementById('game-board');
const boardSize = 10;
let playerPosition = [8, 1];
const map = [
    ['#', '#', '#', '#', '#', '#', '#', '#', '#', '#'],
    ['#', '.', '.', '.', '.', '.', '.', '.', '.', '#'],
    ['#', '.', '#', '#', '#', '#', '#', '#', '.', '#'],
    ['#', '.', '#', 'G', 'G', '.', '.', '#', '.', '#'],
    ['#', '.', '#', 'B', 'B', '.', '.', '#', '.', '#'],
    ['#', '.', '#', '.', '.', '.', '.', '#', '.', '#'],
    ['#', '.', '#', '#', '#', '#', '#', '#', '.', '#'],
    ['#', '.', '.', '.', '.', '.', '.', '.', '.', '#'],
    ['#', 'P', '.', '.', '.', '.', '.', '.', '.', '#'],
    ['#', '#', '#', '#', '#', '#', '#', '#', '#', '#']
];

function createBoard() {
    gameBoard.innerHTML = '';
    for (let y = 0; y < map.length; y++) {
        for (let x = 0; x < map[y].length; x++) {
            const cell = document.createElement('div');
            cell.classList.add('cell');
            if (map[y][x] === '#') {
                cell.classList.add('wall');
            } else if (map[y][x] === 'P') {
                cell.classList.add('player');
                playerPosition = [y, x];
            } else if (map[y][x] === 'B') {
                cell.classList.add('box');
            } else if (map[y][x] === 'G') {
                cell.classList.add('goal');
            }
            gameBoard.appendChild(cell);
        }
    }
}

addEventListener("keydown", (event) => {
    onKeyPress(event.key);
});

function onKeyPress(key) {
    console.log(key);
    switch (key) {
        case "ArrowUp":
            updatePlayer("up");
            break;
        case "ArrowDown":
            updatePlayer("down");
            break;
        case "ArrowLeft":
            updatePlayer("left");
            break;
        case "ArrowRight":
            updatePlayer("right");
            break;
    }
}

function updatePlayer(dir) {
    let newY = playerPosition[0];
    let newX = playerPosition[1];

    switch (dir) {
        case "up":
            newY -= 1;
            break;
        case "down":
            newY += 1;
            break;
        case "left":
            newX -= 1;
            break;
        case "right":
            newX += 1;
            break;
    }

    if (map[newY][newX] === '.') {
        map[playerPosition[0]][playerPosition[1]] = '.';
        playerPosition = [newY, newX];
        map[playerPosition[0]][playerPosition[1]] = 'P';
        createBoard();
    }
}

createBoard();