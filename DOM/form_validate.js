function validateForm() {
    clearErrors();

    var name = document.forms["form"]["name"].value;
    var email = document.forms["form"]["email"].value;

    //Regular Expression
    var nameRegex = /^[A-Za-z\s]+$/;
    var emailRegex = /^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$/;
    var passwordRegex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[a-zA-Z\d]{8,}$/;
    var phoneRegex = /^\d{3}-\d{3}-\d{4}$/;
    var birthdayRegex = /^\d{2}\/\d{2}\/\d{4}$/;

    var isValid = true;

    if(!nameRegex.test(name)) {
        document.getElementById("nameError").innerHTML = "*Please enter a valid name";
        isValid = false;
    }

    return isValid;


}

function clearErrors() {
    var errorElements = document.getElementsByClassName("error");
    for (let i = 0; i < errorElements.length; i++) {
        errorElements[i].innerHTML = "";
    }
}