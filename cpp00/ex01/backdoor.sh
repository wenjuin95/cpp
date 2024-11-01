#!/bin/bash

# Run the phonebook program and automate input using expect
expect << EOF
set timeout 1
spawn ./phonebook

# Add 8 contacts
for {set i 1} {\$i <= 8} {incr i} {
    expect "Enter your command (ADD, SEARCH, EXIT):"
    send "add\r"
    expect "Enter first name:"
    send "Firstname\$i\r"
	expect "Enter last name:"
	send "Lastname\$i\r"
	expect "Enter nick name:"
	send "Nickname\$i\r"
    expect "Enter phone number:"
    send "123456789\$i\r"
    expect "Enter dark secret:"
    send "i'm a spy\$i\r"
}

# Search for the contacts
expect "Enter your command (ADD, SEARCH, EXIT):"
send "search\r"
for {set i 1} {\$i <= 8} {incr i} {
	expect "ENTER INDEX TO DISPLAY CONTACT \\[1 - 8\\]:"
	send "\$i\r"
}
send "back\r"

# add one more contact
expect "Enter your command (ADD, SEARCH, EXIT):"
send "add\r"
expect "Enter first name:"
send "Firstname9\r"
expect "Enter last name:"
send "Lastname9\r"
expect "Enter nick name:"
send "Nickname9\r"
expect "Enter phone number:"
send "1111111111\r"
expect "Enter dark secret:"
send "i'm a spy9\r"

# Search for the contacts
expect "Enter your command (ADD, SEARCH, EXIT):"
send "search\r"
expect "ENTER INDEX TO DISPLAY CONTACT \\[1 - 8\\]: "
send "1\r"
expect "ENTER INDEX TO DISPLAY CONTACT \\[1 - 8\\]: "
send "exit\r"
expect eof

EOF