git add . 
read -p "Commit description: " desc
echo $desc 
git commit -m "$desc"
git push origin HEAD
