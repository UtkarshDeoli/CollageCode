function validateForm() {
    var name = document.getElementById("name").value;
    var age = document.getElementById("age").value;
    var mobile = document.getElementById("mobile").value;
    var email = document.getElementById("email").value;
    var password = document.getElementById("password").value;
    var sname = document.getElementById("Sname").value;
    // Regular expressions for validation
    var nameRegex = /^[a-zA-Z\s]+$/;
    var snameRegex = /^[a-zA-z\s]+$/
    var ageRegex = /^[0-9]+$/;
    var mobileRegex = /^[0-9]{10}$/;
    var emailRegex = /^\S+@\S+\.\S+$/;
    var passwordRegex = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,}$/;

    // Validation
    if (!nameRegex.test(name)) {
        alert("Please enter a valid name.");
        return false;
    }
    if(!snameRegex.test(sname)){
        alert("Enter Surname");
        return false;
    }
    
    if (!ageRegex.test(age)) {
        alert("Please enter a valid age.");
        return false;
    }
    
    if (!mobileRegex.test(mobile)) {
        alert("Please enter a valid mobile number.");
        return false;
    }
    
    if (!emailRegex.test(email)) {
        alert("Please enter a valid email address.");
        return false;
    }
    
    if (!passwordRegex.test(password)) {
        alert("Password must be at least 8 characters long, contain at least one numeric digit, one uppercase and one lowercase letter.");
        return false;
    }
    
    // If all validations pass
    alert('Form Submitted');
    return true;
}


function calculate()
{
    var num1 = document.getElementById("num1").value;
    var num2 = document.getElementById("num2");
    var n = num1*100;
    num2.value=n;
}
function calculate2()
{
    var num1 = document.getElementById("num2").value;
    var num2 = document.getElementById("num1");
    var n = num1/100;
    num2.value=n;
}