shopt -s extglob dotglob nullglob

for file in ~/Downloads/logo/*.in.*; 
do
  output=`echo "$file" | sed -e 's/in/out/'`
# output="${file}"
  echo ${file}
  echo ${output}
  ./sol < ${file} | diff -b - ${output}
done
