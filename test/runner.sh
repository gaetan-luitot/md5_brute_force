#! /bin/bash

dictionnaire=$1
maxThread=$2
rapport="rapport.txt"#Le fichier dans lequel on sort le rapport
#On vérifie qu'il y ai un diccionnaire a disposition
if test -d $dictionnaire
then
	#On boucle dans le dico
	while read line
	do
		i = 0
		#Une boucle qui va augmenter le nombre de thread
		while [$i -l $maxThread]
		do
			exec '$rapport < time ./bruteForce $i $line'
			((i++))
		done
	done < $dictionnaire
fi
