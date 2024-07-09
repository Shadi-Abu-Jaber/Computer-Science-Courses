#!/bin/bash
date=$(date)
user_name=$(whoami)
host_name=$(hostname)

echo "Date: $date"
echo "Username: $user_name"
echo "Hostname: $host_name"

echo -e "\nAliases for this user:\n"
alias

echo -e "\nEnvironment Variables:\n"
env_vars=$(printenv)
echo "$env_vars"

if [ $? -eq 0 ]; then
    echo -e "\nUser last command executed successfully"
else
    echo -e "\nUser Last command did not execute successfully"
fi
