#!/bin/bash

# Check if a commit message is provided
if [ -z "$1" ]; then
  echo "❌ Error: Please provide a commit message."
  exit 1
fi

# Add all changes
git add .

# Commit with provided message
git commit -m "$1"

# Push to the main branch
git push origin main

# Success message
echo "✅ Successfully uploaded solution to GitHub!"

