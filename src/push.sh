#!/bin/bash
echo "Ajout fichiers..."
git add .
echo "Commit modifications..."
git commit -m "Auto-commit: $(date '+%Y-%m-%d %H:%M:%S')"
echo "Push vers GitHub..."
git push origin master
echo "Terminé!"
