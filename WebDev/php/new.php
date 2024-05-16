<?php

// Database connection settings
$servername = "localhost";
$username = "root";
$password = "122002";
$database = "GrophicError";


$conn = new mysqli($servername, $username, $password);


if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Create database if it doesn't exist
$sql_create_db = "CREATE DATABASE IF NOT EXISTS $database";
if ($conn->query($sql_create_db) === TRUE) {
    echo "Database created successfully<br>";
} else {
    echo "Error creating database: " . $conn->error;
}


// Select the created database
$conn->select_db($database);


// Create school table if it doesn't exist
$sql_create_table = "CREATE TABLE IF NOT EXISTS school (
    id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    location VARCHAR(100) NOT NULL
)";


if ($conn->query($sql_create_table) === TRUE) {
    echo "Table 'school' created successfully<br>";
} else {
    echo "Error creating table: " . $conn->error;
}


// Insert sample data into the school table
$sql_insert_data = "INSERT INTO school (name, location) VALUES 
    ('School A', 'Location A'),
    ('School B', 'Location B'),
    ('School C', 'Location C')";



if ($conn->query($sql_insert_data) === TRUE) {
    echo "Sample data inserted into 'school' table successfully<br>";
} else {
    echo "Error inserting data: " . $conn->error;
}

// Read data from the "school" table
$sql_read_data = "SELECT * FROM school";
$result = $conn->query($sql_read_data);

if ($result->num_rows > 0) {
    // Output data of each row
    while($row = $result->fetch_assoc()) {
        echo "ID: " . $row["id"]. " - Name: " . $row["name"]. " - Location: " . $row["location"]. "<br>";
    }
} else {
    echo "0 results";
}

$conn->close();
?>