#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "Configurations.h"

class ConfigReader
{
	using json = nlohmann::json;
public:
	/**
	 * Construit un ConfigReader situé au chemin filePath
	 * Charge les données json depuis le fichier.
	*/
	ConfigReader(std::string filePath);
	/**
	 * Extrait les données de configurations depuis les données json
	*/
	void setGlobalConfig();
	/**
	 * Ajoute les bestioles au milieu correspondant au données json indiquées dans specific_configs
	*/
private:
	json data;
};

