echo "[ uname -a ]"
uname -a
echo "[ ls -l /etc/*release* ]"
ls -l /etc/*release*
echo "[ cat /etc/*release* ]"
cat /etc/*release*
echo "[ bash --version ]"
bash --version
echo "[ lua -v ]"
lua -v
echo "[ lua -e 'os.execute(\"echo \$SHELL\")' ]"
lua -e 'os.execute("echo $SHELL")'
