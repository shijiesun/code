#!/bin/bash
#author:ssj

function isValidDate(){
    date -d "$1" "+%F"|grep -q "$1" 2>/dev/null
    if [ $? = 0 ]; then
        return 0
    else
        return 1
    fi
}

runfile() {
    echo "exec: $0 $*"

    if [ $# -lt 2 ]
    then
        echo "input error"
        return
    fi

    file=$1
    timestr=$2

    echo "runfile($file, $timestr)"

    month=${timestr:0:4}${timestr:5:2}

    format=`cat $file`

    sql=`printf "$format\n" $month $timestr $timestr`

    if which hive 2>/dev/null
    then
        hive -e "$sql"
    else
        echo "not found command:hive"
        echo "hive -e \"$sql\""
    fi
}

runpath() {
    path=$PWD
    if [ $# -ge 1 ]
    then
        path=$1
    else
        echo "you must pass a dictionary or a file"
        echo "usage: ./runsql.sh [dictionary|file] [date]"
        echo "       ./runsql.sh ."
        echo "       ./runsql.sh . 2018-01-25"
        echo "       ./run_sql.sh Bsnl_tapin_pre_ue.sql 2018-01-23"
        return
    fi

    #timestr=`date -d "now" +%Y-%m-%d`
    timestr=`date -d "2 days ago" +%Y-%m-%d`
    if [ $# -gt 1 ]
    then
        timestr=$2
    fi

    date -d "$timestr" "+%F" > /dev/null

    if [ $? = 1 ]; then
        echo "[$timestr] date format error"
        return
    fi

    if [ -d $path ]
    then
        for file in $path/*
        do
            if [ -f $file ]
            then
                runfile $file $timestr
            fi
        done
    elif [ -f $path ]
    then
        runfile $path $timestr
    else
        echo "file[$path] is not exist!"
    fi


}

runpath $*
