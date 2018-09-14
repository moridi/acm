#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <vector>
#include <iostream>
#include <string>

class Configuration
{
public:
	inline Configuration();

	inline std::string make_compatible_string_for_configuration(std::string& line);
	void parse_configuration(std::string line) noexcept;

	inline void reset_validations();
	inline void set_true(size_t index);

	inline bool is_iterable();
	inline bool has_feature(std::string name) noexcept;

	inline std::string get_feature_name(size_t index) const;
	inline size_t get_size() const noexcept;
	inline int get_index(std::string name);
	inline std::string get_name(size_t index);
	inline bool get_validation(size_t index);

private:
	std::vector<std::string> configuration;
	std::vector<bool> configuration_validation;
};

#include "Configuration-inl.h"
#endif
