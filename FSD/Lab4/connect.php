<?php

$conn = new mysqli('localhost', 'root', '', 'college');

if($conn->connect_error){
    echo("error");
} 

?>