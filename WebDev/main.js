// Write a js program to replace the text of a para with "HelloWorld!"
// the original text is the world is beautiful;// on the click of a button
var i=0;
function changeText()
{
    var string='Hello Times:'+i;
    document.getElementById('para').innerHTML=string;
    
    if(i==10)
        document.getElementById('vella').innerHTML='Kitna vella hai bhai!';
    if(i==20)
        {document.getElementById('vella').innerHTML='Kuch jada hi vella hai firr zero kar dunga agar click kia to!';
        i=0;}
    i++;
}
function fun()
{
    document.getElementById('para').innerHTML='Hello World';
}


// change backgrounf color of para to red on hover ans yellow on mouse out of para

function onHover(){
    document.getElementById('click').onmouseenter.innerHTML='Dont click here';
}
function test(){
    var i=0;
    while(i++<5)
        console.log(i);
    if(0)
        console.log('bsdk')
    
        console.log('No')
}



// write a JS program to convert foot to inches and vice versa


function inchToFoot()
{
    let x =document.getElementById('inch').value;
    let ans = ''+(x/12)
    document.getElementById('foot').value=ans;
    
}

function footToInches()
{
    let x =document.getElementById('foot').value;
    let ans = ''+(x*12)
    document.getElementById('inch').value=ans;
}

function changeText()
{
    if(document.getElementById('inch').value)
    {inchToFoot()}
    else
    {footToInches()

    }
}