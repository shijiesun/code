drop table bsnl_intra_pre_hp_1;
drop table bsnl_intra_pre_hp_2;
drop table bsnl_intra_pre_hp_3;
drop table bsnl_intra_pre_hp_4;
drop table bsnl_intra_pre_hp_5;
drop table bsnl_intra_pre_hp_6;
drop table bsnl_intra_pre_hp_7;
drop table bsnl_intra_pre_hp_8;
drop table bsnl_intra_pre_hp_9;
drop table bsnl_intra_pre_hp_10;
drop table bsnl_intra_pre_hp_11;
drop table bsnl_intra_pre_hp_12;
drop table bsnl_intra_pre_hp_13;
drop table bsnl_intra_pre_hp_14;
drop table bsnl_intra_pre_hp_15;
drop table bsnl_intra_pre_hp_16;
drop table bsnl_intra_pre_hp_17;


create table bsnl_intra_pre_hp_1(
ROAM_CIRCLE string,
CHG_DT string,
DURATION int,
CIRCLE string,
CALL_TYPE string,
SERVICE_TYPR string
);

create table bsnl_intra_pre_hp_2 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_3 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_4 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_5 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_6 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_7 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_8 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_9 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_10 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_11 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_12 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_13 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_14 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_15 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_16 like bsnl_intra_pre_hp_1;
create table bsnl_intra_pre_hp_17 like bsnl_intra_pre_hp_1;


from (
select from_unixtime(cast(f.CALLDATETIME/1000+946684800 as int), 'yyyyMMdd') datestr, f.CALLDURATION, f.SUBSCRIPTIONTYPE, f.ORIGINATINGCIRCLE, f.LRN, f.B_PARTY_NUMBER, f.record_type
from TXE_MSC_DETAIL_1_p201711_htable
where f.record_type='MTC' and f.CALLDATETIME>=unix_timestamp('2017-11-01 00:00:00.0')*1000-946684800000 and f.CALLDATETIME<unix_timestamp('2017-12-01 00:00:00.0')*1000-946684800000
) as temp
insert OVERWRITE table bsnl_intra_pre_hp_1
select 'Haryana',datestr,sum(CALLDURATION),'HP','Local',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40434' and LRN in ('2397')
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_2
select 'Haryana',datestr,sum(CALLDURATION),'HP','NLD',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40434' and LRN not in ('2397')
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_3
select 'Haryana',datestr,sum(CALLDURATION),'HP','ILD',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40434' and length(B_PARTY_NUMBER) > 11
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_4
select 'Punjab',datestr,sum(CALLDURATION),'HP','Local',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40453' and LRN in ('2497')
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_5
select 'Punjab',datestr,sum(CALLDURATION),'HP','NLD',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40453' and LRN not in ('2497')
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_6
select 'Punjab',datestr,sum(CALLDURATION),'HP','ILD',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40453' and length(B_PARTY_NUMBER) > 11
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_7
select 'UP East',datestr,sum(CALLDURATION),'HP','Local',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40455' and LRN in ('2540')
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_8
select 'UP East',datestr,sum(CALLDURATION),'HP','NLD',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40455' and LRN not in ('2540')
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_9
select 'UP East',datestr,sum(CALLDURATION),'HP','ILD',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40455' and length(B_PARTY_NUMBER) > 11
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_10
select 'UP West',datestr,sum(CALLDURATION),'HP','Local',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40454' and LRN in ('2541')
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_11
select 'UP West',datestr,sum(CALLDURATION),'HP','NLD',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40454' and LRN not in ('2541')
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_12
select 'UP West',datestr,sum(CALLDURATION),'HP','ILD',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40454' and length(B_PARTY_NUMBER) > 11
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_13
select 'Rajasthan',datestr,sum(CALLDURATION),'HP','Local',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40459' and LRN in ('2498')
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_14
select 'Rajasthan',datestr,sum(CALLDURATION),'HP','NLD',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40459' and LRN not in ('2498')
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_15
select 'Rajasthan',datestr,sum(CALLDURATION),'HP','ILD',SUBSCRIPTIONTYPE
where ORIGINATINGCIRCLE = '40459' and length(B_PARTY_NUMBER) > 11
group by datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_16
select ORIGINATINGCIRCLE ,datestr,sum(CALLDURATION),'HP','MTC',SUBSCRIPTIONTYPE
where record_type='MTC' and ORIGINATINGCIRCLE not in ('40451','XXXXX')
group by ORIGINATINGCIRCLE,datestr,SUBSCRIPTIONTYPE
insert OVERWRITE table bsnl_intra_pre_hp_17
select ORIGINATINGCIRCLE ,datestr,sum(CALLDURATION),'HP','SMO',SUBSCRIPTIONTYPE
where record_type='SMO' and ORIGINATINGCIRCLE not in ('40451','XXXXX')
group by ORIGINATINGCIRCLE,datestr,SUBSCRIPTIONTYPE;
