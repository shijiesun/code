#!/bin/bash
#author:ssj

format="SELECT * FROM %s WHERE SERVED_MSISDN = %s AND START_TIME >='%s 00:00:00' AND START_TIME <'%s 00:00:00'"
run_hive_export="java -Dfile.encoding=utf8 -Djava.ext.dirs=./lib -cp hive-export.jar com.ztesoft.bdai.hive_export.HiveExport export"


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

run() {
    log "exec: $0 $*"

    if [ $# -ge 4 ]
    then
        tb=$1
        key=$2
        from=$3
        to=$4
    else
        log "usage: run [key] [from] [to]"
        return
    fi

    sql=`printf "$format" $tb $key $from $to`
    #echo "$sql"

    outtb=`date -d "now" "+%Y%m%d%H%M%S"`

    java_command=${run_hive_export}" \""${sql}"\" hive_export_"${outtb}

    echo "$java_command"

    eval "${java_command}"
}

run $*
