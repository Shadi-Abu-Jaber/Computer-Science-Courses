echo shadi
echo OLDPWD
mkdir Lab2
cd Lab2
mkdir TryDir EmptyDir
touch foo1
cd TryDir
touch foo1 foo2 foo3
ls
ls -a
ls -l
ls -la
ls -latr
touch foo1
ls -l
cd ..
echo $OLDPWD
cd ./TryDir
echo $OLDPWD 
echo $shadi
pwd
