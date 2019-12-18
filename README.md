# Satanizer

This program takes a file, gets its most common words/strings and replace them by random generated strings.
It doesn't make the file unusable, just unreadable.

## How it works

**Most common words** (20 first, can be changed) of your file are retrieved by a bash script named **common.sh** that writes them in a file called **words**. 

A C program called **rdmstr.c** generates random strings (a-z,A-Z,0-9) and associate each random string to a common word from **words**. The C program print it all in a text file named **matches**.

Finally, a bash script called **replace.sh** does the replacement process between **matches** and **words**.

(work in progress)
