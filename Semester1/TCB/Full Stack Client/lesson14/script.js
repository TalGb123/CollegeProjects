let board_length = 13;
let selectedColor = 'red';

document.addEventListener('DOMContentLoaded', (event) => {
    StartBoard();
});

function StartBoard() {
    let boardContainer = document.getElementById('boardContainer');
    boardContainer.innerHTML = '';
    boardContainer.style.gridTemplateColumns = `repeat(${board_length}, 30px)`;

    for (let i = 1; i <= board_length ** 2; i++) {
        let btn = document.createElement('button');
        btn.id = i;
        btn.onclick = function() { draw(this); };
        boardContainer.appendChild(btn);
    }
}

function ResetBoard() {
    let buttons = document.querySelectorAll('#boardContainer button');
    buttons.forEach(button => {
        button.style.background = '';
    });
}

function draw(button) {
    button.style.background = selectedColor;
}

function selectColor(color) {
    selectedColor = color;
}

function updateBoardSize(size) {
    board_length = size;
    document.getElementById('boardSizeValue').textContent = size;
    StartBoard();
}