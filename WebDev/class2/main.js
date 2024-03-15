var timerfuntion;
var hour =0;
var minutes=0;
var seconds=0;
var isTimerRunning = false;

function startTimer() {
    timerfuntion = setInterval(addSecond, 1000);//setTimeout()
}

function stopTimer() {
    clearInterval(timerfuntion);//clearTimeout()
    times = 0;
    document.getElementById('sec').innerText=seconds;
    isTimerRunning = false;
}

function addSecond()
{
    seconds++;
    if(seconds==60)
    {
        seconds=0;
        minutes++;
        document.getElementById('minutes').innerText=minutes.toString().padStart(2, '0');
    }
    if(minutes==60)
    {
        minutes=0;
        document.getElementById('minutes').innerText=minutes.toString().padStart(2, '0');
        hour++;
        document.getElementById('hour').innerText=hour.toString().padStart(2, '0');
    }
    document.getElementById('sec').innerText=seconds.toString().padStart(2, '0');
    //call s
}


function getID()
{
    var fromUnit = document.getElementById('from').value;
    var toUnit = document.getElementById('to').value;


}
