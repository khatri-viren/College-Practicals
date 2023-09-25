<?php 

$conn = new mysqli('localhost', 'root', '', 'college');

if($conn->connect_error){
    echo("error");
} else {
    // echo("Successfully Connected");
    
}

$name = $_POST['name'];
$school = $_POST['school'];
$pnumber = $_POST['pnumber'];
$email = $_POST['email'];
$state = $_POST['state'];
$city = $_POST['city'];
$country = $_POST['country'];
$pincode = $_POST['pincode'];


$sql = "INSERT INTO user (name, school, pnumber, email, state, city, country, pincode) VALUES ('$name', '$school', '$pnumber', '$email', '$state', '$city', '$country', $pincode)";

if ($conn->query($sql)){
    echo("Successfully entered data");
} else {
    echo("Error entering data");
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>home</title>
    <style>
        form{
            display: flex;
            flex-direction: column;
        }

        input, select, button{
            width: 18rem;
            margin: 1rem 0rem;
            padding: 5px;
        }
    </style>
</head>
<body>
<form>
    <h1>Home</h1>
        <label for="name">Name</label>
        <input type="text" name="name" id="" value="<?= $_POST['name'] ?>" disabled>
        <label for="school">School</label>
        <input type="text" value="<?= $_POST['school'] ?>" disabled>
        <!-- <select name="school" id="" value="<?= $_POST['school'] ?>">
            <option value="SCET">SCET</option>
            <option value="Law">Law</option>
            <option value="Business">Business</option>
        </select> -->
        <label for="pnumber">Phone Number</label>
        <input type="number" name="pnumber" id="" value="<?= $_POST['pnumber'] ?>" disabled>
        <label for="email">Email</label>
        <input type="email" name="email" id="" value="<?= $_POST['email'] ?>" disabled>
        <label for="state">State</label>
        <input type="text" name="state" id="" value="<?= $_POST['state'] ?>" disabled>
        <label for="city">City</label>
        <input type="text" name="city" id="" value="<?= $_POST['city'] ?>" disabled>
        <label for="country">Country</label>
        <input type="text" value="<?= $_POST['country'] ?>" disabled>
        <!-- <select name="country" id="" disabled="disabled">
            <option value="India" selected>India</option>
            <option value="USA" selected>USA</option>
        </select> -->
        <label for="pincode">Pincode</label>
        <input type="number" name="pincode" id="" value="<?= $_POST['pincode'] ?>" disabled>
        <button type="submit">Submit</button>
    </form>
</body>
</html>