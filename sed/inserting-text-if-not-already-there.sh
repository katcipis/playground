
INSERTED_TEXT="set tags+=~/path/to/ctags/sed/example"
ESCAPED_INSERTED_TEXT="set tags+=~\/path\/to\/ctags\/sed\/example"
FILE="example.txt"
echo "inserting: '"$INSERTED_TEXT"' on file:' "$FILE"'"
eval "sed '/"$ESCAPED_INSERTED_TEXT"/ d' -i "$FILE
echo $INSERTED_TEXT >> $FILE
