document.addEventListener('DOMContentLoaded', function() {
    const form = document.querySelector('form[id="form1"]');
    const validationAlert = document.getElementById('validationAlert');

    form.addEventListener('submit', function(event) {
        event.preventDefault();
        let isValid = true;
        validationAlert.style.display = 'none'; // Hide the alert
        validationAlert.innerHTML = ''; // Clear previous validation messages


        // Name validation
        const name = document.querySelector('input[name="name"]');
        if (name.value.trim() === '') {
            isValid = false;
            appendValidationMessage('Name cannot be empty');
        }

        // Phone number validation
        const phoneNumber = document.querySelector('input[name="pnumber"]');
        const phoneNumberRegex = /^\d{10}$/;
        if (!phoneNumberRegex.test(phoneNumber.value.trim())) {
            isValid = false;
            appendValidationMessage('Please enter a valid 10-digit phone number');
        }

        // Email validation
        const email = document.querySelector('input[name="email"]');
        const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        if (!emailRegex.test(email.value.trim())) {
            isValid = false;
            appendValidationMessage('Please enter a valid email address');
        }

        // State validation
        const state = document.querySelector('input[name="state"]');
        if (state.value.trim() === '') {
            isValid = false;
            appendValidationMessage('State cannot be empty');
        }

        // City validation
        const city = document.querySelector('input[name="city"]');
        if (city.value.trim() === '') {
            isValid = false;
            appendValidationMessage('City cannot be empty');
        }

        // Pincode validation
        const pincode = document.querySelector('input[name="pincode"]');
        const pincodeRegex = /^\d{6}$/;
        if (!pincodeRegex.test(pincode.value.trim())) {
            isValid = false;
            appendValidationMessage('Please enter a valid 6-digit pincode');
        }

        const password = document.querySelector('input[name="password"]');
        var passwordRegex = /^(?=.*[A-Z])(?=.*\d)(?=.*[@#$&]).{7,}$/;
        if (!passwordRegex.test(password)) {
            appendValidationMessage("Password must be at least 7 characters long and contain at least one capital letter, one digit, and one special character from [&,$,#@].");
        }

        const password1 = document.querySelector('input[name="password1"]');
        if (password !== password1) {
            appendValidationMessage("Passwords do not match.");
            event.preventDefault();
        }

        if (!isValid) {
            // Prevent form submission if there are validation errors
             
            validationAlert.style.display = 'block';
            return;
        }
    });

    function appendValidationMessage(message) {
        validationAlert.innerHTML += `<p>${message}</p>`;
    }

    
});
