<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Form Something</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f7f7f7;
        }

        h1 {
            text-align: center;
            margin-bottom: 20px;
        }

        a {
            display: block;
            margin-bottom: 20px;
            text-align: center;
            text-decoration: none;
            color: #333;
            font-weight: bold;
        }

        form {
            max-width: 400px;
            margin: 0 auto;
            background-color: #fff;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
        }

        label {
            font-weight: bold;
            margin-bottom: 0.5rem;
            display: block;
        }

        input,
        select {
            width: calc(100% - 10px);
            padding: 8px;
            margin-bottom: 1rem;
            border: 1px solid #ccc;
            border-radius: 4px;
            box-sizing: border-box;
        }

        button {
            padding: 10px 20px;
            background-color: #007bff;
            color: #fff;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            font-size: 16px;
        }

        button:hover {
            background-color: #0056b3;
        }
    </style>
</head>

<body>
    <h1>Form Something</h1>
    <a href="home.php">Home page</a><br><br>
    <form action="home.php" method="post">
        <input type="hidden" name="form" value='formsubmit'>
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
    <script>
        document.addEventListener('DOMContentLoaded', () => {
            const form = document.querySelector('form');

            form.addEventListener('submit', (event) => {
                let isValid = true;
                let errorMessages = [];

                // Name validation
                const name = document.querySelector('input[name="name"]');
                if (name.value.trim() === '') {
                    isValid = false;
                    errorMessages.push('Name cannot be empty');
                }

                // Phone number validation
                const phoneNumber = document.querySelector('input[name="pnumber"]');
                const phoneNumberRegex = /^\d{10}$/;
                if (!phoneNumberRegex.test(phoneNumber.value.trim())) {
                    isValid = false;
                    errorMessages.push('Please enter a valid 10-digit phone number');
                }

                // Email validation
                const email = document.querySelector('input[name="email"]');
                const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
                if (!emailRegex.test(email.value.trim())) {
                    isValid = false;
                    errorMessages.push('Please enter a valid email address');
                }

                // State validation
                const state = document.querySelector('input[name="state"]');
                if (state.value.trim() === '') {
                    isValid = false;
                    errorMessages.push('State cannot be empty');
                }

                // City validation
                const city = document.querySelector('input[name="city"]');
                if (city.value.trim() === '') {
                    isValid = false;
                    errorMessages.push('City cannot be empty');
                }

                // Pincode validation
                const pincode = document.querySelector('input[name="pincode"]');
                const pincodeRegex = /^\d{6}$/;
                if (!pincodeRegex.test(pincode.value.trim())) {
                    isValid = false;
                    errorMessages.push('Please enter a valid 6-digit pincode');
                }

                if (!isValid) {
                    event.preventDefault(); // Prevent form submission if there are validation errors
                    alert(errorMessages.join('\n')); // Display all error messages in a single alert
                }
            });
        });
    </script>
</body>

</html>