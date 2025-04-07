function phoneCheck(){
    let phone = document.getElementById('phone').value;
    if (phone.length == 10){
        if (phone.startsWith('05') && /^\d+$/.test(phone)){
            document.getElementById('result').innerHTML = 'Valid Phone Number';
        }
    }
    else{
        document.getElementById('result').innerHTML = 'Invalid Phone Number';
    }
}

function emailCheck(){
    let email = document.getElementById('email').value;
    if (email.includes('@') && email.includes('.com') && email[0] != "."){
        document.getElementById('result').innerHTML = 'Valid Email';
    }
    else{
        document.getElementById('result').innerHTML = 'Invalid Email';
    }
}

function nameCheck() {
    let name = document.getElementById('name').value;
    if (name.length > 0 && /^[A-Za-z\s]+$/.test(name)) {
        document.getElementById('result').innerHTML = 'Valid Name';
    } else {
        document.getElementById('result').innerHTML = 'Invalid Name';
    }
}

function date(){
    let date = new Date();
    document.getElementById('result').innerHTML = 'The date is ' + date.toLocaleDateString();
}
function time(){
    let time = new Date();
    document.getElementById('result').innerHTML = 'The time is ' + time.toLocaleTimeString();
}