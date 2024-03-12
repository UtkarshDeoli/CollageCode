var colorChange;
var times = 0;
var isTimerRunning = false;

function startTimer() {
    colorChange = setTimeout(addSecond, 1000);
}

function stopTimer() {
    clearTimeout(colorChange);
    times = 0;
    isTimerRunning = false;
}

function addSecond()
{
    times=times+1;
    document.getElementById('time').innerText=times;
    startTimer();
}