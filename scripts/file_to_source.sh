#!/bin/bash

function array_name()
{
        local path="$1";
        local filename=`basename "$1"`;
        local arr_name=`echo $filename | tr '[ .]' '_' `;
        printf "%s" "$arr_name";
}

function array_name_sed_fmt()
{
        local arr_name="$1";
        local sed_fmt="s/@arr_name@/$arr_name/g";
        printf "%s" "$sed_fmt";
}


function hexdump_format_string()
{
        local bytes_per_col=$1;
        local columns_per_row=$2;
        printf '  "\t" %s/%s "0x%%0%sx, " "\n"' "$columns_per_row" "$bytes_per_col" "$(($bytes_per_col*2))"
}

function sed_format_string()
{
        local bytes_per_col=$1;
        printf 's/0x  ,/0x00,/g; ${ s/, 0x00,$/\\n};/}; 1{s/^[^0]\+0x/unsigned char @arr_name@[] = \\n{\\n\\t0x/;}' "$(($bytes_per_col*8))"
}

function generate_array()
{
        local filename="$1";
        local arr_name="$(array_name $1)";
        printf '/* array generated from hexdump of %s */\n' `basename $1` ;
        hexdump -v -e "$(hexdump_format_string 1 16)" $filename | sed -e "$(sed_format_string 1)" | sed -e "$(array_name_sed_fmt $arr_name)";
        printf '\nconst unsigned char * data_start_%s = &%s[0];\n' "$arr_name" "$arr_name" ;
        printf 'const unsigned char * data_end_%s   = (data_start_%s + sizeof(%s));\n' "$arr_name" "$arr_name" "$arr_name" ;
}

generate_array "$1";
