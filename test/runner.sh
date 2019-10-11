#! /bin/bash

dictionnaire=$1
maxThread=$2

#Le fichier dans lequel on sort le rapport
timestamp=`date "+%Y%m%d-%H%M%S"`
rapport="rapport$timestamp.txt"

#On vérifie qu'il y ai un diccionnaire a disposition
if [ -f $dictionnaire ]
then
	#On boucle dans le dico
	while read line
	do
		echo $line >> $rapport
		#On calcul le md5 du mot pris dans le dictionnaire
		md5Print=`echo -n $line | md5sum | cut -d " " -f1`
		i=2
		#Une boucle qui va augmenter le nombre de thread
		while [ $i -le $maxThread ]
		do
			echo "$i threads---------------------" > $rapport
			{ time ./bruteForce $i $md5Print; } 2>> $rapport
			((i++))
		done
	done < $dictionnaire
else
	echo "Le dictionnaire $dictionnaire n'existe pas"
fi
