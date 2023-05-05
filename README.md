# Polytech_PRD_GreedyAlpha
Ce projet a été réalisé dans le cadre d'un projet en 5ième année d'études à Polytech Tours. Une station d’enregistrement est mise en place pour stocker le contenu diffusé sur les chaînes françaises. L’objectif est de stocker les diffusions afin d’y effectuer divers traitements (du fact checking pendant les campagnes présidentielles par exemple). La station TV n'a que 8 carte d'acquisition, il faut donc prendre une décision, car on ne peut enregistrer que 8 programmes simultanément. L'objectif de ce projet est d'implémenter un algorithme GreedyAlpha afin de produire une liste d'intervalles de temps à enregistrer.

L'algorithme implémanté est basé sur l'article "Interval selection : Applications, algorithms, and lower bounds" de Thomas Erlebach a et Frits C.R. Spieksma b,∗ :
http://www.cs.toronto.edu/tss/files/papers/1-s2.0-S0196677402002912-main.pdf

Voici le lien de la base de donnée : http://mathieu.delalandre.free.fr/projects/stvd/pms/

Voici le lien du site miroir : https://dataset-stvd.univ-tours.fr/pms/index.html

Utilisation :
-Télécharger un fichier XMLTV.
-Exécuter le scripte python : /Python/1_generate_latency.py pour générer le fichier collection. 
(Le script python lit tous les fichiers XML dans data/01, c’est ici qu’il faut placer les fichiers XMLTV)
-Lancer l’exécutable c++.
-Donner le chemin d’accès au fichier collection (fichiers exemples présents dans data).
-Donner le nombre d’intervalles simultanés souhaités (nombre de cartes d’acquisition pour la station TV).
-Donner la valeur d’alpha (ratio appliqué aux poids pour l’échange d’intervalles).
-Le fichier solution se trouvera dans le dossier Solution

Compilations : 
Pour re-générer l’exécutable, simplement utiliser g++ sur main.cpp en indiquant les classes au linker : 
g++ main.cpp Greedy.cpp Point.cpp Interval.cpp IntervalParser.cpp SolutionParser.cpp

Des lignes d'affichages sont commentées avec "// [PRINT] //", vous pouvez les utiliser.

Est disponible dans le fichier Doc : 
-Le rapport.
-Doxygen en html / Latex et le doxyfile.
-Les fichiers d’UML Astah.
-Un cahier de tests avec un fichier XMLTV de test et sa solution
