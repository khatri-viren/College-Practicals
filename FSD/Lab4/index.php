<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Form Something</title>
    <style>
        form {
            display: flex;
            flex-direction: column;
        }

        input,
        select,
        button {
            width: 18rem;
            margin: 1rem 0rem;
            padding: 5px;
        }
    </style>
</head>

<body>
    <h1>Form Something</h1>
    <form action="home.php" method="post">
        <label for="name">Name</label>
        <input type="text" name="name" id="">
        <label for="school">School</label>
        <select name="school" id="">
            <option value="SCET">SCET</option>
            <option value="Law">Law</option>
            <option value="Business">Business</option>
        </select>
        <label for="pnumber">Phone Number</label>
        <input type="number" name="pnumber" id="">
        <label for="email">Email</label>
        <input type="email" name="email" id="">
        <label for="state">State</label>
        <input type="text" name="state" id="">
        <label for="city">City</label>
        <input type="text" name="city" id="">
        <label for="country">Country</label>
        <input list="countries" name="country" id="">
        <datalist id="countries">
            <option value="India" selected>India</option>
            <option value="USA">USA</option>
        </datalist>
        <label for="pincode">Pincode</label>
        <input type="number" name="pincode" id="">
        <button type="submit">Submit</button>
    </form>
</body>
<script>
    document.addEventListener('DOMContentLoaded', function() {
    const form = document.querySelector('form');

    form.addEventListener('submit', function(event) {
        let isValid = true;

        // Name validation
        const name = document.querySelector('input[name="name"]');
        if (name.value.trim() === '') {
            isValid = false;
            alert('Name cannot be empty');
        }

        // Phone number validation
        const phoneNumber = document.querySelector('input[name="pnumber"]');
        const phoneNumberRegex = /^\d{10}$/;
        if (!phoneNumberRegex.test(phoneNumber.value.trim())) {
            isValid = false;
            alert('Please enter a valid 10-digit phone number');
        }

        // Email validation
        const email = document.querySelector('input[name="email"]');
        const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        if (!emailRegex.test(email.value.trim())) {
            isValid = false;
            alert('Please enter a valid email address');
        }

        // State validation
        const state = document.querySelector('input[name="state"]');
        if (state.value.trim() === '') {
            isValid = false;
            alert('State cannot be empty');
        }

        // City validation
        const city = document.querySelector('input[name="city"]');
        if (city.value.trim() === '') {
            isValid = false;
            alert('City cannot be empty');
        }

        // Pincode validation
        const pincode = document.querySelector('input[name="pincode"]');
        const pincodeRegex = /^\d{6}$/;
        if (!pincodeRegex.test(pincode.value.trim())) {
            isValid = false;
            alert('Please enter a valid 6-digit pincode');
        }

        if (!isValid) {
            event.preventDefault(); // Prevent form submission if there are validation errors
        }
    });
});

</script>
</html>