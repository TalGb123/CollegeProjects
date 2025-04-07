function showRandomPicture() {  
    let randomNumber = Math.floor(Math.random() * 10) + 1;
    if(randomNumber==1 || randomNumber==3 || randomNumber==6|| randomNumber==9)
        document.getElementById("main-image").src = "pic/pic" + randomNumber+".png" ;
    else{
        document.getElementById("main-image").src = "pic/pic" + randomNumber+".png" ;
    }

    
}

function inputShow() {
    let input = document.getElementById("text-input").value;
    if (input.length >= 4 && input.startsWith("pic")) {
        let imageNumber = input.substring(3);
        let imageExtension;
        
        if (imageNumber == '1' || imageNumber == '3' || imageNumber == '6' || imageNumber == '9') {
            imageExtension = ".png";
        } else {
            imageExtension = ".png";
        }
        
        document.getElementById("main-image").src = "pic/pic" + imageNumber + imageExtension;
    }
}


function changePictureFromSelect() {
    let selectedValue = document.getElementById("image-select").value;
    let imageNumber = selectedValue.substring(3);
    let imageExtension;

    if (imageNumber == '1' || imageNumber == '3' || imageNumber == '6' || imageNumber == '9') {
        imageExtension = ".png";
    } else {
        imageExtension = ".png";
    }

    document.getElementById("main-image").src = "pic/pic" + imageNumber + imageExtension;
 
}

function changeSize() {
    let borderSize = document.getElementById("size-range").value;
    document.getElementById("image-container").style.borderWidth = borderSize + "px";
    console.log("Border size changed to: " + borderSize + "px");
}

function changeBorderColor() {
    let borderColor = document.getElementById("color-picker").value;
    document.getElementById("image-container").style.borderColor = borderColor;
    console.log("Border color changed to: " + borderColor);
}

function makeCircle() {
    var container = document.getElementById("image-container");
    container.style.borderRadius = "50%";
}

function makeSquare() {
    var container = document.getElementById("image-container");
    container.style.borderRadius = "0";
}


