#include "ConfigReader.h"

ConfigReader::ConfigReader(std::string filePath)
{
	std::ifstream file(filePath);
	try {
		data = json::parse(file);
	}
	catch (json::exception& e) {
		std::cout << "Une erreur à eu lieu " << e.what() << std::endl;
		throw std::runtime_error(e.what());
	}
}

void ConfigReader::setGlobalConfig()
{
    data.at("taux_naissance").get_to(Configurations::TAUX_NAISSANCE);
    data.at("clonage_probabilite").get_to(Configurations::CLONAGE_PROBABILITE);
    data.at("meurt_collision_probabilite").get_to(Configurations::MEURT_COLLISION_PROBABILITE);

	data.at("comportement_ratio").at("gregaire_ratio").get_to(Configurations::GREGAIRE_RATIO);
	data.at("comportement_ratio").at("peureuse_ratio").get_to(Configurations::PEUREUSE_RATIO);
    data.at("comportement_ratio").at("kamikaze_ratio").get_to(Configurations::KAMIKAZE_RATIO);
    data.at("comportement_ratio").at("prevoyante_ratio").get_to(Configurations::PREVOYANTE_RATIO);
    data.at("comportement_ratio").at("multiple_ratio").get_to(Configurations::MULTIPLE_RATIO);
	
	auto jsonCapteurs = data.at("capteurs");
	std::array<double,2> range;
	//Yeux
    jsonCapteurs.at("yeux").at("yeux_probabilite").get_to(Configurations::YEUX_PROBABILITE);
	jsonCapteurs.at("yeux").at("vision_angle").get_to(range);
	Configurations::VISION_ANGLE_MIN = M_PI*range[0]/180.0;
	Configurations::VISION_ANGLE_MAX = M_PI*range[1]/180.0;

	jsonCapteurs.at("yeux").at("vision_distance").get_to(range);
	Configurations::VISION_DISTANCE_MIN = range[0];
	Configurations::VISION_DISTANCE_MAX = range[1];

	jsonCapteurs.at("yeux").at("vision_detection_probabilite").get_to(range);
	Configurations::VISION_DETECTION_PROBABILITE_MIN = range[0];
	Configurations::VISION_DETECTION_PROBABILITE_MAX = range[1];

	//Oreilles
    jsonCapteurs.at("oreilles").at("oreilles_probabilite").get_to(Configurations::OREILLES_PROBABILITE);

	jsonCapteurs.at("oreilles").at("audible_distance").get_to(range);
	Configurations::AUDIBLE_DISTANCE_MIN = range[0];
	Configurations::AUDIBLE_DISTANCE_MAX = range[1];

	jsonCapteurs.at("oreilles").at("audible_detection_probabilite").get_to(range);
	Configurations::AUDIBLE_DETECTION_PROBABILITE_MIN = range[0];
	Configurations::AUDIBLE_DETECTION_PROBABILITE_MAX = range[1];

    //Accessoires
	auto jsonAccessoires = data.at("accessoires");

    //Camouflage
    jsonAccessoires.at("camouflage").at("camouflage_probabilite").get_to(Configurations::CAMOUFLAGE_PROBABILITE);

	jsonAccessoires.at("camouflage").at("camouflage_capacite").get_to(range);
	Configurations::CAMOUFLAGE_CAPACITE_MIN = range[0];
	Configurations::CAMOUFLAGE_CAPACITE_MAX = range[1];

    // Carapace
	jsonAccessoires.at("carapace").at("carapace_probabilite").get_to(Configurations::CARAPACE_PROBABILITE);
	jsonAccessoires.at("carapace").at("vitesse_reduction_coeff").get_to(Configurations::VITESSE_REDUCTION_COEFF);
    jsonAccessoires.at("carapace").at("meurt_reduction_coeff").get_to(Configurations::MEURT_REDUCTION_COEFF);
    
    //Nageoire
	jsonAccessoires.at("nageoire").at("nageoire_probabilite").get_to(Configurations::NAGEOIRE_PROBABILITE);
    jsonAccessoires.at("nageoire").at("acceleration_coeff").get_to(Configurations::ACCELERATION_COEFF);

}