#!/bin/bash

git add .
read -p "Descripción del commit: " DESC
git commit -m "$DESC"
git push origin HEAD
