#!/bin/bash

# Check if commit message is provided
if [ -z "$1" ]; then
    echo "Usage: ./upload_solution.sh \"Your commit message\""
    exit 1
fi

# Add all changes to Git
git add .

# Commit the changes with the provided message
git commit -m "$1"

# Push the changes to the remote repository
git push origin main  # Change "main" to "master" if your default branch is master

echo "Solution uploaded successfully!"
