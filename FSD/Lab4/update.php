<?php

require_once('connect.php');

// echo "<pre>";
// print_r($_POST);
// die;



if (isset($_POST['update'])) {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $school = $_POST['school'];
    $pnumber = $_POST['pnumber'];
    $email = $_POST['email'];
    $state = $_POST['state'];
    $city = $_POST['city'];
    $country = $_POST['country'];
    $pincode = $_POST['pincode'];

  

$sql = "UPDATE user 
SET name = '$name', school = '$school', pnumber = $pnumber, email = '$email', state = '$state', city='$city', country='$country', pincode = '$pincode'
WHERE id = $id";

   


if ($conn->query($sql)) {
    header('Location: home.php');
    echo ("Successfully updated data");
} else {
    header('Location: home.php');
    echo ("Error updating data");
}
}

// Deletion
if(isset($_POST['delete'])){
    $id = $_POST['id'];


$sql = "DELETE FROM user WHERE id = $id";
if ($conn->query($sql)) {
    header('Location: home.php');
    echo ("Successfully deleted data");
} else {
    header('Location: home.php');
    echo ("Error deleting data");
}

}