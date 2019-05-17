#pragma once


#include <unordered_map>
#include <array>
#include <algorithm>

template<typename Container, typename T1, typename T2, typename TC>
class value_syncer
{
	using container_type = typename Container::value_type;

	const Container& container;
	T1& key;
	T2& value;
	const TC container_type::* member;

public:
	value_syncer(const Container& container, T1& key, T2& value, const TC container_type::* member)
		: container{ container }
		, key{ key }
		, value{ value }
		, member{ member }
	{}

	auto key_to_value() const -> void
	{
		key = std::clamp(key, T1(0), T1(container.size() - 1));
		value = container.at(key).*member;
	}

	auto value_to_key() const -> void
	{
		auto it = std::find_if(std::begin(container), std::end(container), [this](const container_type& x)
		{
			return value == x.*member;
		});

		// Originally I wanted this to work with maps too, but fuck that
		if (it != std::end(container))
			key = it - std::begin(container);
		else
			key = T1(0);
	}
};

enum class sync_type
{
	VALUE_TO_KEY,
	KEY_TO_VALUE
};

template<sync_type Type, typename Container, typename T1, typename T2, typename TC>
static auto do_sync(const Container& container, T1& key, T2& value, TC Container::value_type::* member) -> void
{
	auto syncer = value_syncer<Container, T1, T2, TC>{ container, key, value, member };
	if constexpr (Type == sync_type::VALUE_TO_KEY)
		syncer.value_to_key();
	else
		syncer.key_to_value();
}

struct item_setting
{
	template<sync_type Type>
	void update()
	{
		do_sync<Type>(


			definition_index,

			);



	}
	int definition_index = 1;
};

class config
{
public:
	config()
	{
		// Ghetto fix for possible race conditions
		m_items.reserve(128);

		// Default config
		m_items.push_back(item_setting());
	}
	auto load() -> void;

	auto get_by_definition_index(int definition_index)->item_setting*;

	auto get_items() -> std::vector<item_setting>&
	{
		return m_items;
	}

private:
	std::vector<item_setting> m_items;
};

extern config g_config;