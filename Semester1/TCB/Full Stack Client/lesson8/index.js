let interval;

function startTimer() {
    let hours = parseInt(document.getElementById('alarmHours').value);
    let minutes = parseInt(document.getElementById('alarmMinutes').value);

    if (isNaN(hours) || hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
        alert('Invalid time');
        return;
    }

    let now = new Date();
    let alarm = new Date(now.getTime() + hours * 60 * 60 * 1000 + minutes * 60 * 1000);
    let timeToAlarm = alarm - now;

    interval = setInterval(() => {
        now = new Date();
        timeToAlarm = alarm - now;

        if (timeToAlarm <= 0) {
            clearInterval(interval);
            document.getElementById('timer').innerHTML = 'Time is up!';
            window.open('https://www.youtube.com/watch?v=dQw4w9WgXcQ', '_blank');
            resetTimer();
        } else {
            let hoursRemaining = Math.floor(timeToAlarm / (1000 * 60 * 60));
            let minutesRemaining = Math.floor((timeToAlarm % (1000 * 60 * 60)) / (1000 * 60));
            let secondsRemaining = Math.floor((timeToAlarm % (1000 * 60)) / 1000);
            document.getElementById('timer').innerHTML = `${hoursRemaining}h ${minutesRemaining}m ${secondsRemaining}s`;
        }
    }, 1000);
}

function resetTimer() {
    clearInterval(interval);
    document.getElementById('timer').innerHTML = '';
    document.getElementById('alarmHours').value = '';
    document.getElementById('alarmMinutes').value = '';
}