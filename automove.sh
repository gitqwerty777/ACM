for f in *; do # iterate all files
    tagflag=`echo $f|awk '{print match($0,"\[")}'`;

    outflag=`echo $f|awk '{print match($0,"output")}'`;
    inflag=`echo $f|awk '{print match($0,"input")}'`;
    tmpflag=`echo $f|awk '{print match($0,"tmp")}'`;
    flag=$((inflag+outflag+tmpflag));
    if [ $flag -gt 0 ];then
	echo "Move File $f to testdata";
	mv $f testdata/
    elif [ $tagflag -gt 0 ];then
	echo "Move File $f to categorized";
	mv $f categorized/
    fi
done

if [ -e "a" ];then
    rm a
fi
if [ -e "a.out" ];then
    rm a.out
fi
if [ -e "test" ];then
    rm test
fi

