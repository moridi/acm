#ifndef FEATURE_MODEL_H_
#define FEATURE_MODEL_H_

#include <vector>
#include <string>
#include <utility>
#include <map>

#include "Configuration.h"
#include "Feature.h"

class FeatureModel
{
public:
	typedef std::map<std::string, std::pair<Commons::DelimiterType, std::vector<Feature>>>
			FeatureModelMap;

	inline FeatureModel();

	void parse_feature_model(std::string line) noexcept;
	inline void fill_feature_model_vector(std::vector<std::string>& tokens,
			std::string line, const char delimiter) noexcept;

	inline std::string get_root_name();
	inline std::string get_adjacent_name(std::string parent_name, size_t index);
	inline size_t get_adjacents_size(std::string parent_name);
	inline FeatureModelMap get_features() const;

private:
	std::string root_name;
	FeatureModelMap features;
};

#include "FeatureModel-inl.h"
#endif
