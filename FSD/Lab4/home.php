<?php

require_once('connect.php');
// echo "<pre>";
// print_r($_POST);
// die;

if (isset($_POST['form'])) {
    $name = $_POST['name'];
    $school = $_POST['school'];
    $pnumber = $_POST['pnumber'];
    $email = $_POST['email'];
    $state = $_POST['state'];
    $city = $_POST['city'];
    $country = $_POST['country'];
    $pincode = $_POST['pincode'];


    $sql = "INSERT INTO user (name, school, pnumber, email, state, city, country, pincode) VALUES ('$name', '$school', '$pnumber', '$email', '$state', '$city', '$country', $pincode)";

    if ($conn->query($sql)) {
        echo ("Successfully entered data");
        unset($_POST);
    } else {
        echo ("Error entering data");
    }
}



$sql = 'SELECT * FROM user LIMIT 5';
$res = $conn->query($sql);
$users = [];
while ($row = $res->fetch_assoc()) {
    $users[] = $row;
}

// echo "<pre>";
// print_r($users);
// die;

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>home</title>
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
    <h1>Home</h1>
    <a href="index.php">Form Page</a>
    <!-- <form>
        <h1>Home</h1>
        <label for="name">Name</label>
        <input type="text" name="name" id="" value="<?= $_POST['name'] ?>" disabled>
        <label for="school">School</label>
        <input type="text" value="<?= $_POST['school'] ?>" disabled>
        <select name="school" id="" value="<?= $_POST['school'] ?>">
            <option value="SCET">SCET</option>
            <option value="Law">Law</option>
            <option value="Business">Business</option>
        </select>
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
        <select name="country" id="" disabled="disabled">
            <option value="India" selected>India</option>
            <option value="USA" selected>USA</option>
        </select>
        <label for="pincode">Pincode</label>
        <input type="number" name="pincode" id="" value="<?= $_POST['pincode'] ?>" disabled>
        <button type="submit">Submit</button>
    </form> -->
    <?php
    foreach ($users as $user) {
        foreach ($user as $key => $value) { ?>
            <form method="post" action="update.php">
                <?php if ($key == 'id') {
                    echo "<input type='hidden' name='$key' value='$value'>";
                } ?>
                <span><?= $key ?>:</span>
                <input type="text" name="<?= $key ?>" value="<?= $value ?>" id=""><br>
            <?php } ?>
            <button type="submit">Update</button>
            <button type="submit" name="delete" value="delete">Delete</button>
            </form>
            <br>
        <?php } ?>
</body>

</html>