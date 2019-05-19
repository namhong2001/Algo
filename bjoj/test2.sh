for file in ~/Downloads/data/secret/*.in
do
  output=`echo "$file" | sed -e 's/in$/ans/'`
  echo ${file}
  echo ${output}
  ./sol < ${file} | diff -b - ${output}
done
