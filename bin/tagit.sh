
if [ $# -eq 0 ]
  then
    echo "No arguments supplied"
    exit
fi

echo $1
git add .; git commit -m "Added $1"; git push
git tag -a $1 -m "added $1 $2 $3 $4 $5 $6 $7 $8 $9 "
git push origin $1
