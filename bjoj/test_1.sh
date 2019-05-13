while [[ $? == 0 ]]; do
	./test.exe > input.txt
	./1108.exe < input.txt
done
