#!/bin/bash
while true
do
    git add .
    git commit -m "Auto-commit at $(date)"
    git push origin main
    sleep 600  # Wait for 10 minutes (600 seconds)
done
