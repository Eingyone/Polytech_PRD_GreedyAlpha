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

