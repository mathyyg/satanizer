tr -c '[:alnum:]' '[\n*]' < debut_jeu.c |
fgrep -v -w -f dict |
sort | uniq -c | sort -nr | head  -20