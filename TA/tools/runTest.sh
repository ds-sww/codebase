#!/bin/sh

# @author whimsycwd
# @date   2014.9.20
# @description  
#     simple tools for auto test

#  How to Use
#  Step One : Modify Root
#  Step Two : alias runTest='${ROOT}/TA/tools/runTest.sh' ( need to replace ROOT with actual value) 

# Configuration

ROOT=/Users/whimsy/WorkDir/codebase/


if [ $# != 3 ]; then 
    echo "Usage: $0 ID assignmentX problemName "
    echo "e.g.  $0 11300240057 assignment0 Add"
    exit -1
fi


# back to root directory 
cd ${ROOT}



files=(`find . | grep $3_ | grep $2 |grep in`)


cd $1/$2/src
g++ $3.cpp -o $3

for var in ${files[@]} 
do
    inputFile=${ROOT}/${var}
    len=`echo ${#inputFile} - 3 | bc`
    outputFile=${inputFile:0:len}.out
    ./$3 <  ${ROOT}/${var} > tmp.out
    Result=${var} 
    
    diffNum=`diff tmp.out ${outputFile} | wc -l`

    if [ ${diffNum} != 0 ]; then 
        Result=${Result}"  [WA]  "
    else 
        Result=${Result}"  [AC]  "
    fi
    echo ${Result}
done

rm tmp.out
rm $3


