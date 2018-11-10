# drum-dia
Drum Dia är ett program, som utgår från en textfil med kommandon, och ritar upp ett diagram över ett trumset - alltså en bild på ett trumset, sett uppifrån. Bilden är i svg-format, och kan också bäddas in i en html-fil.

Drum Dia: Creates drum set diagram from a text command file

```
Usage:

dd < infile.txt > outfile.svg

dd -svg < infile.txt > outfile.svg

dd -html < infile.txt > outfile.htm
```

test1.txt:

```
 c34 150@
 800 0 bd22
 750 -13 dr12
 750 13 dr14
 510 45 dr16
 850 40 cy20

 -150@
 390 0 dr14
 520 -45 hh14
 730 -15 cy16
```

test1.svg:

![svg-file](test1.jpg)

test2.txt:

```
 c34
 -150@ 800 -15 bd22
 740 -3 dr12
 550 -45 hh14
 800 -25 cy18

 150@ 800 15 bd22
 740 1 dr13
 740 29 dr14
 450 55 dr16
 800 60 cy22

 0@ 430 0 dr14
 900 0 cy10 
```

test2.svg:

![svg-file](test2.jpg)

