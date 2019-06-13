while [[ $? == 0 ]]
do
	./test > input.txt 
	./sol < input.txt > /dev/null
done

