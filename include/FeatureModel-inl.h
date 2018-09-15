#ifndef FEATURE_MODEL_INL_H_
#define FEATURE_MODEL_INL_H_

#ifndef FEATURE_MODEL_H_
#error "FeatureModel-inl.h" should be included only in "FeatureModel.h" file.
#endif

#include <vector>
#include <string>
#include <utility>
#include <map>

typedef std::map<std::string, std::pair<Commons::DelimiterType, std::vector<Feature>>>
		FeatureModelMap;

FeatureModel::FeatureModel()
{
}

void FeatureModel::fill_feature_model_vector(std::vector<std::string>& tokens,
		std::string line, const char delimiter) noexcept
{
	constexpr char ASSIGN_DELIMITER = '=';
	constexpr uint8_t LEFT_VALUE_INDEX = 0;
	constexpr uint8_t RIGHT_VALUE_INDEX = 1;

	Commons::tokenize(tokens, line, ASSIGN_DELIMITER);
	line = tokens[RIGHT_VALUE_INDEX];
	tokens.erase(tokens.begin() + RIGHT_VALUE_INDEX);
	Commons::tokenize(tokens, line, delimiter);

	if (features.empty())
		root_name = tokens[LEFT_VALUE_INDEX];
}

std::string FeatureModel::get_root_name()
{
	return root_name;
}

std::string FeatureModel::get_adjacent_name(std::string parent_name, size_t index)
{
	return features[parent_name].second[index].get_name();
}

size_t FeatureModel::get_adjacents_size(std::string parent_name)
{
	return features[parent_name].second.size();
}

FeatureModelMap FeatureModel::get_features() const
{
	return features;
}

#endif
