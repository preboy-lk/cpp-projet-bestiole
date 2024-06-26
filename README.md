BE BESTIOLES
----------------------------------------------------------------------
NGUYEN Le Kim </br>
DUONG Hoang  </br>
JAO Jean-David </br>
ZAOULY Heliote-Ismael </br> 
----------------------------------------------------------------------
## Présentation :
Ce programme propose la simulation simple d'un environnement aquatique dans lequel évoluent différents êtres vivants.
Différentes entités évoluent avec les caractéristiques suivantes :
 - Comportements particuliers, au nombre de 5
 - Des capteurs permettant de détecter les êtres vivants autour
 - Des accessoires pour se défendre et se protéger
 - Des vitesses différentes

## Sommaire
- [Fonctionnement du programme](#fonctionnement)
- [Compilation et exécution](#compilation)
- [Exécution des tests](#exécutions)
  
## Fonctionnement du programme
Le programme se présente sous la forme d'une fenêtre ou évoluent les êtres vivants.
L'évolution peut être observée au cours du temps dans cette fenêtre.

## Compilation et exécution
Pour compiler le programme, navigateur vers le répertoire "build" avec la commande 
```bash
cd build
```
Puis exécutez le makefile en utilisant la commande
```bash
make
```
Pour exécuter le programme, utilisez la commande
```bash
./main
```
Pour lancer le programme avec un fichier de configuration particulier, accédez à cfg/config.json et modifiez les constantes qui y sont définies.
Pour effectuer une opération de nettoyage des fichiers de compilation, exécutez la commande.
```bash
make clean
```

## Exécution des tests :
Il est possible d'éxecuter des tests pour chaque comportement.
Il suffit d'exécuter la commande :
```bash
./test_comportements + <nom de comportement>
Options valides pour <Nom de Comportement > : peureuse, gregaire, kamikaze, prevoyante, personalites_multiples.
```
-----------------------------------------------------------------------
Personnalisation de la simulation :
La simulation est personnalisable pour permettre à l'utilisateur de modifier de nombreux paramètres.
Un modèle de configuration par défaut est disponible à la fin de ce fichier, en annexe.
Le fichier de configuration par défaut se nomme "config.json".
Voici l'explication de chaque paramètre de la configuration :
```bash
{
    {   
    "taux_naissance": 0.2, Possibilité de générer une bestiole toutes les 30 images 
    "clonage_probabilite": 0.2, Possibilité de clonage une bestiole toutes les 30 images 
    "meurt_collision_probabilite": 0.01, Possibilité de générer une bestiole toutes les 30 images 
    "comportement_ratio" : 
    {
        "gregaire_ratio": 0.0, Pourcentage associé au comportement grégaire 
        "peureuse_ratio": 0.0, Pourcentage associé au comportement peureuse  
        "kamikaze_ratio": 0.0, Pourcentage associé au comportement kamikaze 
        "prevoyante_ratio": 1.0, Pourcentage associé au comportement prevoyante 
        "multiple_ratio": 0.0 Pourcentage associé au comportement personalites multiples 
    }, 
         NOTE: Il faut que la somme de ces 5 ratio soit égale à 1, et qu'aucun d'eux ne soit négatif
    "capteurs": 
        "yeux": 
        { 
            "yeux_probabilite": 0.7, Possibilité d'être équipé d'yeux 
            "vision_angle": [0.0, 60.0], Champ de vision en degré 
            "vision_distance": [120.0, 140.0], Distance maximale de vision en pixels 
            "vision_detection_probabilite": [0.8, 0.9] Efficacité des yeux : Probabilité lorsqu'une bestiole est dans le champ de vision d'être réllement détectée 
        },
        "oreilles": 
            "oreilles_probabilite": 0.6, Possibilité d'être équipé d'oreilles
            "audible_distance": [60.0, 70.0],  Distance maximale d'écoute en pixel
            "audible_detection_probabilite": [0.8, 0.9] Efficacité des yeux : Probabilité lorsqu'une bestiole est dans le champ d'écoute d'être réllement détectée
        }
    }, 
    "accessoires":
    {
        "camouflage":
        {
            "camouflage_probabilite": 0.5, Possibilité d'être équipé de camouflage
            "camouflage_capacite": [0.0, 1.0] Le coefficient permet de réduire la possibilité d'être détecté par d'autres bestioles
        },
        "carapace":
        {
            "carapace_probabilite": 0.8, Possibilité d'être équipé de carapace
            "vitesse_reduction_coeff": 1.2, coefficient de décélération
            "meurt_reduction_coeff": 1.1 Coefficient de durabilité, aide à réduire le risque de décès après une collision
        },
        "nageoire":
        {
            "nageoire_probabilite": 0.2, Possibilité d'être équipé de nageoire
            "acceleration_coeff": 2.0  coefficient de accélération
        }
    }
}
```
