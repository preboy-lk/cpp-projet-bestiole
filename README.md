BE BESTIOLES
----------------------------------------------------------------------
NGUYEN Le Kim
DUONG Hoang
JAO Jean-David
ZAOULY Heliote-Ismael 
----------------------------------------------------------------------
Présentation :
Ce programme propose la simulation simple d'un environnement aquatique dans lequel évoluent différents êtres vivants.
Différentes entités évoluent avec les caractéristiques suivantes :
 - Comportements particuliers, au nombre de 5
 - Des capteurs permettant de détecter les êtres vivants autour
 - Des accessoires pour se défendre et se protéger
 - Des vitesses différentes

-----------------------------------------------------------------------
Fonctionnement du programme :
Le programme se présente sous la forme d'une fenêtre ou évoluent les êtres vivants.
L'évolution peut être observée au cours du temps dans cette fenêtre.

-----------------------------------------------------------------------
Compilation et exécution :
Pour compiler, Allez dans le dossier build ( cd build) il suffit d'éxécuter le makefile avec la commande make.
Pour lancer le programme, la commande ./main est utilisée.
Pour lancer le programme avec un fichier de configuration particulier, la commande ./test_comportements + comportementes est utilisée.
Il est possible de nettoyer les fichiers de compilation avec la commande make clean.

-----------------------------------------------------------------------
Exécution des tests :
Il est possible d'éxecuter des tests pour chaque comportement.
Il suffit d'exécuter la commande : make tests/testPrevoyant,
puis ./tests/testPrevoyant .
testPrevoyant peut être remplacé par testGregaire, testKamikaze et testPeureux.

-----------------------------------------------------------------------
Personnalisation de la simulation :
La simulation est personnalisable pour permettre à l'utilisateur de modifier de nombreux paramètres.
Un modèle de configuration par défaut est disponible à la fin de ce fichier, en annexe.
Le fichier de configuration par défaut se nomme "bestiole_config.json".
Voici l'explication de chaque paramètre de la configuration :
{
    "starting_count" : 20, Nombre de bestioles créées par défaut, aux caractéristiques aléatoires (minimum=0)
    "pourcentages" : { Pourcentages qui définit la réparatition de chaque comportement lors de la création de bestioles aléatoires
        "gregaire" : 0.6, Pourcentage associé au comportement grégaire
        "peureuse" : 0.15, Pourcentage associé au comportement peureuse
        "multiple" : 0.10, Pourcentage associé au comportement multiple
        "kamikaze" : 0.05, Pourcentage associé au comportement kamikaze
        "prevoyante" : 0.10 Pourcentage associé au comportement prevoyante
    },
    "birth_per_frame_prob" : 0.01, Probabilité de naissance d'une nouvelle bestiole aléatoire par instant de simulation
    "frames_per_second" : 30, Nombre d'instants de simulation par seconde (et de dessins de la scène par seconde)
    "bestiole" : { Caractéristiques de la bestiole
        "min_lifetime_frames" : 300, Durée de vie naturelle minimale d'une bestiole en instants de simulation
        "max_lifetime_frames" : 1000, Durée de vie maximale d'une bestiole en instants de simulation
        "min_speed" : 4, Vitesse minimale d'une bestiole à sa création en pixel/instant de simulation
        "max_speed" : 10 Vitesse maximale d'une bestiole à sa création en pixel/instant de simulation
    },
    "capteurs" : { Paramètres des capteurs
        "yeux" : { Paramètres concernants les yeux, les paramètres sont choisis au hazard à la création entre [min,max]
            "alpha_range_deg" : [1,180], Champ de vision en degré
            "delta_range_px" : [1,500], Distance maximale de vision en pixels
            "gamma_range_01" : [0,1] Efficacité des yeux : Probabilité lorsqu'une bestiole est dans le champ de vision d'être réllement détectée
        },
        "oreilles" : { Paramètres concernants les oreilles
            "delta_range_px" : [1,300], Distance maximale d'écoute en pixel
            "gamma_range_01" : [0,0.8] Efficacité des yeux : Probabilité lorsqu'une bestiole est dans le champ d'écoute d'être réllement détectée
        }
    },
    "accessoires" : { Paramètres des accessoires
        "nageoires" : { Paramètres des nageoires
            "nu_max" : 5 La bestiole voit sa vitesse multipliée par un facteur constant choisi aléatoirement entre [1,nu_max]
        },
        "carapace" : {
            "omega_max" : 5,La bestiole voit sa probabilité de mourir par collsiion divisée par un facteur constant choisi aléatoirement entre [1,omega_max]
            "eta_max" : 3 La bestiole voit sa vitesse divisée par un facteur constant choisi aléatoirement entre [1,eta_max]
        },
        "camouflage" : {
            "psi_range" : [0,1] Le camouflage est efficace par un facteur constant choisi aléatoirement entre psi_range
        }
    },
    "specific_configs" : [ Ici, il est possible de spécifier des bestioles particulières qui vont apparaitre en plus des autres dans la simulation
        {
            "comportement" : "gregaire", Comportement de la bestiole : "gregaire", "prevoyante", "peureuse", "kamikaze", "multiple"
            "accessoires" : [ Accessoires présents sur la bestiole, maximum 3 et tous différents
                {
                    "type" : "carapace", Type d'accessoires : "carapace", "camouflage", "nageoires"
                    "omega" : 3, Paramètres spécifique à l'accessoire. Cette fonctionnalité de choix spécifique n'est encore implémentée.
                    "eta" : 1.5
                }
            ],
            "capteurs" : []
        },
        {
            "comportement" : "peureuse",
            "accessoires" : [],
            "capteurs" : [ Capteurs présents sur la bestiole, maximum 2 et tous différents
                {
                    "type" : "oreilles", Type de capteur : "Oreilles", "Yeux"
                    "delta" : 200,
                    "gamma" : 0.5
                }
            ]
        },
        {
            "comportement" : "kamikaze",
            "accessoires" : [
                {
                    "type" : "camouflage",
                    "psi" : 0.4
                }
            ],
            "capteurs" : []
        },
        {
            "comportement" : "gregaire",
            "accessoires" : [],
            "capteurs" : [
                {
                    "type" : "yeux",
                    "alpha" : 60,
                    "delta" : 200,
                    "gamma" : 0.8
                }
            ]
        },
        {
            "comportement" : "gregaire",
            "accessoires" : [
                {
                    "type" : "nageoires",
                    "nu" : 2
                }
            ],
            "capteurs" : []
        }
    ]
}

------------------------------------------------------------------
Personnalisation des comportements :
Il n'y a pas de manière simple de modifier les paramètres des comportements.
Voici toutefois les valeurs en question, à modifier directement dans le fichier .cpp associé avant de compiler à nouveau :
- FUIR_PENDANT (ComportementPeureux.cpp) = nombre d'images de la simulation pendant lesquelles fuir en cas de peur, avant de reprendre un régime de fonctionnement normal
- MULTIPLICATEUR_VITESSE (ComportementPeureux.cpp) = facteur multiplicatif (souvent supérieur à 1) à appliquer à la vitesse d'une bestiole apeurée pendant sa fuite
- VOISINS_MAX (ComportementPeureux.cpp) = nombre maximum de bestioles détectables à la fois sans prendre peur
- PROBA_CHANGEMENT (ComportementMultiple.cpp) = probabilité (entre 0 et 1) de changer de comportement à chaque image de la simulation (s'il n'y a pas de changement, le même comportement que précédemment est appliqué ; en cas de changement, le tirage est équiprobable et il demeure possible de retomber sur le même comportement)

------------------------------------------------------------------
Annexes :
Fichier de configuration par défaut :
{
    "starting_count" : 20,
    "pourcentages" : {
        "gregaire" : 0.6,
        "peureuse" : 0.15,
        "multiple" : 0.10,
        "kamikaze" : 0.05,
        "prevoyante" : 0.10
    },
    "birth_per_frame_prob" : 0.01,
    "frames_per_second" : 30,
    "bestiole" : {
        "min_lifetime_frames" : 300,
        "max_lifetime_frames" : 1000,
        "min_speed" : 4,
        "max_speed" : 10
    },
    "capteurs" : {
        "yeux" : {
            "alpha_range_deg" : [1,180],
            "delta_range_px" : [1,500],
            "gamma_range_01" : [0,1]
        },
        "oreilles" : {
            "delta_range_px" : [1,300],
            "gamma_range_01" : [0,0.8]
        }
    },
    "accessoires" : {
        "nageoires" : {
            "nu_max" : 5
        },
        "carapace" : {
            "omega_max" : 5,
            "eta_max" : 3
        },
        "camouflage" : {
            "psi_range" : [0,1]
        }
    },
    "specific_configs" : [
        {
            "comportement" : "gregaire",
            "accessoires" : [
                {
                    "type" : "carapace",
                    "omega" : 3,
                    "eta" : 1.5
                }
            ],
            "capteurs" : []
        },
        {
            "comportement" : "peureuse",
            "accessoires" : [],
            "capteurs" : [
                {
                    "type" : "oreilles",
                    "delta" : 200,
                    "gamma" : 0.5
                }
            ]
        },
        {
            "comportement" : "kamikaze",
            "accessoires" : [
                {
                    "type" : "camouflage",
                    "psi" : 0.4
                }
            ],
            "capteurs" : []
        },
        {
            "comportement" : "gregaire",
            "accessoires" : [],
            "capteurs" : [
                {
                    "type" : "yeux",
                    "alpha" : 60,
                    "delta" : 200,
                    "gamma" : 0.8
                }
            ]
        },
        {
            "comportement" : "gregaire",
            "accessoires" : [
                {
                    "type" : "nageoires",
                    "nu" : 2
                }
            ],
            "capteurs" : []
        }
    ]
}
