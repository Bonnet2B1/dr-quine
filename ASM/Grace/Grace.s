%define QUOTE 34
%define NEW_LINE 10
%define SOURCE_CODE ""
global main
extern printf

section .data
    source_code db SOURCE_CODE

section .text

main:
