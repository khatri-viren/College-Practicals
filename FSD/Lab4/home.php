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
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f7f7f7;
        }

        h1 {
            text-align: center;
        }

        a {
            display: block;
            margin: 1rem auto;
            text-align: center;
            text-decoration: none;
            color: #333;
            font-weight: bold;
        }

        a:hover {
            color: #555;
        }

        form {
            max-width: 400px;
            margin: 2rem auto;
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

        hr {
            border: 1px solid #ccc;
            margin: 1rem 0;
        }

    </style>
</head>

<body>
    <h1>Home</h1>
    <a href="index.php">Form Page</a>
    <div class="container">

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
                <button type="submit" value="update" name="update">Update</button>

                <button type="submit" name="delete" value="delete">Delete</button>
                </form>
                <hr>
            <?php } ?>
    </div>
</body>

</html>