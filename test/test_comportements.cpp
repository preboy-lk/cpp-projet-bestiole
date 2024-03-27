#include "Aquarium.h"
#include "Milieu.h"
#include "Creator.h"
#include "cfg/ConfigReader.h"
#include "cfg/Configurations.h"
#include <iostream>

void displayHelp() {
    std::cout << "Utilisation: ./test_comportements <Nom de Comportement>" << std::endl;
    std::cout << "   -h, --help            Afficher ce message d'aide" << std::endl;
    std::cout<< std::endl;
    std::cout << " Options valides pour <Nom de Comportement > : peureuse, gregaire, kamikaze, prevoyante, personalites_multiples "<< std::endl;
}


bool isValidValue(const char* value) {
    return (std::strcmp(value, "peureuse") == 0 || std::strcmp(value, "gregaire") == 0 || 
            std::strcmp(value, "kamikaze") == 0 || std::strcmp(value, "prevoyante") == 0 || 
            std::strcmp(value, "personalites_multiples") == 0);
}

std::string getConfigFile(const char* comportements) {
    static const std::map<std::string, std::string> fileMap = {
        {"peureuse", "../cfg/config_peureuse.json"},
        {"gregaire", "../cfg/config_gregaire.json"},
        {"kamikaze", "../cfg/config_kamikaze.json"},
        {"prevoyante", "../cfg/config_prevoyante.json"},
        {"personalites_multiples", "../cfg/config_multiples.json"}
    };

    auto it = fileMap.find(comportements);
    if (it != fileMap.end()) {
        return it->second;
    }
    return ""; // Renvoie une chaîne vide si elle n'est pas trouvée
}

int main(int argc, char* argv[])
{
    // Vérifier si l'utilisateur a demandé de l'aide
    if (argc > 1) {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            displayHelp();
            return 0;
        }
        else if (!isValidValue(argv[1]))
        {
            std::cerr << "  Erreur : La valeur entrée est incorrecte. "<< std::endl;
            std::cerr << "  Veuillez entrer l'une des options suivantes pour <Nom de Comportement> : peureuse, gregaire, kamikaze, prevoyante ou personalites_multiples" << std::endl;
            return 1;
        }
    }
    else
    {
        std::cerr << "Erreur: veuillez fournir une valeur unique ou utiliser -h/--help pour les instructions d'utilisation." << std::endl;
        return 1;
    }

    std::string fileName = getConfigFile(argv[1]);
    
    if(!std::filesystem::exists(fileName)){
        std::cout << "Le fichier spécifié \"" << fileName << "\" est introuvable" << std::endl;
        return 1;
    }
    ConfigReader config(fileName);
    config.setGlobalConfig();
    std::cout << Configurations::MULTIPLE_RATIO << std::endl;
    Aquarium       ecosysteme( 640, 480, 30);
    std::unique_ptr<Creator> creator;

    for ( int i = 1; i <= 3; i++ ){
      ecosysteme.getMilieu().addMember( (creator->createBestiole()) );
    }
    ecosysteme.run();


    return 0;

}
