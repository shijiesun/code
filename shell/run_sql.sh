#!/bin/bash
#author:ssj

logtime=`date -d "now" "+%Y-%m-%d %H:%M:%S %N"`

function log() {
    printf "[$logtime]:$@\n"
}

function err() {
    log "$@" 1>&2;
    log "$@"
}

function isValidDate(){
    date -d "$1" "+%F"|grep -q "$1" 2>/dev/null
    if [ $? = 0 ]; then
        return 0
    else
        return 1
    fi
}

runfile() {
    log "exec: $0 $*"

    if [ $# -lt 2 ]
    then
        log "input error"
        return
    fi

    file=$1
    timestr=$2

    log "runfile($file, $timestr)"

    month=${timestr:0:4}${timestr:5:2}

    format=`cat $file`

    sql=`printf "$format\n" $month $timestr $timestr`

    if which hive 2>/dev/null
    then
        hive -e "$sql"
        log "finished todo"
    else
        err "not found command:hive"
        #log "hive -e \"$sql\""
    fi
}

runpath() {
    path=$PWD
    if [ $# -ge 1 ]
    then
        path=$1
    else
        err "you must pass a dictionary or a file"
        log "usage: ./runsql.sh [dictionary|file] [date]"
        log "       ./runsql.sh ."
        log "       ./runsql.sh . 2018-01-25"
        log "       ./run_sql.sh Bsnl_tapin_pre_ue.sql 2018-01-23"
        return
    fi


    timestr=`date -d "2 days ago" +%Y-%m-%d`
    if [ $# -gt 1 ]
    then
        timestr=$2
    fi

    date -d "$timestr" "+%F" > /dev/null

    if [ $? = 1 ]; then
        log "[$timestr] date format error"
        return
    fi

    if [ -d $path ]
    then
        for file in $path/*
        do
            if [ -f $file ]
            then
                if [[ "$file" == *.sql ]]
                then
                    runfile $file $timestr
                fi
            fi
        done
    elif [ -f $path ]
    then
        runfile $path $timestr
    else
        err "file[$path] is not exist!"
    fi


}

runpath $*
#runpath $* 1>>cal_day.log 2>>cal_error.log
